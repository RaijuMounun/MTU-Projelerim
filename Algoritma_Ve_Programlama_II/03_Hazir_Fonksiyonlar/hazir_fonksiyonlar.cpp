/**
 * Algoritma ve Programlama 2 - Hazır Fonksiyonlar
 * Bu program C++ dilinde sık kullanılan hazır fonksiyonları gösterir.
 * 
 * Hazır fonksiyonlar, C++ dilinde önceden tanımlanmış ve kullanıma hazır olan
 * fonksiyonlardır. Bu fonksiyonlar, genel işlemleri kolayca gerçekleştirmemizi
 * sağlar ve tekerleği yeniden icat etmemize gerek kalmaz.
 */
#define _USE_MATH_DEFINES  // PI sabitini kullanabilmek için

#include <iostream>   // Giriş/çıkış işlemleri için
#include <cmath>      // Matematiksel işlemler için
#include <cstring>    // C-string işlemleri için
#include <string>     // C++ string sınıfı için
#include <cctype>     // Karakter işlemleri için
#include <ctime>      // Zaman işlemleri için
#include <cstdlib>    // Genel işlevler ve rastgele sayı üretimi için
#include <iomanip>    // Giriş/çıkış manipülasyonu için

using namespace std;

// Fonksiyon prototipleri
void matematikselFonksiyonlar();
void stringFonksiyonlari();
void karakterFonksiyonlari();
void zamanFonksiyonlari();
void rastgeleSayiUretimi();

int main() {
    cout << "===== HAZIR FONKSİYONLAR =====" << endl << endl;
    
    // 1. Matematiksel fonksiyonlar
    matematikselFonksiyonlar();
    
    // 2. String işlemleri
    stringFonksiyonlari();
    
    // 3. Karakter işlemleri
    karakterFonksiyonlari();
    
    // 4. Zaman fonksiyonları
    zamanFonksiyonlari();
    
    // 5. Rastgele sayı üretimi
    rastgeleSayiUretimi();
    
    return 0;
}

// Matematiksel fonksiyonlar
void matematikselFonksiyonlar() {
    cout << "1) Matematiksel Fonksiyonlar (cmath):" << endl;
    
    // Mutlak değer
    cout << "   abs(-5) = " << abs(-5) << endl; // abs, absolute kelimesinin kısaltmasıdır, o da mutlak demek.
    cout << "   fabs(-5.7) = " << fabs(-5.7) << endl; // fabs, float olan absolute demektir.
    
    // Üs alma
    // pow(sayi, kuvvet) şeklinde kullanılır, power yani kuvvet demektir.
    cout << "   pow(2, 3) = " << pow(2, 3) << endl;      // 2^3 = 8
    cout << "   pow(2.5, 2) = " << pow(2.5, 2) << endl;  // 2.5^2 = 6.25
    
    // Karekök
    // sqrt square root, yani kare kök demektir.
    cout << "   sqrt(16) = " << sqrt(16) << endl;      // 16'nın karekökü = 4
    cout << "   sqrt(2) = " << sqrt(2) << endl;        // 2'nin karekökü ≈ 1.414
    
    // Trigonometrik fonksiyonlar (açılar radyan cinsinden)
    cout << "   sin(PI/2) = " << sin(M_PI/2) << endl;   // sin(90°) = 1
    cout << "   cos(PI) = " << cos(M_PI) << endl;       // cos(180°) = -1
    cout << "   tan(PI/4) = " << tan(M_PI/4) << endl;   // tan(45°) = 1
    
    // Yuvarlama fonksiyonları
    // floor zemin, ceil de ceiling yani tavan'ın kısaltmasıdır.
    cout << "   floor(3.7) = " << floor(3.7) << endl;   // 3.7'yi aşağı yuvarla = 3
    cout << "   ceil(3.2) = " << ceil(3.2) << endl;     // 3.2'yi yukarı yuvarla = 4
    cout << "   round(3.5) = " << round(3.5) << endl;   // 3.5'i en yakın tam sayıya yuvarla = 4
    
    // Logaritmik fonksiyonlar
    cout << "   log(exp(1)) = " << log(exp(1)) << endl;  // e'nin logaritması = 1
    cout << "   log10(100) = " << log10(100) << endl;    // 100'ün 10 tabanında logaritması = 2
    
    cout << endl;
}

// String işlemleri
void stringFonksiyonlari() {
    cout << "2) String İşlemleri:" << endl;
    
    cout << "   a) C stili string işlemleri (cstring):" << endl;
    
    // C stili string (char dizisi) tanımlama
    char str1[20] = "Merhaba";
    char str2[20] = "Dünya";
    char str3[40];
    
    // strlen (string length): String uzunluğunu hesaplar
    cout << "   strlen(str1) = " << strlen(str1) << endl;
    
    // strcpy (string copy): Bir stringi başka bir stringe kopyalar
    strcpy(str3, str1);
    cout << "   strcpy sonrası str3 = " << str3 << endl;
    
    // strcat (string concatenate): İki stringi birleştirir
    strcat(str3, " ");
    strcat(str3, str2);
    cout << "   strcat sonrası str3 = " << str3 << endl;
    
    // strcmp (string compare): İki stringi karşılaştırır
    cout << "   strcmp(str1, str2) = " << strcmp(str1, str2) << endl;
    // Eğer str1 < str2 ise negatif, str1 > str2 ise pozitif, str1 == str2 ise 0 döner
    
    // strstr (string string): Bir string içinde başka bir stringi arar
    char samanlik[50] = "Algoritma ve Programlama dersi";
    char igne[20] = "Programlama";
    char *sonuc = strstr(samanlik, igne);
    
    if (sonuc)
        cout << "   '" << igne << "' stringi bulundu: " << sonuc << endl;
    else
        cout << "   '" << igne << "' stringi bulunamadı" << endl;
    
    cout << endl;
    
    cout << "   b) C++ string sınıfı işlemleri (string):" << endl;
    
    // C++ string oluşturma
    string s1 = "Algoritma";
    string s2 = "Programlama";
    
    // String uzunluğu
    cout << "   s1.length() = " << s1.length() << endl;
    cout << "   s1.size() = " << s1.size() << endl;
    
    // İki stringi birleştirme
    string s3 = s1 + " ve " + s2;
    cout << "   s1 + \" ve \" + s2 = " << s3 << endl;
    
    // Substring alma
    string s4 = s3.substr(0, 9);  // 0. indeksten başlayarak 9 karakter
    cout << "   s3.substr(0, 9) = " << s4 << endl;
    
    // Karakter erişimi
    cout << "   s1[2] = " << s1[2] << endl;
    
    // find: Belirli bir alt stringi arama
    size_t pozisyon = s3.find("ve");
    if (pozisyon != string::npos)
        cout << "   \"ve\" stringi " << pozisyon << ". indekste bulundu" << endl;
    else
        cout << "   \"ve\" stringi bulunamadı" << endl;
    
    // replace: Belirli bir kısmı değiştirme
    string s5 = s3;
    s5.replace(s5.find("ve"), 2, "VE");
    cout << "   s5.replace sonrası = " << s5 << endl;
    
    // insert: Belirli bir pozisyona ekleme
    string s6 = s1;
    s6.insert(0, "C++ ");
    cout << "   s6.insert sonrası = " << s6 << endl;
    
    // erase: Belirli bir kısmı silme
    string s7 = "C++ Programlama Dersi";
    s7.erase(0, 4);  // 0. indeksten başlayarak 4 karakter sil
    cout << "   s7.erase sonrası = " << s7 << endl;
    
    cout << endl;
}

// Karakter işlemleri
void karakterFonksiyonlari() {
    cout << "3) Karakter İşlemleri (cctype):" << endl;
    
    char c;
    
    // İncelenecek karakterler
    char karakterler[] = {'A', '5', 'z', ' ', '#', '\n'};
    
    for (int i = 0; i < sizeof(karakterler)/sizeof(char); i++) {
        c = karakterler[i];
        
        // Karakter yazdırma (özel karakterler için açıklama)
        if (c == ' ')
            cout << "   Karakter: '[SPACE]'" << endl;
        else if (c == '\n')
            cout << "   Karakter: '[NEWLINE]'" << endl;
        else
            cout << "   Karakter: '" << c << "'" << endl;
        
        // isalpha: Alfabetik karakter mi?
        cout << "      isalpha: " << (isalpha(c) ? "Evet" : "Hayır") << endl;
        
        // isdigit: Rakam mı?
        cout << "      isdigit: " << (isdigit(c) ? "Evet" : "Hayır") << endl;
        
        // isalnum: Alfanumerik karakter mi? (harf veya rakam)
        cout << "      isalnum: " << (isalnum(c) ? "Evet" : "Hayır") << endl;
        
        // islower: Küçük harf mi?
        cout << "      islower: " << (islower(c) ? "Evet" : "Hayır") << endl;
        
        // isupper: Büyük harf mi?
        cout << "      isupper: " << (isupper(c) ? "Evet" : "Hayır") << endl;
        
        // isspace: Boşluk karakteri mi?
        cout << "      isspace: " << (isspace(c) ? "Evet" : "Hayır") << endl;
        
        // ispunct: Noktalama işareti mi?
        cout << "      ispunct: " << (ispunct(c) ? "Evet" : "Hayır") << endl;
        
        // tolower/toupper: Küçük/büyük harfe çevirme (sadece harfler için)
        if (isalpha(c)) {
            cout << "      tolower: " << (char)tolower(c) << endl;
            cout << "      toupper: " << (char)toupper(c) << endl;
        }
        
        cout << endl;
    }
}

// Zaman fonksiyonları
void zamanFonksiyonlari() {
    cout << "4) Zaman Fonksiyonları (ctime):" << endl;
    
    // Geçerli zaman bilgisini al
    time_t simdi = time(0);
    cout << "   Geçerli zaman (saniye olarak): " << simdi << endl;
    
    // time_t'yi string'e çevirme
    char* dt = ctime(&simdi);
    cout << "   Yerel zaman: " << dt;
    
    // time_t'yi tm struct'ına çevirme
    tm *ltm = localtime(&simdi);
    
    // tm struct'ından bilgi alma
    cout << "   Yıl: " << 1900 + ltm->tm_year << endl;
    cout << "   Ay: " << 1 + ltm->tm_mon << endl;  // 0-11 arası değer döner
    cout << "   Gün: " << ltm->tm_mday << endl;
    cout << "   Saat: " << ltm->tm_hour << endl;
    cout << "   Dakika: " << ltm->tm_min << endl;
    cout << "   Saniye: " << ltm->tm_sec << endl;
    
    // Tarih ve saat formatını özelleştirme
    char buffer[80];
    strftime(buffer, 80, "Tarih ve Saat: %d/%m/%Y %H:%M:%S", ltm);
    cout << "   Özelleştirilmiş format: " << buffer << endl;
    
    // Program performansı ölçme (çalışma süresi)
    clock_t baslangic = clock();
    
    // Uzun süren bir operasyon simülasyonu
    for (long i = 0; i < 100000000; i++) {
        // Boş döngü
    }
    
    clock_t bitis = clock();
    double gecenSure = double(bitis - baslangic) / CLOCKS_PER_SEC;
    cout << "   Döngü çalışma süresi: " << gecenSure << " saniye" << endl;
    
    cout << endl;
}

// Rastgele sayı üretimi
void rastgeleSayiUretimi() {
    cout << "5) Rastgele Sayı Üretimi (cstdlib):" << endl;
    
    // Rastgele sayı üreteci için tohum (seed) değeri atama
    // Seed değeri değişirse, üretilen sayı dizisi de değişir
    // Konu ilginizi çekiyorsa procedural generation şeklinde araştırabilirsiniz,
    // benim bu konuda çok çalışmam yok, basit bir iki küçük projem var sadece,
    // o yüzden pek bilgili sayılmam procedural generation konusunda.
    srand(time(0));  // Geçerli zamanı seed olarak kullan
    
    cout << "   Rastgele sayılar (0-9 arası):" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "      " << rand() % 10 << endl;
    }
    
    cout << "   Belirli bir aralıkta rastgele sayılar (20-30 arası):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "      " << 20 + (rand() % 11) << endl;  // 20 ile 30 arası
    }
    
    // Rastgele ondalıklı sayı üretme
    cout << "   Rastgele ondalıklı sayılar (0-1 arası):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "      " << fixed << setprecision(6) << (double)rand() / RAND_MAX << endl;
    }
    
    cout << endl;
} 