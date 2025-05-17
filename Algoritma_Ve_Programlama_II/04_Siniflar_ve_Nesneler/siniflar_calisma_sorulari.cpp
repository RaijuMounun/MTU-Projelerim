/**
 * Algoritma ve Programlama 2 - Sınıflar ve Nesneler Çalışma Soruları
 * Bu program, sınıflar ve nesneler konusunda pratik yapmak için hazırlanmış
 * çalışma sorularını ve çözümlerini içerir.
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// ================= SORU 1 =================
// Soru: Bir "Araba" sınıfı oluşturun. Bu sınıf, arabanın markası, modeli, 
// üretim yılı ve fiyatı gibi özellikleri içermeli. 
// Ayrıca arabanın yaşını hesaplayan ve bilgilerini gösteren metotlar ekleyin.

class Araba {
private:
    string marka;
    string model;
    int uretimYili;
    double fiyat;
    
public:
    // Constructor
    Araba(string _marka = "", string _model = "", int _uretimYili = 2023, double _fiyat = 0.0) {
        marka = _marka;
        model = _model;
        uretimYili = _uretimYili;
        fiyat = _fiyat;
    }
    
    // Getter ve Setter metotları
    string getMarka() { return marka; }
    string getModel() { return model; }
    int getUretimYili() { return uretimYili; }
    double getFiyat() { return fiyat; }
    
    void setMarka(string _marka) { marka = _marka; }
    void setModel(string _model) { model = _model; }
    void setUretimYili(int _uretimYili) { uretimYili = _uretimYili; }
    void setFiyat(double _fiyat) { fiyat = _fiyat; }
    
    // Arabanın yaşını hesaplayan metot
    int yasHesapla(int suankiYil = 2025) {
        return suankiYil - uretimYili;
    }
    
    // Arabanın bilgilerini gösteren metot
    void bilgileriGoster() {
        cout << "Araba Bilgileri:" << endl;
        cout << "Marka: " << marka << endl;
        cout << "Model: " << model << endl;
        cout << "Üretim Yılı: " << uretimYili << endl;
        cout << "Araç Yaşı: " << yasHesapla() << endl;
        cout << "Fiyat: " << fiyat << " TL" << endl;
    }
};

// ================= SORU 2 =================
// Soru: Bir "Nokta" sınıfı oluşturun. Bu sınıf, 2D düzlemde bir noktanın x ve y
// koordinatlarını içermeli. İki nokta arasındaki mesafeyi hesaplayan bir metot ekleyin.

class Nokta {
private:
    double x;
    double y;
    
public:
    // Constructor
    Nokta(double _x = 0.0, double _y = 0.0) {
        x = _x;
        y = _y;
    }
    
    // Getter ve Setter metotları
    double getX() { return x; }
    double getY() { return y; }
    
    void setX(double _x) { x = _x; }
    void setY(double _y) { y = _y; }
    
    // İki nokta arasındaki mesafeyi hesaplayan metot
    double mesafeHesapla(Nokta digerNokta) {
        double xFark = x - digerNokta.x;
        double yFark = y - digerNokta.y;
        return sqrt(xFark*xFark + yFark*yFark);
    }
    
    // Noktanın koordinatlarını gösteren metot
    void kordinatlariGoster() {
        cout << "Nokta: (" << x << ", " << y << ")" << endl;
    }
};

// ================= SORU 3 =================
// Soru: Bir "BankaHesabi" sınıfı oluşturun. Bu sınıf, hesap numarası, hesap sahibinin adı,
// ve bakiye gibi özellikleri içermeli. Para yatırma, çekme ve hesap durumunu
// gösterme gibi metotlar ekleyin.

class BankaHesabi {
private:
    string hesapNo;
    string hesapSahibi;
    double bakiye;
    
public:
    // Constructor
    BankaHesabi(string _hesapNo = "", string _hesapSahibi = "", double _bakiye = 0.0) {
        hesapNo = _hesapNo;
        hesapSahibi = _hesapSahibi;
        bakiye = _bakiye;
    }
    
    // Para yatırma metodu
    void paraYatir(double miktar) {
        if (miktar > 0) {
            bakiye += miktar;
            cout << miktar << " TL yatırıldı." << endl;
        } else {
            cout << "Hata: Geçersiz miktar!" << endl;
        }
    }
    
    // Para çekme metodu
    void paraCek(double miktar) {
        if (miktar > 0 && miktar <= bakiye) {
            bakiye -= miktar;
            cout << miktar << " TL çekildi." << endl;
        } else if (miktar <= 0) {
            cout << "Hata: Geçersiz miktar!" << endl;
        } else {
            cout << "Hata: Yetersiz bakiye!" << endl;
        }
    }
    
    // Hesap durumunu gösteren metot
    void hesapDurumunuGoster() {
        cout << "Hesap Durumu:" << endl;
        cout << "Hesap No: " << hesapNo << endl;
        cout << "Hesap Sahibi: " << hesapSahibi << endl;
        cout << "Bakiye: " << bakiye << " TL" << endl;
    }
};

// ================= SORU 4 =================
// Soru: Bir "Ogrenci" sınıfı oluşturun. Öğrencilerin adı, numarası ve bir dizi 
// not (vector<double>) içermeli. Ortalama notu hesaplayan ve öğrenci durumunu
// (geçti/kaldı) belirleyen metotlar ekleyin.

class Ogrenci {
private:
    string ad;
    int numara;
    vector<double> notlar;
    
public:
    // Constructor
    Ogrenci(string _ad = "", int _numara = 0) {
        ad = _ad;
        numara = _numara;
    }
    
    // Not ekleme metodu
    void notEkle(double not_degeri) {
        if (not_degeri >= 0 && not_degeri <= 100) {
            notlar.push_back(not_degeri);
            cout << "Not eklendi: " << not_degeri << endl;
        } else {
            cout << "Hata: Not 0-100 aralığında olmalıdır!" << endl;
        }
    }
    
    // Ortalama hesaplama metodu
    double ortalamaHesapla() {
        if (notlar.empty()) {
            return 0.0;
        }
        
        double toplam = 0.0;
        for (double not_degeri : notlar) {
            toplam += not_degeri;
        }
        
        return toplam / notlar.size();
    }
    
    // Öğrenci durumunu belirleyen metot
    bool gectiMi(double gecmeNotu = 60.0) {
        return ortalamaHesapla() >= gecmeNotu;
    }
    
    // Öğrenci bilgilerini gösteren metot
    void bilgileriGoster() {
        cout << "Öğrenci Bilgileri:" << endl;
        cout << "Ad: " << ad << endl;
        cout << "Numara: " << numara << endl;
        
        cout << "Notlar: ";
        for (double not_degeri : notlar) {
            cout << not_degeri << " ";
        }
        cout << endl;
        
        double ortalama = ortalamaHesapla();
        cout << "Ortalama: " << ortalama << endl;
        cout << "Durum: " << (gectiMi() ? "Geçti" : "Kaldı") << endl;
    }
};

// ================= SORU 5 =================
// Soru: Bir "Kitap" sınıfı ve bir "Kutuphane" sınıfı oluşturun. 
// Kitap sınıfı, kitabın başlığı, yazarı, ISBN ve sayfa sayısı gibi özellikleri içermeli.
// Kütüphane sınıfı, kitapların bir listesini (vector<Kitap>) içermeli
// ve kitap ekleme, çıkarma, arama gibi metotlar içermeli.

class Kitap {
private:
    string baslik;
    string yazar;
    string isbn;
    int sayfaSayisi;
    
public:
    // Constructor
    Kitap(string _baslik = "", string _yazar = "", string _isbn = "", int _sayfaSayisi = 0) {
        baslik = _baslik;
        yazar = _yazar;
        isbn = _isbn;
        sayfaSayisi = _sayfaSayisi;
    }
    
    // Getter metotları
    string getBaslik() const { return baslik; }
    string getYazar() const { return yazar; }
    string getISBN() const { return isbn; }
    int getSayfaSayisi() const { return sayfaSayisi; }
    
    // Kitap bilgilerini gösteren metot
    void bilgileriGoster() {
        cout << "Kitap: " << baslik << endl;
        cout << "Yazar: " << yazar << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Sayfa Sayısı: " << sayfaSayisi << endl;
    }
};

class Kutuphane {
private:
    string ad;
    vector<Kitap> kitaplar;
    
public:
    // Constructor
    Kutuphane(string _ad = "") {
        ad = _ad;
    }
    
    // Kitap ekleme metodu
    void kitapEkle(const Kitap& kitap) {
        kitaplar.push_back(kitap);
        cout << "Kitap eklendi: " << kitap.getBaslik() << endl;
    }
    
    // Kitap çıkarma metodu (ISBN'e göre)
    bool kitapCikar(string isbn) {
        for (size_t i = 0; i < kitaplar.size(); i++) {
            if (kitaplar[i].getISBN() == isbn) {
                cout << "Kitap çıkarıldı: " << kitaplar[i].getBaslik() << endl;
                kitaplar.erase(kitaplar.begin() + i);
                return true;
            }
        }
        cout << "Kitap bulunamadı. ISBN: " << isbn << endl;
        return false;
    }
    
    // Kitap arama metodu (ISBN'e göre)
    Kitap* kitapAra(string isbn) {
        for (size_t i = 0; i < kitaplar.size(); i++) {
            if (kitaplar[i].getISBN() == isbn) {
                return &kitaplar[i];
            }
        }
        return nullptr;
    }
    
    // Tüm kitapları listeleyen metot
    void kitaplariListele() {
        cout << "Kütüphane: " << ad << endl;
        cout << "Kitap Sayısı: " << kitaplar.size() << endl;
        
        if (kitaplar.empty()) {
            cout << "Kütüphanede kitap bulunmamaktadır." << endl;
            return;
        }
        
        cout << "Kitaplar:" << endl;
        cout << "=================================" << endl;
        for (size_t i = 0; i < kitaplar.size(); i++) {
            cout << i+1 << ". ";
            kitaplar[i].bilgileriGoster();
            cout << "---------------------------------" << endl;
        }
    }
};

// ================= MAIN FONKSIYONU =================
int main() {
    cout << "===== SINIFLAR VE NESNELER ÇALIŞMA SORULARI =====" << endl << endl;
    
    int secim = 0;
    
    while (true) {
        cout << "\nÇalışmak istediğiniz soruyu seçin (1-5, 0 çıkış): ";
        cin >> secim;
        
        if (secim == 0) {
            cout << "Program sonlandırılıyor..." << endl;
            break;
        }
        
        cout << "\n===================================" << endl;
        
        switch (secim) {
            case 1: { // Araba Sınıfı
                cout << "SORU 1: Araba Sınıfı\n" << endl;
                
                Araba araba1("Toyota", "Corolla", 2019, 350000);
                araba1.bilgileriGoster();
                
                cout << "\nArabanın yaşı: " << araba1.yasHesapla() << endl;
                
                // Bilgileri değiştirme
                araba1.setUretimYili(2020);
                araba1.setFiyat(400000);
                
                cout << "\nGüncellenen bilgiler:" << endl;
                araba1.bilgileriGoster();
                
                break;
            }
            case 2: { // Nokta Sınıfı
                cout << "SORU 2: Nokta Sınıfı\n" << endl;
                
                Nokta nokta1(3, 4);
                Nokta nokta2(6, 8);
                
                nokta1.kordinatlariGoster();
                nokta2.kordinatlariGoster();
                
                double mesafe = nokta1.mesafeHesapla(nokta2);
                cout << "İki nokta arasındaki mesafe: " << mesafe << endl;
                
                break;
            }
            case 3: { // BankaHesabi Sınıfı
                cout << "SORU 3: BankaHesabi Sınıfı\n" << endl;
                
                BankaHesabi hesap("123456", "Ali Yılmaz", 1000);
                hesap.hesapDurumunuGoster();
                
                hesap.paraYatir(500);
                hesap.hesapDurumunuGoster();
                
                hesap.paraCek(200);
                hesap.hesapDurumunuGoster();
                
                // Hata durumları
                hesap.paraYatir(-100);
                hesap.paraCek(2000);
                
                break;
            }
            case 4: { // Ogrenci Sınıfı
                cout << "SORU 4: Ogrenci Sınıfı\n" << endl;
                
                Ogrenci ogrenci("Ayşe Demir", 12345);
                
                ogrenci.notEkle(85);
                ogrenci.notEkle(90);
                ogrenci.notEkle(75);
                
                // Hatalı not girişi
                ogrenci.notEkle(110);
                
                ogrenci.bilgileriGoster();
                
                // Yeni bir not ekleme
                ogrenci.notEkle(65);
                ogrenci.bilgileriGoster();
                
                break;
            }
            case 5: { // Kitap ve Kutuphane Sınıfları
                cout << "SORU 5: Kitap ve Kutuphane Sınıfları\n" << endl;
                
                Kutuphane kutuphane("Şehir Kütüphanesi");
                
                Kitap kitap1("Suç ve Ceza", "Fyodor Dostoyevski", "9789750726439", 687);
                Kitap kitap2("1984", "George Orwell", "9789750718632", 352);
                Kitap kitap3("Simyacı", "Paulo Coelho", "9789750726446", 184);
                
                kutuphane.kitapEkle(kitap1);
                kutuphane.kitapEkle(kitap2);
                kutuphane.kitapEkle(kitap3);
                
                kutuphane.kitaplariListele();
                
                // Kitap arama
                Kitap* bulunanKitap = kutuphane.kitapAra("9789750718632");
                if (bulunanKitap) {
                    cout << "\nKitap bulundu:" << endl;
                    bulunanKitap->bilgileriGoster();
                }
                
                // Kitap çıkarma
                kutuphane.kitapCikar("9789750718632");
                kutuphane.kitaplariListele();
                
                break;
            }
            default:
                cout << "Geçersiz seçim! Lütfen 1-5 arası bir sayı girin." << endl;
        }
    }
    
    return 0;
} 