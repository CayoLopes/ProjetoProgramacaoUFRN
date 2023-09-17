#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "produtos.h"

void clearScreen();



void sub_menu_produto(void){

    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M A C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n"); 
    printf("**********************    M E N U  D E  P R O D U T O S    ********************** \n");
    printf("********************************************************************************* \n");
    printf("**                      1 - Produtos cadastrados                               ** \n");
    printf("**                      2 - Cadastrar produto                                  ** \n");
    printf("**                      3 - Informacoes de produtos                            ** \n");
    printf("**                      4 - Editar/Apagar produto                              ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
}
