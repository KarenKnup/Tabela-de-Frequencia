#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//para quando digita "fim"

int busca(char vValores[], int qtOcup,char letra){
     
     //   se a letra tiver na primeira posição? return 0
    //   se a letra tiver na segunda posição? return 1
    //   se a letra tiver na terceira posição? return 2
    //  ...
    // até a última posição ocupada do vetor (qtOcup)
    int i;
    for (i=0;i<qtOcup;i++){
      if (vValores[i] == letra)
          return i;
    }
  // se chegar nesta linha --> não tá na lista
  return -1; // não tá
}
void mostraTabelaDeFrequencia(char vValores[], int vQtdades[], int qtOcup){
  int i;
  printf("\nLetra\tQuantidade");
  for(i=0;i<qtOcup;i++){
    printf("\n%-6c\t%6d",vValores[i],vQtdades[i]);
  }
  return;
}
int main(void) {
  //Tabela de frequência: por coluna
  char vValores[26]; // coluna dos valores
  int  vQtdades[26]; // coluna das quantidades
  int qtOcup=0;
  char ultimaLetra;
  char nome[31];
  int tam;
  int pos;
  
  printf("\nDigite o nome ('fim' para acabar): ");
  scanf(" %30[^\n]", nome); 
  
  while (strcmp(nome,"fim")!=0){
    tam = strlen(nome);
    ultimaLetra=nome[tam-1];
    // Se a última letra já tá no vValores: 
    //      atualiza a mesma posição do vQtdades
    //senão
    //      inclui a letra no vValores
    //      inclui 1 no vQtdades
    pos = busca(vValores,qtOcup, ultimaLetra);
    if (pos!= -1) // a letra existe, atualizar a qtdade
      vQtdades[pos]++;
    else{  // a letra não existe AINDA--> incluí-la
      vValores[qtOcup]=ultimaLetra;
      vQtdades[qtOcup]=1;
      qtOcup++;
    }
    printf("Digite o nome ('fim' para acabar): ");
    scanf(" %30[^\n]", nome); 
   
  }
  mostraTabelaDeFrequencia(vValores,vQtdades,qtOcup);
}