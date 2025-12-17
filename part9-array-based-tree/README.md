# Array-Based Tree

Bu bölümde array (dizi) ile bir tree oluşturulmuştur

## Özellikler
- Binary tree
- Array tabanlı temsil
- Ebeveyn ve çocuklar için index ilişkisi

## Dizi ile temsil mantığı
- Root: index 0
- Sol çocuk: 2*i + 1
- Sağ çocuk: 2*i + 2
- Ebeveyn: (i-1)/2 (integer bölme)

## Örnek
Array: [A, B, C, D, E]  

'''
    A
   / \
  B   C
 / \
D   E
'''
