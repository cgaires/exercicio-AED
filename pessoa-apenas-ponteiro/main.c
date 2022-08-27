#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int idade;
    int altura;
}Pessoa;

void adicionaPessoa(int *quantidadePessoas);
void lerPessoas(int *quantidadePessoas);

Pessoa pessoas[10];
void *pBuffer;
int *quantidadePessoas;

int main(){
    int *opcao;

    pBuffer = malloc(sizeof(int) * 3);
    opcao = pBuffer;
    quantidadePessoas = pBuffer + sizeof(int);
    *quantidadePessoas = 0;

    do{
        printf("\n    Menu:\n1. Adicionar Pessoa.\n2.Sair e ver listas de pessoas adicionadas.\nEscolha a sua opcao:");
        scanf("%d", opcao);

        if(*opcao == 1){
            adicionaPessoa(quantidadePessoas);
        }
        else if(*opcao == 2){
            lerPessoas(quantidadePessoas);
        }else{
            printf("\n\n    OPCAO INVALIDA!!");
        }

    }while(*opcao != 2);

    return 0;
}

void adicionaPessoa(int *quantidadePessoas){
    if(*quantidadePessoas == 10){
        printf("Número máximo de pessoas!!");
        return;
    }else{
        printf("\nDigite o nome da Pessoa:");
        scanf("%s", &pessoas[*quantidadePessoas].nome);
        printf("Digite a idade da Pessoa:");
        scanf("%d", &pessoas[*quantidadePessoas].idade);
        printf("Digite a altura da Pessoa:");
        scanf("%d", &pessoas[*quantidadePessoas].altura);

        *quantidadePessoas = *quantidadePessoas + 1;
        
    }
}

void lerPessoas(int *quantidadePessoas){
    int *i;
    i = pBuffer + (sizeof(int) * 2);
    *i = 0;
    for(; *i < *quantidadePessoas;){
        printf("\n  Pessoa %d:", *i + 1);
        printf("\nNome:%s", pessoas[*i].nome);
        printf("\nIdade:%d", pessoas[*i].idade);
        printf("\nAltura:%d", pessoas[*i].altura);
        *i = *i + 1;
    }
}


