#include<stdio.h>
#include<stdlib.h>

typedef struct matriz{

    int l;
    int c;
    int n;
    struct matriz *prox;
} matriz;

matriz* inicializaMatriz(matriz *a){
    int t;
    printf("Digite a quantidade de linhas ou colunas da matriz original.\n");
    scanf("%d", &t);

    a = (matriz*) malloc(sizeof(matriz));
    a->prox = NULL;
    a->l = t;
    a->c = t;
    a->n = 0;

    return a;
}

matriz* inicializaMatrizResultante( matriz *c, int lin, int col){
    c = (matriz*) malloc(sizeof(matriz));
    c->prox = NULL;
    c->l = lin;
    c->c = col;
    c->n = 0;
}

void preencheMatriz(matriz *a, int lin, int col, int n){
    matriz *e;

    for(e = a; e->prox != NULL; e = e->prox){
    }

    matriz *r = (matriz*)malloc(sizeof(matriz));
    r->c = col;
    r->l = lin;
    r->n = n;
    r->prox = NULL;

    e->prox = r;
    a->n++;
}

void printarMatriz(matriz *c){

    matriz *aux;

    for(aux = c; aux != NULL; aux = aux->prox){

        printf("%d | %d | %d\n", aux->l, aux->c, aux->n);
    }
}

matriz* procuraA( matriz *a, int aux1, int i){

    matriz *t;

    for( t = a->prox; t != NULL; t = t->prox){

        if( aux1 == t->l && i == t->c){

            return t;
        }
    }

return NULL;
}

matriz* procuraB( matriz *a, int aux2, int i){

    matriz *t;

    for( t = a->prox; t != NULL; t = t->prox){

        if( aux2 == t->c && i == t->l){

            return t;
        }
    }

return NULL;
}

int main(){

    printf("Sobre a matriz esparca A.\n");
    matriz *a = inicializaMatriz(a);

    printf("Sobre a matriz esparca B.\n");
    matriz *b = inicializaMatriz(b);

        if(a->c != b->l){

            printf("Não é possivel multiplicar as matrizes.\n");
            exit(1);
        }

    int i;
    int aux1, aux2;

    for(i = 0; i < (a->l*a->c); i++){

        int lin;
        int col;
        int n;

        printf("Digite o elemento não nulo da matriz A.\n");
        scanf("%d", &n);

        printf("Digite o numero na coluna dele.\n");
        scanf("%d", &col);

        printf("Digite o numero da linha dele.\n");
        scanf("%d", &lin);

        preencheMatriz(a , lin, col, n);

        printf("Digite 0 se desejar adicionar mais um elemento, ou qualquer outro numero se deseja concluir.\n");
        scanf("%d", &aux1);

        if(aux1 != 0){
            i = a->l*a->c;
        }
    }

    for(i = 0; i < (b->l*b->c); i++){

        int lin;
        int col;
        int n;

        printf("Digite o elemento não nulo da matriz B.\n");
        scanf("%d", &n);

        printf("Digite o numero na coluna dele.\n");
        scanf("%d", &col);

        printf("Digite o numero da linha dele.\n");
        scanf("%d", &lin);

        preencheMatriz(b , lin, col, n);

        printf("Digite 0 se desejar adicionar mais um elemento, ou qualquer outro numero se deseja concluir.\n");
        scanf("%d", &aux1);

        if(aux1 != 0){
            i = b->l*b->c;
        }
    }

    int soma;

    matriz *c = inicializaMatrizResultante( c, a->l, b->c);

    for(aux1 = 1; aux1 <= a->l; aux1++){

        for(aux2 = 1; aux2 <= b->c; aux2++){

            soma = 0;

            for(i = 1; i <= a->c; i++){

                matriz *w = procuraA( a, aux1, i);
                matriz *x;

                if( w != NULL){

                    x = procuraB( b, aux2, i);

                    if( x != NULL){

                        soma += w->n * x->n;
                    }
                }
            }

            if( soma != 0){

                preencheMatriz( c, aux1, aux2, soma);
            }
        }
    }
printarMatriz(c);

return 0;
}
