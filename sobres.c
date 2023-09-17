#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sobres.h"

void clearScreen();



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

