#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "clientes.h"
#include <string.h>
#include "util.h"

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
            case '5':   apaga_cliente();
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
    printf("**                      4 - Editar ficha do cliente                            ** \n");
    printf("**                      5 - Apagar ficha do cliente                            ** \n");
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
  struct cliente Cliente;
  
  char op;
    fflush(stdin);
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************   C A D A S T R A R  C L I E N T E   ********************* \n"); 
    printf("********************************************************************************* \n");
    printf("**          Digite o nome:...                                                  ** \n");
    fgets(Cliente.nome, sizeof(Cliente.nome), stdin);
    Cliente.nome[strcspn(Cliente.nome, "\n")] = '\0';
    if (validarNome(Cliente.nome)) {
        printf("\n");
     } else {
        printf("Nome inválido.\n");  
     } 
    printf("**          Digite o CPF:...                                                   ** \n");
    scanf(" %s", Cliente.cpf);
    getchar();
    if (validarCPF(Cliente.cpf)) {
        printf("\n");
    } else{
       printf("CPF inválido.\n" );
    }
    printf("**          Digite o email:...                                                 ** \n");
    scanf(" %s", Cliente.email);
    getchar();
    if (verificar_email(Cliente.email)){
        printf("\n");
    } else {
       printf("E-mail inválido\n");
    }
    printf("**          Digite o endereço:...                                              ** \n");
    fgets(Cliente.ender, sizeof(Cliente.ender), stdin);
    Cliente.ender[strcspn(Cliente.ender, "\n")] = '\0';
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

char apaga_cliente(){
  char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("************************   D E L E T A R  C L I E N T E   *********************** \n"); 
    printf("********************************************************************************* \n");
    printf("**          Para apagar a ficha:                                               ** \n");
    printf("**                                                                             ** \n");
    printf("**          Digite o CPF:...                                                   ** \n");
    printf("**                                                                             ** \n");
    printf("**          Deseja realmente deletar a ficha? (s/S|n/N)                        ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");    
    scanf(" %c", &op);
    getchar();
    return op;


}