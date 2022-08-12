#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addName(char *str, int *cont);
char *removeName(char *str, int *cont);
int readStr(char *c);
void print(char *str);

int main(){
    char *string = (char *) malloc(sizeof(char));
    string[0] = '\0';
    int opcao, cont = 0;
    while(1){
        printf("\n");
        printf("1) Adicionar nome\n");
        printf("2) Remover nome\n");
        printf("3) Listar\n");
        printf("4) Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        setbuf(stdin, NULL);
        if(opcao == 1){
            string = addName(string, &cont);
        }else if(opcao == 2){
            string = removeName(string, &cont);
        }else if(opcao == 3){
            print(string);
        }else if(opcao == 4){
            break;
        }
    }
    free(string);
    return 0;
}



char *addName(char *str, int *cont){
    char name[60];
    int length;
    printf("\nDigite o nome: ");
    length = readStr(name);
    *cont += length;
    str = realloc(str, (*cont + 1) * sizeof(char));
    if(!str){
        printf("Insufficient Memory");
        return 0;
    }
    strcat(str, name);
    return str;
}

char *removeName(char *str, int *cont){
    int i, j = 0, k = 0, z; // I = Numero pra retirar, j = contador, k = variavel auxiliar
    print(str);
    printf("\nDigite o numero que você deseja remover: ");
    scanf("%d", &i);
    while(str[j] != '\0'){
        if(str[j] == ','){
            if(k == (i - 1)){
                break;
            }
            else{
                k++;
            }
        }
        j++;
    }
    z = j;
    k = 0;
    j++;
    while(str[j] != ',' && j < *cont){
        k++;
        j++;
    }
    if(j < *cont){
        while(str[j] != '\0'){
            str[z] = str[j];
            k++;
            j++;
        }
        str[z] = '\0';
    }
    *cont -= k;
    if(!str){
        printf("Insufficient Memory");
        return 0;
    }
    str[*cont - 1] = '\0';
    return str;
}

int readStr(char *name){
    char caracter = ',';
    int i = 0;
    while(caracter != '\n'){
        name[i] = caracter;
        caracter = getchar();
        i++;
        if(i > 58){
            return 0;
        }
    }
    name[i] = '\0';
    return i;
}

void print(char *str){
    int i = 0, j = 1;

    while (str[i] != '\0')
    {
        if(str[i] == ','){
            printf("\n");
            printf("%d - ", j);
            j++;
        }else
        {
            printf("%c", str[i]);
        }
        i++;
    }
    
    printf("\n");
}