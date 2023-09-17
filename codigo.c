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

/*Essa função foi gerada pelo CHATGPT para limpar as telas dos menus*/
void clearScreen() {
#ifdef _WIN32
    system("cls"); // Limpa a tela no Windows
#else
    system("clear"); // Limpa a tela em sistemas Unix/Linux
#endif
}



char menu_inicial(void);
void menu_sobre(void);
void menu_equipe(void);

void sub_menu_funcionario(void);
void sub_menu_cliente(void);
void sub_menu_venda(void);

int main(void){
   char opcao;

    do {
        opcao = menu_inicial();
        switch(opcao) {
            case '1':
                     sub_menu_produto();
                     break;
            case '2':
                     sub_menu_funcionario();
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

void sub_menu_funcionario(void){

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
}



void sub_menu_cliente(void){
    
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
}


void sub_menu_venda(){

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
}


void menu_sobre(void){

    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");    
    printf("*****************************                     ******************************* \n");
    printf("**      O programa apresentado servira como um meio de avaliacao para o perio- ** \n");
    printf("** do de 2023.2 na materia de programacao (DCT1106) do curso de Sistemas de    ** \n");
    printf("** Informacao. O programa deve conter os modulos e funcionalidades que serao   ** \n");
    printf("** exigidas no decorrer da disciplina de programacao. Qualquer alteracao sera  ** \n");
    printf("** registrada no repositorio do projeto, no perfil do aluno que o desenvolveu. ** \n");
    printf("** E possivel visualizar esse programa no link HTTPS abaixo.                   ** \n");
    printf("** https://github.com/CayoLopes/ProjetoProgramacaoUFRN.git                     ** \n");
    printf("*****************************                     ******************************* \n");
    printf("********************************************************************************* \n");
    printf("Selecione 0 para voltar \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
}


void menu_equipe(void){

    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("*****************************                     ******************************* \n");
    printf("**                                                                             ** \n");   
    printf("**              Este projeto foi desenvolvido por:                             ** \n");
    printf("**                                                                             ** \n");
    printf("**              Discente: Cayo Cesar da Costa Lopes                            ** \n");
    printf("**              E-mail: cayocesarlopes@gmail.com                               ** \n");
    printf("**              Perfil git: https://github.com/CayoLopes                       ** \n");
    printf("**                                                                             ** \n");
    printf("*****************************                     ******************************* \n");
    printf("********************************************************************************* \n");
    printf("Selecione 0 para voltar \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
} 