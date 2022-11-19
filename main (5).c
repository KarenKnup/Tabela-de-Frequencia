#include <stdio.h>
#include <string.h>

//para quando digita "0"

int busca(int vCandidatos[], int qtOcup, int voto){
     
     int i;
    for (i=0;i<qtOcup;i++){
      if (vCandidatos[i] == voto)
          return i;
    }
  return -1; 
}
void mostraTabelaDeFrequencia(int vCandidatos[], int vQtdades[], int qtOcup){
  int i;
  printf("\nCand\tQuantidade");
  for(i=0;i<qtOcup;i++){
    printf("\n%-6d\t%6d",vCandidatos[i],vQtdades[i]);
  }
  return;
}
int main(void) {
  //Tabela de frequência: por coluna
  int vCandidatos[30]; // coluna dos valores
  int  vQtdades[30]; // coluna das quantidades
  int qtOcup=0;
  
  int voto; // voto negativo
  int tam;
  int pos;
  printf("Digite o seu voto: ");
  scanf("%d", &voto); 
  while (voto>0){
    pos = busca(vCandidatos,qtOcup, voto);
    if (pos!= -1) 
      vQtdades[pos]++;
    else{ 
      vCandidatos[qtOcup]=voto;
      vQtdades[qtOcup]=1;
      qtOcup++;
    }
    printf("Digite o voto: ");
    scanf("%d", &voto); 
   
  }
  mostraTabelaDeFrequencia(vCandidatos,vQtdades,qtOcup);
}