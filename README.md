# OddEvenLiskedList

## Soru:

Tek bağlı bir liste veriliyor, tüm tekilinci düğümleri gruplayıp ardına çiftinci düğümleri grup halinde bağlayınız. 
Not: Soruda bahsedilen tekillik düğümlerin içerdiği rakamlar değil sıralarıdır.

Soruyu “in-place” çözmeye çalışınız. Programın uzay karmaşıklığı O(1) ve zaman karmaşıklığı O(n) olmalıdır.

### Örnek 1:  
Girdi: 1->2->3->4->5->NULL  
Çıktı:: 1->3->5->2->4->NULL   

### Örnek 2:  
Girdi: 2->1->3->5->6->4->7->NULL  
Çıktı: 2->3->6->7->1->5->4->NULL  

### Not: Sadece grup sıraları değil, grup içerisindeki görece düğüm sıraları da korunmalıdır.

## Çözüm: 

Dikkat etmemiz gereken nokta bizden çözümün in-place ve O(n) koşu hızında çözülmesi istenmesi. Yani yaptığımız değişiklikler yedek liste olmadan doğrudan ana liste üzerinde olmalı ve iç içe döngü olmamalı.

Fonksiyonda liste başı pointer’ını geri döndürmemiz gerekiyor. Kullanıcı tarafından gönderilen head pointer’ına dokunmuyoruz. Bu head pointer’ı aynı zamanda tekincil düğüm grubunun başı olacaktır. Çözüm için 3 tane daha pointer oluşturuyoruz(tek, cift, cHead). ‘tek’ işaretçisinde tekinci düğümleri tutuyoruz. Başlangıçta head işaretçisiyle aynı konumda. cHead işaretçisinde, çiftinci düğümlerin başlangıcını tutuyoruz, listemizin yapısından mütevellit bu head işaretçisinin next’idir. Tekinci düğümleri grupladıktan sonra sonuna bu işaretçiyi bağlayacağımız için cHead için ilk değer atamasından başka değişiklik yapmıyoruz. ‘cift’ işaretçisinde ise çiftinci sıradaki düğümleri tutuyoruz. Sadece ‘tek’ ve ‘cift’ işaretçileri üzerinde oynama yapıyoruz. Döngü içerisinde iki işaretçiyi de arada bir düğüm atlayacak şekilde next’ine bağlıyoruz. Bu sayede tekinci ve çiftinci düğümler gruplanmış oluyor. Son olarak da ‘tek’ düğümünün next’ine cHead’i bağladığımızda tüm liste istediğimiz şekilde gruplanmış oluyor.

Birbirine giren pointerlar olduğu için çözümü anlamanın en iyi yolu listenin gidişatını zihinde canlandırmak ya da kağıt üzerinde görmek. Aşağıdaki illüstrasyon çözüm algoritmasını daha iyi göstermektedir:

### Zaman Karmaşıklığı : O(n)  Her bir düğümü sadece 1 defa geziyoruz.
### Uzay Karmaşıklığı: O(1). - Tek ihtiyacımız olan şey 4 işaretçi.

