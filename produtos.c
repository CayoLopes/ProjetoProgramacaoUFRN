#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "produtos.h"

void clearScreen();


void modulo_produto(void){
  char opcao;
    do {
        opcao = sub_menu_produto();
        switch(opcao) {
            case '1': 	produto_cads();
                        break;
            case '2':   cadas_produto();
                        break;
            case '3':   info_produto();
                        break; 
            case '4':   edit_produto();
                        break;
        }
    } while (opcao != '0');

    
}

char sub_menu_produto(){

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
    return op;
}

char produto_cads(){
  char op;
    clearScreen();
    printf("\n");

    printf("********************************************************************************* \n"); 
    printf("********************  P R O D U T O S  C A D A S T R A D O S  ******************* \n");
    printf("********************************************************************************* \n");
    printf("**                                                                             ** \n");
    printf("**                 Nome:                                                       ** \n");
    printf("**                 Código:                                                     ** \n");
    printf("**                 Estoque:                                                    ** \n");
    printf("**                                                                             ** \n");
    printf("**                 Nome:                                                       ** \n");
    printf("**                 Código:                                                     ** \n");
    printf("**                 Estoque:                                                    ** \n");
    printf("**                                                                             ** \n");
    printf("**                 Nome:                                                       ** \n");
    printf("**                 Código:                                                     ** \n");
    printf("**                 Estoque:                                                    ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;
  
}

char cadas_produto(){
    char op;
    clearScreen();
    printf("\n");

    printf("********************************************************************************* \n"); 
    printf("**********************  C A D A S T R A R  P R O D U T O S  ********************* \n");
    printf("********************************************************************************* \n");
    printf("**                                                                             ** \n");
    printf("**                 Digite o nome:                                              ** \n");
    printf("**                 Digite o código:                                            ** \n");
    printf("**                 Digite o preço:                                             ** \n");
    printf("**                 Digite o estoque:                                           ** \n");
    printf("**                 Digite a descrição:                                         ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;
  


}

char info_produto(){
    char op;
    clearScreen();
    printf("\n");

    printf("********************************************************************************* \n"); 
    printf("*******************  I N F O R M A C O E S  D O  P R O D U T O  ***************** \n");
    printf("********************************************************************************* \n");
    printf("**                                                                             ** \n");
    printf("**                 nome:                                                       ** \n");
    printf("**                 Código:                                                     ** \n");
    printf("**                 Preço:                                                      ** \n");
    printf("**                 Estoque:                                                    ** \n");
    printf("**                 Descrição:                                                  ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;
  


}


char edit_produto(){
    char op;
    clearScreen();
    printf("\n");

    printf("********************************************************************************* \n"); 
    printf("*************************  E D I T A R  P R O D U T O  ************************* \n");
    printf("********************************************************************************* \n");
    printf("**                                                                             ** \n");
    printf("**                 Novo nome:                                                  ** \n");
    printf("**                 Novo código:                                                ** \n");
    printf("**                 Novo preço:                                                 ** \n");
    printf("**                 Novo estoque:                                               ** \n");
    printf("**                 Nova descrição:                                             ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;

}

