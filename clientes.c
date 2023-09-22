#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "clientes.h"

void clearScreen();


void modulo_cliente(void){
    char opcao;
    do {
        opcao = sub_menu_cliente();
        switch(opcao) {
            case '1': 	cliente_ja_cad();
                        break;
            case '2':   cadas_cliente();
                        break;
            case '3':   ficha_cliente();
                        break; 
            case '4':   edit_cliente();
                        break;
        }
    } while (opcao != '0');
}



char sub_menu_cliente(){
    
    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M A C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n");
    printf("**********************    M E N U  D E  C L I E N T E S    ********************** \n");
    printf("********************************************************************************* \n");
    printf("**                      1 - Clientes cadastrados                               ** \n");
    printf("**                      2 - Cadastrar cliente                                  ** \n");
    printf("**                      3 - Ficha do cliente                                   ** \n");
    printf("**                      4 - Editar/Apagar ficha do cliente                     ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;
}

char cliente_ja_cad(){
    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("*******************   R E G I S T R O  D E  C L I E N T E S   ******************* \n"); 
    printf("********************************************************************************* \n");
    printf("**          Nome:                                                              ** \n");
    printf("**          CPF:                                                               ** \n");
    printf("**                                                                             ** \n");
    printf("**          Nome:                                                              ** \n");
    printf("**          CPF:                                                               ** \n");
    printf("**                                                                             ** \n");
    printf("**          Nome:                                                              ** \n");
    printf("**          CPF                                                                ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");    
    scanf(" %c", &op);
    getchar();
    return op;
}


char cadas_cliente(){
  char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************   C A D A S T R A R  C L I E N T E   ********************* \n"); 
    printf("********************************************************************************* \n");
    printf("**          Digite o nome:...                                                  ** \n");
    printf("**          Digite o CPF:...                                                   ** \n");
    printf("**          Digite o email:...                                                 ** \n");
    printf("**          Digite o endereço:...                                              ** \n");
    printf("**          Outras informações:...                                             ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");    
    scanf(" %c", &op);
    getchar();
    return op;

  
}

char ficha_cliente(){

  char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("***********************   F I C H A  D E  C L I E N T E   *********************** \n"); 
    printf("********************************************************************************* \n");
    printf("**          Nome:                                                              ** \n");
    printf("**          CPF:                                                               ** \n");
    printf("**          Email:                                                             ** \n");
    printf("**          Endereço:                                                          ** \n");
    printf("**          Outros:                                                            ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");    
    scanf(" %c", &op);
    getchar();
    return op;
}


char edit_cliente(){
  char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("*************************   E D I T A R  C L I E N T E   ************************ \n"); 
    printf("********************************************************************************* \n");
    printf("**          Novo nome:...                                                      ** \n");
    printf("**          Novo CPF:...                                                       ** \n");
    printf("**          Novo email:...                                                     ** \n");
    printf("**          Novo endereço:...                                                  ** \n");
    printf("**          Nova informações:...                                               ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");    
    scanf(" %c", &op);
    getchar();
    return op;

  
}