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
    p->vet[0] = l;
    p->vet[1] = c;
    p->vet[2] = naonulo;
    j->prox = p;
    ++e->vet[2];
}

//funcao que gera a transposta a partir da esparsa
void criarTransposta(esparsa *e){
    esparsa *r = e;
    int aux;
    for(;r != NULL; r = r->prox){
        aux = r->vet[0];
        r->vet[0] = r->vet[1];
        r->vet[1] = aux;
    }
}
//imprime a matriz esparsa
void mostrarEsparsa(esparsa *e){
    esparsa *j;
    for(j = e; j != NULL; j = j->prox){
        printf("%d | %d | %d\n", j->vet[0], j->vet[1], j->vet[2]);
    }
}

int main(){
    int i; //variavel de controle
    int q; //quantidade de elementos da matriz esparsa
    int n; //dimensao da matriz
    int l; //linhas da matriz
    int c; //colunas da matriz
    int elem; //elemento da matriz
    esparsa *e;

    do{ //recebe a dimensao da matriz
        printf("Digite a dimensao da matriz:\n");
        scanf("%d", &n);
    }while(n<=0); //enquanto for um valor inválido

    do{ //recebe a quantidade de elementos da matriz esparsa
        printf("Digite a quantidade de elementos da matriz esparsa (entre 1 e %d):\n", n*n);
        scanf("%d", &q);
    }while(q>n*n || q <= 1); //enquanto for um valor inválido

    e = inicializaEsparsa(e,n);
    system("CLS");

    for(i = 1; i <= q; i++){
        printf("Digite o elemento %d para a matriz esparsa:\n", i);
        scanf("%d", &elem);
        do{
            printf("Digite a linha correspondente (entre 1 e %d):\n", n);
            scanf("%d", &l);
        }while(l<=0 || l > n);
        do{
            printf("Digite a coluna correspondente (entre 1 e %d):\n", n);
            scanf("%d", &c);
        }while(c<=0 || c > n);
        insereNaoNuloEsparsa(e, l, c, elem);
    }

    system("CLS");
    criarTransposta(e);
    printf("A matriz esparsa transposta equivalente e: \n\n");
    mostrarEsparsa(e);
    return 0;
}
