/**
 * Algoritma ve Programlama 2 - Struct (Yapı) Temel Kullanımı
 * Bu program struct yapılarının temel kullanımını gösterir.
 * 
 * Struct (yapı), farklı veri tiplerini tek bir isim altında gruplandırmamızı sağlayan
 * bir veri yapısıdır. C++'ta class'ların atası olarak düşünülebilir. Struct'lar
 * sayesinde birbiriyle ilişkili verileri tek bir değişken altında toplayabiliriz.
 */

#include <iostream>
#include <string>
using namespace std;

// Basit bir struct tanımı
/*
 * Struct tanımı "struct" kelimesi ile başlar ve sonra adı verilir, değişken gibi.
 * Süslü parantezler içinde struct'ın üyeleri tanımlanır.
 * Struct'ın üyeleri farklı veri tiplerinde olabilir (int, string, double, vb.).
 */
struct Ogrenci {
    int numara;
    string ad;
    string soyad;
    double ortalama;
};

// İç içe struct tanımı
/*
 * Struct'lar iç içe kullanılabilir. Yani bir struct'ın üyesi başka bir struct olabilir.
 * Burada önce Adres struct'ını tanımlıyoruz, sonra bu struct'ı Personel struct'ında kullanıyoruz.
 */
struct Adres {
    string sokak;
    string sehir;
    string ulke;
    int postaKodu;
};

struct Personel {
    int sicilNo;
    string ad;
    string soyad;
    double maas;
    Adres evAdresi;  // İç içe struct kullanımı
};

// Fonksiyon prototipleri
void ogrenciGoster(Ogrenci ogr);
void ogrenciDegistir(Ogrenci* ogr);
Ogrenci yeniOgrenciOlustur(int numara, string ad, string soyad, double ortalama);
void personelGoster(Personel p);

int main() {
    cout << "===== STRUCT (YAPI) TEMEL KULLANIMI =====" << endl << endl;
    
    // 1. Struct değişken tanımlama ve erişim
    /*
     * Struct tipinde bir değişken tanımlamak normal değişken tanımlamaya benzer.
     * Struct_adı değişken_adı; şeklinde tanımlanır.
     * Struct üyelerine nokta (.) operatörü ile erişilir: değişken_adı.üye_adı
     */
    cout << "1) Struct değişken tanımlama ve erişim:" << endl;
    
    Ogrenci ogr1;
    ogr1.numara = 1001;
    ogr1.ad = "Ahmet";
    ogr1.soyad = "Yılmaz";
    ogr1.ortalama = 3.5;
    
    cout << "   Öğrenci Bilgileri:" << endl;
    cout << "   Numara: " << ogr1.numara << endl;
    cout << "   Ad: " << ogr1.ad << endl;
    cout << "   Soyad: " << ogr1.soyad << endl;
    cout << "   Ortalama: " << ogr1.ortalama << endl;
    
    // 2. Struct başlatma (Initialization)
    /*
     * Struct değişkenleri tanımlanırken başlangıç değerleri verilebilir.
     * Bu işlem süslü parantezler {} içinde, struct üyelerinin sırasına göre değerler yazılarak yapılır.
     * Bu yöntem, struct üyelerinin sırasını bilmeyi gerektirir ve karışıklığa yol açabilir.
     * Modern C++'ta üye adları belirtilerek de başlatma yapılabilir. Aşağıdaki örnekte üye 
     * adlarıyla başlattım. 
     * Başlatma kelimesi de yanlış anlaşılabilir, hazırlama gibi de düşünebilirsiniz.
     * Başlatma olarak çevirdiğim Initialization kelimesi, Türkçe tam karşılığı var mı bilmiyorum. 
     */
    cout << "\n2) Struct başlatma (Initialization):" << endl;
    
    Ogrenci ogr2 = {numara: 1002, ad: "Zeynep", soyad: "Kaya", ortalama: 3.8};
    cout << "   Öğrenci Bilgileri:" << endl;
    cout << "   Numara: " << ogr2.numara << endl;
    cout << "   Ad: " << ogr2.ad << endl;
    cout << "   Soyad: " << ogr2.soyad << endl;
    cout << "   Ortalama: " << ogr2.ortalama << endl;
    
    // 3. Struct dizisi
    /*
     * Struct'lardan oluşan diziler tanımlanabilir.
     * Bu diziler, her bir elemanı bir struct olan dizilerdir.
     * Dizi elemanlarına normal dizi gösterimi ile erişilir: dizi[indeks]
     * Dizi elemanlarının üyelerine ise nokta ile erişilir: dizi[indeks].üye_adı
     */
    cout << "\n3) Struct dizisi:" << endl;
    
    Ogrenci sinif[3] = {
        {1003, "Mehmet", "Demir", 2.8},
        {1004, "Ayşe", "Can", 3.2},
        {1005, "Ali", "Yıldız", 3.0}
    }; // 3 elemanlı öğrenci dizisi
    
    cout << "   Sınıf Listesi:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "   " << i+1 << ". Öğrenci: " 
             << sinif[i].numara << " - " 
             << sinif[i].ad << " " 
             << sinif[i].soyad << " - " 
             << sinif[i].ortalama << endl;
    } // Dizi olduğu için for döngüsü kullandık. Daha modern dillerde foreach döngüsü kullanıyoruz.
    
    // 4. Struct ve fonksiyonlar
    /*
     * Struct'lar fonksiyonlara parametre olarak geçirilebilir, fonksiyonlardan döndürülebilir.
     * Struct'ları fonksiyonlara geçirirken üç yöntem kullanılabilir:
     * 1. Değer ile geçirme: Struct'ın bir kopyası oluşturulur, fonksiyon içindeki değişiklikler
     *    orijinal struct'ı etkilemez. Gönderilen struct'ın bir değeri lazımsa kullanılabilir.
     * 2. Pointer ile geçirme: Struct'ın adresi geçirilir, fonksiyon içindeki değişiklikler
     *    orijinal struct'ı etkiler. Üyelere -> ile erişilir.
     * 3. Referans ile geçirme: Struct'ın referansı geçirilir, fonksiyon içindeki değişiklikler
     *    orijinal struct'ı etkiler. Üyelere . ile erişilir.
     */
    cout << "\n4) Struct ve fonksiyonlar:" << endl;
    
    cout << "   Fonksiyona struct geçirme:" << endl;
    ogrenciGoster(ogr1);
    
    cout << "\n   Pointer ile struct değiştirme:" << endl;
    cout << "   Değişiklik öncesi ortalama: " << ogr1.ortalama << endl;
    ogrenciDegistir(&ogr1);
    cout << "   Değişiklik sonrası ortalama: " << ogr1.ortalama << endl;
    
    cout << "\n   Fonksiyondan struct döndürme:" << endl;
    Ogrenci ogr3 = yeniOgrenciOlustur(1006, "Burak", "Solgun", 3.9);
    ogrenciGoster(ogr3);
    
    // 5. İç içe struct kullanımı
    /*
     * Bir struct'ın üyesi olarak başka bir struct kullanılabilir.
     * Bu durumda iç struct'ın üyelerine erişmek için iki nokta operatörü kullanılır:
     * dış_struct.iç_struct.üye_adı
     * 
     * Bu yapı, karmaşık veri yapıları oluşturmak için kullanılır. Örneğin, bir personelin
     * adres bilgilerini ayrı bir struct olarak tanımlayıp, personel struct'ı içinde kullanabiliriz.
     */
    cout << "\n5) İç içe struct kullanımı:" << endl;
    
    Personel per1;
    per1.sicilNo = 5001;
    per1.ad = "Mustafa";
    per1.soyad = "Öztürk";
    per1.maas = 15000.0;
    per1.evAdresi.sokak = "Atatürk Cad. No:123";
    per1.evAdresi.sehir = "İzmir";
    per1.evAdresi.ulke = "Türkiye";
    per1.evAdresi.postaKodu = 35000;
    
    personelGoster(per1);
    
    return 0;
}

// Struct'ı parametre olarak alan fonksiyon
/*
 * Bu fonksiyon, Ogrenci struct'ını değer olarak alır.
 * Yani fonksiyona çağrıldığında, orijinal struct'ın bir kopyası oluşturulur.
 * Fonksiyon içinde yapılan değişiklikler orijinal struct'ı etkilemez.
 */
void ogrenciGoster(Ogrenci ogr) {
    cout << "   Öğrenci Bilgileri:" << endl;
    cout << "   Numara: " << ogr.numara << endl;
    cout << "   Ad: " << ogr.ad << endl;
    cout << "   Soyad: " << ogr.soyad << endl;
    cout << "   Ortalama: " << ogr.ortalama << endl;
}

// Struct'ı pointer olarak alan ve değiştiren fonksiyon
/*
 * Bu fonksiyon, Ogrenci struct'ının bellekteki adresini alır.
 * Pointer üzerinden yapılan değişiklikler orijinal struct'ı etkiler.
 * Pointer üzerinden struct üyelerine erişmek için -> operatörü kullanılır.
 * ogr->ortalama ifadesi, (*ogr).ortalama ifadesinin göreceli olarak kısa yazımıdır.
 * İkisi de olur, hoca da kabul eder.
 */
void ogrenciDegistir(Ogrenci* ogr) {
    ogr->ortalama = 4.0;  // -> operatörü ile pointer üzerinden erişim
}

// Struct döndüren fonksiyon
/*
 * Fonksiyonlar struct tipinde değer döndürebilir.
 * Bu durumda, fonksiyon içinde oluşturulan struct'ın bir kopyası döndürülür.
 * Bu yöntem, yeni struct nesneleri oluşturmak için kullanışlı olabilir duruma göre.
 */
Ogrenci yeniOgrenciOlustur(int numara, string ad, string soyad, double ortalama) {
    Ogrenci yeniOgr;
    yeniOgr.numara = numara;
    yeniOgr.ad = ad;
    yeniOgr.soyad = soyad;
    yeniOgr.ortalama = ortalama;
    return yeniOgr;
}

// İç içe struct'ı gösteren fonksiyon
/*
 * Bu fonksiyon, Personel struct'ını değer olarak alır ve bilgilerini gösterir.
 * İç içe struct'ın üyelerine erişmek için nokta kullanılır:
 * p.evAdresi.sokak gibi.
 */
void personelGoster(Personel p) {
    cout << "   Personel Bilgileri:" << endl;
    cout << "   Sicil No: " << p.sicilNo << endl;
    cout << "   Ad: " << p.ad << endl;
    cout << "   Soyad: " << p.soyad << endl;
    cout << "   Maaş: " << p.maas << " TL" << endl;
    cout << "   Ev Adresi:" << endl;
    cout << "     Sokak: " << p.evAdresi.sokak << endl;
    cout << "     Şehir: " << p.evAdresi.sehir << endl;
    cout << "     Ülke: " << p.evAdresi.ulke << endl;
    cout << "     Posta Kodu: " << p.evAdresi.postaKodu << endl;
} 