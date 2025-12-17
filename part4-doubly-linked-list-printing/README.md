# Doubly Linked List (Recursive & Non-Recursive)

Bu bölümde çift yönlü bağlı liste (doubly linked list) yapısı kullanılarak
elemanların hem recursive hem de non-recursive (iterative) şekilde yazdırılması gösterilmiştir.

## Açıklama
Her düğüm bir önceki (`prev`) ve bir sonraki (`next`) düğümün adresini tutar.
Non-recursive yazdırma while döngüsü ile yapılırken,
recursive yazdırmada fonksiyon kendisini bir sonraki düğüm için çağırır.

## Önemli Noktalar
- Recursive yaklaşımda bir durma koşulu (NULL) gereklidir.
- Non-recursive yaklaşım daha az bellek kullanır.
- Liste sonunda bellek sızıntısını önlemek için tüm düğümler serbest bırakılmıştır.
