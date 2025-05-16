/*
 * FONKSİYONLARIN AŞIRI YÜKLENMESİ (FUNCTION OVERLOADING)
 * 
 * C++'da aşırı yükleme, aynı isme sahip birden fazla fonksiyon oluşturabilme özelliğidir.
 * Bu fonksiyonlar parametre sayısı veya parametre türleri bakımından farklılık göstermelidir.
 * 
 * Fonksiyon aşırı yükleme, kodun okunabilirliğini artırır ve farklı veri tipleriyle çalışan
 * benzer işlevlere aynı ismi vererek programcının işini kolaylaştırır.
 * 
 * Not: Yalnızca dönüş tipi farklı olan fonksiyonlar aşırı yüklenemez.
 */

#include <iostream>
#include <string>
using namespace std;

// 1. Temel fonksiyon aşırı yükleme örnekleri
// 1.1. Parametresiz fonksiyon
void yazdir() {
    cout << "Parametre almayan yazdir() fonksiyonu çağrıldı." << endl;
}

// 1.2. Integer parametre alan fonksiyon
void yazdir(int sayi) {
    cout << "Int parametre alan yazdir() fonksiyonu çağrıldı: " << sayi << endl;
}

// 1.3. Double parametre alan fonksiyon
void yazdir(double sayi) {
    cout << "Double parametre alan yazdir() fonksiyonu çağrıldı: " << sayi << endl;
}

// 1.4. String parametre alan fonksiyon
void yazdir(string metin) {
    cout << "String parametre alan yazdir() fonksiyonu çağrıldı: " << metin << endl;
}

// 1.5. Birden fazla parametre alan fonksiyon
void yazdir(int sayi1, int sayi2) {
    cout << "İki int parametre alan yazdir() fonksiyonu çağrıldı: " 
         << sayi1 << " ve " << sayi2 << endl;
}

// 1.6. Karışık parametreli fonksiyon
void yazdir(string ad, int yas) {
    cout << "String ve int parametre alan yazdir() fonksiyonu çağrıldı: " 
         << ad << ", " << yas << " yaşında" << endl;
}

// 2. Varsayılan parametre ve aşırı yükleme birlikte kullanımı
void mesaj(string ad, string mesaj = "Merhaba") {
    cout << mesaj << ", " << ad << "!" << endl;
}

// 3. Farklı türlerde işlem yapan bir fonksiyon ailesi
int topla(int a, int b) {
    cout << "Integer toplama işlemi" << endl;
    return a + b;
}

double topla(double a, double b) {
    cout << "Double toplama işlemi" << endl;
    return a + b;
}

string topla(string a, string b) {
    cout << "String birleştirme işlemi" << endl;
    return a + b;
}

// 4. Referans kullanımı ile aşırı yükleme
void degistir(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Int değişkenler değiştirildi" << endl;
}

void degistir(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
    cout << "Double değişkenler değiştirildi" << endl;
}

// 5. Const parametreli aşırı yükleme
void bilgiGoster(int* ptr) {
    cout << "Değiştirilebilir pointer: " << *ptr << endl;
    (*ptr)++; // Değeri değiştirebiliriz
}

void bilgiGoster(const int* ptr) {
    cout << "Değiştirilemez pointer (const): " << *ptr << endl;
    // (*ptr)++; // Hata! Const değer değiştirilemez
}

// 6. Sınıf ile aşırı yükleme örneği
class Matematik {
public:
    // Statik metotlarda aşırı yükleme
    static int kare(int x) {
        return x * x;
    }
    
    static double kare(double x) {
        return x * x;
    }
    
    // Üye metotlarda aşırı yükleme
    int carp(int a, int b) {
        return a * b;
    }
    
    double carp(double a, double b) {
        return a * b;
    }
    
    int carp(int a, int b, int c) {
        return a * b * c;
    }
};

int main() {
    cout << "=== FONKSİYON AŞIRI YÜKLEME ÖRNEKLERİ ===" << endl;
    
    // 1. Temel fonksiyon aşırı yükleme çağrıları
    cout << "\n--- Temel fonksiyon aşırı yükleme ---" << endl;
    yazdir();
    yazdir(42);
    yazdir(3.14);
    yazdir("C++ Programlama");
    yazdir(10, 20);
    yazdir("Ali", 25);
    
    // 2. Varsayılan parametre ile kullanım
    cout << "\n--- Varsayılan parametre ---" << endl;
    mesaj("Ayşe");
    mesaj("Mehmet", "İyi günler");
    
    // 3. Farklı türlerde işlem yapan fonksiyonlar
    cout << "\n--- Farklı türlerde işlemler ---" << endl;
    cout << "10 + 20 = " << topla(10, 20) << endl;
    cout << "3.5 + 2.7 = " << topla(3.5, 2.7) << endl;
    cout << "\"Merhaba\" + \" Dünya\" = " << topla("Merhaba", " Dünya") << endl;
    
    // 4. Referans ile aşırı yükleme
    cout << "\n--- Referans ile aşırı yükleme ---" << endl;
    int sayi1 = 10, sayi2 = 20;
    double ondalik1 = 3.5, ondalik2 = 7.5;
    
    cout << "Önce: sayi1 = " << sayi1 << ", sayi2 = " << sayi2 << endl;
    degistir(sayi1, sayi2);
    cout << "Sonra: sayi1 = " << sayi1 << ", sayi2 = " << sayi2 << endl;
    
    cout << "Önce: ondalik1 = " << ondalik1 << ", ondalik2 = " << ondalik2 << endl;
    degistir(ondalik1, ondalik2);
    cout << "Sonra: ondalik1 = " << ondalik1 << ", ondalik2 = " << ondalik2 << endl;
    
    // 5. Const parametreleri ile aşırı yükleme
    cout << "\n--- Const parametreli aşırı yükleme ---" << endl;
    int deger = 5;
    const int sabitDeger = 10;
    
    bilgiGoster(&deger);
    cout << "deger şimdi: " << deger << endl; // 6 olmalı
    
    bilgiGoster(&sabitDeger); // const int* versiyonu çağrılır
    // Ayrıca normal pointer'ı const pointer fonksiyonuna da geçirebiliriz
    bilgiGoster(&deger); // Burada da const int* versiyonu çağrılabilir
    
    // 6. Sınıf içinde aşırı yükleme
    cout << "\n--- Sınıf içinde aşırı yükleme ---" << endl;
    Matematik mat;
    
    // Statik metotların çağrılması
    cout << "5'in karesi: " << Matematik::kare(5) << endl;
    cout << "2.5'in karesi: " << Matematik::kare(2.5) << endl;
    
    // Üye metotların çağrılması
    cout << "4 * 6 = " << mat.carp(4, 6) << endl;
    cout << "2.5 * 3.0 = " << mat.carp(2.5, 3.0) << endl;
    cout << "2 * 3 * 4 = " << mat.carp(2, 3, 4) << endl;
    
    return 0;
} 