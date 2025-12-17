# Sparse Matrix (Seyrek Matris)

Sparse matrix (seyrek matris), elemanlarının büyük bir kısmı sıfır olan matrislere verilen isimdir.
Toplam eleman sayısına göre sıfır olmayan eleman sayısı çok az ise bu matris seyrek olarak kabul edilir.

## Tanım
Büyük boyutlu matrislerde sıfır olan elemanları da saklamak hem bellek hem de işlem maliyeti açısından verimsizdir.
Bu nedenle sparse matrislerde yalnızca sıfır olmayan elemanlar özel temsil yöntemleriyle saklanır.

## Neden Kullanılır?
- Bellek kullanımını azaltmak için
- Hesaplama verimliliğini artırmak için
- Büyük veri yapılarıyla çalışırken performans kazanmak için

Sparse matrisler özellikle:
- Grafik (graph) gösterimleri
- Bilimsel hesaplamalar
- Makine öğrenmesi
- Ağ analizleri

gibi alanlarda yaygın olarak kullanılır.

## Sparse Matrix Temsil Yöntemleri

### 1. Coordinate List (COO)
Bu yöntemde yalnızca sıfır olmayan elemanlar saklanır.
Her eleman için satır, sütun ve değer bilgisi tutulur.

**(Satır, Sütun, Değer)**

### 2. Compressed Sparse Row (CSR)
Bu yöntemde:
- Değerler
- Sütun indeksleri
- Satır başlangıç indeksleri

ayrı diziler halinde saklanır.
Satır bazlı işlemler için oldukça verimlidir.

### 3. Compressed Sparse Column (CSC)
CSR yöntemine benzer şekilde çalışır ancak bu sefer sütun bazlı saklama yapılır.
Sütun bazlı işlemler için uygundur.

## Örnek

Aşağıdaki 4x4 matris bir sparse matrix örneğidir:
0 0 3 0
0 0 0 0
5 0 0 0
0 0 0 7
Bu matriste yalnızca 3 adet sıfır olmayan eleman vardır:
- (0, 2) → 3
- (2, 0) → 5
- (3, 3) → 7

COO gösterimi şu şekilde olur:

(0, 2, 3)
(2, 0, 5)
(3, 3, 7)
