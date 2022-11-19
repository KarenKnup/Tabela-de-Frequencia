#include <stdio.h>
#include <string.h>

//pos = posição
//strcmp = string compare
//est = estoque

int montaTabela(char vNomes[][31],int vCod[], float vPr[], int vEst[]){
  strcpy(vNomes[0],"garfo");vCod[0]=1020; vPr[0]=3; vEst[0]=8;
  strcpy(vNomes[1],"faca");vCod[1]=1030; vPr[1]=5; vEst[1]=200;
  strcpy(vNomes[2],"colher");vCod[2]=1005; vPr[2]=2.54; vEst[2]=20;
  strcpy(vNomes[3],"prato");vCod[3]=2015; vPr[3]=7; vEst[3]=19;
  
  return 4;

  
}
int buscaNomes( char vN[][31], int qt, char val[]){
  int i;
  for(i=0;i<qt;i++){
    if (strcmp(vN[i],val)==0)
      return i;
  }
  return -1;
}
int main(void) {

//   montar a tabela a ser consultada (em geral de um arquivo)
//   consulta
//       entra um valor chave  (colher)
//       procura o valor chave na tabela
//       Se ele existe
//            mostra/atualiza/ um valor relacionado ou eliminar a chave
//       senão
//            enviar uma mensagem/incluir
//  exibir a tabela resultante  (em geral salvá-la num arquivo)
    int vCod[20];
    float vPr[20];
    int vEst[20];
    char vNomes[20][31];//são 20 nomes, cada nome c no máx 31 letras/caracteres
    int qt;
    int qtDesejada,pos;
    char prodDesejado[31];
    qt=montaTabela(vNomes,vCod,vPr,vEst);
    printf("Digite o produto: ");
    scanf(" %[^\n]",prodDesejado); // valor chave
    while (strcmp(prodDesejado,"fim")!=0){
      pos= buscaNomes(vNomes,qt,prodDesejado);
      if (pos == -1){
        printf("\nEste produto não existe");
      }
      else{
        printf("\n%s - Preço do %d: R$: %.2f",prodDesejado,vCod[pos],vPr[pos]);
        printf("\nTemos %d unidades. \nQuantos vc quer? ",vEst[pos]);
        scanf("%d", &qtDesejada);
        if (qtDesejada !=0 && qtDesejada <= vEst[pos]){
          vEst[pos]= vEst[pos] - qtDesejada;
          printf("\nTotal R$ %.2f",qtDesejada*vPr[pos]);
        }
        else{
          printf("\n Compra não efetivada");
        }
        
      }
    printf("\n\nDigite o produto: ");
    scanf(" %[^\n]",prodDesejado); // valor chave
  }
  return 0;
}