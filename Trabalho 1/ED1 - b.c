#include<stdio.h>
#include<stdlib.h>

//estrutura que define a matriz bidimensional
typedef struct matriz{
    int linhas;
    int colunas;
    int **m;
}matriz;

//funcao que aloca espaco para a matriz bidimensional
matriz* criarMatriz(int linhas, int colunas){
    int i;
    matriz* mat = (matriz*) malloc(sizeof(matriz));
    mat->colunas = colunas;
    mat->linhas = linhas;
    mat->m = (int**) malloc(sizeof(int*) * linhas);
    for(i=0; i<linhas; i++) {
        mat->m[i] = (int*) malloc(colunas * sizeof(int));
    }
    return mat;
}

//funcao que preenche a matriz com zeros
void preencherMatriz(struct matriz* mat){
    int i, j;
    for(i=0; i<mat->linhas; i++) {
        for(j=0; j<mat->colunas; j++) {
            mat->m[i][j] = 0;
        }
    }
}

//funcao que mostra o conteudo da matriz
void imprimirMatriz(struct matriz* mat) {
    int i, j;
    for(i=0; i<mat->linhas; i++) {
        for(j=0; j<mat->colunas; j++) {
            printf("%d  ", mat->m[i][j]);
        }
        printf("\n");
    }
}

//funcao que gera a matriz bidimensional
void insereNaoNulosMatriz(matriz *mat, int n, int q){
    int i, l, c, elem;
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
        mat->m[l-1][c-1] = elem;
        printf("\n\n");
    }
}

//funcao que libera a memoria associada a matriz
void destruirMatriz(matriz* m){
    int i;
    for(i=0; i<m->linhas; i++) {
        free(m->m[i]);
    }
    free(m->m);
    free(m);
}

int main(){
    int n; //dimensao da matriz
    int q; //quantidade de elementos da esparsa

    do{ //recebe a dimensao da matriz
        printf("Digite a dimensao da matriz:\n");
        scanf("%d", &n);
    }while(n<=0); //enquanto for um valor inválido

    //inicializa a matriz com zeros
    matriz* mat = criarMatriz(n, n);
    preencherMatriz(mat);

    do{ //recebe a quantidade de elementos da matriz esparsa
        printf("Digite a quantidade de elementos da matriz esparsa (entre 1 e %d):\n", n*n);
        scanf("%d", &q);
    }while(q>n*n || q <= 1); //enquanto for um valor inválido

    system("CLS");

    insereNaoNulosMatriz(mat, n, q);

    system("CLS");
    printf("A matriz bidimensional equivalente e: \n\n");
    imprimirMatriz(mat);

    return 0;
}


