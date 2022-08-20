#include <stdio.h>
#include <stdlib.h>

int menu();
void criaPessoa(void *pBuffer, const int tamanho, int contador);
void listarPessoas(void *pBuffer, int contador);

int main(){
    int opcao;
    const int tamanho = (sizeof(char) * 10) + (sizeof(int) * 2);
    int contador = 0;
    void *pBuffer;
    do{ 
        opcao = menu();

        switch (opcao)
        {
        case 1:
            if(contador == 0){
                pBuffer = malloc(tamanho);
            } else {
                pBuffer = realloc(pBuffer, (contador + 1) * sizeof(tamanho));
            }
            criaPessoa(pBuffer, tamanho, contador);
            contador ++;
            break;
        case 2:
            break;
        case 4:
            listarPessoas(pBuffer, contador);
        }


    }while(opcao != 5);


}

int menu(){
    int opcao;

    printf("\n    Menu:\n1. Incluir pessoa.\n2. Apagar pessoa.\n3. Buscar pessoa.\n4. Listar pessoas.\n5. Sair\n");
    printf("Selecione a opcao: ");
    scanf("%d", &opcao);
    fflush(stdin);

    return opcao;
}

void criaPessoa(void *pBuffer, const int tamanho, int contador) {
    char nome[10];
    int idade;
    int telefone;

    char *pNome;
    int *pIdade;
    int *pTelefone;

    printf("\nQual o nome? ");
    scanf("%s", &nome);
    fflush(stdin);

    printf("Qual a idade? ");
    scanf("%d", &idade);
    fflush(stdin);

    printf("Qual o telefone? ");
    scanf("%d", &telefone);
    fflush(stdin);

    void *modificador;
    
    //inicio da próxima pessoa
    if(contador == 0){
        modificador = pBuffer;
    }else{
        modificador = pBuffer + (contador * tamanho);
    }

    pNome = modificador;
    int i;
    for(i = 0; i < 10; i++){
        *pNome = nome[i];
        pNome = modificador + (sizeof(char) * (i + 1));
    }

    modificador = modificador + (sizeof(char) * 10);
    pIdade = modificador;
    *pIdade = idade;

    modificador = modificador + sizeof(int);
    pTelefone = modificador;
    *pTelefone = telefone;
}

void listarPessoas(void *pBuffer, int contador){
    if(contador == 0){
        printf("\nNão há pessoas registradas!");
    }else{
        int i;
        char *pNome;
        int *pIdade;
        int *pTelefone;

        void *modificador;
        modificador = pBuffer;
        for(i = 0; i < contador; i++){
            printf("\n    Pessoa %d:", (i + 1));
            pNome = modificador;
            printf("\nNome: %s", pNome);
            modificador = modificador + (sizeof(char) * 10);

            pIdade = modificador;
            printf("\nIdade: %d", *pIdade);
            modificador = modificador + sizeof(int);

            pTelefone = modificador;
            printf("\nTelefone: %d\n", *pTelefone);
            modificador = modificador + sizeof(int);
        };
    }
}