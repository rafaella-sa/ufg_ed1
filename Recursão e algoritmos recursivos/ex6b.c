/* Este programa testa a fun��o recursiva maximo_r,
// que procura um elemento m�ximo de um vetor.
/////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
int maximo_r( int n, int v[]);
int confere( int x, int n, int v[]);

#define N 50

int main( void)
{
   int v[N], n, x, i;

   printf( "\nN�mero de elementos: ");
   scanf( "%d", &n);
   if (n < 1 || n > N) {
      printf( "Sequ�ncia vazia ou muito grande\n");
      return EXIT_FAILURE;
   }
   for (i = 0; i < n; ++i)
      v[i] = rand( );
   for (i = 0; i < n && i < 20; ++i)
      printf( "%11d\n", v[i]);
   if (n > 20) printf( "      . . .\n");
   x = maximo_r( n, v);
   printf( "m�ximo =\n%11d\n", x);
   if (confere( x, n, v) == 1)
      return EXIT_SUCCESS;
   printf( "Alguma coisa est� errada!\n");
   return EXIT_FAILURE;
}


/* Ao receber v e n >= 1, esta fun��o devolve
// o valor de um elemento m�ximo de v[0..n-1].
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


/* Esta fun��o confere o resultado da fun��o maximo_r.
// � claro que s� vou usar a fun��o durante os testes;
// depois que tiver confian�a em maximo_r, vou eliminar
// essa fun��o.
//
// Se x � o valor de um elemento m�ximo de v[0..n-1]
// esta fun��o devolve 1. Sen�o, devolve 0.
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
