/*
 * SANAL FONKSİYONLAR VE POLİMORFİZM (VIRTUAL FUNCTIONS AND POLYMORPHISM)
 * 
 * C++'da sanal fonksiyonlar ve polimorfizm, nesne yönelimli programlamanın temel kavramlarından biridir.
 * 
 * Sanal fonksiyon (virtual function):
 * - Temel sınıfta 'virtual' anahtar kelimesi ile tanımlanan
 * - Türetilmiş sınıfta geçersiz kılınabilen (override edilebilen) fonksiyonlardır
 * 
 * Polimorfizm (çok biçimlilik):
 * - Aynı arayüzü kullanarak farklı türdeki nesnelerin farklı davranışlar sergilemesidir
 * - C++'da çalışma zamanında (runtime) hangi sınıfın metodunun çağrılacağının belirlenmesini sağlar
 * 
 * Saf sanal fonksiyon (pure virtual function):
 * - "= 0" ile tanımlanan ve temel sınıfta gövdesi olmayan fonksiyonlardır
 * - Saf sanal fonksiyon içeren sınıflar soyut sınıf (abstract class) olarak adlandırılır
 * - Soyut sınıflardan nesne oluşturulamaz, yalnızca türetilmiş sınıflar için arayüz görevi görür
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 1. Temel sınıf ve sanal fonksiyonlar
class Sekil {
protected:
    string tur;
    
public:
    // Yapıcı fonksiyon
    Sekil(const string& t) : tur(t) {
        cout << tur << " şekli oluşturuldu." << endl;
    }
    
    // Sanal yıkıcı fonksiyon - türetilmiş sınıf nesneleri için önemli
    virtual ~Sekil() {
        cout << tur << " şekli silindi." << endl;
    }
    
    // Sanal fonksiyon - türetilmiş sınıflarda override edilebilir
    virtual void bilgileriGoster() const {
        cout << "Şekil türü: " << tur << endl;
    }
    
    // Saf sanal fonksiyon - tüm türetilmiş sınıflar tarafından implement edilmelidir
    virtual double alanHesapla() const = 0;
    
    // Saf sanal fonksiyon
    virtual double cevreHesapla() const = 0;
    
    // Sanal olmayan bir fonksiyon - tüm türetilmiş sınıflarda aynı davranış gösterir
    void sekilTuru() const {
        cout << "Bu bir " << tur << " şeklidir." << endl;
    }
};

// 2. Türetilmiş sınıf: Daire
class Daire : public Sekil {
private:
    double yaricap;
    const double PI = 3.14159;
    
public:
    Daire(double r) : Sekil("Daire"), yaricap(r) {}
    
    // Sanal fonksiyonun override edilmesi
    void bilgileriGoster() const override {
        Sekil::bilgileriGoster();
        cout << "Yarıçap: " << yaricap << endl;
    }
    
    // Saf sanal fonksiyonun implementasyonu
    double alanHesapla() const override {
        return PI * yaricap * yaricap;
    }
    
    // Saf sanal fonksiyonun implementasyonu
    double cevreHesapla() const override {
        return 2 * PI * yaricap;
    }
};

// 3. Türetilmiş sınıf: Dikdortgen
class Dikdortgen : public Sekil {
private:
    double genislik;
    double yukseklik;
    
public:
    Dikdortgen(double g, double y) : Sekil("Dikdörtgen"), genislik(g), yukseklik(y) {}
    
    // Sanal fonksiyonun override edilmesi
    void bilgileriGoster() const override {
        Sekil::bilgileriGoster();
        cout << "Genişlik: " << genislik << ", Yükseklik: " << yukseklik << endl;
    }
    
    // Saf sanal fonksiyonun implementasyonu
    double alanHesapla() const override {
        return genislik * yukseklik;
    }
    
    // Saf sanal fonksiyonun implementasyonu
    double cevreHesapla() const override {
        return 2 * (genislik + yukseklik);
    }
};

// 4. Türetilmiş sınıf: Ucgen
class Ucgen : public Sekil {
private:
    double kenar1, kenar2, kenar3;
    
public:
    Ucgen(double k1, double k2, double k3) 
        : Sekil("Üçgen"), kenar1(k1), kenar2(k2), kenar3(k3) {}
    
    // Sanal fonksiyonun override edilmesi
    void bilgileriGoster() const override {
        Sekil::bilgileriGoster();
        cout << "Kenarlar: " << kenar1 << ", " << kenar2 << ", " << kenar3 << endl;
    }
    
    // Saf sanal fonksiyonun implementasyonu (Heron formülü ile)
    double alanHesapla() const override {
        double s = (kenar1 + kenar2 + kenar3) / 2;
        return sqrt(s * (s - kenar1) * (s - kenar2) * (s - kenar3));
    }
    
    // Saf sanal fonksiyonun implementasyonu
    double cevreHesapla() const override {
        return kenar1 + kenar2 + kenar3;
    }
};

// 5. Sanal fonksiyonlarla çoklu düzey kalıtım
class Kare : public Dikdortgen {
public:
    Kare(double kenar) : Dikdortgen(kenar, kenar) {
        tur = "Kare"; // Temel sınıftan gelen protected veri üyesini değiştiriyoruz
    }
    
    // Sanal fonksiyonun override edilmesi
    void bilgileriGoster() const override {
        Sekil::bilgileriGoster(); // Doğrudan Sekil sınıfının fonksiyonunu çağırabiliriz
        cout << "Kenar uzunluğu: " << sqrt(alanHesapla()) << endl;
    }
    
    // Not: alanHesapla() ve cevreHesapla() fonksiyonlarını override etmiyoruz
    // çünkü Dikdortgen sınıfının implementasyonları Kare için de doğrudur
};

// 6. Sanal fonksiyonların final ile işaretlenmesi (C++11 ve sonrası)
class SpecialDaire : public Daire {
public:
    SpecialDaire(double r) : Daire(r) {
        tur = "Özel Daire";
    }
    
    // final anahtar kelimesi bu fonksiyonun daha fazla override edilmesini engeller
    void bilgileriGoster() const override final {
        cout << "Bu özel bir dairedir." << endl;
        Daire::bilgileriGoster();
    }
    
    // Alan hesaplama fonksiyonu da final olarak işaretlenebilir
    double alanHesapla() const override final {
        return Daire::alanHesapla() * 1.1; // %10 fazla alan
    }
};

// 7. Sanal fonksiyon tablosu (vtable) örnekleri
void sekilBilgileriniGoster(const Sekil& s) {
    s.bilgileriGoster();
    cout << "Alan: " << s.alanHesapla() << endl;
    cout << "Çevre: " << s.cevreHesapla() << endl;
    cout << "-------------------" << endl;
}

int main() {
    cout << "=== SANAL FONKSİYONLAR VE POLİMORFİZM ÖRNEKLERİ ===" << endl;
    
    // 1. Temel sınıf nesnesi oluşturulamaz (soyut sınıf)
    // Sekil s("Bilinmeyen"); // HATA! Soyut sınıftan nesne oluşturulamaz
    
    // 2. Türetilmiş sınıf nesneleri
    Daire d(5.0);
    Dikdortgen dik(4.0, 6.0);
    Ucgen u(3.0, 4.0, 5.0);
    Kare k(4.0);
    SpecialDaire sd(5.0);
    
    cout << "\n--- Temel Sınıf Referansı ile Polimorfizm ---" << endl;
    // 3. Temel sınıf referansı ile polimorfizm
    sekilBilgileriniGoster(d);
    sekilBilgileriniGoster(dik);
    sekilBilgileriniGoster(u);
    sekilBilgileriniGoster(k);
    sekilBilgileriniGoster(sd);
    
    // 4. Temel sınıf pointer'ları ile polimorfizm
    cout << "\n--- Temel Sınıf Pointer'ları ile Polimorfizm ---" << endl;
    Sekil* sekiller[] = {&d, &dik, &u, &k, &sd};
    
    for (Sekil* sekil : sekiller) {
        sekil->bilgileriGoster();
        cout << "Alan: " << sekil->alanHesapla() << endl;
        cout << "Çevre: " << sekil->cevreHesapla() << endl;
        sekil->sekilTuru(); // Sanal olmayan fonksiyon
        cout << "-------------------" << endl;
    }
    
    // 5. Dynamic_cast ve RTTI (Run-Time Type Information) kullanımı
    cout << "\n--- dynamic_cast ve RTTI Kullanımı ---" << endl;
    Sekil* bilinmeyenSekil = &d; // Aslında bir Daire
    
    // dynamic_cast ile tür dönüşümü
    Daire* dairePtrDyn = dynamic_cast<Daire*>(bilinmeyenSekil);
    if (dairePtrDyn) {
        cout << "Başarılı dönüşüm! Bu bir Daire nesnesidir." << endl;
        cout << "Dairenin alanı: " << dairePtrDyn->alanHesapla() << endl;
    } else {
        cout << "Dönüşüm başarısız! Bu bir Daire nesnesi değildir." << endl;
    }
    
    // Yanlış türe dönüşüm denemesi
    Ucgen* ucgenPtrDyn = dynamic_cast<Ucgen*>(bilinmeyenSekil);
    if (ucgenPtrDyn) {
        cout << "Başarılı dönüşüm! Bu bir Ucgen nesnesidir." << endl;
    } else {
        cout << "Dönüşüm başarısız! Bu bir Ucgen nesnesi değildir." << endl;
    }
    
    // 6. typeid operatörü ile tür bilgisi alma
    cout << "\n--- typeid Operatörü Kullanımı ---" << endl;
    cout << "bilinmeyenSekil'in gerçek türü: " << typeid(*bilinmeyenSekil).name() << endl;
    cout << "dik'in türü: " << typeid(dik).name() << endl;
    
    // 7. Farklı sınıf nesnelerinin container içinde saklanması
    cout << "\n--- Container içinde Sanal Fonksiyon Kullanımı ---" << endl;
    vector<Sekil*> sekilListesi;
    sekilListesi.push_back(new Daire(3.0));
    sekilListesi.push_back(new Dikdortgen(2.0, 3.0));
    sekilListesi.push_back(new Ucgen(3.0, 4.0, 5.0));
    sekilListesi.push_back(new Kare(5.0));
    
    // Tüm şekillerin toplam alanını hesaplama
    double toplamAlan = 0.0;
    for (Sekil* s : sekilListesi) {
        toplamAlan += s->alanHesapla();
        s->bilgileriGoster();
    }
    
    cout << "Tüm şekillerin toplam alanı: " << toplamAlan << endl;
    
    // Bellek temizliği
    for (Sekil* s : sekilListesi) {
        delete s; // Sanal yıkıcı fonksiyon çağrılır
    }
    
    return 0;
} 