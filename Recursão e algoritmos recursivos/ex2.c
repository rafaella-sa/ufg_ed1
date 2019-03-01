#include <stdio.h>

int maxi( int n, int v[]) {
   int j, m = v[0];
   for (j = 1; j < n; ++j)
      if (v[j-1] < v[j]) {
        printf("Trocando %d por %d\n", m, v[j]);
        m = v[j];
      }
   return m;
}

int main(){
    int i, n;
    scanf("%d", &n);
    int v[n];
    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);
    printf("%d", maxi(n, v));
    return 0;
}
