#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void *primeiraPessoa = NULL; // igual a cabeça da lista

void *tempPessoa;

int *tempPessoaIdade;
int *tempPessoaTelefone;
int *tempPessoaProximo;
int *tempPessoaAnterior;
char *tempPessoaNome;

const TAMANHO_PESSOA = (sizeof(int) * 4) + (sizeof(char) * 10);

void *pBuffer;

int *opcao;
int *incrementador;
int *validador;
char *nome;

void menu();
void adicionarPessoa();
void apagarPessoa();
void buscarPessoa();
void *buscarPessoaPorNome();
void listarPessoas();
void limparLista();

int main()
{
    pBuffer = malloc((sizeof(int) * 3) + (sizeof(char) * 10));
    validador = pBuffer;
    opcao = pBuffer + sizeof(int);
    incrementador = pBuffer + (sizeof(int) * 2);
    nome = pBuffer + (sizeof(int) * 3);

    do
    {
        menu();
        if (*opcao == 1)
        {
            adicionarPessoa();
        }
        else if (*opcao == 2)
        {
            apagarPessoa();
        }
        else if (*opcao == 3)
        {
            buscarPessoa();
        }
        else if (*opcao == 4)
        {
            listarPessoas();
        }
        else if (*opcao == 5)
        {
            limparLista();
        }
        else
        {
            printf("\nOpcao Invalida!!!\n");
        }

    } while (*opcao != 5);
}

void menu()
{
    printf("\n\n  MENU:\n1.Adicionar Pessoa.\n2.Excluir Pessoa.\n3.Buscar Pessoa.\n4.Listar Pessoas.\n5.Sair.\n\nEscolha a opcao desejada: ");
    scanf("%d", opcao);
}

void adicionarPessoa()
{
    void *novaPessoa = malloc(sizeof(TAMANHO_PESSOA));

    int *novaPessoaIdade = novaPessoa;
    int *novaPessoaTelefone = novaPessoa + sizeof(int);
    int *novaPessoaProximo = novaPessoa + (sizeof(int) * 2);
    int *novaPessoaAnterior = novaPessoa + (sizeof(int) * 3);
    char *novaPessoaNome = novaPessoa + (sizeof(int) * 4);

    printf("\nQual o nome? ");
    scanf("%s", novaPessoaNome);
    fflush(stdin);

    printf("Qual a idade? ");
    scanf("%d", novaPessoaIdade);
    fflush(stdin);

    printf("Qual o telefone? ");
    scanf("%d", novaPessoaTelefone);
    fflush(stdin);

    if (primeiraPessoa == NULL)
    {
        primeiraPessoa = novaPessoa;

        *novaPessoaAnterior = (int) NULL;
        *novaPessoaProximo = (int) NULL;
    }
    else
    {
        tempPessoa = primeiraPessoa;
        tempPessoaIdade = tempPessoa;
        tempPessoaTelefone = tempPessoa + sizeof(int);
        tempPessoaProximo = tempPessoa + (sizeof(int) * 2);
        tempPessoaAnterior = tempPessoa + (sizeof(int) * 3);
        tempPessoaNome = tempPessoa + (sizeof(int) * 4);

        do{
            if(*novaPessoaIdade >= *tempPessoaIdade){
                if(*tempPessoaProximo != (int) NULL){
                    tempPessoa = (void *) *tempPessoaProximo;
                    tempPessoaIdade = tempPessoa;
                    tempPessoaTelefone = tempPessoa + sizeof(int);
                    tempPessoaProximo = tempPessoa + (sizeof(int) * 2);
                    tempPessoaAnterior = tempPessoa + (sizeof(int) * 3);
                    tempPessoaNome = tempPessoa + (sizeof(int) * 4);
                }else{
                    //adicionarDepoisDaUltimaPessoa
                    *tempPessoaProximo = (int) novaPessoa;
                    *novaPessoaAnterior = (int) tempPessoa;
                    *novaPessoaProximo = (int) NULL;
                    break;
                }
            }
            else if(*novaPessoaIdade < *tempPessoaIdade){
                if(tempPessoa == primeiraPessoa){
                    //adicionarAntesDaPrimeiraPessoa
                    *tempPessoaAnterior = (int) novaPessoa;
                    *novaPessoaAnterior = (int) NULL;
                    *novaPessoaProximo = (int) tempPessoa;

                    primeiraPessoa = novaPessoa;
                    break;
                }
                else{
                    //adicionarEntrePessoas (tempPessoa é a próxima)
                    void *pessoaElementoAnterior;
                    int *pessoaElementoAnteriorProximo;
                    pessoaElementoAnterior = (void *) *tempPessoaAnterior;
                    pessoaElementoAnteriorProximo = pessoaElementoAnterior + (sizeof(int) * 2);

                    *pessoaElementoAnteriorProximo = (int) novaPessoa;
                    *novaPessoaAnterior = (int) pessoaElementoAnterior;
                    *novaPessoaProximo = (int) tempPessoa;
                    *tempPessoaAnterior = (int) novaPessoa;

                    break;
                }
            }
        }while(true);
    }
}

void apagarPessoa()
{
    if (primeiraPessoa == NULL)
    {
        printf("\nNao ha pessoas cadastradas!!!\n");
        return;
    }

    printf("\nNome da Pessoa que sera apagada: ");
    scanf("%s", nome);
    fflush(stdin);

    tempPessoa = (void *)buscarPessoaPorNome();

    if (tempPessoa == NULL)
    {
        printf("\nNao existe usuario cadastrado com esse nome!!!\n");
        return;
    }

    tempPessoaIdade = tempPessoa;
    tempPessoaTelefone = tempPessoa + sizeof(int);
    tempPessoaProximo = tempPessoa + (sizeof(int) * 2);
    tempPessoaAnterior = tempPessoa + (sizeof(int) * 3);
    tempPessoaNome = tempPessoa + (sizeof(int) * 4);    

    if (tempPessoa == primeiraPessoa)
    {
        if(*tempPessoaProximo == (int) NULL){
            free(primeiraPessoa);
            primeiraPessoa = NULL;
        }
        else{
            void *pessoaElementoProximo;
            int *pessoaElementoProximoAnterior;
            pessoaElementoProximo = tempPessoaProximo;
            pessoaElementoProximoAnterior = tempPessoaProximo + (sizeof(int) * 3);
            *pessoaElementoProximoAnterior = (int) NULL;
            free(primeiraPessoa);
            primeiraPessoa = pessoaElementoProximo;
        }
    }
    else
    {
        if(*tempPessoaProximo == (int) NULL){
            void *pessoaElementoAnterior;
            int *pessoaElementoAnteriorProximo;
            pessoaElementoAnterior = (void *) *tempPessoaAnterior;
            pessoaElementoAnteriorProximo = pessoaElementoAnterior + (sizeof(int) * 2);

            *pessoaElementoAnteriorProximo = (int) NULL;
            free(tempPessoa);
        }
        else{
            void *pessoaElementoAnterior;
            int *pessoaElementoAnteriorProximo;
            pessoaElementoAnterior = (void *) *tempPessoaAnterior;
            pessoaElementoAnteriorProximo = pessoaElementoAnterior + (sizeof(int) * 2);

            void *pessoaElementoProximo;
            int *pessoaElementoProximoAnterior;
            pessoaElementoProximo = tempPessoaProximo;
            pessoaElementoProximoAnterior = tempPessoaProximo + (sizeof(int) * 3);

            *pessoaElementoAnteriorProximo = (int) pessoaElementoProximo;
            *pessoaElementoProximoAnterior = (int) pessoaElementoAnterior;

            free(tempPessoa);
        }
    }

    printf("\nPessoa excluida com sucesso!\n");
}

void *buscarPessoaPorNome()
{
    tempPessoa = primeiraPessoa; 

    *validador = 0;
    do
    {
        tempPessoaIdade = tempPessoa;
        tempPessoaTelefone = tempPessoa + sizeof(int);
        tempPessoaProximo = tempPessoa + (sizeof(int) * 2);
        tempPessoaAnterior = tempPessoa + (sizeof(int) * 3);
        tempPessoaNome = tempPessoa + (sizeof(int) * 4);

        if ((strcmp(tempPessoaNome, nome) == 0))
        {
            return tempPessoa;
        }
        else if ((*tempPessoaProximo) == (int) NULL)
        {
            *validador = 1;
        }
        else
        {
            tempPessoa = (void *) *tempPessoaProximo;
        }
    } while (*validador == 0);

    return NULL;
}

void buscarPessoa()
{
    printf("\nDigite o nome da pessoa que deseja buscar:");
    scanf("%s", nome);

    tempPessoa = buscarPessoaPorNome();

    if (tempPessoa == NULL)
    {
        printf("\nPessoa nao existe!!!");
        return;
    }

    tempPessoaIdade = tempPessoa;
    tempPessoaTelefone = tempPessoa + sizeof(int);
    tempPessoaProximo = tempPessoa + (sizeof(int) * 2);
    tempPessoaAnterior = tempPessoa + (sizeof(int) * 3);
    tempPessoaNome = tempPessoa + (sizeof(int) * 4);

    printf("\n\nDados da pessoa buscada:");
    printf("\nNome: %s", tempPessoaNome);
    printf("\nIdade: %d", *tempPessoaIdade);
    printf("\nTelefone: %d", *tempPessoaTelefone);
}

void listarPessoas()
{
    if (primeiraPessoa == NULL)
    {
        printf("\n  Nao ha pessoas no cadastro!!!\n");
    }
    else
    {
        tempPessoa = primeiraPessoa;

        *validador = 0;
        *incrementador = 1;
        do
        {
            tempPessoaIdade = tempPessoa;
            tempPessoaTelefone = tempPessoa + sizeof(int);
            tempPessoaProximo = tempPessoa + (sizeof(int) * 2);
            tempPessoaAnterior = tempPessoa + (sizeof(int) * 3);
            tempPessoaNome = tempPessoa + (sizeof(int) * 4);

            printf("\n\n  Pessoa %d:", *incrementador);
            printf("\nNome: %s", tempPessoaNome);
            printf("\nIdade: %d", *tempPessoaIdade);
            printf("\nTelefone: %d", *tempPessoaTelefone);

            if (*tempPessoaProximo == (int) NULL)
            {
                *validador = 1;
            }
            else
            {
                tempPessoa = (void *) *tempPessoaProximo;
            }

            *incrementador = *incrementador + 1;
        } while (*validador == 0);
    }
}

void limparLista(){
    if(primeiraPessoa != NULL){
        tempPessoa = primeiraPessoa;
        void *proximaPessoa;

        do{
            tempPessoaProximo = tempPessoa + (sizeof(int) * 2);

            if(*tempPessoaProximo == (int) NULL){
                free(tempPessoa);
                break;
            }
            else{
                proximaPessoa = (void *) *tempPessoaProximo;
                free(tempPessoa);
                tempPessoa = proximaPessoa;
            }
        }while(true);
    }

    printf("\n\n\n  Obrigado por usar a lista desenvolvida por Charles Goncalves Aires  :)\n\n\n");

}