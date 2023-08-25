/* 
Projeto: Sistema de Gestão para Farmácias
UFRN|CERES|BSI
Programação|2023.2|Prof:Flavius Gorgonio
Discente: Cayo César da Costa Lopes
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
    printf("\n");
}


void sub_menu_produto(void){

    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M Á C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n"); 
    printf("********************************************************************************* \n");
    printf("**                      1 - Produtos cadastrados                               ** \n");
    printf("**                      2 - Cadastrar produto                                  ** \n");
    printf("**                      3 - Informações de produtos                            ** \n");
    printf("**                      4 - Editar/Apagar produto                              ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
}


void sub_menu_funcionario(void){


    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M Á C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n"); 
    printf("********************************************************************************* \n");
    printf("**                      1 - Funcionários cadastrados                           ** \n");
    printf("**                      2 - Cadastrar funcionário                              ** \n");
    printf("**                      3 - Ficha do funcionário                               ** \n");
    printf("**                      4 - Editar/Apagar ficha do funcionário                 ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");    
}



void sub_menu_cliente(void){

    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M Á C I A   E M   C                 *********** \n");
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
    printf("***********                 F A R M Á C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n"); 
    printf("********************************************************************************* \n");
    printf("**                      1 - Realizar uma venda                                 ** \n");
    printf("**                      2 - Relatório de vendas                                ** \n");
    printf("**                      3 - Editar/Apagar uma venda                            ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
}


void menu_sobre(void){

    printf("\n");
    printf("********************************************************************************* \n");    
    printf("*****************************                     ******************************* \n");
    printf("**      O programa apresentado servirá como um meio de avaliação para o perío- ** \n");
    printf("** do de 2023.2 na matéria de programação (DCT1106) do curso de Sistemas de    ** \n");
    printf("** Informação. O programa deve conter os módulos e funcionalidades que serão   ** \n");
    printf("** exigidas no decorrer da disciplina de programação. Qualquer alteração será  ** \n");
    printf("** registrada no repositório do projeto, no perfil do aluno que o desenvolveu. ** \n");
    printf("** É possivel visualizar esse programa no link HTTPS abaixo.                   ** \n");
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
    printf("**              Discente: Cayo César da Costa Lopes                            ** \n");
    printf("**              E-mail: cayocesarlopes@gmail.com                               ** \n");
    printf("**              Perfil git: https://github.com/CayoLopes                       ** \n");
    printf("**                                                                             ** \n");
    printf("*****************************                     ******************************* \n");
    printf("********************************************************************************* \n");
    printf("\n");
} 