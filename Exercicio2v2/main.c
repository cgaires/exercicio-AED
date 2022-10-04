#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    struct elementoPilha *elementoAbaixo;
    char caractere[10];
}elementoPilha;

elementoPilha *ultimoDaPilha = NULL;
int quantidadeDeElementos = 0;

void pop(){ //retirar valor do topo
    elementoPilha *novoUltimo;

    novoUltimo = (void *) ultimoDaPilha->elementoAbaixo;
    free(ultimoDaPilha);

    ultimoDaPilha = novoUltimo;
    quantidadeDeElementos--;

}

void push(char *caractere){ //adicionar valor na pilha
    elementoPilha *novoElemento = malloc(sizeof(elementoPilha));

    novoElemento->elementoAbaixo = (void *) ultimoDaPilha;
    strcpy(novoElemento->caractere, caractere);
    
    ultimoDaPilha = novoElemento;

    quantidadeDeElementos ++;
}

void analisar(){
    elementoPilha *novoElemento;
    elementoPilha *ultimoDaNovaPilha = NULL;

    int quantidadeParaAnalise = quantidadeDeElementos / 2;

    float ehImpar = quantidadeDeElementos % 2;

    if(quantidadeParaAnalise == 0){
        printf("Foi digitada apenas uma letra!!");
        return;
    }

    int i = 0;
    for(; i < quantidadeParaAnalise; i++){
        novoElemento = malloc(sizeof(elementoPilha));
        //novoElemento->caractere = ultimoDaPilha->caractere;
        novoElemento->elementoAbaixo = (void *) ultimoDaNovaPilha;
        strcpy(novoElemento->caractere,ultimoDaPilha->caractere);
        ultimoDaNovaPilha = novoElemento;

        pop();
        if(ehImpar > 0){
            pop();
        }
    }

    i = 0;
    int palindromo;
    for(; i<quantidadeParaAnalise; i++){
        if(strcmp(ultimoDaNovaPilha->caractere,ultimoDaPilha->caractere) == 0){
            palindromo = 1;
        }else{
            palindromo = 0;
            break;
        }
    }

    if(palindromo == 0){
        printf("Nao, Palavra nao eh um palindromo!!");
    }
    else if(palindromo == 1){
        printf("Sim, Palavra eh um palindromo!!");

    }
    
}

int main(){
    char caractere[10];

    do{
        printf("Digite uma letra ou x para avaliar se eh um palindromo: ");
        scanf("%c%c", &caractere);
        fflush(stdin);

        if( strcmp(caractere, "x" ) != 0){
            push(caractere);
        }else{
            analisar();
        }
    }while(strcmp(caractere, "x" ) != 0);

    return 0;
}