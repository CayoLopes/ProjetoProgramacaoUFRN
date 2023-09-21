/* 
Projeto: Sistema de Gestão para Farmácias
UFRN|CERES|BSI
Programação|2023.2|Prof:Flavius Gorgonio
Discente: Cayo César da Costa Lopes
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "produtos.h"
#include "funcionarios.h"
#include "clientes.h"
#include "vendas.h"
#include "sobres.h"
#include "equipe.h"

/*Essa função foi gerada pelo CHATGPT para limpar as telas dos menus*/
void clearScreen() {
#ifdef _WIN32
    system("cls"); // Limpa a tela no Windows
#else
    system("clear"); // Limpa a tela em sistemas Unix/Linux
#endif
}



char menu_inicial(void);


int main(void){
   char opcao;

    do {
        opcao = menu_inicial();
        switch(opcao) {
            case '1':
                     modulo_produto();
                     break;
            case '2':
                     modulo_funcionario();
                     break;
            case '3':
                     sub_menu_cliente();
                     break;
            case '4':
                     sub_menu_venda();
                     break;
            case '5':
                     menu_sobre();
                     break;    
            case '6':
                     menu_equipe();
                     break;
        }
      }while (opcao != '0');

    return 0;
}


char menu_inicial(void){
    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");    
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M A C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n");
    printf("**                      1 - Menu Produtos                                      ** \n");
    printf("**                      2 - Menu Funcionarios                                  ** \n");
    printf("**                      3 - Menu Clientes                                      ** \n");
    printf("**                      4 - Menu Vendas                                        ** \n");
    printf("**                      5 - Menu Sobre o Programa                              ** \n");
    printf("**                      6 - Menu Sobre o Programador                           ** \n");
    printf("**                      0 - Sair                                               ** \n");  
    printf("**                                                                             ** \n");
    printf("*************           Escolha a opcao desejada:                   ************* \n");
    printf("*****************                                               ***************** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;   

}






