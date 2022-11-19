#include <stdio.h>
int montaTabela(int vCod[], float vPr[], int vEst[]){
  vCod[0]=1020; vPr[0]=3; vEst[0]=8;
  vCod[1]=1030; vPr[1]=5; vEst[1]=200;
  vCod[2]=1005; vPr[2]=2.54; vEst[2]=20;
  vCod[3]=2015; vPr[3]=7; vEst[3]=19;
  
  return 4;

  
}
int busca( int v[], int qt, int val){
  int i;
  for(i=0;i<qt;i++){
    if (v[i]==val)
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
    int qt;
    int cod, qtDesejada,pos;
    qt=montaTabela(vCod,vPr,vEst);
    printf("Digite o produto: ");
    scanf("%d",&cod); // valor chave
    while (cod >0){
      pos= busca(vCod,qt,cod);
      if (pos == -1){
        printf("\nEste produto não existe");
      }
      else{
        printf("\nPreço do %d: R$: %.2f",vCod[pos],vPr[pos]);
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
    scanf("%d",&cod); // valor chave
  }
  return 0;
}