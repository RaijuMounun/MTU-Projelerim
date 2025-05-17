/**
 * Algoritma ve Programlama 2 - Pointer'lar (İşaretçiler) ve Fonksiyonlar
 * Bu program pointer'ların fonksiyonlarla kullanımını ve dinamik bellek yönetimini gösterir.
 */

#include <iostream>
using namespace std;

// Fonksiyon prototipleri
// Prototip tanımlamasına şu yüzden ihtiyaç duyuyoruz:
// Bir fonksiyonu çağırabilmek için, fonksiyonun önceden tanımlanmış olması gerekiyor.
// Bu örnkete bir class kullanmadığımız, ve fonksiyonu tanımlamadan önce çağırdığımız için
// prototip tanımlaması yapmamız gerekiyor.
// Prototip de aslında programa şunu diyor: "Ben bu fonksiyonu kullanacağım ama çağırdığım
// yerin altında tanımladım, aşağıda tanımını ara"
// Bir class kullanıyor olsaydık, class'ın içinde fonksiyonun nerede tanımlandığının
// bir önemi olmazdı ve istediğimiz yerde fonksiyonu çağırabilirdik, prototiplere ihtiyaç olmazdı.
void degerIleGecirme(int _sayi);
void pointerIleGecirme(int* sayi_ptr);
void referansIleGecirme(int& sayi_ref);
int* dinamikDiziOlustur(int boyut);
void diziYazdir(int* dizi, int boyut);
void diziSerbestBirak(int* dizi);
void cokBoyutluDiziOrnegi();

int main() {
    cout << "===== POINTER (İŞARETÇİ) VE FONKSİYONLAR =====" << endl << endl;
    
    // 1. Değer aktarımı karşılaştırma
    int sayi = 10;
    
    cout << "1) Değer aktarımı karşılaştırma:" << endl;
    cout << "   Orijinal değer: " << sayi << endl;
    
    degerIleGecirme(sayi);
    cout << "   Değer ile geçirdikten sonra: " << sayi << endl;
    
    pointerIleGecirme(&sayi);
    cout << "   Pointer ile geçirdikten sonra: " << sayi << endl;
    
    referansIleGecirme(sayi);
    cout << "   Referans ile geçirdikten sonra: " << sayi << endl;
    
    // 2. Dinamik bellek yönetimi
    cout << "\n2) Dinamik bellek yönetimi:" << endl;
    int boyut = 5;
    
    int* dinamikDizi = dinamikDiziOlustur(boyut);
    cout << "   Dinamik dizi oluşturuldu." << endl;
    
    cout << "   Dinamik dizi elemanları: ";
    diziYazdir(dinamikDizi, boyut);
    
    // Belleği serbest bırakma
    diziSerbestBirak(dinamikDizi);
    
    // 3. Çok boyutlu diziler ve pointerlar
    cout << "\n3) Çok boyutlu diziler ve pointerlar:" << endl;
    cokBoyutluDiziOrnegi();
    
    return 0;
}
// Main ayracı------------------------------------------------------------

// Fonksiyon içindeki değişiklik main'deki değişkeni etkilemez
// çünkü fonksiyon gönderilen değerin kopyasını alır.
void degerIleGecirme(int _sayi) {
    _sayi = 20;
    cout << "   Değer ile geçirme fonksiyonu içinde: " << _sayi << endl;
}

// Pointer ile geçirme - fonksiyon içindeki değişiklik main'deki değişkeni etkiler.
// Çünkü fonksiyon gönderilen pointer'ın kopyasını alır. Pointer'ın kopyası da orijinal
// pointer'la aynı değişkeni gösterdiği için, kopyasını da almış olsak değişkenin değerini
// değiştirebiliyoruz.
void pointerIleGecirme(int* sayi_ptr) {
    *sayi_ptr = 30;
    cout << "   Pointer ile geçirme fonksiyonu içinde: " << *sayi_ptr << endl;
}

// Referans ile geçirme - fonksiyon içindeki değişiklik main'deki değişkeni etkiler.
// Çünkü fonksiyon gönderilen referansın kopyasını alır. Referansın kopyası da orijinal
// referansla aynı değişkeni gösterdiği için, kopyasını da almış olsak değişkenin değerini
// değiştirebiliyoruz. int& yazarak değişkene referans vermiş oluruz. Değerini kopyalamak yerine,
// fonksiyona bu sefer direkt değişkenin kendisini gönderiyoruz.
void referansIleGecirme(int& sayi_ref) {
    sayi_ref = 40;
    cout << "   Referans ile geçirme fonksiyonu içinde: " << sayi_ref << endl;
}

// Dinamik bellek ayırma ve dizi oluşturma
int* dinamikDiziOlustur(int boyut) {
    // C++ eski bir dil olduğu için, ram'den elle alan ayırmamız gerekiyor.
    // new operatörü ile dinamik bellek ayırma, malloc da kullanılıyor.
    int* dizi = new int[boyut];
    
    // Diziyi oluşturuyoruz.
    for (int i = 0; i < boyut; i++) {
        dizi[i] = (i + 1) * 10;
    }
    
    return dizi; // Oluşturduğumuz diziyi fonksiyonun çağırıldığı yere döndürüyoruz.
}

// Dizi elemanlarını yazdırma
// Kendi kendini açıklıyordur zaten ama döngüleri unuttuysanız,
// dizinin elemanlarını yazdırmak için for döngüsü kullanıyoruz.
// Bu for döngüsü 0'dan başlayıp, fonksiyona parametre olarak gelen boyut sayısı kadar dönüyor.
// Dizi[i] ile dizinin i'inci elemanını yazdırıyoruz. i değeri 0'dan başlayıp
// for döngüsünün her bir dönüşünde 1 artıyor.
// Bu sayede dizinin tüm elemanlarını yazdırabiliyoruz.
void diziYazdir(int* dizi, int boyut) {
    for (int i = 0; i < boyut; i++) {
        cout << dizi[i] << " ";
    }
    cout << endl;
}

// Belleği serbest bırakma
void diziSerbestBirak(int* dizi) {
    delete[] dizi;
    cout << "   Dinamik dizi için ayrılan bellek serbest bırakıldı." << endl;
}


// Statik ve dinamik matrisler ders notlarında var mı bilmiyorum, yoksa muhtemelen sadece
// statik matrisler vardır, dinamik matris kısmını atlayabilirsiniz.
// Çok boyutlu dizi örneği
void cokBoyutluDiziOrnegi() {
    // Statik çok boyutlu dizi
    int matris[3][4] = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34}
    };
    
    cout << "   Statik 3x4 matris elemanları:" << endl;
    // Matris yazdırabilmek için, veya matris elemanlarıyla işlem yapabilmek için,
    // matrisin boyutu kadar döngü kullanmamız gerekiyor. Bu örnekte iki boyutlu bir matris var.
    // O yüzden iç içe iki for döngüsü kullanıyoruz. İlk for döngüsü matrisin satırlarını döner.
    // İkinci for döngüsü ile bulunduğumuz satırdaki değerleri geziyoruz.
    for (int i = 0; i < 3; i++) {
        cout << "   ";
        for (int j = 0; j < 4; j++) {
            cout << matris[i][j] << "\t";
            // Burada matris[i] değeri matirisin i'inci satırındaki sayıların bulunduğu bir dizi
            // olduğu için, o satırdaki değerlere de matris[i][j] şeklinde erişebiliyoruz.
        }
        cout << endl;
    }
    
    // Dinamik çok boyutlu dizi
    cout << "\n   Dinamik çok boyutlu dizi örneği:" << endl;
    
    // Satırlar için bellek ayırma
    /*
     * Dinamik çok boyutlu dizi oluşturmak için önce satırlar için bellek ayırıyoruz.
     * int** dinamikMatris = new int*[3]; satırı ile 3 adet int* tipinde pointer için
     * bellekte yer ayırıyoruz. Bu pointerlar, her bir satırı temsil edecek.
     * 
     * int** ifadesi "pointer'a pointer" anlamına gelir. Yani int* tipindeki değişkenlerin
     * adreslerini tutan bir pointer. Bu yapı, çok boyutlu dizileri dinamik olarak oluşturmak
     * için kullanılır.
     * 
     * Statik matris[3][4] yapısı bellekte tek bir blok olarak tutulurken,
     * dinamik matris yapısı iki aşamalı olarak oluşturulur:
     * 1. Önce satırlar için pointer dizisi oluşturulur (satır sayısı kadar)
     * 2. Sonra her satır için ayrı ayrı bellek bloğu ayrılır (sütun sayısı kadar)
     */
    int** dinamikMatris = new int*[3];
    
    // Her satır için sütun belleği ayırma
    /*
     * Şimdi her bir satır için ayrı ayrı bellek ayırıyoruz.
     * dinamikMatris[i] = new int[4]; satırı ile her bir satır için 4 sütunluk
     * int dizisi için bellek ayırıyoruz.
     * 
     * Bu yapı, her satırın farklı uzunlukta olmasına da imkan tanır (düzensiz matris).
     * Örneğin;
     * dinamikMatris[0] = new int[4]; 
     * dinamikMatris[1] = new int[6];
     * gibi farklı boyutlarda satırlar oluşturabiliriz.
     * 
     * Aşağıdaki döngüde her satır için bellek ayırdıktan sonra, o satırın
     * elemanlarını dolduruyoruz. (i+1)*10+j+1 formülü ile her hücreye
     * benzersiz bir değer atıyoruz.
     */
    for (int i = 0; i < 3; i++) {
        dinamikMatris[i] = new int[4]; // Satır için 4 sütunluk bellek ayırdık.
        
        // Ayırdığımız belleğe değer atıyoruz.
        for (int j = 0; j < 4; j++) {
            dinamikMatris[i][j] = (i + 1) * 10 + j + 1;
        }
    }
    
    // Dinamik matrisi yazdırma
    /*
     * Dinamik matrisi yazdırmak için de statik matriste olduğu gibi
     * iç içe iki for döngüsü kullanıyoruz. Erişim şekli de aynı:
     * dinamikMatris[i][j] şeklinde i. satır, j. sütundaki elemana erişiyoruz.
     * 
     * Dinamik matrisin bellekteki yapısı statik matristen farklıdır.
     * Statik matrisin değerleri bellekte art arda tutulurken,
     * dinamik matris farklı bellek bölgelerinde tutulur ve pointer'lar ile bağlanır.
     */
    cout << "   Dinamik 3x4 matris elemanları:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "   "; 
        for (int j = 0; j < 4; j++) {
            cout << dinamikMatris[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Belleği serbest bırakma - önce sütunlar, sonra satırlar
    /*
     * Dinamik olarak ayrılan belleği kullandıktan sonra mutlaka serbest bırakmalıyız.
     * Aksi halde bellek sızıntısı (memory leak) oluşur.
     * Çünkü c++ eski ve kötü syntax'lı bir dil. Niye hala ilk defa yazılım öğrenen öğrencilere
     * c++ öğretmekte diretiyorlar bilmiyorum.
     * 
     * Çok boyutlu dinamik dizilerde belleği serbest bırakırken sıra önemli:
     * 1. Önce her bir satır için ayrılan belleği serbest bırakıyoruz (delete[] dinamikMatris[i])
     * 2. Sonra satırlar için ayrılan belleği serbest bırakıyoruz (delete[] dinamikMatris)
     * 
     * Bu sıralamayı tersine çevirirsek, önce satırlar için ayrılan belleği serbest bırakırsak,
     * satırların içindeki bellek bloklarına erişemez hale geliriz ve bellek sızıntısı oluşur.
     * Çünkü o satırların içindeki pointer'lara erişimi kaybederiz.
     * 
     * new[] ile bellek ayırdık, delete[] ile serbest bırakıyoruz.
     * new ile bellek ayırsaydık, delete ile serbest bırakacaktık.
     */
    for (int i = 0; i < 3; i++) {
        delete[] dinamikMatris[i];
    }
    delete[] dinamikMatris;
    
    cout << "   Dinamik matris için ayrılan bellek serbest bırakıldı." << endl;
} 