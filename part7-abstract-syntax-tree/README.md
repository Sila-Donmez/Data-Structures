 Abstract Syntax Tree (AST) Examples

Bu bölümde bir ifadenin AST (Abstract Syntax Tree) ile gösterimi yapılmıştır.
Her düğüm bir operatör veya operand olabilir.

## Örnek 1
İfade: a - (b + c * 2)

AST:
      -
     / \
    a   +
       / \
      b   *
         / \
        c   2

**Açıklama:**
- '*' işlemi en yüksek önceliğe sahip, önce çözülür.
- '+' işlemi ikinci öncelik.
- '-' işlemi kök düğümdür.

## Örnek 2
İfade: (x + y) * (z - 1)

AST:
      *
     / \
    +   -
   / \ / \
  x  y z  1

**Not:** AST, derleyici mantığında bir ifadenin ağaç yapısı ile gösterimidir.  
Kod ile traversal veya evaluation yapılabilir.
