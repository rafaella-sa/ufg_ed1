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

matriz* inicianlizaResultante(matriz *c){

    c = (matriz*) malloc(sizeof(matriz));
    c->prox = NULL;
    c->n = 0;
    c->l = 1;
    c->c = 1;

    return c;
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

void preencheMatrizResultate(matriz *a, int lin, int col, int n){

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

        if(a->c < (col+1)){

            a->c = (col+1);
        }

        if(a->l < (lin+1)){

            a->l = (lin+1);
        }
}

void printarMatriz(matriz *c){

    matriz *aux;

    for(aux = c; aux != NULL; aux = aux->prox){

        printf("%d | %d | %d\n", aux->l, aux->c, aux->n);
    }
}

int main(){

    printf("Sobre a matriz esparca A.\n");
    matriz *a = inicializaMatriz(a);

    printf("Sobre a matriz esparca B.\n");
    matriz *b = inicializaMatriz(b);

        if(a->l != b->l || a->c != a->c){

            printf("Não é possivel somar as matrizes, pois elas não tem o mesmo numero de linhas e colunas.\n");
            exit(1);
        }

    int i;
    int vc;

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
        scanf("%d", &vc);

        if(vc != 0){
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
        scanf("%d", &vc);

        if(vc != 0){
            i = b->l*b->c;
        }
    }

    matriz *c = inicianlizaResultante(c);

    matriz *aux1;
    matriz *aux2;

    for(aux1 = a->prox; aux1 != NULL; aux1 = aux1->prox){

        for(aux2 = b->prox; aux2 != NULL; aux2 = aux2->prox){

            if(aux1->l == aux2->l && aux1->c == aux2->c){

                preencheMatrizResultate(c, aux1->l, aux1->c, (aux1->n + aux2->n));
            }
        }
    }

    vc = 0;

    for(aux1 = a->prox; aux1 != NULL; aux1 = aux1->prox){

        vc = 0;

        for(aux2 = c->prox; aux2 != NULL && vc ==0; aux2 = aux2->prox){

            if(aux1->l == aux2->l && aux1->c == aux2->c){

                vc++;
            }
        }

        if(vc == 0){

            preencheMatrizResultate(c, aux1->l, aux1->c, aux1->n);
        }
    }

    for(aux1 = b->prox; aux1 != NULL; aux1 = aux1->prox){

        vc = 0;

        for(aux2 = c->prox; aux2 != NULL && vc ==0; aux2 = aux2->prox){

            if(aux1->l == aux2->l && aux1->c == aux2->c){

                vc++;
            }
        }

        if(vc == 0){

            preencheMatrizResultate(c, aux1->l, aux1->c, aux1->n);
        }
    }

    printarMatriz(c);

return 0;
}
