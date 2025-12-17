# Towers of Hanoi

Towers of Hanoi (Hanoi Kuleleri), recursion (özyineleme) mantığını öğretmek için sıkça kullanılan klasik bir algoritma problemidir.

## Problem Tanımı
Üç adet çubuk (A, B, C) ve farklı boyutlarda N adet disk vardır.
Başlangıçta tüm diskler A çubuğu üzerinde, büyükten küçüğe doğru sıralı haldedir.

Amaç, tüm diskleri A çubuğundan C çubuğuna taşımaktır.

## Kurallar
- Aynı anda sadece bir disk taşınabilir.
- Büyük bir disk, küçük bir diskin üzerine konulamaz.
- Taşıma işlemleri kurallara uygun olmalıdır.

## Temel Fikir
Towers of Hanoi problemi recursive olarak çözülür.

Bir diski taşımak için:
1. Üstteki N-1 diski yardımcı çubuğa taşı
2. En büyük diski hedef çubuğa taşı
3. Yardımcı çubuktaki N-1 diski hedef çubuğa taşı

Bu işlem her adımda daha küçük bir problem haline gelir.

## Zaman Karmaşıklığı
Towers of Hanoi probleminin çözümü için gereken minimum hamle sayısı:

2^N - 1
Bu nedenle algoritmanın zaman karmaşıklığı üstel (exponential) seviyededir.
