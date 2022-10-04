#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Pessoa{
    char nome[10];
    int idade;
    int telefone;

    struct Pessoa *prox;
    struct Pessoa *ant;
};

void *pBuffer;

struct Pessoa *cabecaPessoa;
struct Pessoa *novaPessoa;
struct Pessoa *ultimaPessoa;
int *tamanhoBuffer;
int *opcao;
int *incrementador;
int *validador;
char *nome;


void menu();
void adicionarPessoa();
void apagarPessoa();
void buscarPessoa();
struct Pessoa *buscarPessoaPorNome();

void listarPessoas();


int main(){
    pBuffer = malloc((sizeof(int) * 4) + (sizeof(char) * 10));
    tamanhoBuffer = pBuffer;
    opcao = pBuffer + sizeof(int);
    incrementador = pBuffer + (sizeof(int) * 2);
    validador = pBuffer + (sizeof(int) * 3);
    nome = pBuffer + (sizeof(int) * 4);
    cabecaPessoa = NULL;

    do{
        menu();
        if(*opcao == 1){
            adicionarPessoa();
        }
        else if(*opcao == 2){
            apagarPessoa();
        }
        else if(*opcao == 3){
            buscarPessoa();
        }
        else if(*opcao == 4){
            listarPessoas();
        }
        else if(*opcao == 5){
            /* tudo que é alocado tem que ter um free */
            /* fazer um teste com um programa com um malloc só sem free para ver se meu dr. memory tá funcionando */

            /* reescrever tudo inglês e pegar esse costume */
        }
        else{
            printf("\nOpcao Invalida!!!\n");
        }

    }while(*opcao != 5);
    

}

void menu(){
    printf("\n\n  MENU:\n1.Adicionar Pessoa.\n2.Excluir Pessoa.\n3.Buscar Pessoa.\n4.Listar Pessoas.\n5.Sair.\n\nEscolha a opcao desejada: ");
    scanf("%d", opcao);
}

void adicionarPessoa(){

    if(cabecaPessoa == NULL){
        cabecaPessoa = malloc(sizeof(struct Pessoa));
        ultimaPessoa = cabecaPessoa;
        ultimaPessoa->prox = NULL;
        ultimaPessoa->ant = NULL;
    }
    else{
        novaPessoa = malloc(sizeof(struct Pessoa));
        novaPessoa->ant = ultimaPessoa;
        ultimaPessoa->prox = novaPessoa;
        ultimaPessoa = novaPessoa;
        ultimaPessoa->prox = NULL;
    }

    printf("\nQual o nome? ");
    scanf("%s", &ultimaPessoa->nome);
    fflush(stdin);

    printf("Qual a idade? ");
    scanf("%d", &ultimaPessoa->idade);
    fflush(stdin);

    printf("Qual o telefone? ");
    scanf("%d", &ultimaPessoa->telefone);
    fflush(stdin);

}

void apagarPessoa(){
    struct Pessoa *pessoaExclusao;
    struct Pessoa *pessoaExclusaoAnt;

    printf("\nNome da Pessoa que sera apagada: ");
    scanf("%s", nome);
    fflush(stdin);

    if(cabecaPessoa == NULL){
        printf("\nNao ha pessoas cadastradas!!!\n");
        return;
    }

    pessoaExclusao = (struct Pessoa *) buscarPessoaPorNome();

    if(pessoaExclusao == NULL){
        printf("\nNao existe usuario cadastrado com esse nome!!!\n");
        return;
    }

    if(pessoaExclusao->ant == NULL){
        free(cabecaPessoa);
        cabecaPessoa = pessoaExclusao->prox;
    }
    else{
        pessoaExclusaoAnt = pessoaExclusao->ant;
        pessoaExclusaoAnt->prox = pessoaExclusao->prox;
        free(pessoaExclusao);
    }

    printf("\nPessoa excluida com sucesso!\n");

}

struct Pessoa *buscarPessoaPorNome(){
    struct Pessoa *ultimaPessoa;
    ultimaPessoa = cabecaPessoa;

    *validador = 0;
    do{
        if((strcmp(ultimaPessoa->nome, nome) == 0)){
            return ultimaPessoa;
        }
        else if((ultimaPessoa->prox) == NULL){
            *validador = 1;
        }
        else{
            ultimaPessoa = ultimaPessoa->prox;
        }
    }while(*validador == 0);

    return NULL;
}

void buscarPessoa(){
    struct Pessoa *pessoaBuscada;

    printf("\nDigite o nome da pessoa que deseja buscar:");
    scanf("%s", nome);

    pessoaBuscada = (struct Pessoa *) buscarPessoaPorNome();

    if(pessoaBuscada == NULL){
        printf("\nPessoa nao existe!!!");
        return;
    }

    printf("\n\nDados da pessoa buscada:");
    printf("\nNome: %s", pessoaBuscada->nome);
    printf("\nIdade: %d", pessoaBuscada->idade);
     printf("\nTelefone: %d", pessoaBuscada->telefone);

}

void listarPessoas(){
    struct Pessoa *ultimaPessoa;
    ultimaPessoa = cabecaPessoa;

    *validador = 0;
    *incrementador = 1;
    do{
        printf("\n\n  Pessoa %d:", *incrementador);
        printf("\nNome: %s", ultimaPessoa->nome);
        printf("\nIdade: %d", ultimaPessoa->idade);
        printf("\nTelefone: %d", ultimaPessoa->telefone);

        if((ultimaPessoa->prox) == NULL){
            *validador = 1;
        }
        else{
            ultimaPessoa = ultimaPessoa->prox;
        }

        *incrementador = *incrementador + 1;
    }while(*validador == 0);

}