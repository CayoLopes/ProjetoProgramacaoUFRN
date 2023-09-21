#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funcionarios.h"

void clearScreen();

void modulo_funcionario(void) {
    char opcao;
    do {
        opcao = sub_menu_funcionario();
        switch(opcao) {
            case '1': 	funcio_ja_cad();
                        break;
            case '2':   cadas_func();
                        break;
            case '3':   ficha_func();
                        break; 
            case '4':   edit_fun();
                        break;
        }
    } while (opcao != '0');
}


char sub_menu_funcionario(){

    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M A C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n");
    printf("*******************   M E N U  D E  F U N C I O N A R I O S   ******************* \n"); 
    printf("********************************************************************************* \n");
    printf("**                      1 - Funcionarios cadastrados                           ** \n");
    printf("**                      2 - Cadastrar funcionario                              ** \n");
    printf("**                      3 - Ficha do funcionario                               ** \n");
    printf("**                      4 - Editar/Apagar ficha do funcionario                 ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");    
    scanf("%c", &op);
    getchar();
    return op;
}


char funcio_ja_cad(){
    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("***************   R E G I S T R O  D E  F U N C I O N A R I O S   *************** \n"); 
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

char cadas_func(){

    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("******************   C A D A S T R A R  F U N C I O N A R I O   ***************** \n"); 
    printf("********************************************************************************* \n");
    printf("**          Digite o nome:...                                                  ** \n");
    printf("**          Digite o CPF:...                                                   ** \n");
    printf("**          Digite o cargo/função:...                                          ** \n");
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




char ficha_func(){

  char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("*******************   F I C H A  D E  F U N C I O N A R I O   ******************* \n"); 
    printf("********************************************************************************* \n");
    printf("**          Nome:                                                              ** \n");
    printf("**          CPF:                                                               ** \n");
    printf("**          Cargo:                                                             ** \n");
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


char edit_fun(){
  char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("*********************   E D I T A R  F U N C I O N A R I O   ******************** \n"); 
    printf("********************************************************************************* \n");
    printf("**          Novo nome:...                                                      ** \n");
    printf("**          Novo CPF:...                                                       ** \n");
    printf("**          Novo cargo/função:...                                              ** \n");
    printf("**          Novo email:...                                                     ** \n");
    printf("**          Novo endereço:...                                                  ** \n");
    printf("**          Outras informações:...                                             ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");    
    scanf(" %c", &op);
    getchar();
    return op;

  
}