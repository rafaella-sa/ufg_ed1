/* Este programa testa a fun��o recursiva maximo_r,
// que calcula um elemento m�ximo de um vetor.
/////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
int maximo_r( int n, int v[]);

#define N 10000

int main( void)
{
   int v[N], n, x, i;

   printf( "\nN�mero de elementos: ");
   scanf( "%d", &n);
   if (n < 1 || n > N) {
      printf( "Sequ�ncia vazia ou muito grande\n");
      return EXIT_FAILURE;
   }
   printf( "Elementos:\n");
   for (i = 0; i < n; ++i)
      scanf( "%d", &v[i]);
   x = maximo_r( n, v);
   printf( "m�ximo = %d\n", x);
   return EXIT_SUCCESS;
}

int maximo_r( int n, int v[])
{
   if (n == 1)
      return v[0];
   else {
      int x;
      x = maximo_r( n-1, v);  /* m�ximo de v[0..n-2] */
      if (x > v[n-1])
         return x;
      else
         return v[n-1];
   }
}
