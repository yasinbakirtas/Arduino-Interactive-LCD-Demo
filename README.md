# 🖥️ Arduino İnteraktif LCD Animasyon ve Menü Demosu

Bu proje, standart bir 16x2 LCD Keypad Shield kullanılarak donanım üzerinde nasıl animasyon yapılabileceğini ve kullanıcı ile etkileşimli bir arayüz (UI) menüsünün nasıl kurgulanabileceğini gösteren bir C programlama demosudur. 

## 🛠️ Öne Çıkan Teknik Geliştirmeler

* **Byte Matrisleri ile Özel Karakter (Custom Character) Üretimi:** ASCII tablosunda bulunmayan ikonlar (robotlar, onay/red işaretleri, veri paketleri) bit düzeyinde tasarlanarak hafızaya kaydedilmiş ve ekrana çizdirilmiştir.
* **Algoritmik Animasyon Döngüleri:** Karakterlerin ekranın iki ucundan merkeze doğru hareket etmesi, `for` döngüleri ve imleç (cursor) konumlandırma mantığıyla dinamik olarak hesaplanmıştır.
* **ADC (Analog to Digital Converter) Tuş Okuma:** Devre karmaşasını önlemek adına 5 farklı fiziksel butonun durumu, tek bir analog pin (A0) üzerinden voltaj bölücü direnç eşikleri okunarak tespit edilmiştir.
* **Dinamik Fonksiyon Yönetimi:** String manipülasyonu ile ekrana karakter karakter yazdırma işlemi yapan `daktiloYaz()` fonksiyonu tasarlanmış; ana akış (loop) `while` döngüleri ile bloke edilerek kullanıcının kararına göre yönlenen bir menü sistemi kurulmuştur.
