#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    char matricula[50];
    char nome[50];

    float notaPrimeiraProva;
    float notaSegundaProva;
    
    struct Aluno *prox;
}Aluno;

int main(void) {
  printf("Entre com os dados de 5 alunos:");

  int i = 0;
  Aluno *inicial;
  Aluno *atual;
  do{
    if (i == 0){
      inicial = (Aluno *)malloc(sizeof(Aluno));
      atual = inicial;
    }else{
      Aluno *novaCelula;
      novaCelula = (Aluno *)malloc(sizeof(Aluno));
      atual->prox = novaCelula;

      atual = novaCelula;
    }
    
    i++;
    printf("\nAluno %d:\n", i);
    printf("Matricula:");
    scanf("%s", &(atual->matricula[50]));
    printf("Nome:");
    scanf("%s", &(atual->nome[50]));
    printf("Nota da Primeira Prova:");
    scanf("%f", &(atual->notaPrimeiraProva));
    printf("Nota da Segunda Prova:");
    scanf("%f", &(atual->notaSegundaProva));
  }while(i != 5);

  int n = 0;
  
  int notaAltaPrimeiraProva = 0;
  int alunoNotaAltaPrimeiraProva = 0;
  
  float media = 0;

  int mediaAlta = 0;
  int alunoMediaAlta = 0;

  int mediaBaixa = 99999999;
  int alunoMediaBaixa = 0;
  for(atual = inicial; n != 5; atual = atual->prox){
    n++;
    if(atual->notaPrimeiraProva > notaAltaPrimeiraProva){
      notaAltaPrimeiraProva = atual->notaPrimeiraProva;
      alunoNotaAltaPrimeiraProva = n;
    }

    media = (atual->notaPrimeiraProva + atual->notaSegundaProva) / 2;

    if(media > mediaAlta){
      mediaAlta = media;
      alunoMediaAlta = n;
      }

    if(media < mediaBaixa){
      mediaBaixa = media;
      alunoMediaBaixa = n;
      }   
    }

  printf("\nAluno com maior nota da primeira prova: Aluno %d", alunoNotaAltaPrimeiraProva);
  printf("\nAluno com maior media geral: Aluno %d", alunoMediaAlta);
  printf("\nAluno com menor media geral: Aluno %d", alunoMediaBaixa);
  
  
  return 0;
}