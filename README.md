# OddEvenLiskedList

## Soru:

Tek başına bağlı bir liste göz önüne alındığında, tüm garip düğümleri birlikte takip eden çift düğümleri gruplayın. Lütfen not edin ki, düğüm numarasından bahsediyoruz, düğüm değerlerinden değil.

Yerinde yapmayı denemelisin. Program O (1) uzay karmaşıklığı ve O (düğümler) zaman karmaşıklığı içerisinde çalışmalıdır.

Örnek 1:

Giriş: 1-> 2-> 3-> 4-> 5-> NULL Çıkış: 1-> 3-> 5-> 2-> 4-> NULL Örnek 2:

Giriş: 2-> 1-> 3-> 5-> 6-> 4-> 7-> NULL Çıkış: 2-> 3-> 6-> 7-> 1-> 5-> 4-> NULL Not:

Hem çift hem de tekli grupların içindeki göreceli sıra, girişte olduğu gibi kalmalıdır. İlk düğüm garip olarak kabul edilir, ikinci düğüm de böyle devam eder ...

Algoritma

Çözüm çok sezgisel. Ancak özlü ve hatasız bir kod yazmak önemsiz değildir.

İyi biçimlendirilmiş LinkedList'in her iki ucundaki işlemleri desteklemek için iki işaretçi başı ve kuyruğu gerekir. Head ve odd değişkenleri, oddList olarak adlandırdığımız LinkedList öğesinin baş işaretçisi ve kuyruk işaretçisidir; değişkenler evenHead ve hatta başka bir LinkedList'in baş işaretçisi ve kuyruk işaretçisidir. Algoritma, orijinal LinkedList'i dolaşır ve tek düğümleri oddList'e ve çift düğümleri evenList'e yerleştirir. LinkedList'i geçmek için geçerli düğüm için bir yineleyici olarak en az bir işaretçiye ihtiyacımız var. Fakat burada işaretçiler tuhaf ve hatta sadece kuyruk işaretçilerine hizmet etmekle kalmıyor, aynı zamanda orijinal listenin yineleyicileri gibi davranıyorlar.

Herhangi bir bağlantılı liste problemini çözmenin en iyi yolu, onu zihninizde veya bir kağıt parçası üzerinde görselleştirmektir. Algoritmamızın bir örneği aşağıdaki gibidir:

Karmaşıklık Analizi Zaman karmaşıklığı: O (n) Toplam nn düğümü var ve her düğümü bir kez ziyaret ediyoruz. Uzay karmaşıklığı: O (1). Tek ihtiyacımız olan dört işaretçi.
