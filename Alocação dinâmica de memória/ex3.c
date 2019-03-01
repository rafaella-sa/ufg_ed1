#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n;
    scanf("%d", &n);
    int *vet = (int*) malloc (n*sizeof(int));
    //int vet[n];
    for(i = 0; i < n; i++){
        scanf("%d", &vet[i]);
        //scanf("%d", *(vet+i));
    }
    for(i = n-1; i >= 0; i--){
        printf("%d ", vet[i]);
    }
    free(vet);
    return 0;
}
