#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void *PrimeiraPessoa = NULL; // igual a cabeça da lista
void *ultimaPessoa;
void *ultimaPessoaAnterior;
void *novaPessoa;

int *novaPessoaIdade;
int *novaPessoaTelefone;
int *novaPessoaProximo;
int *novaPessoaAnterior;
char *novaPessoaNome;

const TAMANHO_PESSOA = (sizeof(int) * 4) + (sizeof(char) * 10);

void *pBuffer;

int *tamanhoBuffer;
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

int main()
{
    pBuffer = malloc((sizeof(int) * 4) + (sizeof(char) * 10));
    tamanhoBuffer = pBuffer;
    opcao = pBuffer + sizeof(int);
    incrementador = pBuffer + (sizeof(int) * 2);
    validador = pBuffer + (sizeof(int) * 3);
    nome = pBuffer + (sizeof(int) * 4);

    *tamanhoBuffer = 0;

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
            /* tudo que é alocado tem que ter um free */
            /* fazer um teste com um programa com um malloc só sem free para ver se meu dr. memory tá funcionando */

            /* reescrever tudo inglês e pegar esse costume */
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
    novaPessoa = malloc(sizeof(TAMANHO_PESSOA));

    novaPessoaIdade = novaPessoa;
    novaPessoaTelefone = novaPessoa + sizeof(int);
    novaPessoaProximo = novaPessoa + (sizeof(int) * 2);
    novaPessoaAnterior = novaPessoa + (sizeof(int) * 3);
    novaPessoaNome = novaPessoa + (sizeof(int) * 4);

    printf("\nQual o nome? ");
    scanf("%s", novaPessoaNome);
    fflush(stdin);

    printf("Qual a idade? ");
    scanf("%d", novaPessoaIdade);
    fflush(stdin);

    printf("Qual o telefone? ");
    scanf("%d", novaPessoaTelefone);
    fflush(stdin);

    if (PrimeiraPessoa == NULL)
    {
        PrimeiraPessoa = novaPessoa;
        ultimaPessoa = novaPessoa;

        *novaPessoaAnterior = (int) NULL;
        *novaPessoaProximo = (int) NULL;
    }
    else
    {
        void *candidataAnterior;

        void *temp;

        int *tempIdade;
        int *tempProxima;

        temp = PrimeiraPessoa;

        do
        {
            

            if (*novaPessoaIdade >= *tempIdade)
            {
                candidataAnterior = temp;
                tempProxima = temp + (sizeof(int) * 2);
                if(*tempProxima != (int) NULL){
                    temp = (void *) *tempProxima;
                    tempIdade = temp;
                }
            }
            else
            {
                break;   
            }

        } while (*tempProxima != (int) NULL);




        if (candidataAnterior == NULL)
        {
            // se for menor que a primeira pessoa;

            // primeirapessoaanterior = novapessoa
            int *primeiraPessoaAnterior;
            primeiraPessoaAnterior = PrimeiraPessoa + (sizeof(int) * 3);
            *primeiraPessoaAnterior = (int) novaPessoa;
            // novapessoaanterior = NULL;
            *novaPessoaAnterior = (int) NULL;
            // novapessoaproximo = primeirapessoa
            *novaPessoaProximo = (int) PrimeiraPessoa;
            // primeira pessoa = novapessoa
            PrimeiraPessoa = novaPessoa;
        }
        else
        {
            // novapessoa prox = candidata prox
            int *candidataAnteriorProximo;
            *candidataAnteriorProximo = (int) candidataAnterior + (sizeof(int) * 2);
            *novaPessoaProximo = *candidataAnteriorProximo;
            // pessoa candidata prox = novapessoa
            *candidataAnteriorProximo = (int) novaPessoa;
            // nova pessoa anterior = candidata
            *novaPessoaAnterior = (int) candidataAnterior;
        }
    }
}

void apagarPessoa()
{
    void *pessoaExclusao;
    int *pessoaExclusaoAnt;
    int *pessoaExclusaoProximo;

    printf("\nNome da Pessoa que sera apagada: ");
    scanf("%s", nome);
    fflush(stdin);

    if (PrimeiraPessoa == NULL)
    {
        printf("\nNao ha pessoas cadastradas!!!\n");
        return;
    }

    pessoaExclusao = (void *)buscarPessoaPorNome();
    pessoaExclusaoAnt = pessoaExclusao + (sizeof(int) * 3);
    pessoaExclusaoProximo = pessoaExclusao + (sizeof(int) * 2);

    if (pessoaExclusao == NULL)
    {
        printf("\nNao existe usuario cadastrado com esse nome!!!\n");
        return;
    }

    if (*pessoaExclusaoAnt == (int) NULL)
    {
        free(PrimeiraPessoa);
        PrimeiraPessoa = (void *) *pessoaExclusaoProximo;
    }
    else
    {
        int *pessoaExclusaoAnteriorProx;
        pessoaExclusaoAnteriorProx = pessoaExclusao + (sizeof(int) * 2);
        *pessoaExclusaoAnteriorProx = *pessoaExclusaoProximo;
        free(pessoaExclusao);
    }

    printf("\nPessoa excluida com sucesso!\n");
}

void *buscarPessoaPorNome()
{
    void *temp;
    temp = PrimeiraPessoa;

    int *tempProximo;
    tempProximo = temp + (sizeof(int) * 2);
    char *tempNome = temp + (sizeof(int) * 4);

    *validador = 0;
    do
    {
        if ((strcmp(tempNome, nome) == 0))
        {
            return temp;
        }
        else if ((*tempProximo) == (int) NULL)
        {
            *validador = 1;
        }
        else
        {
            temp = (void *) *tempProximo;
        }
    } while (*validador == 0);

    return NULL;
}

void buscarPessoa()
{
    void *pessoaBuscada;

    char *pessoaBuscadaNome = pessoaBuscada + (sizeof(int) * 4);
    int *pessoaBuscadaIdade = pessoaBuscada;
    int *pessoaBuscadaTelefone = pessoaBuscada + (sizeof(int));

    printf("\nDigite o nome da pessoa que deseja buscar:");
    scanf("%s", nome);

    pessoaBuscada = buscarPessoaPorNome();

    if (pessoaBuscada == NULL)
    {
        printf("\nPessoa nao existe!!!");
        return;
    }

    printf("\n\nDados da pessoa buscada:");
    printf("\nNome: %s", pessoaBuscadaNome);
    printf("\nIdade: %d", pessoaBuscadaIdade);
    printf("\nTelefone: %d", pessoaBuscadaTelefone);
}

void listarPessoas()
{
    if (PrimeiraPessoa == NULL)
    {
        printf("\n  Nao ha pessoas no cadastro!!!\n");
    }
    else
    {
        void *temp;
        temp = PrimeiraPessoa;

        char *tempPessoaNome;
        int *tempPessoaIdade;
        int *tempPessoaTelefone;

        int *tempPessoaProximo;

        *validador = 0;
        *incrementador = 1;
        do
        {
            tempPessoaNome = temp + (sizeof(int) * 4);
            tempPessoaIdade = temp;
            tempPessoaTelefone = temp + (sizeof(int));

            tempPessoaProximo = temp + (sizeof(int) * 2);

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
                temp = (void *) *tempPessoaProximo;
            }

            *incrementador = *incrementador + 1;
        } while (*validador == 0);
    }
}