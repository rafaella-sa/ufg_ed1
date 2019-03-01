#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
#define O 5 //ordem 5

struct no{
    int n; //n < O; Número de chaves no nó vai ser sempre menor que a ordem da árvore B
    int chaves[O-1]; /*vetor de chaves*/
    struct no *p[O]; /* (n+1 ponteiros serao usados) */
}*raiz=NULL;

//enumeracao para mostrar o estado atual da chave
enum statusdachave { Duplicado,FalhaNaBusca,Sucesso,Insercao,ChavesMenores };

void inserir(int key);
void imprimir(struct no *raiz,int);
void remover(int x);
void buscar(int x);
enum statusdachave ins(struct no *r, int x, int* y, struct no** u);
int buscarPos(int x,int *vet_chave, int n);
enum statusdachave rem(struct no *r, int x);

int main() {
    int chave, opcao;
    printf("Criacao de uma arvore B de ordem %d\n",O);
    while(1){
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Buscar\n");
        printf("4. Imprimir\n");
        printf("5. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                printf("Ingresse a chave: ");
                scanf("%d",&chave);
                inserir(chave);
                break;
            case 2:
                printf("Ingresse a chave: ");
                scanf("%d",&chave);
                remover(chave);
                break;
            case 3:
                printf("Ingresse a chave: ");
                scanf("%d",&chave);
                buscar(chave);
                break;
            case 4:
                printf("A arvore B e:\n");
                imprimir(raiz,0);
                break;
            case 5:
                exit(1);
            default:
                printf("OPCAO INVALIDA!!!\n");
                break;
        }/*fim do switch*/
    }/*fim do while*/
    return 0;
}/*fim do main()*/

void inserir(int chave) {
    struct no *novoNo;
    int chaveNova;
    enum statusdachave valor;
    valor = ins(raiz, chave, &chaveNova, &novoNo);
    if (valor == Duplicado)
        printf("Chave ja inserida! \n");
    if (valor == Insercao){
        struct no *novaraiz = raiz;
        raiz=malloc(sizeof(struct no));
        raiz->n = 1;
        raiz->chaves[0] = chaveNova;
        raiz->p[0] = novaraiz;
        raiz->p[1] = novoNo;
    }/*fim do if */
}/*fim do inserir()*/

enum statusdachave ins(struct no *ptr, int chave, int *chaveacima ,struct no
**novoNo){
    struct no *novoptr, *ultimoptr;
    int pos, i, n, dividirpos;
    int novaChave, ultimaChave;
    enum statusdachave valor;
    if (ptr == NULL){
        *novoNo = NULL;
        *chaveacima = chave;
        return Insercao;
    }
    n = ptr->n;
    pos = buscarPos(chave, ptr->chaves, n);
    if (pos < n && chave == ptr->chaves[pos])
        return Duplicado;
    valor = ins(ptr->p[pos], chave, &novaChave, &novoptr);
    if (valor != Insercao)
        return valor;
        //Se as chaves no nó sao menos que O-1 onde O é a ordem da árvore B
        if (n < O - 1){
            pos = buscarPos(novaChave, ptr->chaves, n);
            /*deslocando a chave e o ponteiro direito para inserir a nova chave*/
            for (i=n; i>pos; i--){
                ptr->chaves[i] = ptr->chaves[i-1];
                ptr->p[i+1] = ptr->p[i];
            }
            /*chave é inserida no local exato*/
            ptr->chaves[pos] = novaChave;
            ptr->p[pos+1] = novoptr;
            ++ptr->n; /*incrementando o número de chaves no nó*/
            return Sucesso;
        }/*fim do if */
    /*Se as chaves no nó sao mazimas e a posicao do nó a ser inserido é a última*/
    if (pos == O - 1){
        ultimaChave = novaChave;
        ultimoptr = novoptr;
    }
    else{/*Se as chaves no nó sao máximas e a posicao do nó a ser inserido nao é a última */
        ultimaChave = ptr->chaves[O-2];
        ultimoptr = ptr->p[O-1];
        for (i=O-2; i>pos; i--){
            ptr->chaves[i] = ptr->chaves[i-1];
            ptr->p[i+1] = ptr->p[i];
        }
        ptr->chaves[pos] = novaChave;
        ptr->p[pos+1] = novoptr;
    }
    dividirpos = (O - 1)/2;
    (*chaveacima) = ptr->chaves[dividirpos];
    (*novoNo)=malloc(sizeof(struct no));/*no direito depois da divisao*/
    ptr->n = dividirpos; /*Número de chaves para o nó esquerdo dividido*/
    (*novoNo)->n = O-1-dividirpos;/*Número de chaves para o nó direito dividido*/
    for (i=0; i < (*novoNo)->n; i++){
        (*novoNo)->p[i] = ptr->p[i + dividirpos + 1];
        if(i < (*novoNo)->n - 1)
            (*novoNo)->chaves[i] = ptr->chaves[i + dividirpos + 1];
        else
            (*novoNo)->chaves[i] = ultimaChave;
    }
    (*novoNo)->p[(*novoNo)->n] = ultimoptr;
    return Insercao;
}/*fim de ins()*/

void imprimir(struct no *ptr, int espacos){
    if (ptr){
        int i;
        for(i=1;i<=espacos;i++)
            printf(" ");
        for (i=0; i < ptr->n; i++)
            printf("%d ",ptr->chaves[i]);
        printf("\n");
        for (i=0; i <= ptr->n; i++)
            imprimir(ptr->p[i], espacos+10);
    }/*fim do if*/
}/*fim do imprimir()*/

void buscar(int chave){
    int pos, i, n;
    struct no *ptr = raiz;
    printf("Caminho da busca:\n");
    while (ptr){
        n = ptr->n;
        for (i=0; i < ptr->n; i++)
            printf(" %d",ptr->chaves[i]);
        printf("\n");
        pos = buscarPos(chave, ptr->chaves, n);
        if (pos < n && chave == ptr->chaves[pos]){
            printf("Chave %d encontrada na posicao %d do ultimo no mostrado\n",chave,i);
            return;
        }
        ptr = ptr->p[pos];
    }
    printf("Chave %d nao esta disponivel\n",chave);
}/*fim do buscar()*/

int buscarPos(int chave, int *vet_chave, int n){
    int pos=0;
    while (pos < n && chave > vet_chave[pos])
    pos++;
    return pos;
}/*fim do buscarPos()*/

void remover(int chave){
    struct no *raizacima;
    enum statusdachave valor;
    valor = rem(raiz,chave);
    switch (valor){
        case FalhaNaBusca:
            printf("Chave %d nao esta disponivel\n",chave);
            break;
        case ChavesMenores:
            raizacima = raiz;
            raiz = raiz->p[0];
            free(raizacima);
            break;
    }/*fim do switch*/
}/*fim do remover()*/

enum statusdachave rem(struct no *ptr, int chave){
    int pos, i, pivo, n ,min;
    int *vet_chave;
    enum statusdachave valor;
    struct no **p,*ptr_esq,*ptr_dir;
    if (ptr == NULL)
        return FalhaNaBusca;
    /*atribuir valores do no*/
    n=ptr->n;
    vet_chave = ptr->chaves;
    p = ptr->p;
    min = (O - 1)/2;/*numero minimo de chaves*/
    pos = buscarPos(chave, vet_chave, n);
    if (p[0] == NULL){
        if (pos == n || chave < vet_chave[pos])
            return FalhaNaBusca;
        /*reorganizar pelo lado esquerdo*/
        for (i=pos+1; i < n; i++){
            vet_chave[i-1] = vet_chave[i];
            p[i] = p[i+1];
        }
        return --ptr->n >= (ptr==raiz ? 1 : min) ? Sucesso : ChavesMenores;
    }/*fim do if */
    if (pos < n && chave == vet_chave[pos]){
        struct no *qp = p[pos], *qp1;
        int nchave;
        while(1){
            nchave = qp->n;
            qp1 = qp->p[nchave];
            if (qp1 == NULL)
                break;
            qp = qp1;
        }/*fim do while*/
        vet_chave[pos] = qp->chaves[nchave-1];
        qp->chaves[nchave - 1] = chave;
    }/*fim do if */
    valor = rem(p[pos], chave);
    if (valor != ChavesMenores)
        return valor;
    if (pos > 0 && p[pos-1]->n > min){
        pivo = pos - 1; /*pivo para no esquerdo e direito*/
        ptr_esq = p[pivo];
        ptr_dir = p[pos];
        /*atribui valores ao no direito*/
        ptr_dir->p[ptr_dir->n + 1] = ptr_dir->p[ptr_dir->n];
        for (i=ptr_dir->n; i>0; i--){
            ptr_dir->chaves[i] = ptr_dir->chaves[i-1];
            ptr_dir->p[i] = ptr_dir->p[i-1];
        }
        ptr_dir->n++;
        ptr_dir->chaves[0] = vet_chave[pivo];
        ptr_dir->p[0] = ptr_esq->p[ptr_esq->n];
        vet_chave[pivo] = ptr_esq->chaves[--ptr_esq->n];
        return Sucesso;
    }/*fim do if */
    if (pos > min){
        pivo = pos; /*pivo para o no esquerdo e direito*/
        ptr_esq= p[pivo];
        ptr_dir = p[pivo+1];
        /*atribui valores para o no esquerdo*/
        ptr_esq->chaves[ptr_esq->n] = vet_chave[pivo];
        ptr_esq->p[ptr_esq->n + 1] = ptr_dir->p[0];
        vet_chave[pivo] = ptr_dir->chaves[0];
        ptr_esq->n++;
        ptr_dir->n--;
        for (i=0; i < ptr_dir->n; i++){
            ptr_dir->chaves[i] = ptr_dir->chaves[i+1];
            ptr_dir->p[i] = ptr_dir->p[i+1];
        }/*fim do for*/
        ptr_dir->p[ptr_dir->n] = ptr_dir->p[ptr_dir->n + 1];
        return Sucesso;
    }/*fim do if */
    if(pos == n)
        pivo = pos-1;
    else
        pivo = pos;
    ptr_esq = p[pivo];
    ptr_dir = p[pivo+1];
    /*troca no esquerdo com no direito*/
    ptr_esq->chaves[ptr_esq->n] = vet_chave[pivo];
    ptr_esq->p[ptr_dir->n + 1] = ptr_dir->p[0];
    for (i=0; i < ptr_dir->n; i++){
        ptr_esq->chaves[ptr_esq->n + 1 + i] = ptr_dir->chaves[i];
        ptr_esq->p[ptr_esq->n + 2 + i] = ptr_dir->p[i+1];
    }
    ptr_esq->n = ptr_esq->n + ptr_dir->n +1;
    free(ptr_dir); /*remove o no direito*/
    for (i=pos+1; i < n; i++){
        vet_chave[i-1] = vet_chave[i];
        p[i] = p[i+1];
    }
    return --ptr->n >= (ptr == raiz ? 1 : min) ? Sucesso : ChavesMenores;
}/*fim do rem()*/
