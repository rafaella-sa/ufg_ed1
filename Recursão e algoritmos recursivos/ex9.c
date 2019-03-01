#include <stdio.h>
#include <stdlib.h>

// Exercício 17 (Gustavo)
// Escreva uma função recursiva que calcule a soma dos dígitos de um inteiro
// positivo n. A soma dos dígitos de 132, por exemplo, é 6.

// Alexandre C. Rondon
// 22/06/2009

// se n tiver só um dígito, a soma dos dígitos é o próprio n
// senão, retorna n%10 (que é o último dígito) mais a soma dos dígitos do resto do número
// n-n%10 é o número menos o último dígito, ex. 132 - 2 = 130
// dividindo por 10, temos os outros dígitos: 130/10 = 13
// nesse caso, a função retornará 2 + soma(13) = 2 + 3 + soma(1) = 2 + 3 + 1 = 6
int soma (int n) {
   if (n < 10) return n;
   return n%10 + soma((n-n%10)/10);
}

int main() {
   int n;
   printf("Digite um numero: ");
   scanf("%d",&n);
   printf("A soma dos digitos eh %d.",soma(n));
   getch();
}
