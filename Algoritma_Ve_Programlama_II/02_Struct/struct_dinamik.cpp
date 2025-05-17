/**
 * Algoritma ve Programlama 2 - Struct (Yapı) ve Dinamik Bellek Yönetimi
 * Bu program struct yapılarında dinamik bellek yönetimini gösterir.
 * 
 * Struct'lar içinde dinamik bellek kullanımı, daha esnek veri yapıları oluşturmamızı sağlar.
 * Örneğin, boyutu önceden bilinmeyen dizileri struct içinde tutabiliriz.
 * Ancak dinamik bellek kullanımı, bellek yönetimi sorumluluğunu da beraberinde getirir.
 * Bu örnekte, struct içinde dinamik bellek kullanımı ve bellek yönetimi gösterilmektedir.
 */

#include <iostream>
#include <string>
#include <cstring> // strcpy için
using namespace std;

// Dinamik bellek içeren struct
/*
 * Bu struct içinde dinamik bellek kullanımı gösteren üyeler var:
 * - ad ve soyad: char pointer'ları, bellek dinamik olarak ayrılacak
 * - notlar: double pointer'ı, dinamik dizi olarak kullanılacak
 * 
 * Dinamik bellek içeren struct'lar kullanırken dikkat edilmesi gereken noktalar:
 * 1. Bellek ayırma (new/malloc)
 * 2. Belleği temizleme (delete/free)
 * 3. Derin kopyalama (deep copy) ihtiyacı
 * Çünkü c++ eski bir dil.
 */
struct Ogrenci {
    int numara;
    char* ad;        // Dinamik bellek kullanılacak
    char* soyad;     // Dinamik bellek kullanılacak
    double* notlar;  // Dinamik dizi olarak notlar
    int notSayisi;
};

// Dinamik dizi içeren struct
/*
 * Bu struct içinde dinamik Ogrenci dizisi tutan bir üye var.
 * Bir struct içinde başka bir struct'ın dinamik dizisini tutmak,
 * iç içe dinamik bellek yönetimi gerektirir.
 */
struct Sinif {
    string sinifAdi;
    Ogrenci* ogrenciler; // Dinamik Ogrenci dizisi
    int ogrenciSayisi;
};

// Fonksiyon prototipleri
Ogrenci ogrenciOlustur(int numara, const char* ad, const char* soyad, int notSayisi);
void ogrenciGoster(const Ogrenci& ogr);
void ogrenciTemizle(Ogrenci& ogr);
Sinif sinifOlustur(string sinifAdi, int ogrenciSayisi);
void sinifaOgrenciEkle(Sinif& sinif, int index, const Ogrenci& ogr);
void sinifGoster(const Sinif& sinif);
void sinifTemizle(Sinif& sinif);

int main() {
    cout << "===== STRUCT (YAPI) VE DİNAMİK BELLEK YÖNETİMİ =====" << endl << endl;
    
    // 1. Dinamik bellek içeren struct oluşturma
    /*
     * Dinamik bellek içeren struct oluşturmak için özel bir fonksiyon kullanıyoruz.
     * Bu fonksiyon, struct'ın üyeleri için gereken belleği ayırır ve başlangıç değerlerini atar.
     */
    cout << "1) Dinamik bellek içeren struct oluşturma:" << endl;
    
    Ogrenci ogr1 = ogrenciOlustur(1001, "Ahmet", "Yılmaz", 3);
    
    // Notları atama
    /*
     * Dinamik olarak ayrılan notlar dizisine değer atıyoruz.
     * Bu dizi için bellek, ogrenciOlustur fonksiyonu içinde ayrılmıştı.
     */
    ogr1.notlar[0] = 85.5;
    ogr1.notlar[1] = 90.0;
    ogr1.notlar[2] = 78.5;
    
    ogrenciGoster(ogr1);
    
    // 2. Dinamik Ogrenci dizisi içeren Sinif oluşturma
    /*
     * Şimdi daha karmaşık bir yapı oluşturuyoruz: Ogrenci struct'larından oluşan
     * dinamik bir dizi içeren Sinif struct'ı.
     * 
     * Bu, iç içe dinamik bellek yönetimi gerektirir:
     * - Sinif struct'ı için Ogrenci dizisi belleği
     * - Her bir Ogrenci için ad, soyad ve notlar için bellek
     */
    cout << "\n2) Dinamik Ogrenci dizisi içeren Sinif oluşturma:" << endl;
    
    Sinif sinif1 = sinifOlustur("10-A", 3);
    
    // Öğrencileri oluşturup sınıfa ekleme
    /*
     * Önce Ogrenci struct'larını oluşturuyoruz, sonra bunları sınıfa ekliyoruz.
     * sinifaOgrenciEkle fonksiyonu, öğrencilerin derin kopyasını oluşturur.
     */
    Ogrenci ogr2 = ogrenciOlustur(1002, "Zeynep", "Kaya", 2);
    ogr2.notlar[0] = 92.0;
    ogr2.notlar[1] = 88.5;
    
    Ogrenci ogr3 = ogrenciOlustur(1003, "Mehmet", "Demir", 2);
    ogr3.notlar[0] = 75.0;
    ogr3.notlar[1] = 82.5;
    
    Ogrenci ogr4 = ogrenciOlustur(1004, "Ayşe", "Can", 2);
    ogr4.notlar[0] = 95.0;
    ogr4.notlar[1] = 91.0;
    
    sinifaOgrenciEkle(sinif1, 0, ogr2);
    sinifaOgrenciEkle(sinif1, 1, ogr3);
    sinifaOgrenciEkle(sinif1, 2, ogr4);
    
    sinifGoster(sinif1);
    
    // 3. Bellek temizleme
    /*
     * Dinamik bellek kullandığımız için, programın sonunda bu belleği serbest bırakmalıyız.
     * Aksi halde bellek sızıntısı (memory leak) oluşur. Çünkü c++ hala eski bir dil.
     * 
     * Önce her bir öğrenci için ayrılan belleği, sonra sınıf için ayrılan belleği temizliyoruz.
     */
    cout << "\n3) Bellek temizleme:" << endl;
    
    cout << "   Öğrenci için ayrılan bellek temizleniyor..." << endl;
    ogrenciTemizle(ogr1);
    ogrenciTemizle(ogr2);
    ogrenciTemizle(ogr3);
    ogrenciTemizle(ogr4);
    
    cout << "   Sınıf için ayrılan bellek temizleniyor..." << endl;
    sinifTemizle(sinif1);
    
    cout << "   Tüm bellekler başarıyla temizlendi!" << endl;
    
    return 0;
}

// Dinamik bellek içeren öğrenci oluşturma
/*
 * Bu fonksiyon, Ogrenci struct'ı için bellek ayırma işlemlerini yapar:
 * 1. Ad için bellek ayırma ve kopyalama
 * 2. Soyad için bellek ayırma ve kopyalama
 * 3. Notlar için bellek ayırma
 * 
 * C++'ta string sınıfı otomatik bellek yönetimi sağlar, ancak bu örnekte
 * C tarzı karakter dizileri (char*) kullanarak dinamik bellek yönetimini görüyoruz.
 */
Ogrenci ogrenciOlustur(int numara, const char* ad, const char* soyad, int notSayisi) {
    Ogrenci yeniOgr;
    
    yeniOgr.numara = numara;
    
    // Ad için bellek ayırma ve kopyalama
    /*
     * strlen(ad) + 1: ad stringinin uzunluğu + null terminator ('\0') için 1 byte
     * new char[...]: Bu boyutta bellek ayırma
     * strcpy: Kaynak stringi hedef belleğe kopyalama
     */
    yeniOgr.ad = new char[strlen(ad) + 1];
    strcpy(yeniOgr.ad, ad);
    
    // Soyad için bellek ayırma ve kopyalama
    yeniOgr.soyad = new char[strlen(soyad) + 1];
    strcpy(yeniOgr.soyad, soyad);
    
    // Notlar için bellek ayırma
    /*
     * notSayisi kadar double değer için bellek ayırıyoruz.
     * Bu, dinamik bir dizi oluşturur.
     */
    yeniOgr.notSayisi = notSayisi;
    yeniOgr.notlar = new double[notSayisi];
    
    // Notları başlangıçta 0 olarak atama
    for (int i = 0; i < notSayisi; i++) {
        yeniOgr.notlar[i] = 0.0;
    }
    
    return yeniOgr;
}

// Öğrenci bilgilerini gösterme
/*
 * Bu fonksiyon, Ogrenci struct'ını referans olarak alır ve bilgilerini gösterir.
 * const referans kullanarak, fonksiyonun struct'ı değiştirmesini engelliyoruz.
 * Const, constant'ın kısaltmasıdır, sabit anlamına gelir.
 * 
 * Referans kullanarak, struct'ın kopyasını oluşturmaktan kaçınıyoruz,
 * bu da bellek ve zaman tasarrufu sağlıyor.
 */
void ogrenciGoster(const Ogrenci& ogr) {
    cout << "   Öğrenci Bilgileri:" << endl;
    cout << "   Numara: " << ogr.numara << endl;
    cout << "   Ad: " << ogr.ad << endl;
    cout << "   Soyad: " << ogr.soyad << endl;
    
    cout << "   Notlar: ";
    for (int i = 0; i < ogr.notSayisi; i++) {
        cout << ogr.notlar[i];
        if (i < ogr.notSayisi - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    
    // Not ortalaması hesaplama
    double toplam = 0.0;
    for (int i = 0; i < ogr.notSayisi; i++) {
        toplam += ogr.notlar[i];
    }
    double ortalama = toplam / ogr.notSayisi;
    
    cout << "   Not Ortalaması: " << ortalama << endl;
}

// Öğrenci için ayrılan belleği temizleme
/*
 * Bu fonksiyon, Ogrenci struct'ı için ayrılan dinamik belleği serbest bırakır.
 * 
 * Dinamik bellek içeren struct'ları kullanırken, belleği temizlemek çok önemlidir.
 * Aksi halde bellek sızıntısı oluşur ve program zamanla daha fazla bellek kullanır.
 * Modern diller bu işi otomatik yaparlar, ama c++ hala eski bir dil.
 * 
 * Belleği temizledikten sonra, pointer'ları nullptr olarak ayarlamak güvenli bir uygulamadır.
 * Bu, dangling pointer (askıda kalan pointer) sorunlarını önler.
 */
void ogrenciTemizle(Ogrenci& ogr) {
    delete[] ogr.ad;
    delete[] ogr.soyad;
    delete[] ogr.notlar;
    
    // Bellek temizlendikten sonra null pointer atama
    ogr.ad = nullptr;
    ogr.soyad = nullptr;
    ogr.notlar = nullptr;
    ogr.notSayisi = 0;
}

// Sınıf oluşturma
/*
 * Bu fonksiyon, Sinif struct'ı için bellek ayırma işlemlerini yapar.
 * Öğrenciler için dinamik bir dizi oluşturulur, ancak bu aşamada
 * öğrencilerin kendileri için bellek ayrılmaz.
 */
Sinif sinifOlustur(string sinifAdi, int ogrenciSayisi) {
    Sinif yeniSinif;
    
    yeniSinif.sinifAdi = sinifAdi;
    yeniSinif.ogrenciSayisi = ogrenciSayisi;
    
    // Öğrenciler için bellek ayırma
    /*
     * ogrenciSayisi kadar Ogrenci struct'ı için bellek ayırıyoruz.
     * Bu, Ogrenci struct'larından oluşan dinamik bir dizi oluşturur.
     */
    yeniSinif.ogrenciler = new Ogrenci[ogrenciSayisi];
    
    return yeniSinif;
}

// Sınıfa öğrenci ekleme (derin kopyalama)
/*
 * Bu fonksiyon, bir Ogrenci struct'ını Sinif struct'ındaki belirli bir indekse ekler.
 * 
 * Önemli nokta: Burada derin kopyalama (deep copy) yapılıyor.
 * Yani sadece değerleri kopyalamakla kalmıyor, dinamik bellek içeren üyeler için
 * yeni bellek ayrılıyor ve içerik kopyalanıyor.
 * 
 * Derin kopyalama, dinamik bellek içeren struct'lar için çok önemlidir.
 * Sığ kopyalama (shallow copy) yapılırsa, iki struct aynı bellek bölgesini
 * gösterir ve birindeki değişiklik diğerini de etkiler.
 */
void sinifaOgrenciEkle(Sinif& sinif, int index, const Ogrenci& ogr) {
    if (index >= 0 && index < sinif.ogrenciSayisi) {
        // Öğrenci bilgilerini kopyalama
        sinif.ogrenciler[index].numara = ogr.numara;
        
        // Ad için bellek ayırma ve kopyalama
        sinif.ogrenciler[index].ad = new char[strlen(ogr.ad) + 1];
        strcpy(sinif.ogrenciler[index].ad, ogr.ad);
        
        // Soyad için bellek ayırma ve kopyalama
        sinif.ogrenciler[index].soyad = new char[strlen(ogr.soyad) + 1];
        strcpy(sinif.ogrenciler[index].soyad, ogr.soyad);
        
        // Notlar için bellek ayırma ve kopyalama
        sinif.ogrenciler[index].notSayisi = ogr.notSayisi;
        sinif.ogrenciler[index].notlar = new double[ogr.notSayisi];
        
        for (int i = 0; i < ogr.notSayisi; i++) {
            sinif.ogrenciler[index].notlar[i] = ogr.notlar[i];
        }
    }
}

// Sınıf bilgilerini gösterme
/*
 * Bu fonksiyon, Sinif struct'ını referans olarak alır ve bilgilerini gösterir.
 * Sınıftaki her öğrenci için ogrenciGoster fonksiyonunu çağırır.
 */
void sinifGoster(const Sinif& sinif) {
    cout << "   Sınıf Adı: " << sinif.sinifAdi << endl;
    cout << "   Öğrenci Sayısı: " << sinif.ogrenciSayisi << endl;
    cout << "   Öğrenci Listesi:" << endl;
    
    for (int i = 0; i < sinif.ogrenciSayisi; i++) {
        cout << "\n   " << (i + 1) << ". ";
        ogrenciGoster(sinif.ogrenciler[i]);
    }
}

// Sınıf için ayrılan belleği temizleme
/*
 * Bu fonksiyon, Sinif struct'ı için ayrılan tüm dinamik belleği serbest bırakır.
 * 
 * İç içe dinamik bellek kullanımında, belleği temizleme sırası önemlidir:
 * 1. Önce en içteki dinamik bellek temizlenir (her öğrenci için ayrılan bellek)
 * 2. Sonra dıştaki dinamik bellek temizlenir (öğrenci dizisi için ayrılan bellek)
 * 
 * Bu sıralamayı tersine çevirirsek, içteki bellek bloklarına erişemez hale geliriz
 * ve bellek sızıntısı oluşur.
 */
void sinifTemizle(Sinif& sinif) {
    // Önce her öğrenci için ayrılan belleği temizle
    for (int i = 0; i < sinif.ogrenciSayisi; i++) {
        ogrenciTemizle(sinif.ogrenciler[i]);
    }
    
    // Sonra öğrenci dizisi için ayrılan belleği temizle
    delete[] sinif.ogrenciler;
    
    // Bellek temizlendikten sonra null pointer atama
    sinif.ogrenciler = nullptr;
    sinif.ogrenciSayisi = 0;
} 