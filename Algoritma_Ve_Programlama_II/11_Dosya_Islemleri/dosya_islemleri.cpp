/*
 * DOSYA İŞLEMLERİ (FILE OPERATIONS)
 * 
 * C++'da dosya işlemleri, <fstream> başlık dosyası içindeki sınıflar kullanılarak yapılır.
 * Temel dosya işlemi sınıfları:
 * 
 * 1. ifstream: Dosyadan okuma işlemleri için kullanılır (input file stream)
 * 2. ofstream: Dosyaya yazma işlemleri için kullanılır (output file stream)
 * 3. fstream: Hem okuma hem yazma işlemleri için kullanılır
 * 
 * Dosya açma modları:
 * - ios::in     -> Okuma modu
 * - ios::out    -> Yazma modu (dosya yoksa oluşturulur, varsa içeriği silinir)
 * - ios::app    -> Ekleme modu (dosyanın sonuna ekleme yapar)
 * - ios::ate    -> Dosya açıldığında imleç dosyanın sonuna konumlanır
 * - ios::trunc  -> Dosya açıldığında içeriği silinir (varsayılan)
 * - ios::binary -> İkili (binary) modda dosya açar
 * 
 * Not: Modlar birleştirilebilir, örneğin: ios::out | ios::binary
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> // Biçimlendirme için
using namespace std;

// Metin dosyasına yazma örneği
void metinDosyasinaYaz() {
    cout << "\n--- Metin Dosyasına Yazma ---" << endl;
    
    // 1. ofstream ile dosya açma
    ofstream dosyaYaz("metin_dosyasi.txt");
    
    // Dosya açılıp açılmadığını kontrol etme
    if (!dosyaYaz) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }
    
    // 2. Dosyaya yazma
    dosyaYaz << "Bu bir metin dosyasına yazma örneğidir." << endl;
    dosyaYaz << "C++ programlama dili ile dosya işlemleri." << endl;
    dosyaYaz << "Sayılar: " << 42 << " " << 3.14 << endl;
    
    // 3. Dosyayı kapatma
    dosyaYaz.close();
    cout << "metin_dosyasi.txt dosyasına yazma işlemi tamamlandı." << endl;
}

// Metin dosyasından okuma örneği
void metinDosyasindanOku() {
    cout << "\n--- Metin Dosyasından Okuma ---" << endl;
    
    // 1. ifstream ile dosya açma
    ifstream dosyaOku("metin_dosyasi.txt");
    
    // Dosya açılıp açılmadığını kontrol etme
    if (!dosyaOku) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }
    
    // 2. Dosyadan satır satır okuma
    string satir;
    cout << "Dosya içeriği:" << endl;
    cout << "------------------------" << endl;
    
    while (getline(dosyaOku, satir)) {
        cout << satir << endl;
    }
    cout << "------------------------" << endl;
    
    // 3. Dosyayı kapatma
    dosyaOku.close();
}

// Dosyaya ekleme yapma örneği
void dosyayaEkle() {
    cout << "\n--- Dosyaya Ekleme Yapma ---" << endl;
    
    // 1. ofstream ile ekleme modunda dosya açma
    ofstream dosyaEkle("metin_dosyasi.txt", ios::app);
    
    if (!dosyaEkle) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }
    
    // 2. Dosyaya ekleme yapma
    dosyaEkle << "\nBu satır dosyaya sonradan eklenmiştir." << endl;
    dosyaEkle << "Tarih: " << __DATE__ << " " << __TIME__ << endl;
    
    // 3. Dosyayı kapatma
    dosyaEkle.close();
    cout << "metin_dosyasi.txt dosyasına ekleme işlemi tamamlandı." << endl;
}

// Farklı okuma yöntemleri
void farkliOkumaYontemleri() {
    cout << "\n--- Farklı Okuma Yöntemleri ---" << endl;
    
    // 1. fstream ile hem okuma hem yazma modunda dosya açma
    fstream dosya("okuma_ornegi.txt", ios::out);
    
    // Örnek veri yazma
    dosya << "10 20 30" << endl;
    dosya << "C++ Programlama" << endl;
    dosya << "3.14 2.71 1.62" << endl;
    dosya.close();
    
    // 2. Dosyayı okuma modunda tekrar açma
    dosya.open("okuma_ornegi.txt", ios::in);
    
    if (!dosya) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }
    
    // 3. Kelime kelime okuma
    cout << "Kelime kelime okuma:" << endl;
    string kelime;
    
    // İlk satırı kelime kelime okuma
    while (dosya >> kelime) {
        cout << kelime << " ";
        if (dosya.peek() == '\n') {
            break;
        }
    }
    cout << endl;
    
    // Satır sonunu atla
    dosya.ignore();
    
    // 4. Bir satırı tamamen okuma
    string tamSatir;
    getline(dosya, tamSatir);
    cout << "Tam satır: " << tamSatir << endl;
    
    // 5. Farklı veri tiplerini okuma
    double d1, d2, d3;
    dosya >> d1 >> d2 >> d3;
    cout << "Sayılar: " << d1 << ", " << d2 << ", " << d3 << endl;
    
    dosya.close();
}

// İkili (binary) dosya işlemleri
void ikiliDosyaIslemleri() {
    cout << "\n--- İkili (Binary) Dosya İşlemleri ---" << endl;
    
    // 1. Yapı tanımlama
    struct Ogrenci {
        int numara;
        char ad[50];
        char soyad[50];
        double notOrtalamasi;
    };
    
    // 2. Örnek veriler oluşturma
    vector<Ogrenci> ogrenciler = {
        {1001, "Ali", "Yılmaz", 85.5},
        {1002, "Ayşe", "Demir", 92.0},
        {1003, "Mehmet", "Kaya", 78.7}
    };
    
    // 3. Binary modda dosyaya yazma
    ofstream yazBin("ogrenciler.bin", ios::binary);
    
    if (!yazBin) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }
    
    // Her öğrenci kaydını binary olarak yazma
    for (const Ogrenci& ogr : ogrenciler) {
        yazBin.write(reinterpret_cast<const char*>(&ogr), sizeof(Ogrenci));
    }
    
    yazBin.close();
    cout << "Öğrenci verileri binary dosyaya yazıldı." << endl;
    
    // 4. Binary dosyadan okuma
    ifstream okuBin("ogrenciler.bin", ios::binary);
    
    if (!okuBin) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }
    
    // Dosyadan okunan verileri saklamak için dizi
    vector<Ogrenci> okunanOgrenciler;
    Ogrenci okunanOgr;
    
    // Dosya sonuna kadar okuma
    while (okuBin.read(reinterpret_cast<char*>(&okunanOgr), sizeof(Ogrenci))) {
        okunanOgrenciler.push_back(okunanOgr);
    }
    
    okuBin.close();
    
    // 5. Okunan verileri gösterme
    cout << "\nBinary dosyadan okunan öğrenci bilgileri:" << endl;
    cout << left << setw(10) << "Numara" << setw(15) << "Ad" << setw(15) << "Soyad" << "Not Ort." << endl;
    cout << string(50, '-') << endl;
    
    for (const Ogrenci& ogr : okunanOgrenciler) {
        cout << left << setw(10) << ogr.numara 
             << setw(15) << ogr.ad 
             << setw(15) << ogr.soyad 
             << fixed << setprecision(1) << ogr.notOrtalamasi << endl;
    }
}

// Rastgele erişimli dosya işlemleri
void rastgeleErisim() {
    cout << "\n--- Rastgele Erişimli Dosya İşlemleri ---" << endl;
    
    // 1. Dosyayı yazma modunda açma
    fstream dosya("rastgele_erisim.dat", ios::out | ios::binary);
    
    // Örnek veriler
    int sayilar[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(sayilar) / sizeof(sayilar[0]);
    
    // Dosyaya yazma
    for (int i = 0; i < n; i++) {
        dosya.write(reinterpret_cast<char*>(&sayilar[i]), sizeof(int));
    }
    
    dosya.close();
    
    // 2. Dosyayı okuma ve yazma modunda açma
    dosya.open("rastgele_erisim.dat", ios::in | ios::out | ios::binary);
    
    if (!dosya) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }
    
    // 3. Belirli bir konuma erişim (örneğin 5. eleman - indeks 4)
    int indeks = 4;
    dosya.seekg(indeks * sizeof(int), ios::beg); // okuma konumunu ayarla
    
    int okunanSayi;
    dosya.read(reinterpret_cast<char*>(&okunanSayi), sizeof(int));
    
    cout << "5. eleman: " << okunanSayi << endl;
    
    // 4. Belirli bir konuma yazma (3. elemana yeni değer)
    indeks = 2;
    int yeniDeger = 333;
    
    dosya.seekp(indeks * sizeof(int), ios::beg); // yazma konumunu ayarla
    dosya.write(reinterpret_cast<char*>(&yeniDeger), sizeof(int));
    
    // 5. Dosyanın tamamını okuma ve gösterme
    dosya.seekg(0, ios::beg); // başa dön
    
    cout << "Dosya içeriği: ";
    for (int i = 0; i < n; i++) {
        dosya.read(reinterpret_cast<char*>(&okunanSayi), sizeof(int));
        cout << okunanSayi << " ";
    }
    cout << endl;
    
    dosya.close();
}

// Dosya durumu işlemleri
void dosyaDurumuIslemleri() {
    cout << "\n--- Dosya Durumu İşlemleri ---" << endl;
    
    // 1. Dosya açma
    fstream dosya("durum_dosyasi.txt", ios::out);
    
    // Örnek veri yazma
    dosya << "Satır 1" << endl;
    dosya << "Satır 2" << endl;
    dosya << "Satır 3" << endl;
    
    // Dosya konumunu gösterme
    cout << "Yazma sonrası konum: " << dosya.tellp() << endl;
    
    dosya.close();
    
    // 2. Dosyayı okuma modunda açma
    dosya.open("durum_dosyasi.txt", ios::in);
    
    if (!dosya) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }
    
    // 3. Hata bayraklarını kontrol etme
    string satir;
    
    while (getline(dosya, satir)) {
        cout << "Okunan: " << satir << endl;
        cout << "  Okuma konumu: " << dosya.tellg() << endl;
        
        // Durum bayraklarını kontrol etme
        cout << "  EOF: " << dosya.eof() << endl;
        cout << "  Fail: " << dosya.fail() << endl;
        cout << "  Bad: " << dosya.bad() << endl;
        cout << "  Good: " << dosya.good() << endl;
    }
    
    // Dosya sonuna ulaştıktan sonra
    cout << "Dosya sonuna ulaşıldı" << endl;
    cout << "  EOF: " << dosya.eof() << endl;
    
    // Bayrakları temizleme ve başa dönme
    dosya.clear(); // Hata bayraklarını temizle
    dosya.seekg(0, ios::beg); // Başa dön
    
    // Tekrar bayrakları kontrol etme
    cout << "Bayraklar temizlendikten sonra:" << endl;
    cout << "  EOF: " << dosya.eof() << endl;
    cout << "  Good: " << dosya.good() << endl;
    
    dosya.close();
}

// Dosya var mı kontrolü
bool dosyaVarMi(const string& dosyaAdi) {
    ifstream dosya(dosyaAdi);
    return dosya.good();
}

int main() {
    cout << "=== DOSYA İŞLEMLERİ ÖRNEKLERİ ===" << endl;
    
    // 1. Metin dosyasına yazma
    metinDosyasinaYaz();
    
    // 2. Metin dosyasından okuma
    metinDosyasindanOku();
    
    // 3. Dosyaya ekleme yapma
    dosyayaEkle();
    
    // 4. Ekleme sonrası dosya içeriğini okuma
    metinDosyasindanOku();
    
    // 5. Farklı okuma yöntemleri
    farkliOkumaYontemleri();
    
    // 6. İkili (binary) dosya işlemleri
    ikiliDosyaIslemleri();
    
    // 7. Rastgele erişim
    rastgeleErisim();
    
    // 8. Dosya durumu işlemleri
    dosyaDurumuIslemleri();
    
    // 9. Dosya var mı kontrolü
    cout << "\n--- Dosya Kontrolü ---" << endl;
    cout << "metin_dosyasi.txt var mı? " << (dosyaVarMi("metin_dosyasi.txt") ? "Evet" : "Hayır") << endl;
    cout << "olmayan_dosya.txt var mı? " << (dosyaVarMi("olmayan_dosya.txt") ? "Evet" : "Hayır") << endl;
    
    // 10. Program sonunda geçici dosyaları silme
    cout << "\nGeçici dosyalar siliniyor..." << endl;
    remove("metin_dosyasi.txt");
    remove("okuma_ornegi.txt");
    remove("ogrenciler.bin");
    remove("rastgele_erisim.dat");
    remove("durum_dosyasi.txt");
    
    return 0;
} 