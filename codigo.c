/* 
Projeto: Sistema de Gestão para Farmácias
UFRN|CERES|BSI
Programação|2023.2|Prof:Flavius Gorgonio
Discente: Cayo César da Costa Lopes
 */


#include <stdio.h>
#include <locale.h>


void menu_inicial(void);

int main(void){
    setlocale(LC_ALL,"Portuguese");

    menu_inicial();

    return 0;
}


void menu_inicial(void){


    printf("********************************************************************************* \n");    
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M Á C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n");
    printf("**                      1 - Menu Produtos                                      ** \n");
    printf("**                      2 - Menu Funcionários                                  ** \n");
    printf("**                      3 - Menu Clientes                                      ** \n");
    printf("**                      4 - Menu Vendas                                        ** \n");
    printf("**                      5 - Menu Sobre o Programa                              ** \n");
    printf("**                      6 - Menu Sobre o Programador                           ** \n");
    printf("**                      0 - Sair                                               ** \n");
    printf("********************************************************************************* \n");

}