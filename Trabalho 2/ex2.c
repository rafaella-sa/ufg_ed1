#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha{
    char dado;
    struct pilha *prox;
}pilha;

int estaVazia(pilha *p);
pilha* push(pilha *p, char dado);
pilha* pop(pilha *p);
void imprimir(pilha *p);
int eOperando(char c);
int eOperador (char c);
int obterPrioridade(char c);
char *converterDeInAPos(char infixa[]);

int main(){
    int op = 0;
    char expressao[50];
    pilha *p = NULL;
    do{
        printf("*** MENU ***\n\n1. Converter uma nova expressao\n2. Sair\n\nOpcao selecionada: ");
        scanf("%d", &op);
        switch(op){
            case 1:{
                system("CLS");
                printf("Ingresse a expressao em notacao infixa:\n\n");
                scanf("%s", expressao);
                printf("\nExpressao original (infixa): %s\n", expressao);
                printf("\nExpressao posfixa: %s\n\n", converterDeInAPos(expressao));
                break;
            }
            case 2: {
                system("CLS");
                printf("Saindo...\n");
                break;
            }
            default: {
                printf("\nOpcao invalida!!!\n\n");
                break;
            }
        }
    }while(op!=2);
    return 0;
}

int estaVazia(pilha *p){
    if(p == NULL)
        return 1;
    else
        return 0;
}

pilha* push(pilha *p, char dado){
    pilha *novo, *aux = p;
    if((novo = (pilha*) malloc (sizeof(pilha))) == NULL){
        printf("ERRO!\n");
        exit(1);
    }
    novo->dado = dado;
    novo->prox = NULL;
    if(estaVazia(p)) return novo;
    else{
        novo->prox = aux;
        return novo;
    }
}

pilha* pop(pilha *p){
    if(estaVazia(p)) return p;
    else{
        pilha *aux = p->prox;
        free(p);
        return aux;
    }
}

void imprimir(pilha *p){
    pilha *aux = NULL; int i = 1;
    for(;!estaVazia(p); p = p->prox){
        printf("%d. %d\n", i++, p->dado);
        aux = push(aux, p->dado);
    }
    printf("\n");
    for(;!estaVazia(aux); aux = aux->prox){
        p = push(p, aux->dado);
    }
}

int eOperando(char c){
    return (c != '(' && c != '{' && c != '+' && c != '-' && c != '*' && c != '/' && c != ')' && c != '}');
}

int eOperador (char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int obterPrioridade(char c){
        if(c == '(')
            return 1;
        else if(c == '+' || c == '-')
            return 2;
        else if(c == '*' || c == '/')
            return 3;
        return 0;
}

char *converterDeInAPos(char infixa[]){
    pilha *p = NULL;
    char c, *posfixa;
    if((posfixa = (char*) malloc (sizeof(infixa))) == NULL){
        printf("\nErro de alocacao de memoria.\n");
        return NULL;
    }
    int i, j = 0, prioridade = 0;
    infixa = strlwr(infixa);
    for(i = 0; infixa[i] != '\0'; i++){
        if(eOperando(infixa[i]))
            posfixa[j++] = infixa[i];
        else if (eOperador(infixa[i])){
                prioridade = obterPrioridade(infixa[i]);
                while (!estaVazia(p) && (obterPrioridade(p->dado)) >= prioridade){
                    posfixa[j++] = p->dado;
                    p = pop(p);
                }
                p = push(p, infixa[i]);
            }
        else if(infixa[i] == '(')
            p = push(p, infixa[i]);
        else if(infixa[i] == ')'){
                c = p->dado;
                p = pop(p);
                while(c != '('){
                    posfixa[j++] = c;
                    c = p->dado;
                    p = pop(p);
                }
        }
    }

    while(!estaVazia(p)){
            posfixa[j++] = p->dado;
            p = pop(p);
    }
    posfixa[j] = '\0';
    posfixa = strupr(posfixa);
    return posfixa;
}
