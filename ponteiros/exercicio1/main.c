/*
Charles Gonçalves Aires
Lista 09 de ponteiros - Exercício 1
*/

#include <stdio.h>

int main(){
    int inteiro;
    float real;
    char caractere;

    int* inteiroPonteiro;
    float* realPonteiro;
    char* caracterePonteiro;

    inteiroPonteiro = &inteiro;
    realPonteiro = &real;
    caracterePonteiro = &caractere;

    printf("Insira um inteiro:");
    scanf("%d", inteiroPonteiro);
    fflush(stdin);

    printf("Insira um real:");
    scanf("%f", realPonteiro);
    fflush(stdin);

    printf("Insira um caractere:");
    scanf("%c", caracterePonteiro);
    fflush(stdin);

    printf("\nInteiro:%d\nReal:%f\nCaractere:%c", inteiro, real, caractere);

    return 0;
}