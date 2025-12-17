# Infix to Postfix (Shunting Yard Algorithm)

Infix gösterimde operatörler operandların arasında bulunur (A + B).
Postfix gösterimde ise operatörler operandlardan sonra gelir (A B +).

Shunting Yard algoritması, infix bir ifadeyi postfix forma dönüştürmek için
bir stack (yığın) kullanır.

## Temel Kurallar
- Operandlar doğrudan çıktıya yazılır.
- Operatörler önceliklerine göre stack’e alınır.
- Parantezler öncelik kontrolü için kullanılır.
- Stack boşaltılarak postfix ifade elde edilir.
