# Recursive Destroy Fonksiyonu

Bu örnekte, C dilinde tek yönlü bağlı bir listenin tüm düğümlerinin recursive (özyinelemeli) olarak bellekten silinmesi gösterilmektedir.

## Açıklama
`destroy` fonksiyonu, kendisini bir sonraki düğüm için çağırarak listenin sonuna kadar ilerler.
Liste sonuna ulaşıldığında (`NULL` durumu), recursion durur.

Recursion geri sarılırken her düğüm `free` fonksiyonu ile bellekten silinir.
Bu sayede düğümler sondan başa doğru güvenli bir şekilde yok edilir.

## Önemli Noktalar
- Recursion için mutlaka bir durma koşulu (base case) tanımlanmalıdır.
- Bellek, düğümler ters sırayla (sondan başa) serbest bırakılır.
- Bu yöntem bellek sızıntılarını (memory leak) önler
