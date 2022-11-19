#include <stdio.h>
#include <string.h>

//para quando digita "fim"

void mostraTabelaDeFrequencia(int vQtdades[], int qtOcup){
  int i;
  printf("\nLetra\tQuantidade");
  for(i=0;i<qtOcup;i++){
    printf("\n%-6c\t%6d",i+'a',vQtdades[i]);
  }
  return;
}
void montaTabFreqInicial( int vQtdades[],int qt){
  int i;
  
  for(i=0;i<qt;i++){
      vQtdades[i]=0;
  }
}
int main(void) {
  //Tabela de frequência: Quantas palavras
  // terminam em a, em b, em c, em d, em e, em f, em g, em h.
  
  int  vQtdades[8]; // coluna das quantidades
  int qtOcup=0;
  char ultimaLetra;
  char nome[31];
  int tam;
  int pos;
  montaTabFreqInicial(vQtdades,8);
  printf("Digite o nome: ");
  scanf(" %30[^\n]", nome); 
  while (strcmp(nome,"fim")!=0){
    tam = strlen(nome);
    ultimaLetra=nome[tam-1];
    // Se a última letra  tá no vValores: 
    //      atualiza a mesma posição do vQtdades
   
    pos = ultimaLetra -'a';
    if (pos>=0 && pos < 8) // a letra existe, atualizar a qtdade
      vQtdades[pos]++;
    
    printf("Digite o nome: ");
    scanf(" %30[^\n]", nome); 
   
  }
  mostraTabelaDeFrequencia(vQtdades,7);
}