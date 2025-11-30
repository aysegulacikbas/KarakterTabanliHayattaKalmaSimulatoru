#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// --- Durum Deðiþkenleri --- [cite: 22]
int saglik = 100;    // 0-100 arasi [cite: 23]
int enerji = 100;    // 0-100 arasi [cite: 24]
int yemek = 0;       // Yemek sayýsý [cite: 25]
int siginak = 0;     // 0=Yok, 1=Var [cite: 26]
char komut;

// --- Envanteri Görüntüleme Fonksiyonu (Komut E) --- [cite: 11]
void envanter_goster() {
    printf("\n>>> KARAKTER DURUMU <<<\n");
    printf(" Saglik: %d/100\n", saglik);
    printf(" Enerji: %d/100\n", enerji);
    printf(" Yemek Sayisi: %d\n", yemek);
    printf(" Siginak Durumu: %s\n", siginak ? "Bulundu (Guvenli)" : "Yok (Risk Altinda)");
    printf("------------------------\n");
}

int main() {
    // Rastgelelik için tohumlama
    srand(time(NULL));

    printf("<<< Hayatta Kalma Simulatoru Basladi >>>\n");
    printf("Komutlar: A=Avlan, S=Siginak, R=Dinlen, E=Envanter, F=Tehlike, P=Sifre, X=Cikis\n");

    // --- 1. Ana Komut Dinleme Döngüsü (DO-WHILE zorunlu) --- [cite: 7, 19]
    do {
        // Her döngü baþýnda oyuncu ölmüþ mü kontrol et
        if (saglik <= 0 || enerji <= 0) {
            printf("\n!!! SIMULASYON SONA ERDI: HAYATTA KALAMADINIZ !!!\n");
            komut = 'X'; // Çýkýþ komutuna set et
            continue; // Döngünün geri kalanýný atla
        }
        
        envanter_goster(); // Mevcut durumu göster
        printf(">>> Bir komut giriniz: ");
        scanf(" %c", &komut);
        
        // Komutu büyük harfe çevir (kullanýcý küçük harf girse bile çalýþsýn)
        if (komut >= 'a' && komut <= 'z') {
            komut = komut - ('a' - 'A');
        }

        // --- 2. Komut Yönetimi (SWITCH-CASE zorunlu) --- [cite: 9]
        switch (komut) {
            case 'A': // Avlan [cite: 11]
                printf("Avlaniyorsunuz...\n");
                
                // Enerji azalýr (Aritmetik Operatörler) [cite: 12]
                enerji -= 15;
                if (enerji < 0) enerji = 0;
                
                // Yemek bulma veya yaralanma þansý (Mantýksal Operatörler, IF-ELSE) [cite: 13, 27]
                int rastgele = rand() % 100;

                // Baþarýlý Avlanma (%70 þans)
                if (rastgele < 70) {
                    // Mantýksal Operatör: Sýðýnak varsa VE && enerji 20'den fazlaysa 2 yemek bul
                    if (siginak == 1 && enerji > 20) { 
                        yemek += 2;
                        printf("Harika! Siginak avantajiyla 2 adet yemek buldunuz.\n");
                    } else { // Sadece 1 yemek
                        yemek += 1;
                        printf("Basari! 1 adet yemek kazandiniz.\n");
                    }
                } 
                // Yaralanma Þansý (%15 þans VEYA || enerji çok düþükse)
                else if (rastgele >= 70 && rastgele < 85 || enerji < 10) { 
                    saglik -= 10;
                    if (saglik < 0) saglik = 0;
                    printf("Tuzak veya hayvan saldirisi! Saglik -10.\n");
                } 
                // Baþarýsýzlýk
                else {
                    printf("Avlanma Basarisiz. Bir sey bulunamadi.\n");
                }
                break;

            case 'S': // Sýðýnak Ara [cite: 11]
                printf("Siginak araniyor...\n");
                
                // Sýðýnak bulma ihtimali (IF-ELSE Yapýlarý) [cite: 14, 27]
                if (siginak == 0) {
                    if ((rand() % 100) > 65) { // %35 baþarý þansý
                        siginak = 1; // Aritmetik Operatör
                        printf("Tebrikler! Guvenli bir siginak buldunuz.\n");
                    } else {
                        printf("Siginak bulunamadi. Aramaya devam etmelisin.\n");
                    }
                } else {
                    printf("Zaten bir siginagin var.\n");
                }
                break;

            case 'R': // Dinlen [cite: 11]
                printf("Dinleniyorsunuz...\n");
                
                // Saðlýk ve enerji artýþý (Aritmetik Operatörler) [cite: 14]
                enerji += 20;
                saglik += 15;
                
                // Durum sýnýr kontrolü (IF-ELSE) [cite: 27]
                if (enerji > 100) enerji = 100;
                if (saglik > 100) saglik = 100;
                
                printf("Enerji (+20) ve Saglik (+15) artti.\n");

                // Dinlenme sýrasýnda yemek tüketimi
                if (yemek > 0) {
                    yemek -= 1;
                    printf("Bir ögun yemek tuketildi. Yemek sayisi: %d\n", yemek);
                }
                break;
                
            case 'E': // Envanteri Görüntüle [cite: 11]
                // Fonksiyon çaðrýsý ile durum gösterimi zaten yapýlýyor.
                printf("Envanter Durumu basariyla goruntulendi.\n");
                break;

            case 'F': { // Tehlike Serisi Simülasyonu (FOR döngüsü zorunlu) [cite: 11, 16]
                printf("\n*** BOLGESEL TEHLIKE DALGASI BASLADI (3 Adým) ***\n");
                
                // FOR döngüsü ile tehlike serisini simüle et [cite: 17]
                int i;
                for ( i = 1; i <= 3; i++)
				 {
                    printf("-- Tehlike Adimi %d --\n", i);
                    
                    int hasar_tur = rand() % 3; // 0=Saðlýk, 1=Enerji, 2=Kaçýþ
                    int hasar_miktari = 10 + (rand() % 5); // 10-14 arasý hasar

                    // Oyuncunun durumuna baðlý koþullu sonuçlar [cite: 18]
                    if (hasar_tur == 0 && siginak == 0) {
                        saglik -= hasar_miktari; // Aritmetik Operatör
                        printf("Kotu Hava/Dusman! Saglik -%d.\n", hasar_miktari);
                    } else if (hasar_tur == 1) {
                        enerji -= hasar_miktari; // Aritmetik Operatör
                        printf("Hizli Kosu Gerekli! Enerji -%d.\n", hasar_miktari);
                    } else {
                        printf("Tehlikeden basariyla kacildi (Siginak varsa veya sansliysaniz).\n");
                    }
                    
                    // IF-ELSE ile durum kontrolü
                    if (saglik < 0) saglik = 0;
                    if (enerji < 0) enerji = 0;
                    
                    if (saglik == 0) {
                        printf("Sagliginiz bitti. Seriyi durdurmak zorundayiz!\n");
                        break; // Saðlýk 0 ise FOR döngüsünden çýk
                    }
                }
                printf("Tehlike Dalgasi Sona Erdi.\n");
                break;
            }

            case 'P': { // Þifreli Ýlerleme (DO-WHILE doðrulama döngüsü zorunlu) [cite: 11, 19]
                printf("\n--- GIZLI GECIT ---\n");
                printf("Engeli asmak icin dogru sifreyi giriniz : ");
                char girilen_sifre;
                char dogru_sifre = 'K';

                // Doðru karakter girilene kadar devam eden döngü [cite: 20]
                do {
                    scanf(" %c", &girilen_sifre);
                    // Girilen þifreyi de büyük harfe çevir
                    if (girilen_sifre >= 'a' && girilen_sifre <= 'z') {
                        girilen_sifre = girilen_sifre - ('a' - 'A');
                    }

                    if (girilen_sifre == dogru_sifre) {
                        printf("!!! SIFRE DOGRU !!! Gizli Gecit Acildi.\n");
                        saglik += 5; // Baþarý bonusu
                    } else {
                        printf("Yanlýs Sifre! Enerji kaybediyorsun. Tekrar Dene: ");
                        enerji -= 3; // Yanlýþ denemede ceza
                        if (enerji < 0) enerji = 0;
                    }
                } while (girilen_sifre != dogru_sifre && enerji > 0); // Enerji bitene kadar veya doðru þifreye kadar

                if (enerji == 0) {
                    printf("Enerjiniz bitti. Sifreyi kirmak icin çok yorgunsunuz.\n");
                }
                break;
            }

            case 'X': // Çýkýþ [cite: 11]
                printf("\nSimulasyon Basariyla Sonlandiriliyor...\n");
                break;
                
            default:
                printf("Gecersiz komut. Lutfen gecerli bir harf girin (A, S, R, E, F, P, X).\n");
                break;
        }

    } while (komut != 'X'); // Çýkýþ komutuna (X) kadar simülasyon devam eder [cite: 7]

    return 0;
}
