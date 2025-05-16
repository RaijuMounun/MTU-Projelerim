/*
 * BAŞVURULAR (REFERENCES)
 * 
 * C++'da başvurular (references), bir değişkenin alternatif adı veya takma adı olarak düşünülebilir.
 * Başvurular, özellikle fonksiyonlara parametre geçirme ve bellek yönetiminde çok kullanışlıdır.
 * 
 * Bir başvuru, pointer (işaretçi) gibi adres tutar ancak kullanımı daha basittir ve bazı avantajları vardır:
 * 1. Başvurular başlatıldıktan sonra başka bir değişkene bağlanamaz
 * 2. Başvurular NULL olamaz
 * 3. Başvurular otomatik olarak dereference edilir (yıldız * operatörü gerekmez)
 */

#include <iostream>
using namespace std;

// Değer ile parametre geçirme (Call by Value)
void degerIleArttir(int sayi) {
    sayi += 10;
    cout << "Fonksiyon içinde değer: " << sayi << endl;
    // Fonksiyon bittiğinde, bu değişiklik kaybolur
}

// Pointer ile parametre geçirme (Call by Pointer)
void pointerIleArttir(int* sayi) {
    *sayi += 10;
    cout << "Fonksiyon içinde pointer değeri: " << *sayi << endl;
    // Değişiklik kalıcıdır
}

// Başvuru ile parametre geçirme (Call by Reference)
void referansIleArttir(int& sayi) {
    sayi += 10;
    cout << "Fonksiyon içinde referans değeri: " << sayi << endl;
    // Değişiklik kalıcıdır
}

// Sabit referans kullanımı - değişiklik yapılamaz
void sabitReferansGoster(const int& sayi) {
    // sayi += 10; // Hata! Sabit referans değiştirilemez
    cout << "Sabit referans değeri: " << sayi << endl;
}

// Döndürülen referans örneği
int& enBuyukElementiDondur(int dizi[], int boyut) {
    int enBuyukIndex = 0;
    for (int i = 1; i < boyut; i++) {
        if (dizi[i] > dizi[enBuyukIndex]) {
            enBuyukIndex = i;
        }
    }
    return dizi[enBuyukIndex];
}

int main() {
    // 1. Başvuru tanımlama
    int x = 10;
    int& ref_x = x; // x'e başvuru oluşturuldu
    
    cout << "x = " << x << endl;
    cout << "ref_x = " << ref_x << endl;
    
    // Başvuru değiştirildiğinde, orijinal değişken de değişir
    ref_x = 20;
    cout << "ref_x değiştirildikten sonra x = " << x << endl;
    
    // 2. Farklı parametre geçirme yöntemlerinin karşılaştırılması
    int a = 5;
    
    cout << "\n--- Değer ile parametre geçirme ---" << endl;
    cout << "Çağrıdan önce a = " << a << endl;
    degerIleArttir(a);
    cout << "Çağrıdan sonra a = " << a << endl; // Değişiklik olmaz (5)
    
    cout << "\n--- Pointer ile parametre geçirme ---" << endl;
    cout << "Çağrıdan önce a = " << a << endl;
    pointerIleArttir(&a);
    cout << "Çağrıdan sonra a = " << a << endl; // Değişiklik olur (15)
    
    cout << "\n--- Referans ile parametre geçirme ---" << endl;
    cout << "Çağrıdan önce a = " << a << endl;
    referansIleArttir(a);
    cout << "Çağrıdan sonra a = " << a << endl; // Değişiklik olur (25)
    
    // 3. Sabit referans kullanımı
    sabitReferansGoster(a);
    
    // 4. Referans döndüren fonksiyon
    int sayilar[] = {5, 8, 3, 12, 7};
    int boyut = sizeof(sayilar) / sizeof(sayilar[0]);
    
    cout << "\n--- Referans döndüren fonksiyon ---" << endl;
    cout << "Dizi: ";
    for (int i = 0; i < boyut; i++) {
        cout << sayilar[i] << " ";
    }
    cout << endl;
    
    // Döndürülen referans üzerinden değişiklik yapma
    enBuyukElementiDondur(sayilar, boyut) = 100;
    
    cout << "En büyük eleman değiştirildikten sonra dizi: ";
    for (int i = 0; i < boyut; i++) {
        cout << sayilar[i] << " ";
    }
    cout << endl;
    
    // 5. Başvuru ve pointer arasındaki temel farklar
    cout << "\n--- Referans ve Pointer Karşılaştırması ---" << endl;
    int y = 50;
    int& ref_y = y;
    int* ptr_y = &y;
    
    cout << "y = " << y << endl;
    cout << "ref_y = " << ref_y << endl;
    cout << "ptr_y içeriği = " << *ptr_y << endl;
    
    // Referanslar yeniden atanamaz
    int z = 100;
    // ref_y = z; // Bu, ref_y'nin gösterdiği değeri (y) değiştirir, referansı değil
    cout << "ref_y = z sonrası y = " << y << endl;
    
    // Pointerlar yeniden atanabilir
    ptr_y = &z;
    cout << "ptr_y = &z sonrası *ptr_y = " << *ptr_y << endl;
    cout << "y hala: " << y << endl;
    
    return 0;
} 