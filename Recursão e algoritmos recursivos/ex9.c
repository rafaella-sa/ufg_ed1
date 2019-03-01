#include <stdio.h>
#include <stdlib.h>

// Exerc�cio 17 (Gustavo)
// Escreva uma fun��o recursiva que calcule a soma dos d�gitos de um inteiro
// positivo n. A soma dos d�gitos de 132, por exemplo, � 6.

// Alexandre C. Rondon
// 22/06/2009

// se n tiver s� um d�gito, a soma dos d�gitos � o pr�prio n
// sen�o, retorna n%10 (que � o �ltimo d�gito) mais a soma dos d�gitos do resto do n�mero
// n-n%10 � o n�mero menos o �ltimo d�gito, ex. 132 - 2 = 130
// dividindo por 10, temos os outros d�gitos: 130/10 = 13
// nesse caso, a fun��o retornar� 2 + soma(13) = 2 + 3 + soma(1) = 2 + 3 + 1 = 6
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
