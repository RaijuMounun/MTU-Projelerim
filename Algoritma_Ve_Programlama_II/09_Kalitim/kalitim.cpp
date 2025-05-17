/*
 * KALITIM (INHERITANCE)
 * 
 * C++'da kalıtım, bir sınıfın başka bir sınıfın özelliklerini ve davranışlarını devralmasını sağlayan
 * nesne yönelimli programlamanın temel kavramlarından biridir.
 * 
 * Kalıtım hiyerarşisinde:
 * - Temel Sınıf (Base Class / Parent Class): Özelliklerini devreden sınıf
 * - Türetilmiş Sınıf (Derived Class / Child Class): Özellikleri devralan sınıf
 * 
 * Kalıtım ile:
 * 1. Kod tekrarını azaltabiliriz
 * 2. Hiyerarşik bir yapı oluşturabiliriz
 * 3. Mevcut sınıflarda değişiklik yapmadan onları genişletebiliriz
 * 
 * C++'da üç tür kalıtım erişim belirleyicisi vardır:
 * - public: Temel sınıfın public üyeleri türetilmiş sınıfta public, protected üyeleri protected kalır
 * - protected: Temel sınıfın public ve protected üyeleri türetilmiş sınıfta protected olur
 * - private: Temel sınıfın public ve protected üyeleri türetilmiş sınıfta private olur
 */

#include <iostream>
#include <string>
using namespace std;

// 1. Temel Sınıf (Base Class)
class Canli {
protected:
    string tur;
    int yas;
    
public:
    // Yapıcı fonksiyon
    Canli(string t, int y) : tur(t), yas(y) {
        cout << "Canli sınıfı yapıcısı çalıştı." << endl;
    }
    
    // Yıkıcı fonksiyon (destructor)
    ~Canli() {
        cout << "Canli sınıfı yıkıcısı çalıştı." << endl;
    }
    
    // Üye fonksiyonlar
    void bilgileriGoster() {
        cout << "Tür: " << tur << ", Yaş: " << yas << endl;
    }
    
    void nefesAl() {
        cout << tur << " nefes alıyor." << endl;
    }
};

// 2. Türetilmiş Sınıf (Derived Class) - public kalıtım
class Hayvan : public Canli {
private:
    bool evcil;
    
public:
    // Türetilmiş sınıf yapıcısı, temel sınıf yapıcısını çağırır
    Hayvan(string t, int y, bool e) : Canli(t, y), evcil(e) {
        cout << "Hayvan sınıfı yapıcısı çalıştı." << endl;
    }
    
    // Yıkıcı fonksiyon
    ~Hayvan() {
        cout << "Hayvan sınıfı yıkıcısı çalıştı." << endl;
    }
    
    // Temel sınıftan gelen metodu override etme (geçersiz kılma)
    void bilgileriGoster() {
        Canli::bilgileriGoster(); // Temel sınıfın metodunu çağırma
        cout << "Evcil mi: " << (evcil ? "Evet" : "Hayır") << endl;
    }
    
    // Yeni üye fonksiyon
    void sesCikar() {
        cout << tur << " ses çıkarıyor." << endl;
    }
};

// 3. İkinci Düzey Türetilmiş Sınıf - Çok düzeyli kalıtım (Multilevel Inheritance)
class Kopek : public Hayvan {
private:
    string cins;
    
public:
    Kopek(string t, int y, bool e, string c) : Hayvan(t, y, e), cins(c) {
        cout << "Kopek sınıfı yapıcısı çalıştı." << endl;
    }
    
    ~Kopek() {
        cout << "Kopek sınıfı yıkıcısı çalıştı." << endl;
    }
    
    void bilgileriGoster() {
        Hayvan::bilgileriGoster();
        cout << "Cins: " << cins << endl;
    }
    
    void sesCikar() {
        cout << cins << " havlıyor" << endl;
    }
    
    void kuyrukSalla() {
        cout << cins << " kuyruk sallıyor." << endl;
    }
};

// 4. İkinci bir türetilmiş sınıf - Hiyerarşik kalıtım (Hierarchical Inheritance)
class Kus : public Hayvan {
private:
    bool ucabilir;
    
public:
    Kus(string t, int y, bool e, bool u) : Hayvan(t, y, e), ucabilir(u) {
        cout << "Kus sınıfı yapıcısı çalıştı." << endl;
    }
    
    ~Kus() {
        cout << "Kus sınıfı yıkıcısı çalıştı." << endl;
    }
    
    void bilgileriGoster() {
        Hayvan::bilgileriGoster();
        cout << "Uçabilir mi: " << (ucabilir ? "Evet" : "Hayır") << endl;
    }
    
    void sesCikar() {
        cout << tur << " ötüyor" << endl;
    }
    
    void uc() {
        if (ucabilir) {
            cout << tur << " uçuyor." << endl;
        } else {
            cout << tur << " uçamıyor." << endl;
        }
    }
};

// 5. Çoklu Kalıtım (Multiple Inheritance)
class Motor {
protected:
    int beygirGucu;
    
public:
    Motor(int bg) : beygirGucu(bg) {
        cout << "Motor sınıfı yapıcısı çalıştı." << endl;
    }
    
    ~Motor() {
        cout << "Motor sınıfı yıkıcısı çalıştı." << endl;
    }
    
    void calistir() {
        cout << "Motor çalıştı. Beygir gücü: " << beygirGucu << endl;
    }
};

class Tekne {
protected:
    int uzunluk;
    
public:
    Tekne(int u) : uzunluk(u) {
        cout << "Tekne sınıfı yapıcısı çalıştı." << endl;
    }
    
    ~Tekne() {
        cout << "Tekne sınıfı yıkıcısı çalıştı." << endl;
    }
    
    void yelkenAc() {
        cout << uzunluk << " metrelik teknede yelken açıldı." << endl;
    }
};

// Çoklu kalıtım ile yeni bir sınıf
class Motorlu_Tekne : public Motor, public Tekne {
private:
    string model;
    
public:
    Motorlu_Tekne(int bg, int u, string m) : Motor(bg), Tekne(u), model(m) {
        cout << "Motorlu_Tekne sınıfı yapıcısı çalıştı." << endl;
    }
    
    ~Motorlu_Tekne() {
        cout << "Motorlu_Tekne sınıfı yıkıcısı çalıştı." << endl;
    }
    
    void bilgileriGoster() {
        cout << "Model: " << model << endl;
        cout << "Beygir gücü: " << beygirGucu << endl;
        cout << "Uzunluk: " << uzunluk << " metre" << endl;
    }
    
    void hareketEt() {
        calistir();
        cout << model << " hareket ediyor." << endl;
    }
};

// 6. Protected kalıtım örneği
class A {
public:
    int x;
protected:
    int y;
private:
    int z;
    
public:
    A() : x(1), y(2), z(3) {}
    
    void goster() {
        cout << "A sınıfı: x=" << x << ", y=" << y << ", z=" << z << endl;
    }
};

// Protected kalıtım
class B : protected A {
public:
    void degerGoster() {
        cout << "B sınıfı: x=" << x << ", y=" << y << endl; // z erişilemez
        // A sınıfının public ve protected üyeleri B için protected oldu
    }
    
    void publicFonksiyon() {
        cout << "B sınıfı public fonksiyon" << endl;
    }
};

// B'den türetilmiş sınıf
class C : public B {
public:
    void degerGoster() {
        cout << "C sınıfı: x=" << x << ", y=" << y << endl; // z erişilemez
        // B'den miras alınan x ve y, C için protected
    }
};

// 7. Private kalıtım örneği
class D : private A {
public:
    void degerGoster() {
        cout << "D sınıfı: x=" << x << ", y=" << y << endl; // z erişilemez
        // A sınıfının public ve protected üyeleri D için private oldu
    }
};

// D'den türetilmiş sınıf
class E : public D {
public:
    void degerGoster() {
        // cout << "E sınıfı: x=" << x << ", y=" << y << endl; // HATA! x ve y erişilemez
        // D sınıfı A'dan private olarak türetildiği için x ve y, E için erişilemez
        cout << "E sınıfı degerGoster()" << endl;
    }
};

int main() {
    cout << "=== KALITIM ÖRNEKLERİ ===" << endl;
    
    // 1. Temel sınıf örneği
    cout << "\n--- Temel Sınıf Örneği ---" << endl;
    Canli canli("Bilinmeyen", 1);
    canli.bilgileriGoster();
    canli.nefesAl();
    
    // 2. Türetilmiş sınıf örneği - Tek düzeyli kalıtım
    cout << "\n--- Türetilmiş Sınıf Örneği (Hayvan) ---" << endl;
    Hayvan hayvan("Memeli", 5, true);
    hayvan.bilgileriGoster();
    hayvan.nefesAl();
    hayvan.sesCikar();
    
    // 3. İkinci düzey türetilmiş sınıf - Çok düzeyli kalıtım
    cout << "\n--- İkinci Düzey Türetilmiş Sınıf Örneği (Kopek) ---" << endl;
    Kopek kopek("Köpek", 3, true, "Golden Retriever");
    kopek.bilgileriGoster();
    kopek.nefesAl();
    kopek.sesCikar();
    kopek.kuyrukSalla();
    
    // 4. Diğer türetilmiş sınıf - Hiyerarşik kalıtım
    cout << "\n--- Diğer Türetilmiş Sınıf Örneği (Kus) ---" << endl;
    Kus kus("Kanarya", 2, true, true);
    kus.bilgileriGoster();
    kus.nefesAl();
    kus.sesCikar();
    kus.uc();
    
    // 5. Çoklu kalıtım örneği
    cout << "\n--- Çoklu Kalıtım Örneği ---" << endl;
    Motorlu_Tekne yat(250, 15, "Lüks Yat");
    yat.bilgileriGoster();
    yat.hareketEt();
    yat.yelkenAc();
    
    // 6. Protected kalıtım örneği
    cout << "\n--- Protected Kalıtım Örneği ---" << endl;
    B b_nesnesi;
    // b_nesnesi.x = 10; // HATA! x artık protected (dışarıdan erişilemez)
    b_nesnesi.publicFonksiyon();
    b_nesnesi.degerGoster();
    
    C c_nesnesi;
    c_nesnesi.degerGoster();
    c_nesnesi.publicFonksiyon();
    
    // 7. Private kalıtım örneği
    cout << "\n--- Private Kalıtım Örneği ---" << endl;
    D d_nesnesi;
    d_nesnesi.degerGoster();
    // d_nesnesi.x = 20; // HATA! x artık private
    
    E e_nesnesi;
    e_nesnesi.degerGoster();
    
    cout << "\n--- Yıkıcı Fonksiyonların Çağrılma Sırası ---" << endl;
    // Aşağıdaki blok bittiğinde, yıkıcı fonksiyonları çağrılma sırasını görebiliriz
    {
        Kopek gecici("Kopek", 4, true, "Terrier");
    } // Yıkıcılar ters sırada çağrılır: Kopek -> Hayvan -> Canli
    
    return 0;
} 