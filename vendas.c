#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "vendas.h"

void clearScreen();



void sub_menu_venda(void){

    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M A C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n");
    printf("**********************      M E N U  D E  V E N D A S      ********************** \n");
    printf("********************************************************************************* \n");
    printf("**                      1 - Realizar uma venda                                 ** \n");
    printf("**                      2 - Relatorio de vendas                                ** \n");
    printf("**                      3 - Editar/Apagar uma venda                            ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;
}

char venda(){
    char op;
    clearScreen();
    printf("********************************************************************************* \n");
    printf("**********************      R E A L I Z A R  V E N D A      ********************* \n");
    printf("********************************************************************************* \n");
    printf("**               Sobre o produto                                               ** \n");
    printf("**               Digite o código:                                              ** \n");
    printf("**               Digite o número da venda:                                     ** \n");
    printf("**               Digite a quantidade:                                          ** \n");
    printf("**               Digite o CPF do cliente:                                       ** \n");
    printf("**               Sobre a venda:                                                ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;
  
}

char relatorio_venda(){
  char op;
    clearScreen();
    printf("********************************************************************************* \n");
    printf("*******************     R E L A T Ó R I O  D E  V E N D A S    ****************** \n");
    printf("********************************************************************************* \n");
    printf("**               Sobre a venda                                                 ** \n");
    printf("**               Digite número da venda:                                       ** \n");
    printf("********************************************************************************* \n");
    printf("**               Nome do cliente:                                              ** \n");
    printf("**               Produto:                                                      ** \n");
    printf("**               Quantidade:                                                   ** \n");
    printf("**               Valor total:                                                  ** \n");
    printf("**               Sobre a venda:                                                ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;
  
  
}

char edit_venda(){
    char op;
    clearScreen();
    printf("********************************************************************************* \n");
    printf("************************      E D I T A R  V E N D A      *********************** \n");
    printf("********************************************************************************* \n");
    printf("**               Novo produto                                                  ** \n");
    printf("**               Novo código:                                                  ** \n");
    printf("**               Nova quantidade:                                              ** \n");
    printf("**               CPF do cliente:                                               ** \n");
    printf("**               Motivo da edição:                                             ** \n");
    printf("**               Sobre a venda:                                                ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;




}