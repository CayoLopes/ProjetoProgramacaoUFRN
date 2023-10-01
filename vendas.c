#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "vendas.h"

void clearScreen();

void modulo_venda(void) {
    char opcao;
    do {
        opcao = sub_menu_venda();
        switch(opcao) {
            case '1': 	venda();
                        break;
            case '2':   relatorio_venda();
                        break;
            case '3':   edit_venda();
                        break; 
        }
    } while (opcao != '0');
}


char sub_menu_venda(){

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
    printf("**                      3 - Cancelar venda                                     ** \n");
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
    printf("**               Digite o CPF do cliente:                                      ** \n");
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
    printf("************************    C A N C E L A R  V E N D A    *********************** \n");
    printf("********************************************************************************* \n");
    printf("**                                                                             ** \n");
    printf("**               Sobre a venda:                                                ** \n");
    printf("**               Digite o código:                                              ** \n");
    printf("**                                                                             ** \n");
    printf("**               Deseja realmente cancelar a venda? (s/S|n/N)                  ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;




}