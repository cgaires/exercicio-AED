#include <stdio.h>

int menu();

int main (void){
    char nome[50];
    char *T;
    int selecao;
    int sair = 0;
    int i = 0;

    do{
        
        selecao = menu();

        if(selecao == 1){
            printf("Nome para ser adicionado:");
            scanf("%s",&nome);
            T = (char*) malloc(sizeof(nome));

            
        }else if(selecao == 2){

        }else if(selecao == 3){
            //printf("%s", nome[50]);
        }else if(selecao == 4){
            sair = 1;
        }else{

        }
        i++;
    }while( sair != 1);
    
    return 0;
}

int menu(){
    int selecao;
    printf("\n    Menu:\n1)Adicionar nome\n2)Remover nome\n3)Listar\n4)Sair\n\n");
    scanf("%d", &selecao);

    return selecao;
}
