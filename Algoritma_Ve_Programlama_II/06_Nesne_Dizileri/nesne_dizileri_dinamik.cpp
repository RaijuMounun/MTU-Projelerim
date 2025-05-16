/**
 * Algoritma ve Programlama 2 - Dinamik Nesne Dizileri
 * Bu program C++ dilinde dinamik nesne dizilerinin kullanımını gösterir.
 * 
 * Dinamik nesne dizileri, boyutu çalışma zamanında belirlenebilen nesne koleksiyonlarıdır.
 * Boyutun önceden bilinmediği veya değişken olduğu durumlarda kullanılır.
 * Bu örnekte "new" ve "delete" operatörleri ile dinamik bellek yönetimi gösterilmektedir.
 */

#include <iostream>
#include <string>
using namespace std;

// Ürün sınıfı tanımı
class Urun {
private:
    int id;
    string ad;
    double fiyat;
    
public:
    // Parametresiz constructor
    Urun() {
        id = 0;
        ad = "";
        fiyat = 0.0;
    }
    
    // Parametreli constructor
    Urun(int _id, string _ad, double _fiyat) {
        id = _id;
        ad = _ad;
        fiyat = _fiyat;
    }
    
    // Getter ve Setter metotları
    int getId() const { return id; }
    string getAd() const { return ad; }
    double getFiyat() const { return fiyat; }
    
    void setId(int _id) { id = _id; }
    void setAd(string _ad) { ad = _ad; }
    void setFiyat(double _fiyat) { fiyat = _fiyat; }
    
    // Ürün bilgilerini gösteren metot
    void bilgileriGoster() const {
        cout << "ID: " << id << ", Ad: " << ad << ", Fiyat: " << fiyat << " TL" << endl;
    }
};

// Öğrenci sınıfı tanımı
class Ogrenci {
private:
    int numara;
    string ad;
    string soyad;
    double* notlar;  // Dinamik not dizisi
    int notSayisi;   // Not sayısı
    
public:
    // Constructor
    Ogrenci(int _numara = 0, string _ad = "", string _soyad = "") {
        numara = _numara;
        ad = _ad;
        soyad = _soyad;
        notlar = nullptr;  // Başlangıçta not dizisi boş
        notSayisi = 0;
    }
    
    // Copy constructor - derin kopya (deep copy) oluşturmak için
    Ogrenci(const Ogrenci& digerOgrenci) {
        numara = digerOgrenci.numara;
        ad = digerOgrenci.ad;
        soyad = digerOgrenci.soyad;
        notSayisi = digerOgrenci.notSayisi;
        
        // Notlar için yeni bellek alanı ayırma
        if (notSayisi > 0) {
            notlar = new double[notSayisi];
            
            // Diğer öğrencinin notlarını kopyalama
            for (int i = 0; i < notSayisi; i++) {
                notlar[i] = digerOgrenci.notlar[i];
            }
        } else {
            notlar = nullptr;
        }
    }
    
    // Destructor
    ~Ogrenci() {
        // Dinamik olarak ayrılan belleği serbest bırakma
        if (notlar != nullptr) {
            delete[] notlar;
        }
    }
    
    // Not dizisi için bellek ayıran metot
    void notlariAyarla(int _notSayisi) {
        // Eğer zaten bir not dizisi varsa, önce onu serbest bırak
        if (notlar != nullptr) {
            delete[] notlar;
        }
        
        // Yeni not sayısını ayarla
        notSayisi = _notSayisi;
        
        // Yeni notlar için bellek ayırma
        if (notSayisi > 0) {
            notlar = new double[notSayisi];
            
            // Notları sıfırlama
            for (int i = 0; i < notSayisi; i++) {
                notlar[i] = 0.0;
            }
        } else {
            notlar = nullptr;
        }
    }
    
    // Belirli bir notun değerini ayarlama
    void notAyarla(int indeks, double deger) {
        if (notlar != nullptr && indeks >= 0 && indeks < notSayisi) {
            notlar[indeks] = deger;
        } else {
            cout << "Hata: Geçersiz not indeksi veya not dizisi henüz oluşturulmadı!" << endl;
        }
    }
    
    // Notları gösterme
    void notlariGoster() const {
        if (notlar != nullptr && notSayisi > 0) {
            cout << "Notlar: ";
            for (int i = 0; i < notSayisi; i++) {
                cout << notlar[i];
                if (i < notSayisi - 1) cout << ", ";
            }
            cout << endl;
        } else {
            cout << "Not bilgisi bulunmamaktadır." << endl;
        }
    }
    
    // Ortalama hesaplama
    double ortalamaHesapla() const {
        if (notlar == nullptr || notSayisi == 0) {
            return 0.0;
        }
        
        double toplam = 0.0;
        for (int i = 0; i < notSayisi; i++) {
            toplam += notlar[i];
        }
        
        return toplam / notSayisi;
    }
    
    // Getter metotları
    int getNumara() const { return numara; }
    string getAd() const { return ad; }
    string getSoyad() const { return soyad; }
    int getNotSayisi() const { return notSayisi; }
    
    // Öğrenci bilgilerini gösteren metot
    void bilgileriGoster() const {
        cout << "Numara: " << numara << ", Ad: " << ad << ", Soyad: " << soyad << endl;
        notlariGoster();
        cout << "Ortalama: " << ortalamaHesapla() << endl;
    }
};

// Sepet sınıfı - dinamik ürün dizisi kullanan bir sınıf
class Sepet {
private:
    Urun* urunler;       // Dinamik ürün dizisi
    int urunSayisi;      // Sepetteki toplam ürün sayısı
    int kapasite;        // Sepet kapasitesi
    
public:
    // Constructor
    Sepet(int _kapasite = 5) {
        kapasite = (_kapasite > 0) ? _kapasite : 5;  // En az 5 kapasiteli olsun
        urunler = new Urun[kapasite];  // Ürünler için bellek ayırma
        urunSayisi = 0;  // Başlangıçta sepet boş
    }
    
    // Copy constructor - derin kopya (deep copy)
    Sepet(const Sepet& digerSepet) {
        kapasite = digerSepet.kapasite;
        urunSayisi = digerSepet.urunSayisi;
        
        // Yeni ürünler dizisi için bellek ayırma
        urunler = new Urun[kapasite];
        
        // Diğer sepetteki ürünleri kopyalama
        for (int i = 0; i < urunSayisi; i++) {
            urunler[i] = digerSepet.urunler[i];
        }
    }
    
    // Destructor
    ~Sepet() {
        // Dinamik olarak ayrılan belleği serbest bırakma
        delete[] urunler;
    }
    
    // Sepete ürün ekleme
    bool urunEkle(const Urun& urun) {
        if (urunSayisi < kapasite) {
            urunler[urunSayisi] = urun;
            urunSayisi++;
            return true;
        } else {
            cout << "Sepet dolu! Ürün eklenemedi." << endl;
            return false;
        }
    }
    
    // Sepetten ürün çıkarma (ID'ye göre)
    bool urunCikar(int urunId) {
        for (int i = 0; i < urunSayisi; i++) {
            if (urunler[i].getId() == urunId) {
                // Bulunan ürünü çıkarma (sonraki ürünleri kaydırma)
                for (int j = i; j < urunSayisi - 1; j++) {
                    urunler[j] = urunler[j + 1];
                }
                urunSayisi--;
                return true;
            }
        }
        cout << "Ürün bulunamadı! ID: " << urunId << endl;
        return false;
    }
    
    // Sepeti boşaltma
    void sepetiBosalt() {
        urunSayisi = 0;
        cout << "Sepet boşaltıldı." << endl;
    }
    
    // Sepet içeriğini gösterme
    void icerikGoster() const {
        if (urunSayisi == 0) {
            cout << "Sepet boş." << endl;
            return;
        }
        
        cout << "Sepet İçeriği (" << urunSayisi << " ürün):" << endl;
        for (int i = 0; i < urunSayisi; i++) {
            cout << i+1 << ". ";
            urunler[i].bilgileriGoster();
        }
        
        // Toplam tutarı hesaplama
        double toplamTutar = 0.0;
        for (int i = 0; i < urunSayisi; i++) {
            toplamTutar += urunler[i].getFiyat();
        }
        cout << "Toplam Tutar: " << toplamTutar << " TL" << endl;
    }
    
    // Getter metotları
    int getUrunSayisi() const { return urunSayisi; }
    int getKapasite() const { return kapasite; }
};

int main() {
    cout << "===== DİNAMİK NESNE DİZİLERİ =====" << endl << endl;
    
    // 1. Dinamik Nesne Dizisi Oluşturma (new operatörü ile)
    cout << "1) Dinamik Nesne Dizisi Oluşturma:" << endl;
    
    int ogrenciSayisi;
    cout << "Kaç öğrenci bilgisi girilecek? ";
    cin >> ogrenciSayisi;
    
    // Dinamik öğrenci dizisi oluşturma
    Ogrenci* ogrenciler = new Ogrenci[ogrenciSayisi];
    
    // Öğrenci bilgilerini girme
    for (int i = 0; i < ogrenciSayisi; i++) {
        int numara;
        string ad, soyad;
        
        cout << "\n" << i+1 << ". Öğrenci Bilgileri:" << endl;
        cout << "Numara: ";
        cin >> numara;
        cin.ignore();  // Buffer temizleme
        
        cout << "Ad: ";
        getline(cin, ad);
        
        cout << "Soyad: ";
        getline(cin, soyad);
        
        ogrenciler[i] = Ogrenci(numara, ad, soyad);
        
        // Not sayısını belirleme ve notları girme
        int notSayisi;
        cout << "Not sayısı: ";
        cin >> notSayisi;
        
        ogrenciler[i].notlariAyarla(notSayisi);
        
        for (int j = 0; j < notSayisi; j++) {
            double not_degeri;
            cout << j+1 << ". Not: ";
            cin >> not_degeri;
            ogrenciler[i].notAyarla(j, not_degeri);
        }
    }
    
    // Öğrenci bilgilerini listeleme
    cout << "\nÖğrenci Listesi:" << endl;
    for (int i = 0; i < ogrenciSayisi; i++) {
        cout << i+1 << ". Öğrenci:" << endl;
        ogrenciler[i].bilgileriGoster();
        cout << endl;
    }
    
    // Belleği serbest bırakma
    delete[] ogrenciler;
    
    // 2. Sınıf İçinde Dinamik Dizi Kullanımı
    cout << "\n2) Sınıf İçinde Dinamik Dizi Kullanımı:" << endl;
    
    // Ürünleri oluşturalım
    Urun urun1(101, "Laptop", 15000);
    Urun urun2(102, "Telefon", 8000);
    Urun urun3(103, "Kulaklık", 500);
    Urun urun4(104, "Mouse", 250);
    
    // Sepet oluşturalım
    Sepet sepet1(3);  // 3 kapasiteli bir sepet
    
    // Sepete ürün ekleyelim
    sepet1.urunEkle(urun1);
    sepet1.urunEkle(urun2);
    
    // Sepet içeriğini gösterelim
    cout << "\nSepet 1 İçeriği:" << endl;
    sepet1.icerikGoster();
    
    // Bir ürün daha ekleyelim ve sepet dolsun
    sepet1.urunEkle(urun3);
    
    // Sepet doluyken eklemeyi deneyelim
    sepet1.urunEkle(urun4);  // Hata mesajı verecek
    
    // Sepetten ürün çıkaralım
    cout << "\nSepetten ürün çıkarma:" << endl;
    sepet1.urunCikar(102);  // Telefonu çıkar
    sepet1.icerikGoster();
    
    // Şimdi yeni bir ürün ekleyebiliriz
    sepet1.urunEkle(urun4);  // Mouse'u ekle
    cout << "\nYeni ürün eklendikten sonra:" << endl;
    sepet1.icerikGoster();
    
    // 3. Copy Constructor Kullanımı
    cout << "\n3) Copy Constructor Kullanımı (Derin Kopya):" << endl;
    
    // Sepet2, sepet1'in bir kopyası olacak
    Sepet sepet2 = sepet1;  // Copy constructor çağrılır
    
    cout << "\nSepet 2 (Sepet 1'in kopyası):" << endl;
    sepet2.icerikGoster();
    
    // Sepet1'i boşaltalım
    cout << "\nSepet 1 boşaltılıyor..." << endl;
    sepet1.sepetiBosalt();
    sepet1.icerikGoster();
    
    // Sepet2 hala dolu olmalı (derin kopya sayesinde)
    cout << "\nSepet 1 boşaltıldıktan sonra Sepet 2:" << endl;
    sepet2.icerikGoster();
    
    // 4. Öğrenci Kopyalama
    cout << "\n4) Öğrenci Nesnesi Kopyalama (Derin Kopya):" << endl;
    
    // Bir öğrenci oluşturalım
    Ogrenci ogr1(1001, "Ali", "Yılmaz");
    ogr1.notlariAyarla(3);
    ogr1.notAyarla(0, 85);
    ogr1.notAyarla(1, 90);
    ogr1.notAyarla(2, 75);
    
    cout << "Öğrenci 1:" << endl;
    ogr1.bilgileriGoster();
    
    // Öğrenciyi kopyalayalım
    Ogrenci ogr2 = ogr1;  // Copy constructor çağrılır
    
    cout << "\nÖğrenci 2 (Öğrenci 1'in kopyası):" << endl;
    ogr2.bilgileriGoster();
    
    // Öğrenci 1'in 2. notunu değiştirelim
    ogr1.notAyarla(1, 60);
    
    cout << "\nÖğrenci 1'in notu değiştikten sonra:" << endl;
    cout << "Öğrenci 1:" << endl;
    ogr1.bilgileriGoster();
    
    cout << "Öğrenci 2:" << endl;
    ogr2.bilgileriGoster();
    
    return 0;
} 