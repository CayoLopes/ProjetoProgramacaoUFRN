/* 
Projeto: Sistema de Gest�o para Farm�cias
UFRN|CERES|BSI
Programa��o|2023.2|Prof:Flavius Gorgonio
Discente: Cayo C�sar da Costa Lopes
 */


#include <stdio.h>
#include <locale.h>


void menu_inicial(void);
void menu_sobre(void);
void menu_equipe(void);
void sub_menu_produto(void);
void sub_menu_funcionario(void);
void sub_menu_cliente(void);
void sub_menu_venda(void);

int main(void){
    setlocale(LC_ALL,"Portuguese");

    menu_inicial();
    sub_menu_produto();
    sub_menu_funcionario();
    sub_menu_cliente();
    sub_menu_venda();
    menu_sobre();
    menu_equipe();

    return 0;
}


void menu_inicial(void){

    printf("\n");
    printf("********************************************************************************* \n");    
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M � C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n");
    printf("**                      1 - Menu Produtos                                      ** \n");
    printf("**                      2 - Menu Funcion�rios                                  ** \n");
    printf("**                      3 - Menu Clientes                                      ** \n");
    printf("**                      4 - Menu Vendas                                        ** \n");
    printf("**                      5 - Menu Sobre o Programa                              ** \n");
    printf("**                      6 - Menu Sobre o Programador                           ** \n");
    printf("**                      0 - Sair                                               ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
}


void sub_menu_produto(void){

    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M � C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n"); 
    printf("********************************************************************************* \n");
    printf("**                      1 - Produtos cadastrados                               ** \n");
    printf("**                      2 - Cadastrar produto                                  ** \n");
    printf("**                      3 - Informa��es de produtos                            ** \n");
    printf("**                      4 - Editar/Apagar produto                              ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
}


void sub_menu_funcionario(void){


    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M � C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n"); 
    printf("********************************************************************************* \n");
    printf("**                      1 - Funcion�rios cadastrados                           ** \n");
    printf("**                      2 - Cadastrar funcion�rio                              ** \n");
    printf("**                      3 - Ficha do funcion�rio                               ** \n");
    printf("**                      4 - Editar/Apagar ficha do funcion�rio                 ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");    
}



void sub_menu_cliente(void){

    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M � C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n"); 
    printf("********************************************************************************* \n");
    printf("**                      1 - Clientes cadastrados                               ** \n");
    printf("**                      2 - Cadastrar cliente                                  ** \n");
    printf("**                      3 - Ficha do cliente                                   ** \n");
    printf("**                      4 - Editar/Apagar ficha do cliente                     ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
}


void sub_menu_venda(){

    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M � C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n"); 
    printf("********************************************************************************* \n");
    printf("**                      1 - Realizar uma venda                                 ** \n");
    printf("**                      2 - Relat�rio de vendas                                ** \n");
    printf("**                      3 - Editar/Apagar uma venda                            ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
}


void menu_sobre(void){

    printf("\n");
    printf("********************************************************************************* \n");    
    printf("*****************************                     ******************************* \n");
    printf("**      O programa apresentado servir� como um meio de avalia��o para o per�o- ** \n");
    printf("** do de 2023.2 na mat�ria de programa��o (DCT1106) do curso de Sistemas de    ** \n");
    printf("** Informa��o. O programa deve conter os m�dulos e funcionalidades que ser�o   ** \n");
    printf("** exigidas no decorrer da disciplina de programa��o. Qualquer altera��o ser�  ** \n");
    printf("** registrada no reposit�rio do projeto, no perfil do aluno que o desenvolveu. ** \n");
    printf("** � possivel visualizar esse programa no link HTTPS abaixo.                   ** \n");
    printf("** https://github.com/CayoLopes/ProjetoProgramacaoUFRN.git                     ** \n");
    printf("*****************************                     ******************************* \n");
    printf("********************************************************************************* \n");
    printf("\n");
}


void menu_equipe(void){

    printf("\n");
    printf("********************************************************************************* \n");
    printf("*****************************                     ******************************* \n");
    printf("**                                                                             ** \n");   
    printf("**              Este projeto foi desenvolvido por:                             ** \n");
    printf("**                                                                             ** \n");
    printf("**              Discente: Cayo C�sar da Costa Lopes                            ** \n");
    printf("**              E-mail: cayocesarlopes@gmail.com                               ** \n");
    printf("**              Perfil git: https://github.com/CayoLopes                       ** \n");
    printf("**                                                                             ** \n");
    printf("*****************************                     ******************************* \n");
    printf("********************************************************************************* \n");
    printf("\n");
} 