#include <stdio.h>
#include <limits.h>

void maxmin(int n, int v[], int max, int min){
   if (n == 1){
    max = v[0];
    min = v[0];
   }

   else {
      maxmin( n-1, v, max, min);  /* máximo/mínimo de v[0..n-2] */
      if (min > v[n-1])
         min = v[n-1];
        if(max < v[n-1])
        max = v[n-1];
   }
   printf("Maior: %d\nMenor: %d\n", max, min);
}

int main(){
    int i, n;
    scanf("%d", &n);
    int v[n];
    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);
    maxmin(n, v, v[0], v[0]);
    return 0;
}
