#include <stdio.h>
#include <stdlib.h>
/* Recebe um vetor v e um número n >= 0.
   Devolve a soma dos elementos positivos
   de v[0..n-1].
   -------------------------------------*/

int soma2( int n, int v[]) {
   return soma_r( 0, n, v);
}

/* Recebe v, ini e fim tais que ini < fim.  Devolve o  */
/* valor de um elemento máximo do vetor v[ini..fim-1]. */

int soma_r( int ini, int fim, int v[]) {
   if (ini == fim-1) return v[fim-1];
   else {
      int x;
      x = soma_r( ini + 1, fim, v);
      return x+v[ini];
   }
}
#define N 1000
int main( void)
{
   int v[N], n, x, i;

   printf( "\nNúmero de elementos: ");
   scanf( "%d", &n);
   if (n < 1 || n > N) {
      printf( "Sequência vazia ou muito grande\n");
      return EXIT_FAILURE;
   }
   printf( "Elementos:\n");
   for (i = 0; i < n; ++i)
      scanf( "%d", &v[i]);
   x = soma2(n, v);
   printf( "soma = %d\n", x);
   return EXIT_SUCCESS;
}
