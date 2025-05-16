/**
 * Algoritma ve Programlama 2 - Pointer (İşaretçi) Temel Kavramlar
 * 
 * Pointer bellekteki bir adresi tutan değişkenlerdir. Oluşturduğumuz her bir değişken
 * bellekte (ram'de) bir adres tutar. Bu değişkenler ram'in belirli bir bölgesine yerleştirilirler.
 * Pointer'lar, belirlediğimiz değişkenlerin ram'deki adreslerini tutar. 
 */

#include <iostream>
using namespace std;

int main() {
    cout << "===== POINTER TEMEL KAVRAMLAR =====" << endl << endl; //Çıktı temiz görünsün diye başlık
    
    // Değişken tanımlama
    int sayi = 42;
    
    /*
        -Pointer tanımlaması bu şekilde yapılıyor.
        -Türün başındaki * ile pointer olduğunu belirtiyoruz.
        -& işareti ile de belirlediğimiz değişkenin adresini alıyoruz.
        Yani &sayi kısmı sayi değişkeninin değerini değil, ram'deki adresini alır.
        -tür* pointer_adı = &adresi_alınacak_değişken;
        -12. satırda int* ptr = &sayi; şeklinde tanımladık, burada da sayi değişkeninin
        adresini aldık ve ptr adlı pointer'a atadık.
    */
    int* ptr = &sayi;
    
    cout << "1) Temel pointer gösterimi:" << endl; //Çıktıda başlık
    cout << "   sayi değişkeninin değeri: " << sayi << endl;
    cout << "   sayi değişkeninin adresi (&sayi): " << &sayi << endl;
    cout << "   ptr pointer'ının değeri (sayi'nin adresi): " << ptr << endl;
    cout << "   ptr pointer'ının gösterdiği değer (*ptr): " << *ptr << endl;
    
    /*
        -Burada ptr pointer'ının tuttuğu adresteki değişkenin değerini değiştiriyoruz.
        -Bu örneğimizde ptr pointer'ı sayi değişkenini gösteriyor, dolayısıyla aslında 
            sayi değişkeninin değerini değiştiriyoruz.
        -ptr pointer'ının tuttuğu adreste bulunan değişkene *ptr şeklinde erişebiliriz.
        -sadece ptr yazarsak pointer'ın kendisinin adresini görürüz.
        -*ptr = 100; şeklinde pointer'ın gösterdiği değişkenin değerini değiştirebiliriz.
        -Yani *ptr yazarak aslında ptr pointer'ının gösterdiği değişkene erişiyoruz.
    */
    cout << "\n2) Pointer üzerinden değer değiştirme:" << endl;
    cout << "   sayi değişkeninin mevcut değeri: " << sayi << endl;
    *ptr = 100;
    cout << "   sayi değişkeninin atama sonrası değeri: " << sayi << endl;
    cout << "   ptr pointer'ının gösterdiği yeni değer (*ptr): " << *ptr << endl;
    
    // Pointer aritmetiği
    int sayilar[5] = {10, 20, 30, 40, 50};
    int* sayilarPtr = sayilar; //Pointer'lar dizileri gösterebilirler.
    
    cout << "\n4) Pointer aritmetiği:" << endl;
    cout << "   Dizi elemanları: ";
    for (int i = 0; i < 5; i++) {
        cout << sayilar[i] << " ";
    }
    cout << endl;
    
    cout << "   sayilarPtr[0]: " << sayilarPtr[0] << endl;
    cout << "   sayilarPtr[1]: " << sayilarPtr[1] << endl;
    cout << "   *sayilarPtr: " << *sayilarPtr << endl;
    cout << "   *(sayilarPtr + 1): " << *(sayilarPtr + 1) << endl;
    cout << "   *(sayilarPtr + 2): " << *(sayilarPtr + 2) << endl;
    
    // Pointer aritmetiği ile dizi gezinme
    cout << "\n5) Pointer aritmetiği ile dizi gezinme:" << endl;
    for (int* p = sayilar; p < sayilar + 5; p++) {
        //burada p pointer'ı sayilar dizisinin başından başlayarak 5 eleman kadar ilerliyor.
        cout << "   Adres: " << p << ", Değer: " << *p << endl;
    }
    
    // Pointer ve fonksiyonlar
    cout << "\n6) Pointerlar ve değişken boyutları:" << endl;
    cout << "   int boyutu: " << sizeof(int) << " byte" << endl;
    cout << "   int* boyutu: " << sizeof(int*) << " byte" << endl;
    cout << "   double boyutu: " << sizeof(double) << " byte" << endl;
    cout << "   double* boyutu: " << sizeof(double*) << " byte" << endl;
    
    return 0;
} 