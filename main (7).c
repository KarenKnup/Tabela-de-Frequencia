#include <stdio.h>
#include <string.h>
#define TAM 7
#define QT 8


void inic_vetor(int n, int v[]){
  int i;
  for (i=0;i!=n;i++){
    v[i]=0;
  }
}

void exibe_tabela(int vSomaIdade[], int vContadorIdadeMedia[],int vIdadeMaisVelho[]){
  int i;
  float idadeMedia;
  printf("\n Instrução \t Idade Média \t Idade Mais Velho");
  for (i=0;i<TAM;i++){
    if (vContadorIdadeMedia[i]>0)
        idadeMedia=vSomaIdade[i]/vContadorIdadeMedia[i];
    else
        idadeMedia=0;
    printf("\n %-6d \t %6.1f \t %13d", i+1, idadeMedia, vIdadeMaisVelho[i]);
  }
}



int main(void) {
  int idade,vSomaIdade[TAM], vIdadeMaisVelho[TAM], i=0, pos, vContadorIdadeMedia[TAM];
  int instrucao;
  int cont;
  
  
  inic_vetor(TAM, vSomaIdade);
  inic_vetor(TAM, vIdadeMaisVelho);
  inic_vetor(TAM,vContadorIdadeMedia);
  
  
  for (cont=0; cont<QT;cont++) {
    printf("\nDigite seu grau de instrução (1,2,3,4,5,6 ou 7): ");
    scanf("%d", &instrucao);
    printf("Digite sua idade: ");
    scanf("%d", &idade);
  
    pos = instrucao-1;
    if (pos>=0 && pos <TAM){
      if(vIdadeMaisVelho[pos]<idade){
        vIdadeMaisVelho[pos]=idade;
      }
      vSomaIdade[pos]+=idade;
      vContadorIdadeMedia[pos]++;
    }
  }
  exibe_tabela(vSomaIdade,vContadorIdadeMedia, vIdadeMaisVelho);
  return 0;
}