/**
 * Algoritma ve Programlama 2 - Sınıflarda Erişim Belirleyiciler
 * Bu program C++ dilinde sınıf erişim belirleyicilerini (access modifiers) gösterir.
 * 
 * C++'ta üç temel erişim belirleyici vardır:
 * 1. public: Herkes tarafından erişilebilir
 * 2. private: Sadece kendi sınıfının üye fonksiyonları tarafından erişilebilir
 * 3. protected: Kendi sınıfı ve o sınıftan türetilmiş sınıflar tarafından erişilebilir
 */

#include <iostream>
#include <string>
using namespace std;

// Ana sınıf tanımı
class Insan {
private:
    // Private üyeler: Sadece kendi sınıfı içinden erişilebilir
    string tcKimlik;
    
protected:
    // Protected üyeler: Kendi sınıfı ve türetilmiş sınıflardan erişilebilir
    string ad;
    string soyad;
    int yas;
    
public:
    // Public üyeler: Her yerden erişilebilir
    
    // Constructor
    Insan(string _tcKimlik = "", string _ad = "", string _soyad = "", int _yas = 0) {
        tcKimlik = _tcKimlik;
        ad = _ad;
        soyad = _soyad;
        yas = _yas;
    }
    
    // Getter ve Setter metotları
    string getTcKimlik() {
        return tcKimlik;
    }
    
    void setTcKimlik(string _tcKimlik) {
        // TC Kimlik numarası 11 haneli olmalıdır
        if (_tcKimlik.length() == 11) {
            tcKimlik = _tcKimlik;
        } else {
            cout << "Hata: TC Kimlik numarası 11 haneli olmalıdır!" << endl;
        }
    }
    
    string getAd() {
        return ad;
    }
    
    void setAd(string _ad) {
        ad = _ad;
    }
    
    string getSoyad() {
        return soyad;
    }
    
    void setSoyad(string _soyad) {
        soyad = _soyad;
    }
    
    int getYas() {
        return yas;
    }
    
    void setYas(int _yas) {
        if (_yas >= 0 && _yas <= 120) {
            yas = _yas;
        } else {
            cout << "Hata: Yaş 0-120 aralığında olmalıdır!" << endl;
        }
    }
    
    // Diğer public metotlar
    void bilgileriGoster() {
        cout << "İnsan Bilgileri:" << endl;
        cout << "TC Kimlik: " << (tcKimlik.empty() ? "Belirtilmemiş" : tcKimlik) << endl;
        cout << "Ad: " << (ad.empty() ? "Belirtilmemiş" : ad) << endl;
        cout << "Soyad: " << (soyad.empty() ? "Belirtilmemiş" : soyad) << endl;
        cout << "Yaş: " << yas << endl;
    }
    
    void selamVer() {
        cout << "Merhaba, ben " << ad << " " << soyad << "." << endl;
    }
};

// Türetilmiş sınıf (Derived class)
class Ogrenci : public Insan {
private:
    // Öğrenciye özel private üyeler
    int ogrenciNo;
    double ortalama;
    
public:
    // Constructor
    Ogrenci(string _tcKimlik = "", string _ad = "", string _soyad = "", int _yas = 0,
            int _ogrenciNo = 0, double _ortalama = 0.0)
        : Insan(_tcKimlik, _ad, _soyad, _yas) { // Türetilmiş sınıf, ana sınıfın constructor'ını çağırır
        
        ogrenciNo = _ogrenciNo;
        ortalama = _ortalama;
    }
    
    // Getter ve Setter metotları
    int getOgrenciNo() {
        return ogrenciNo;
    }
    
    void setOgrenciNo(int _ogrenciNo) {
        ogrenciNo = _ogrenciNo;
    }
    
    double getOrtalama() {
        return ortalama;
    }
    
    void setOrtalama(double _ortalama) {
        if (_ortalama >= 0.0 && _ortalama <= 4.0) {
            ortalama = _ortalama;
        } else {
            cout << "Hata: Ortalama 0-4 aralığında olmalıdır!" << endl;
        }
    }
    
    // Ana sınıfın metotlarını override etme (yeniden tanımlama)
    void bilgileriGoster() {
        // Ana sınıfın bilgileriGoster metotunu çağırma
        Insan::bilgileriGoster(); // Çünkü bu örnekte ana sınıftaki işler yapılmaya devam etsin istiyoruz.
        
        // Öğrenciye özel bilgileri ekleyerek gösterme
        cout << "Öğrenci No: " << ogrenciNo << endl;
        cout << "Ortalama: " << ortalama << endl;
    }
    
    // Protected üyelere erişim örneği
    void adSoyadDegistir(string _ad, string _soyad) {
        // ad ve soyad, ana sınıfta protected olduğu için türetilmiş sınıftan erişilebilir
        ad = _ad;
        soyad = _soyad;
        cout << "Ad ve soyad değiştirildi: " << ad << " " << soyad << endl;
    }
    
    // Private üyelere erişim denemesi
    /*
    void tcKimlikDegistir(string _tcKimlik) {
        // Bu kod hata verir, çünkü tcKimlik ana sınıfta private olarak tanımlıdır
        // tcKimlik = _tcKimlik;
        
        // Private üyelere erişmek için getter/setter metotları kullanılmalıdır
        setTcKimlik(_tcKimlik);
    }
    */
};

// Erişim belirleyicilerini göstermek için bir friend fonksiyon örneği
class Kutu {
private:
    double uzunluk;
    double genislik;
    double yukseklik;
    
    // Friend fonksiyon bildirimi (friend function)
    friend void kutuHacimGoster(Kutu k);
    
public:
    Kutu(double u = 1.0, double g = 1.0, double y = 1.0) {
        uzunluk = u;
        genislik = g;
        yukseklik = y;
    }
    
    double getUzunluk() { return uzunluk; }
    double getGenislik() { return genislik; }
    double getYukseklik() { return yukseklik; }
    
    void setUzunluk(double u) { uzunluk = u; }
    void setGenislik(double g) { genislik = g; }
    void setYukseklik(double y) { yukseklik = y; }
    
    double hacimHesapla() {
        return uzunluk * genislik * yukseklik;
    }
};

// Friend fonksiyon tanımı
// Bu fonksiyon Kutu sınıfının bir üyesi değil, ancak private üyelere erişebilir
void kutuHacimGoster(Kutu k) {
    cout << "Kutu Hacmi: " << k.uzunluk * k.genislik * k.yukseklik << " (friend fonksiyon ile)" << endl;
}

int main() {
    cout << "===== SINIFLARDA ERİŞİM BELİRLEYİCİLER =====" << endl << endl;
    
    // 1. Public erişim örneği
    cout << "1) Public erişim örneği:" << endl;
    
    Insan insan1("12345678901", "Ali", "Yılmaz", 30);
    insan1.bilgileriGoster();
    
    // Public metotlara her yerden erişilebilir
    insan1.setAd("Ahmet");
    insan1.selamVer();
    
    cout << endl;
    
    // 2. Private erişim örneği
    cout << "2) Private erişim örneği:" << endl;
    
    Insan insan2;
    
    // Private üyelere doğrudan erişilemez, sadece public metotlar üzerinden erişilebilir
    // insan2.tcKimlik = "12345678901";  // Bu kod hata verir.
    
    insan2.setTcKimlik("12345678901");
    insan2.setAd("Zeynep");
    insan2.setSoyad("Kaya");
    insan2.setYas(25);
    
    insan2.bilgileriGoster();
    
    cout << endl;
    
    // 3. Protected erişim örneği
    cout << "3) Protected erişim örneği:" << endl;
    
    Ogrenci ogr1("98765432109", "Mehmet", "Demir", 20, 1001, 3.5);
    ogr1.bilgileriGoster();
    
    // Protected üyelere ana sınıf dışından doğrudan erişilemez
    // ogr1.ad = "Yeni Ad";  // Bu kod hata verir.
    
    // Ancak türetilmiş sınıf içindeki metotlar protected üyelere erişebilir
    ogr1.adSoyadDegistir("Mehmet Can", "Demir");
    ogr1.bilgileriGoster();
    
    cout << endl;
    
    // 4. Friend fonksiyon örneği
    cout << "4) Friend fonksiyon örneği:" << endl;
    
    Kutu kutu1(2.0, 3.0, 4.0);
    cout << "Kutu Hacmi: " << kutu1.hacimHesapla() << " (üye fonksiyon ile)" << endl;
    
    // Friend fonksiyon private üyelere erişebilir
    kutuHacimGoster(kutu1);
    
    return 0;
} 