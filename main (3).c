#include <stdio.h>
#include <string.h>

//Quantas vezes as letras "adegkmuvz" aparecem
//acaba quando digita "fim"

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
void montaTabFreqInicial(char vValores[], int vQtdades[],int qt){
  int i;
  char letras[]="adegkmuvz";
  for(i=0;i<qt;i++){
    vValores[i]=letras[i];
    vQtdades[i]=0;
  }
}
int main(void) {
  //Tabela de frequência: Quantas palavras
  // terminam em a, d, e, g, k, m, u, v, z
  char vValores[8]; // coluna dos valores
  int  vQtdades[8]; // coluna das quantidades
  int qtOcup=0;
  char ultimaLetra;
  char nome[31];
  int tam;
  int pos;
  montaTabFreqInicial(vValores,vQtdades,8);
  printf("Digite o nome: ");
  scanf(" %30[^\n]", nome); 
  while (strcmp(nome,"fim")!=0){
    tam = strlen(nome);
    ultimaLetra=nome[tam-1];
    // Se a última letra  tá no vValores: 
    //      atualiza a mesma posição do vQtdades
   
    pos = busca(vValores,8, ultimaLetra);
    if (pos!= -1) // a letra existe, atualizar a qtdade
      vQtdades[pos]++;
    
    printf("Digite o nome: ");
    scanf(" %30[^\n]", nome); 
   
  }
  mostraTabelaDeFrequencia(vValores,vQtdades,8);
}