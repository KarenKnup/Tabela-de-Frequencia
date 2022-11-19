#include <stdio.h>
#include <string.h>

int buscaInt(int v[], int qt, int val){
    int i;
    for(i = 0; i <qt; i++){
        if(v[i] == val){
            return i;
        }
    }
    return -1;
}

int buscaChar(char v[], int qt, char val){
    int i;
    for(i = 0; i <qt; i++){
        if(v[i] == val){
            return i;
        }
    }
    return -1;
}

int buscaTexto(char v[][3], int qt, char val[]){
    int i;
    for(i = 0; i <qt; i++){
        if(strcmp(v[i], val) == 0){
            return i;
        }
    }
    return -1;
}

int inicializaVetor(int v[], int qt, int val){
    int i;
    for(i = 0; i <qt; i++){
        v[i] = val;
    }
    return -1;
}

int ContabilizarRegiao( char v[][3], int qt, int val []){
    int i;
    for(i = 0; i < qt; i++){
        printf("Regiao %s, Total de consultas: %d \n", v[i], val[i]);
    }
    return 0;
}

int main(){
    
    int vIdProd[12] = {10, 20, 12, 34, 45, 56, 67, 78, 89, 90, 21, 32};
    int vEmbProd[12] = {1, 2, 3, 4, 5, 2, 3, 4, 1, 5, 3, 4};
    float vPrecoProd[12] = {10, 40, 20, 35, 50, 50, 50, 10, 20, 20, 10, 50};

    float vPrecoEmb[5] = {2, 3.5, 1, 3, 6.5};
    
    char vRegioes[8][3] = {"SU", "SE", "SO", "NT", "NE", "NO", "CT", "CO"};
    int cRegioes[8] ;
    float vTxEntrega[8] = {4, 4, 5, 8, 9, 14, 6, 7};

    int codigoProd;
    char regiao [3];
    int idProd;
    int idReg;
    float total;

    total = 0;

    inicializaVetor(cRegioes, 8, 0);

    printf("Digite o Codigo do Produto que deseja: ");
    scanf("%d", &codigoProd);
    printf("\nDigite a Região que deseja enviar o produto: ");
    scanf("%s", regiao);
    

    while(codigoProd > 0){
        idProd = buscaInt(vIdProd, 12, codigoProd);
        idReg = buscaTexto(vRegioes, 8, regiao);
        printf("\n=========================================\n");
        if(idReg >= 0){
                
            if(idProd >= 0 ){
                
                printf("\nValor do Produto: R$%.2f", vPrecoProd[idProd] );
                printf("\nValor da Embalagem: R$%.2f",vPrecoEmb[vEmbProd[idProd] - 1] );
                
                printf("\nValor do Taxa de Entrega: R$%.2f",vTxEntrega[idReg]);

                total = vPrecoProd[idProd] + vPrecoEmb[vEmbProd[idProd] - 1] + vTxEntrega[idReg];

                printf("\nValor Total: R$%.2f \n", total);

                cRegioes[idReg]++;
                
            }
            else{
                printf("\nCodigo do Produto está inválido.");
            }
            
        }
        else{
            printf("\nRegião Inválida ou não está disponível para entrega\n(Tente utilizar todas as letras maiusculas ex:. SU ou CO) \n");
        }
        
        printf("\n=========================================\n");

        printf("\nDigite o Codigo do Produto que deseja: ");
        scanf("%d", &codigoProd); 
        printf("Digite a Região que deseja enviar o produto: ");
        scanf("%s", regiao);
      
    }
    printf("\nServiço Terminado");

    printf("\n=========================================\n");
    ContabilizarRegiao(vRegioes, 8, cRegioes);
    printf("=========================================");
    return 0;
}