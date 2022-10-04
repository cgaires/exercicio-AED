#include <stdio.h>
#include <stdlib.h>

/*
int main(){
    int *CabecaPessoa;
    int *NovaPessoa;

    NovaPessoa = malloc(sizeof(int));
    CabecaPessoa = NovaPessoa;

    int **prox;

    // endereço do ponteiro para ponteiro
    *prox = CabecaPessoa; //endereço do
    **prox = 5;

    printf("%d", *NovaPessoa);


    return 0;
}
*/

/*
int main(){
    int numero = 3;
    // valor: numero        ;  endereço: &numero
    // valor guarda um int  ;  endereço: guarda um endereço para um int;
    int *ponteiroParaNumero = &numero;
    // valor: ponteiroParaNumero  valor armazenado *ponteiroParaNumero   ;        endereço: &ponteiroParaNumero    ;
    // valor guarda um endereço para um int  ;  endereço: guarda um endereço para um ponteiro para um int

    int **ponteiroParaPonteiroNumero = &ponteiroParaNumero;
    // valor: ponteiroParaPonteiroNumero                ; endereço: &ponteiroParaPonteiroNumero
    // guarda um endereço para um ponteiro para um int ;  endereço: guarda um endereço para um ponteiro de ponteiro para um ponteiro para um int

    // ponteiroParaPonteiroNumero == &ponteiroParaNumero;  **ponteiroParaPonteiroNumero == *ponteiroParaNumero
    
    printf("%d\n", ponteiroParaPonteiroNumero);
    printf("%d\n\n", &ponteiroParaNumero);

    printf("%d\n", *ponteiroParaPonteiroNumero);
    printf("%d\n\n", &numero);

    printf("%d\n", **ponteiroParaPonteiroNumero);
    printf("%d\n\n", numero);
    

    return 0;
}
*/

/*
int main(){
    const TAMANHO_TESTE = sizeof(void **) + sizeof(int) + sizeof(void **);

    void *cabeca;
    void **nova;
    void *prox;

    printf("%d", sizeof(void *));  //o tamanho de um ponteiro void é 4

    nova = malloc(sizeof(prox));

    prox = *nova;

    // printf("%d", *nova); não pode pq não tem nada dentro de *nova



    return 0;
}
*/

/*
const TAMANHO_TESTE = sizeof(int) + sizeof(int) + sizeof(int);
    void *nova;
    void *ultima;
    int *prox;
    int *anterior;
int main(){
    nova = malloc(TAMANHO_TESTE);
    ultima = nova;
    anterior = nova;
    *anterior = NULL;

    if(*anterior == NULL){
        printf("deu certo");
    }


    return 0;
}
*/

int main(){
    int i;
int vetor[8];

for(i=0; i<8; i++) {
    vetor[i] = 0;
}
/*
for(i=0; i<8; i++) {
    printf("%d\n", vetor[i]);
}
*/
for(i=0; i<8; i++) {
if(i%2==0)
vetor[i] = i * 2;
else
vetor[i] = vetor[i] + vetor[i-1];
}

for(i=0; i<8; i++) {
    printf("%d\n", vetor[i]);
}

}