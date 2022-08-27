#include <stdio.h>
#include <stdlib.h>

void menu();
void imprimeNumeros();

int opcao;
void *pBuffer;
int quantidadeNumeros = 0;
int tamanhoBuffer = 0;

int main(){
    do{
        menu();
        if( opcao == 1){
            char *charInteiro;
            int *inteiro;
            if(quantidadeNumeros == 0){
                pBuffer = malloc(sizeof(char) + sizeof(int));
                charInteiro = pBuffer;
                inteiro = pBuffer + sizeof(char);
                tamanhoBuffer = tamanhoBuffer + 5;
            }
            else{
                pBuffer = realloc(pBuffer, tamanhoBuffer + sizeof(char) + sizeof(int));
                charInteiro = pBuffer + tamanhoBuffer;
                inteiro = pBuffer + tamanhoBuffer + sizeof(char);
                tamanhoBuffer = tamanhoBuffer + 5;
            }

            printf("\nEntre com o numero inteiro:");
            scanf("%d", inteiro);
            *charInteiro = 'd';
            quantidadeNumeros = quantidadeNumeros + 1;

        }
        else if( opcao == 2){
            char *charFlutuante;
            int *flutuante;
            if(quantidadeNumeros == 0){
                pBuffer = malloc(sizeof(char) + sizeof(float));
                charFlutuante = pBuffer;
                flutuante = pBuffer + sizeof(char);
                tamanhoBuffer = tamanhoBuffer + 5;
            }
            else{
                pBuffer = realloc(pBuffer, tamanhoBuffer + sizeof(char) + sizeof(float));
                charFlutuante = pBuffer + tamanhoBuffer;
                flutuante = pBuffer + tamanhoBuffer + sizeof(char);
                tamanhoBuffer = tamanhoBuffer + 5;
            }

            printf("\nEntre com o numero flutuante:");
            scanf("%f", flutuante);
            *charFlutuante = 'f';
            quantidadeNumeros = quantidadeNumeros + 1;

        }
        else if( opcao == 3){
            char *charDobro;
            double *dobro;
            if(quantidadeNumeros == 0){
                pBuffer = malloc(sizeof(char) + sizeof(double));
                charDobro = pBuffer;
                dobro = pBuffer + sizeof(char);
                tamanhoBuffer = tamanhoBuffer + 9;
            }
            else{
                pBuffer = realloc(pBuffer, tamanhoBuffer + sizeof(char) + sizeof(double));
                charDobro = pBuffer + tamanhoBuffer;
                dobro = pBuffer + tamanhoBuffer + sizeof(char);
                tamanhoBuffer = tamanhoBuffer + 9;
            }

            printf("\nEntre com o numero double:");
            scanf("%lf", dobro);
            *charDobro = 'D';
            quantidadeNumeros = quantidadeNumeros + 1;

        }
        else if( opcao == 4){
            imprimeNumeros();


        }
        else{
            printf("\nOPCAO INVALIDA!!!");
        }
    }while(opcao != 4);

    return 0;
}

void menu(){
    printf("    Qual o tipo de numero deseja gravar?\n1. INT\n2. FLOAT\n3. DOUBLE\n4. SAIR E MOSTRAR NUMEROS\nOPCAO:");
    scanf("%d", &opcao);
}

void imprimeNumeros(){
    void *leitor;
    leitor = pBuffer;
    
    char *caractere;
    caractere = pBuffer;

    int *inteiro;
    float *flutuante;
    double *dobro;

    if( quantidadeNumeros == 0){
        printf("NAO HA NUMEROS CADASTRADOS");
        return;
    }
    else{
        printf("\nSEQUENCIA DOS NUMEROS CADASTRADOS:\n");
        int i = 0;
        for(; i < quantidadeNumeros; i++){
            if(*caractere == 'd'){
                inteiro = leitor + sizeof(char);
                printf("\n%d", *inteiro);

                leitor = leitor + sizeof(char) + sizeof(int);
                caractere = leitor;

            }
            else if(*caractere == 'f'){
                flutuante = leitor + sizeof(char);
                printf("\n%f", *flutuante);

                leitor = leitor + sizeof(char) + sizeof(float);
                caractere = leitor;

            }
            else if(*caractere == 'D'){
                dobro = leitor + sizeof(char);
                printf("\n%lf", *dobro);

                leitor = leitor + sizeof(char) + sizeof(double);
                caractere = leitor;
            }
        }
    }

}