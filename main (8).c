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


int tabela_opcoes (char vEscolaridade[][31]){
  strcpy(vEscolaridade[0],"Analfabeto");
  strcpy(vEscolaridade[1],"Primeiro grau");
  strcpy(vEscolaridade[2],"Segundo grau");
  strcpy(vEscolaridade[3],"Superior");
  strcpy(vEscolaridade[4],"Mestrado");
  strcpy(vEscolaridade[5],"Doutorado");
  strcpy(vEscolaridade[6],"Outros");
  
  return 7;
}




int busca_Nomes(char vN[][31], int x, char vN2[]){
  int i;
  for (i=0;i<x;i++){
    if (strcmp(vN[i],vN2)==0){
      return i;
    }
  }
  return -1;
}
void obtem_Nivel_Escolaridade(char vEsc[][31], int qt,char esc[]){
  int i,num;
  printf("\nNíveis de escolaridade:\n");
  printf("\n[%d] - %s",0,"fim");
  for (i=0;i<qt;i++){
    printf("\n[%d] - %s",i+1,vEsc[i]);
  }
  printf("\n");
  scanf("%d",&num);
  while(num<0 || num >qt){
    printf("\nopção inválida. Digite novamente o nível de escolaridade\n");
    scanf("%d",&num);
  }
  if (num !=0)
    strcpy(esc,vEsc[num-1]);
  else
    strcpy(esc,"fim");
  return;
}
  
void exibe_tabela(int vSomaIdade[], int vContadorIdadeMedia[],int vIdadeMaisVelho[], char vEscolaridade[][31]){
  int i;
  float idadeMedia;
  printf("\n Instrução    \t Idade Média \t Idade Mais Velho");
  for (i=0;i<TAM;i++){
    if (vContadorIdadeMedia[i]>0)
        idadeMedia=vSomaIdade[i]/vContadorIdadeMedia[i];
    else
        idadeMedia=0;
    printf("\n %-15s \t %6.1f \t %13d", vEscolaridade[i], idadeMedia, vIdadeMaisVelho[i]);
  }
}

int main(void) {
  int x;
  char vEscolaridade[7][31], escolaridade [31]; 
  int idade,vSomaIdade[TAM], vIdadeMaisVelho[TAM], vContadorIdadeMedia[TAM],qt;
  int i=0, pos;
  
  inic_vetor(TAM, vSomaIdade);
  inic_vetor(TAM, vIdadeMaisVelho);
  inic_vetor(TAM,vContadorIdadeMedia);
  
  qt=tabela_opcoes(vEscolaridade);
  obtem_Nivel_Escolaridade(vEscolaridade,qt,escolaridade);
  
  while (strcmp(escolaridade,"fim")!=0){
    printf("Qual a sua idade?   ");
    scanf("%d", &idade);
  
    pos = busca_Nomes(vEscolaridade, qt, escolaridade);
    
    if(vIdadeMaisVelho[pos]<idade){
      vIdadeMaisVelho[pos]=idade;
    }
    vSomaIdade[pos]+=idade;
    vContadorIdadeMedia[pos]++;
    
    obtem_Nivel_Escolaridade(vEscolaridade,qt,escolaridade);
  }
  
  exibe_tabela(vSomaIdade,vContadorIdadeMedia, vIdadeMaisVelho,vEscolaridade);
  
  return 0;
}
