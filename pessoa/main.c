#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[30];
    int idade;
    int altura;
    struct Pessoa *prox;
} Pessoa;

int interacao();
void adicionaPessoa(Pessoa *primeiraPessoa, int *quantidadePessoas);
void lerPessoas(Pessoa *primeiraPessoa, Pessoa *pessoaAtual, int *quantidadePessoas);

Pessoa *pessoaAtual;

int main(){
    int opcao;
    Pessoa *primeiraPessoa;
    primeiraPessoa = (Pessoa *) malloc(sizeof(Pessoa));

    int *quantidadePessoas;
    quantidadePessoas = (int *) malloc(sizeof(int));
    *quantidadePessoas = 0;

    do{
        opcao = interacao();

        if(opcao == 1){
            adicionaPessoa(primeiraPessoa, quantidadePessoas);
        }
        else if(opcao == 2){
            lerPessoas(primeiraPessoa, pessoaAtual, quantidadePessoas);
        }else{
            printf("\n\n    OPCAO INVALIDA!!");
        }
    }while(opcao != 2);

    return 0;
}

int interacao(){
    int opcao;
    printf("\n    Menu:\n1. Adicionar Pessoa.\n2.Sair e ver listas de pessoas adicionadas.\nEscolha a sua opcao:");
    scanf("%d", &opcao);
    return opcao;
}

void adicionaPessoa(Pessoa *primeiraPessoa, int *quantidadePessoas){
    char nome[30];
    int idade;
    int altura;

    Pessoa *novaPessoa;

    if(*quantidadePessoas == 0){
        pessoaAtual = primeiraPessoa;
    }else{
        novaPessoa = (Pessoa *) malloc(sizeof(Pessoa));
        pessoaAtual->prox = novaPessoa;
        pessoaAtual = novaPessoa;
    }

    printf("\nDigite o nome da Pessoa:");
    scanf("%s", &nome);
    printf("Digite a idade da Pessoa:");
    scanf("%d", &idade);
    printf("Digite a altura da Pessoa:");
    scanf("%d", &altura);

    strcpy(pessoaAtual->nome, nome);
    pessoaAtual->idade = idade;
    pessoaAtual->altura = altura;

    pessoaAtual->prox = NULL;
    *quantidadePessoas = *quantidadePessoas + 1;

}

void lerPessoas(Pessoa *primeiraPessoa, Pessoa *pessoaAtual, int *quantidadePessoas){
    pessoaAtual = primeiraPessoa;
    int i = 0;
    for(; i < *quantidadePessoas; i++){
        printf("\n  Pessoa %d:", i+1);
        printf("\nNome:%s", pessoaAtual->nome);
        printf("\nIdade:%d", pessoaAtual->idade);
        printf("\nAltura:%d", pessoaAtual->altura);

        pessoaAtual = primeiraPessoa->prox;
    }
}