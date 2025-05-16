/**
 * Algoritma ve Programlama 2 - Hazır Fonksiyonlar (Uygulamalar)
 * Bu program C++ dilinde hazır fonksiyonların pratik uygulamalarını gösterir.
 */

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// Fonksiyon prototipleri
void sifreOlusturucu();
void metinIstatistikleri();
void hesapMakinesi();
void sayiTahminOyunu();

int main() {
    cout << "===== HAZIR FONKSİYONLAR UYGULAMALAR =====" << endl << endl;
    
    int secim;
    bool devam = true;
    
    while (devam) {
        cout << "Uygulamayı seçin:" << endl;
        cout << "1. Şifre Oluşturucu" << endl;
        cout << "2. Metin İstatistikleri" << endl;
        cout << "3. Hesap Makinesi" << endl;
        cout << "4. Sayı Tahmin Oyunu" << endl;
        cout << "0. Çıkış" << endl;
        cout << "Seçiminiz: ";
        cin >> secim;
        
        switch (secim) {
            case 1:
                sifreOlusturucu();
                break;
            case 2:
                metinIstatistikleri();
                break;
            case 3:
                hesapMakinesi();
                break;
            case 4:
                sayiTahminOyunu();
                break;
            case 0:
                devam = false;
                cout << "Program sonlandırılıyor..." << endl;
                break;
            default:
                cout << "Geçersiz seçim! Tekrar deneyin." << endl;
        }
        
        if (devam) {
            cout << endl << "Devam etmek için ENTER tuşuna basın...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            cout << "\n----------------------------------------\n" << endl;
        }
    }
    
    return 0;
}

// 1. Uygulama: Rastgele şifre oluşturucu
void sifreOlusturucu() {
    cout << "\n--- Şifre Oluşturucu ---" << endl;
    
    // Kullanılacak karakter setleri
    const string BUYUK_HARFLER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string KUCUK_HARFLER = "abcdefghijklmnopqrstuvwxyz";
    const string RAKAMLAR = "0123456789";
    const string OZEL_KARAKTERLER = "!@#$%^&*()-_=+[]{}|;:,.<>?";
    
    int uzunluk;
    bool buyukHarfKullan, kucukHarfKullan, rakamKullan, ozelKarakterKullan;
    string tumKarakterler = "";
    
    // Kullanıcı tercihlerini al
    cout << "Şifre uzunluğunu girin: ";
    cin >> uzunluk;
    
    cout << "Büyük harf kullanılsın mı? (1/0): ";
    cin >> buyukHarfKullan;
    
    cout << "Küçük harf kullanılsın mı? (1/0): ";
    cin >> kucukHarfKullan;
    
    cout << "Rakam kullanılsın mı? (1/0): ";
    cin >> rakamKullan;
    
    cout << "Özel karakter kullanılsın mı? (1/0): ";
    cin >> ozelKarakterKullan;
    
    // Karakter havuzunu oluştur
    if (buyukHarfKullan) tumKarakterler += BUYUK_HARFLER;
    if (kucukHarfKullan) tumKarakterler += KUCUK_HARFLER;
    if (rakamKullan) tumKarakterler += RAKAMLAR;
    if (ozelKarakterKullan) tumKarakterler += OZEL_KARAKTERLER;
    
    // Hiçbir karakter seti seçilmediyse uyarı ver
    if (tumKarakterler.empty()) {
        cout << "Hata: En az bir karakter seti seçmelisiniz!" << endl;
        return;
    }
    
    // Rastgele sayı üretecini başlat
    srand(time(0));
    
    // Şifreyi oluştur
    string sifre = "";
    for (int i = 0; i < uzunluk; i++) {
        int rastgeleIndeks = rand() % tumKarakterler.length();
        sifre += tumKarakterler[rastgeleIndeks];
    }
    
    cout << "Oluşturulan şifre: " << sifre << endl;
}

// 2. Uygulama: Metin istatistikleri
void metinIstatistikleri() {
    cout << "\n--- Metin İstatistikleri ---" << endl;
    
    string metin;
    cout << "Bir metin girin: ";
    cin.ignore();
    getline(cin, metin);
    
    // İstatistikler
    int karakterSayisi = metin.length();
    int harfSayisi = 0;
    int rakamSayisi = 0;
    int boslukSayisi = 0;
    int ozelKarakterSayisi = 0;
    int buyukHarfSayisi = 0;
    int kucukHarfSayisi = 0;
    
    // Kelime sayısı
    int kelimeSayisi = 0;
    bool kelimeIcinde = false;
    
    // En uzun kelime
    string enUzunKelime = "";
    string guncelKelime = "";
    
    // Karakter istatistiklerini hesapla
    for (char c : metin) {
        if (isalpha(c)) {
            harfSayisi++;
            if (isupper(c)) {
                buyukHarfSayisi++;
            } else {
                kucukHarfSayisi++;
            }
            
            guncelKelime += c;
            kelimeIcinde = true;
        } else if (isdigit(c)) {
            rakamSayisi++;
            guncelKelime += c;
            kelimeIcinde = true;
        } else if (isspace(c)) {
            boslukSayisi++;
            
            if (kelimeIcinde) {
                kelimeSayisi++;
                if (guncelKelime.length() > enUzunKelime.length()) {
                    enUzunKelime = guncelKelime;
                }
                guncelKelime = "";
                kelimeIcinde = false;
            }
        } else {
            ozelKarakterSayisi++;
            guncelKelime += c;
            kelimeIcinde = true;
        }
    }
    
    // Son kelimeyi kontrol et
    if (kelimeIcinde) {
        kelimeSayisi++;
        if (guncelKelime.length() > enUzunKelime.length()) {
            enUzunKelime = guncelKelime;
        }
    }
    
    // Sonuçları göster
    cout << "Metin: \"" << metin << "\"" << endl;
    cout << "Toplam karakter sayısı: " << karakterSayisi << endl;
    cout << "Harf sayısı: " << harfSayisi << endl;
    cout << "Büyük harf sayısı: " << buyukHarfSayisi << endl;
    cout << "Küçük harf sayısı: " << kucukHarfSayisi << endl;
    cout << "Rakam sayısı: " << rakamSayisi << endl;
    cout << "Boşluk sayısı: " << boslukSayisi << endl;
    cout << "Özel karakter sayısı: " << ozelKarakterSayisi << endl;
    cout << "Kelime sayısı: " << kelimeSayisi << endl;
    cout << "En uzun kelime: \"" << enUzunKelime << "\" (" << enUzunKelime.length() << " karakter)" << endl;
}

// 3. Uygulama: Basit hesap makinesi
void hesapMakinesi() {
    cout << "\n--- Hesap Makinesi ---" << endl;
    
    double sayi1, sayi2;
    char islem;
    double sonuc;
    
    cout << "İlk sayıyı girin: ";
    cin >> sayi1;
    
    cout << "İkinci sayıyı girin: ";
    cin >> sayi2;
    
    cout << "İşlemi seçin (+, -, *, /, ^, r [kök alma]): ";
    cin >> islem;
    
    switch (islem) {
        case '+':
            sonuc = sayi1 + sayi2;
            cout << sayi1 << " + " << sayi2 << " = " << sonuc << endl;
            break;
        case '-':
            sonuc = sayi1 - sayi2;
            cout << sayi1 << " - " << sayi2 << " = " << sonuc << endl;
            break;
        case '*':
            sonuc = sayi1 * sayi2;
            cout << sayi1 << " * " << sayi2 << " = " << sonuc << endl;
            break;
        case '/':
            if (sayi2 != 0) {
                sonuc = sayi1 / sayi2;
                cout << sayi1 << " / " << sayi2 << " = " << sonuc << endl;
            } else {
                cout << "Hata: Sıfıra bölme hatası!" << endl;
            }
            break;
        case '^':
            sonuc = pow(sayi1, sayi2);
            cout << sayi1 << " ^ " << sayi2 << " = " << sonuc << endl;
            break;
        case 'r':
            if (sayi1 >= 0) {
                sonuc = pow(sayi1, 1.0 / sayi2);
                cout << sayi1 << "'in " << sayi2 << ". dereceden kökü = " << sonuc << endl;
            } else {
                cout << "Hata: Negatif sayının kökü hesaplanamıyor!" << endl;
            }
            break;
        default:
            cout << "Geçersiz işlem!" << endl;
    }
    
    // Ek matematiksel işlemler
    cout << "\nEk bilgiler:" << endl;
    
    if (sayi1 >= 0) {
        cout << sayi1 << "'in karekökü: " << sqrt(sayi1) << endl;
    }
    
    cout << sayi1 << "'in yuvarlanmış hali: " << round(sayi1) << endl;
    cout << sayi1 << "'in alt tam sayı değeri: " << floor(sayi1) << endl;
    cout << sayi1 << "'in üst tam sayı değeri: " << ceil(sayi1) << endl;
    cout << "|" << sayi1 << "| (mutlak değer): " << fabs(sayi1) << endl;
}

// 4. Uygulama: Sayı tahmin oyunu
void sayiTahminOyunu() {
    cout << "\n--- Sayı Tahmin Oyunu ---" << endl;
    
    // Rastgele sayı üretecini başlat
    srand(time(0));
    
    int minSayi = 1;
    int maxSayi = 100;
    int rastgeleSayi = minSayi + (rand() % (maxSayi - minSayi + 1));
    int tahmin;
    int denemeSayisi = 0;
    bool dogruTahmin = false;
    
    cout << minSayi << " ile " << maxSayi << " arasında bir sayı tuttum." << endl;
    
    // Zamanı ölç
    time_t baslangic = time(0);
    
    while (!dogruTahmin) {
        cout << "Tahmininiz: ";
        cin >> tahmin;
        denemeSayisi++;
        
        if (tahmin < minSayi || tahmin > maxSayi) {
            cout << "Lütfen " << minSayi << " ile " << maxSayi << " arasında bir sayı girin!" << endl;
        } else if (tahmin < rastgeleSayi) {
            cout << "Daha büyük bir sayı!" << endl;
        } else if (tahmin > rastgeleSayi) {
            cout << "Daha küçük bir sayı!" << endl;
        } else {
            dogruTahmin = true;
            cout << "Tebrikler! " << denemeSayisi << " denemede doğru tahmin ettiniz." << endl;
        }
    }
    
    // Geçen süreyi hesapla
    time_t bitis = time(0);
    double gecenSure = difftime(bitis, baslangic);
    
    cout << "Toplam süre: " << gecenSure << " saniye" << endl;
    
    // Performans puanı hesapla (düşük deneme sayısı ve kısa süre = yüksek puan)
    double performansPuani = 1000.0 / (denemeSayisi * (gecenSure + 1));
    performansPuani = round(performansPuani * 100);
    
    cout << "Performans puanınız: " << performansPuani << endl;
} 