/**
 * Algoritma ve Programlama 2 - Sınıflar ve Nesneler Temel Kavramlar
 * Bu program C++ dilinde sınıf ve nesne kullanımının temellerini gösterir.
 * 
 * Sınıflar (Class), nesne yönelimli programlamanın temel yapı taşlarıdır.
 * Sınıflar, veri üyeleri (özellikler) ve fonksiyon üyeleri (metotlar) içerebilir.
 * Nesneler ise, sınıflardan oluşturulan veri tipleridir. Bir sınıfın örneğidir.
 */

#include <iostream>
#include <string>
using namespace std;

// Basit bir sınıf tanımı
class Ogrenci {
private:
    // Private üyeler: Sınıf dışından doğrudan erişilemez
    int numara;
    string ad;
    string soyad;
    double ortalama;
    
public:
    // Public üyeler: Sınıf dışından erişilebilir
    
    // Constructor (Yapıcı) metot: Nesne oluşturulduğunda çağrılır
    Ogrenci() {
        numara = 0;
        ad = "";
        soyad = "";
        ortalama = 0.0;
        cout << "Parametresiz constructor çağrıldı." << endl;
    }
    
    // Parametreli constructor
    Ogrenci(int _numara, string _ad, string _soyad, double _ortalama) {
        numara = _numara;
        ad = _ad;
        soyad = _soyad;
        ortalama = _ortalama;
        cout << "Parametreli constructor çağrıldı." << endl;
    }
    
    // Destructor (Yıkıcı) metot: Nesne yok edildiğinde çağrılır
    ~Ogrenci() {
        cout << "Destructor çağrıldı. Öğrenci nesnesi siliniyor: " << ad << endl;
    }
    
    // Getter metotları (erişim metotları)
    int getNumara() {
        return numara;
    }
    
    string getAd() {
        return ad;
    }
    
    string getSoyad() {
        return soyad;
    }
    
    double getOrtalama() {
        return ortalama;
    }
    
    // Setter metotları (değiştirme metotları)
    void setNumara(int _numara) {
        numara = _numara;
    }
    
    void setAd(string _ad) {
        ad = _ad;
    }
    
    void setSoyad(string _soyad) {
        soyad = _soyad;
    }
    
    void setOrtalama(double _ortalama) {
        if (_ortalama >= 0 && _ortalama <= 4.0) {
            ortalama = _ortalama;
        } else {
            cout << "Hata: Ortalama 0-4 aralığında olmalıdır!" << endl;
        }
    }
    
    // Diğer üye fonksiyonlar
    void bilgileriGoster() {
        cout << "Öğrenci Bilgileri:" << endl;
        cout << "Numara: " << numara << endl;
        cout << "Ad: " << ad << endl;
        cout << "Soyad: " << soyad << endl;
        cout << "Ortalama: " << ortalama << endl;
    }
    
    bool basariliMi() {
        return ortalama >= 2.0;
    }
};

// İkinci bir sınıf örneği
class Dikdortgen {
private:
    double uzunluk;
    double genislik;
    
public:
    // Constructor
    Dikdortgen(double u = 1.0, double g = 1.0) {
        uzunluk = u;
        genislik = g;
    }
    
    // Getter ve setter metotları
    double getUzunluk() { return uzunluk; }
    double getGenislik() { return genislik; }
    
    void setUzunluk(double u) { 
        if (u > 0) uzunluk = u; 
        else cout << "Uzunluk pozitif olmalıdır!" << endl;
    }
    
    void setGenislik(double g) { 
        if (g > 0) genislik = g; 
        else cout << "Genişlik pozitif olmalıdır!" << endl;
    }
    
    // Alan ve çevre hesaplama metotları
    double alan() {
        return uzunluk * genislik;
    }
    
    double cevre() {
        return 2 * (uzunluk + genislik);
    }
    
    // Dikdörtgen bilgilerini yazdırma
    void bilgileriGoster() {
        cout << "Dikdörtgen:" << endl;
        cout << "Uzunluk: " << uzunluk << endl;
        cout << "Genişlik: " << genislik << endl;
        cout << "Alan: " << alan() << endl;
        cout << "Çevre: " << cevre() << endl;
    }
};

int main() {
    cout << "===== SINIFLAR VE NESNELER TEMEL KAVRAMLAR =====" << endl << endl;
    
    // 1. Nesne oluşturma
    cout << "1) Nesne oluşturma:" << endl;
    
    // Parametresiz constructor kullanarak nesne oluşturma
    Ogrenci ogr1;
    ogr1.setNumara(1001);
    ogr1.setAd("Ahmet");
    ogr1.setSoyad("Yılmaz");
    ogr1.setOrtalama(3.2);
    
    cout << "Öğrenci 1 oluşturuldu:" << endl;
    ogr1.bilgileriGoster();
    
    // Parametreli constructor kullanarak nesne oluşturma
    cout << endl;
    Ogrenci ogr2(1002, "Zeynep", "Kaya", 3.8);
    
    cout << "Öğrenci 2 oluşturuldu:" << endl;
    ogr2.bilgileriGoster();
    
    // 2. Üye fonksiyonları kullanma
    cout << endl << "2) Üye fonksiyonları kullanma:" << endl;
    
    cout << "Öğrenci 1 başarılı mı? " << (ogr1.basariliMi() ? "Evet" : "Hayır") << endl;
    
    ogr1.setOrtalama(1.8);
    ogr1.bilgileriGoster();
    cout << "Öğrenci 1 başarılı mı? " << (ogr1.basariliMi() ? "Evet" : "Hayır") << endl;
    
    // 3. Getter metotlarını kullanma
    cout << endl << "3) Getter metotlarını kullanma:" << endl;
    
    cout << "Öğrenci 2 bilgileri:" << endl;
    cout << "Numara: " << ogr2.getNumara() << endl;
    cout << "Ad: " << ogr2.getAd() << endl;
    cout << "Soyad: " << ogr2.getSoyad() << endl;
    cout << "Ortalama: " << ogr2.getOrtalama() << endl;
    
    // 4. İkinci sınıf örneği
    cout << endl << "4) Dikdörtgen sınıfı örneği:" << endl;
    
    Dikdortgen d1(5.0, 3.0);
    d1.bilgileriGoster();
    
    cout << endl;
    Dikdortgen d2;  // Varsayılan değerlerle (1x1) oluşur
    d2.bilgileriGoster();
    
    cout << endl;
    d2.setUzunluk(4.5);
    d2.setGenislik(2.5);
    d2.bilgileriGoster();
    
    // 5. Dinamik nesne oluşturma (pointer ile)
    cout << endl << "5) Dinamik nesne oluşturma (pointer ile):" << endl;
    
    Ogrenci* ogrPtr = new Ogrenci(1003, "Mehmet", "Demir", 2.9);
    
    cout << "Dinamik oluşturulan öğrenci:" << endl;
    ogrPtr->bilgileriGoster();  // -> operatörü pointer üzerinden nesnenin üyelerine erişmek için kullanılır
    
    // Dinamik oluşturulan nesneyi bellekten silme
    delete ogrPtr;
    
    return 0;
} 