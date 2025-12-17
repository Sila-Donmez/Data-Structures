#include <stdio.h>

/*
    Towers of Hanoi recursive çözümü
    n: disk sayısı
    from: başlangıç çubuğu
    to: hedef çubuğu
    aux: yardımcı çubuk
*/

void hanoi(int n, char from, char to, char aux) {
    // Base case
    if (n == 1) {
        printf("Disk 1: %c -> %c\n", from, to);
        return;
    }

    // 1. Üstteki n-1 diski yardımcı çubuğa taşı
    hanoi(n - 1, from, aux, to);

    // 2. En büyük diski hedef çubuğa taşı
    printf("Disk %d: %c -> %c\n", n, from, to);

    // 3. Yardımcı çubuktaki n-1 diski hedef çubuğa taşı
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n = 3; // Disk sayısı

    printf("Towers of Hanoi çözümü (%d disk):\n\n", n);
    hanoi(n, 'A', 'C', 'B');

    return 0;
}
/*
Örnek çıktı:
Disk 1: A -> C
Disk 2: A -> B
Disk 1: C -> B
Disk 3: A -> C
Disk 1: B -> A
Disk 2: B -> C
Disk 1: A -> C

Her çağrıda problem daha küçük bir alt probleme bölünür
Base case: n == 1
Çıktı olarak her disk hareketini yazdırır
*/
