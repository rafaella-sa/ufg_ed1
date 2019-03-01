/* Este programa testa a função recursiva maximo_r,
// que procura um elemento máximo de um vetor.
/////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
int maximo_r( int n, int v[]);
int confere( int x, int n, int v[]);

#define N 50

int main( void)
{
   int v[N], n, x, i;

   printf( "\nNúmero de elementos: ");
   scanf( "%d", &n);
   if (n < 1 || n > N) {
      printf( "Sequência vazia ou muito grande\n");
      return EXIT_FAILURE;
   }
   for (i = 0; i < n; ++i)
      v[i] = rand( );
   for (i = 0; i < n && i < 20; ++i)
      printf( "%11d\n", v[i]);
   if (n > 20) printf( "      . . .\n");
   x = maximo_r( n, v);
   printf( "máximo =\n%11d\n", x);
   if (confere( x, n, v) == 1)
      return EXIT_SUCCESS;
   printf( "Alguma coisa está errada!\n");
   return EXIT_FAILURE;
}


/* Ao receber v e n >= 1, esta função devolve
// o valor de um elemento máximo de v[0..n-1].
*/
int maximo_r( int n, int v[])
{
   if (n == 1)
      return v[0];
   else {
      int x;
      x = maximo_r( n-1, v);
      if (x > v[n-1])
         return x;
      else
         return v[n-1];
   }
}


/* Esta função confere o resultado da função maximo_r.
// É claro que só vou usar a função durante os testes;
// depois que tiver confiança em maximo_r, vou eliminar
// essa função.
//
// Se x é o valor de um elemento máximo de v[0..n-1]
// esta função devolve 1. Senão, devolve 0.
*/
int confere( int x, int n, int v[])
{
   int i, bandeira;

   bandeira = 0;
   for (i = 0; i < n; ++i) {
      if (v[i] > x) return 0;
      if (v[i] == x) bandeira = 1;
   }
   return bandeira;
}
