#include<stdio.h>
#include<stdlib.h>

//estrutura dos elementos da matriz esparsa
typedef struct esparsa{
    int vet[3];
    struct esparsa *prox;
} esparsa;

//funcao que inicializa a matriz esparsa
esparsa* inicializaEsparsa(esparsa *e, int n){
    e = (esparsa*) malloc(sizeof(esparsa));
    e->prox = NULL;
    e->vet[0] = n;
    e->vet[1] = n;
    e->vet[2] = 0;
    return e;
}

//funcao que insere um elemento na lista da matriz esparsa
void insereNaoNuloEsparsa(esparsa *e, int l, int c, int naonulo){
    esparsa *j;
    for(j = e; j->prox != NULL; j = j->prox);
    esparsa *p = (esparsa*) malloc(sizeof(esparsa));
    p->prox = NULL;
    p->vet[0] = ++l;
    p->vet[1] = ++c;
    p->vet[2] = naonulo;
    j->prox = p;
    ++e->vet[2];
}

//imprime a matriz esparsa
void mostrarEsparsa(esparsa *e){
    esparsa *j;
    for(j = e; j != NULL; j = j->prox){
        printf("%d | %d | %d\n", j->vet[0], j->vet[1], j->vet[2]);
    }
}

int main(){
    int n; //dimensao da matriz
    int l; //linhas da matriz
    int c; //colunas da matriz
    esparsa *e;

    do{ //recebe a dimensao da matriz
        printf("Digite a dimensao da matriz:\n");
        scanf("%d", &n);
    }while(n<=0); //enquanto for um valor inválido

    int M[n][n]; //matriz em seu estado normal
    e = inicializaEsparsa(e,n);
    system("CLS");

    for(l = 0; l < n; l++){
        for(c = 0; c < n; c++){
            printf("Digite o elemento M(%d, %d) para a matriz:\n", l+1, c+1);
            scanf("%d", &M[l][c]);
            if(M[l][c] != 0){
                insereNaoNuloEsparsa(e, l, c, M[l][c]);
            }
        }
    }
    system("CLS");
    printf("A matriz esparsa equivalente e: \n\n");
    mostrarEsparsa(e);
    return 0;
}
