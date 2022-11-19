#include <stdio.h>

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
void zera(int v[],int qt){
  int i;
  
  for(i=0;i<qt;i++){
     v[i]=0;
  }
}
int main(void) {
  //Monta Tabela de frequência: por coluna
  int vCandidatos[4]={1234, 2345,3445,4567}; 
  int  vQtdades[4]; 
  int qtOcup=4;
  
  int voto; // voto negativo
  int tam;
  int pos;
  zera(vQtdades,4);
  printf("Digite o seu voto: ");
  scanf("%d", &voto); 
  while (voto>0){
    pos = busca(vCandidatos,qtOcup, voto);
    if (pos!= -1) 
      vQtdades[pos]++;
    
    printf("Digite o voto: ");
    scanf("%d", &voto); 
   
  }

 mostraTabelaDeFrequencia(vCandidatos,vQtdades,4);
}