# KarakterTabanliHayattaKalmaSimulatoru
📘 HAYATTA KALMA SİMÜLATÖRÜ – PROJE RAPORU
1. Giriş

Bu proje, C programlama dilinin temel kontrol yapıları, döngüler, koşullar, fonksiyonlar, rastgelelik ve kullanıcı etkileşimi gibi temel kavramlarını uygulamalı olarak göstermek amacıyla tasarlanmış bir hayatta kalma simülasyonudur.
Oyuncu; sağlık, enerji, yemek ve sığınak gibi durum değişkenlerini yöneterek hayatta kalmaya çalışır. Kullanıcıdan sürekli komut alınarak simülasyon ilerletilir.

2. Programın Amacı

Program, kullanıcıya bir hayatta kalma ortamı sunarak şu C programlama konularını uygulamayı hedefler:

Değişkenler ve veri tipleri

Karar yapıları (IF-ELSE, SWITCH-CASE)

Döngüler (DO-WHILE, FOR)

Fonksiyonlar

Rastgele sayı üretimi

Mantıksal ve aritmetik operatörler

Kullanıcı girdisi işleme

Koşullu durum yönetimi

3. Kullanılan Değişkenler
Değişken	Tür	Açıklama
saglik	int	Oyuncunun sağlık durumu (0–100)
enerji	int	Oyuncunun enerji seviyesi (0–100)
yemek	int	Biriken yemek sayısı
siginak	int	0 = Yok, 1 = Var
komut	char	Kullanıcıdan alınan komut
4. Programın Genel Çalışma Yapısı
4.1 Ana Döngü (DO-WHILE)

Program daima kullanıcıdan komut alır ve 'X' girilene kadar çalışmaya devam eder.

Ayrıca döngü her başta:

Sağlık ≤ 0

Enerji ≤ 0
ise oyun otomatik sonlanır.

5. Komutların Açıklaması (SWITCH-CASE)
A – Avlan

Enerji 15 azalır.

%70 yemek bulma şansı.

Sığınak + yeterli enerji sayesinde 2 yemek kazanılabilir.

%15 yaralanma şansı veya enerji çok düşükse:

Sağlık 10 azalır.

S – Sığınak Ara

%35 ihtimalle sığınak bulunur.

Bir kez bulunduğunda tekrar bulunmaz.

R – Dinlen

Enerji +20

Sağlık +15

Yemek varsa 1 adet tüketilir.

Değerler 100'ü geçmez.

E – Envanteri Göster

saglik, enerji, yemek, siginak değerlerini ekrana yazar.

F – Tehlike Dalgası (FOR Döngüsü)

3 adımlık tehlike simülasyonu:

Sağlık veya enerji rastgele 10–14 azalabilir.

Sığınak koruma sağlayabilir.

Sağlık sıfırlanırsa döngü kırılır.

P – Şifreli Geçit (DO-WHILE ile doğrulama)

Kullanıcı doğru şifreyi (‘K’) girene kadar devam eder.

Yanlış denemelerde enerji −3 azalır.

Enerji biterse kullanıcı başarısız olur.

X – Çıkış

Simülasyonu sonlandırır.

6. Kullanılan C Yapıları ve Tekniklerin İncelenmesi
✔ Koşul Yapıları

Program yoğun şekilde IF-ELSE kullanarak:

Avlanma sonuçları

Tehlike hasarı

Sığınak durumu

Sağlık/enerji kontrolü

Şifre doğrulama
gibi süreçleri yönetir.

✔ Döngüler
Döngü	Kullanıldığı Yer	Amaç
DO-WHILE	Ana oyun döngüsü	X girilene kadar çalıştırma
DO-WHILE	Şifre kontrolü	Doğru şifre girilene kadar
FOR	Tehlike dalgası	3 adımlık risk simülasyonu
✔ Rastgelelik
rand() % 100
rand() % 3


ile belirli olasılıklara dayalı:

Av başarı–başarısızlık

Yaralanma

Tehlike türü
seçilir.

✔ Fonksiyon Kullanımı

envanter_goster()
→ Kod tekrarını azaltır, düzeni artırır.

7. Program Akış Diyagramı (Özet)
   Başla
     |
DO-WHILE
     |
  Sağlık/Enerji kontrolü → Ölü ise bitiş
     |
  Envanter göster
     |
  Komut al
     |
 SWITCH-CASE
     ├─ A → Avlan
     ├─ S → Sığınak
     ├─ R → Dinlen
     ├─ E → Envanter
     ├─ F → Tehlike Döngüsü
     ├─ P → Şifre Sistemi
     └─ X → Çıkış
     |
Tekrar

