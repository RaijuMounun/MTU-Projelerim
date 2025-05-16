/**
 * Algoritma ve Programlama 2 - Nesne Dizileri Temel Kavramlar
 * Bu program C++ dilinde nesne dizilerinin temel kullanımını gösterir.
 * 
 * Nesne dizileri, aynı sınıfa ait nesnelerin bir koleksiyonunu oluşturmak için kullanılır.
 * Böylece aynı sınıfa ait birden fazla nesneyi tek bir değişkende tutabilir ve yönetebiliriz.
 */

#include <iostream>
#include <string>
using namespace std;

// Temel bir öğrenci sınıfı tanımlayalım
class Ogrenci {
private:
    int numara;
    string ad;
    string soyad;
    double ortalama;
    
public:
    // Parametresiz constructor
    Ogrenci() {
        numara = 0;
        ad = "";
        soyad = "";
        ortalama = 0.0;
    }
    
    // Parametreli constructor
    Ogrenci(int _numara, string _ad, string _soyad, double _ortalama) {
        numara = _numara;
        ad = _ad;
        soyad = _soyad;
        ortalama = _ortalama;
    }
    
    // Getter ve Setter metodları
    int getNumara() const { return numara; }
    string getAd() const { return ad; }
    string getSoyad() const { return soyad; }
    double getOrtalama() const { return ortalama; }
    
    void setNumara(int _numara) { numara = _numara; }
    void setAd(string _ad) { ad = _ad; }
    void setSoyad(string _soyad) { soyad = _soyad; }
    void setOrtalama(double _ortalama) { ortalama = _ortalama; }
    
    // Öğrenci bilgilerini gösteren metot
    void bilgileriGoster() const {
        cout << "Numara: " << numara << ", Ad: " << ad << ", Soyad: " << soyad
             << ", Ortalama: " << ortalama << endl;
    }
    
    // Öğrencinin başarı durumunu döndüren metot
    bool basariliMi() const {
        return ortalama >= 2.0; // 4.0 üzerinden 2.0 ve üzeri başarılı kabul edilsin
    }
};

// İkinci bir sınıf tanımlayalım
class Urun {
private:
    int id;
    string ad;
    double fiyat;
    int stokMiktari;
    
public:
    // Constructor
    Urun(int _id = 0, string _ad = "", double _fiyat = 0.0, int _stokMiktari = 0) {
        id = _id;
        ad = _ad;
        fiyat = _fiyat;
        stokMiktari = _stokMiktari;
    }
    
    // Getter metotları
    int getId() const { return id; }
    string getAd() const { return ad; }
    double getFiyat() const { return fiyat; }
    int getStokMiktari() const { return stokMiktari; }
    
    // Setter metotları
    void setId(int _id) { id = _id; }
    void setAd(string _ad) { ad = _ad; }
    void setFiyat(double _fiyat) { fiyat = _fiyat; }
    void setStokMiktari(int _stokMiktari) { stokMiktari = _stokMiktari; }
    
    // Ürün bilgilerini gösteren metot
    void bilgileriGoster() const {
        cout << "ID: " << id << ", Ad: " << ad << ", Fiyat: " << fiyat
             << " TL, Stok: " << stokMiktari << endl;
    }
    
    // Stok durumunu kontrol eden metot
    bool stokVarMi() const {
        return stokMiktari > 0;
    }
};

int main() {
    cout << "===== NESNE DİZİLERİ TEMEL KAVRAMLAR =====" << endl << endl;
    
    // 1. Statik Nesne Dizisi Oluşturma
    cout << "1) Statik Nesne Dizisi Oluşturma:" << endl;
    
    // a) Önce boş bir öğrenci dizisi oluşturup sonra değer atama
    Ogrenci sinif1[3]; // 3 elemanlı Ogrenci dizisi
    
    // Değer atama
    sinif1[0].setNumara(1001);
    sinif1[0].setAd("Ahmet");
    sinif1[0].setSoyad("Yılmaz");
    sinif1[0].setOrtalama(3.2);
    
    sinif1[1].setNumara(1002);
    sinif1[1].setAd("Zeynep");
    sinif1[1].setSoyad("Kaya");
    sinif1[1].setOrtalama(3.8);
    
    sinif1[2].setNumara(1003);
    sinif1[2].setAd("Mehmet");
    sinif1[2].setSoyad("Demir");
    sinif1[2].setOrtalama(1.9);
    
    // Öğrenci bilgilerini listeleme
    cout << "Sınıf 1 Öğrenci Listesi:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i+1 << ". Öğrenci - ";
        sinif1[i].bilgileriGoster();
    }
    
    cout << endl;
    
    // b) İlk değer vererek öğrenci dizisi oluşturma
    Ogrenci sinif2[3] = {
        Ogrenci(2001, "Ali", "Can", 2.7),
        Ogrenci(2002, "Ayşe", "Yıldız", 3.5),
        Ogrenci(2003, "Mustafa", "Öztürk", 1.8)
    };
    
    // Öğrenci bilgilerini listeleme
    cout << "Sınıf 2 Öğrenci Listesi:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i+1 << ". Öğrenci - ";
        sinif2[i].bilgileriGoster();
    }
    
    cout << endl;
    
    // 2. Nesne Dizisinde Belirli Özelliklere Göre İşlem Yapma
    cout << "2) Nesne Dizisinde Belirli Özelliklere Göre İşlem Yapma:" << endl;
    
    // Başarılı öğrencileri listeleme
    cout << "Başarılı Öğrenciler (Sınıf 1):" << endl;
    for (int i = 0; i < 3; i++) {
        if (sinif1[i].basariliMi()) {
            cout << "- ";
            sinif1[i].bilgileriGoster();
        }
    }
    
    // Ortalama hesaplama
    double toplamOrtalama = 0.0;
    for (int i = 0; i < 3; i++) {
        toplamOrtalama += sinif1[i].getOrtalama();
    }
    double sinifOrtalamasi = toplamOrtalama / 3;
    
    cout << "Sınıf 1 Genel Ortalaması: " << sinifOrtalamasi << endl;
    
    cout << endl;
    
    // 3. Farklı Boyutta Nesne Dizileri
    cout << "3) Farklı Boyutta Nesne Dizileri:" << endl;
    
    const int URUN_SAYISI = 5;
    Urun urunler[URUN_SAYISI] = {
        Urun(101, "Laptop", 15000, 10),
        Urun(102, "Telefon", 8000, 25),
        Urun(103, "Kulaklık", 500, 50),
        Urun(104, "Mouse", 250, 0),
        Urun(105, "Klavye", 350, 15)
    };
    
    cout << "Ürün Listesi:" << endl;
    for (int i = 0; i < URUN_SAYISI; i++) {
        cout << i+1 << ". ";
        urunler[i].bilgileriGoster();
    }
    
    // Stokta olan ürünleri listeleme
    cout << "\nStokta Olan Ürünler:" << endl;
    for (int i = 0; i < URUN_SAYISI; i++) {
        if (urunler[i].stokVarMi()) {
            cout << "- ";
            urunler[i].bilgileriGoster();
        }
    }
    
    // Fiyat aralığına göre filtreleme
    double minFiyat = 300;
    double maxFiyat = 1000;
    
    cout << "\n" << minFiyat << " - " << maxFiyat << " TL Arası Ürünler:" << endl;
    for (int i = 0; i < URUN_SAYISI; i++) {
        double fiyat = urunler[i].getFiyat();
        if (fiyat >= minFiyat && fiyat <= maxFiyat) {
            cout << "- ";
            urunler[i].bilgileriGoster();
        }
    }
    
    // 4. Dizideki en yüksek ve en düşük değerleri bulma
    cout << "\n4) Dizideki En Yüksek ve En Düşük Değerleri Bulma:" << endl;
    
    // En pahalı ve en ucuz ürünü bulma
    int enPahaliIndeks = 0;
    int enUcuzIndeks = 0;
    
    for (int i = 1; i < URUN_SAYISI; i++) {
        if (urunler[i].getFiyat() > urunler[enPahaliIndeks].getFiyat()) {
            enPahaliIndeks = i;
        }
        
        if (urunler[i].getFiyat() < urunler[enUcuzIndeks].getFiyat()) {
            enUcuzIndeks = i;
        }
    }
    
    cout << "En Pahalı Ürün: ";
    urunler[enPahaliIndeks].bilgileriGoster();
    
    cout << "En Ucuz Ürün: ";
    urunler[enUcuzIndeks].bilgileriGoster();
    
    return 0;
} 