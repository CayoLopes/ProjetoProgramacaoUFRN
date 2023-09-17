#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "equipe.h"

void clearScreen();



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