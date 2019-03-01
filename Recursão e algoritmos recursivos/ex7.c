#include <stdio.h>
#include <stdlib.h>
/* Recebe um vetor v e um número n >= 0.
   Devolve a soma dos elementos positivos
   de v[0..n-1].
   -------------------------------------*/

int soma( int v[], int n) {
   if (n == 0)
      return 0;
   else {
      int s;
      s = soma( v, n-1);
      if (v[n-1] > 0) s += v[n-1];
      return s;
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
   x = soma(v, n);
   printf( "soma = %d\n", x);
   return EXIT_SUCCESS;
}
