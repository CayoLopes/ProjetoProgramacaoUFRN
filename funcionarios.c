#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "funcionarios.h"
#include "util.h"

void clearScreen();

void modulo_funcionario(void) {
  Funcionario* funcionario;
  struct funcionario Funcionario;
    char opcao;
    do {
        opcao = sub_menu_funcionario();
        switch(opcao) {
            case '1': 	funcio_ja_cad(funcionario);
                        break;
            case '2':   funcionario = cadas_func();
                        gravar_func(funcionario);
                        break;
            case '3':   ficha_func();
                        break; 
            case '4':   edit_fun();
                        break;
            case '5':   apaga_fun();
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
    printf("**                      4 - Editar ficha do funcionario                        ** \n");
    printf("**                      5 - Apagar ficha do funcionario                        ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");    
    scanf("%c", &op);
    getchar();
    return op;
}


char funcio_ja_cad(Funcionario* funcionario){
    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("***************   R E G I S T R O  D E  F U N C I O N A R I O S   *************** \n"); 
    printf("********************************************************************************* \n");
    FILE* fp;
    Funcionario func;
    fp = fopen("funcionarios.dat", "rb"); // Abra o arquivo para leitura binária

    if (fp == NULL) {
         printf("Ops! Erro na abertura do arquivo!\n");
         printf("Não é possível continuar...\n");
         exit(1);
     }

    while (fread(&func, sizeof(Funcionario), 1, fp) == 1) {
        printf("Nome: %s\n", func.nome);
        printf("CPF: %s\n", func.cpf);
        printf("Cargo: %s\n", func.cargo);
        printf("E-mail: %s\n", func.email);
        printf("Endereço: %s\n", func.ender);
        printf("\n");
       }

     fclose(fp);

     printf("Pressione Enter para retornar ao menu principal...");
     getchar();
    }


Funcionario* cadas_func(void){
  Funcionario* func;
  func = (Funcionario*) malloc(sizeof(Funcionario));

    fflush(stdin);
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("******************   C A D A S T R A R  F U N C I O N A R I O   ***************** \n"); 
    printf("********************************************************************************* \n");
    printf("**          Digite o nome:                                                     ** \n");
    fgets(func->nome, sizeof(func->nome), stdin);
    func->nome[strcspn(func->nome, "\n")] = '\0';
    if (validarNome(func->nome)) {
        printf("\n");
     } else {
        printf("Nome inválido.\n");  
     } 
    printf("**          Digite o CPF:                                                      ** \n");
    scanf(" %s", func->cpf);
    getchar();
    if (validarCPF(func->cpf)) {
        printf("\n");
    } else{
       printf("CPF inválido.\n" );
    }
    printf("**          Digite o cargo/função:                                             ** \n");
    scanf(" %s",func->cargo);
    getchar();
    printf("**          Digite o email:                                 funcionarios                   ** \n");
    scanf(" %s", func->email);
    getchar();
    if (verificar_email(func->email)){
        printf("\n");
    } else {
       printf("E-mail inválido\n");
    }
    printf("**          Digite o endereço:                                                 ** \n");
    fgets(func->ender, sizeof(func->ender), stdin);
    func->ender[strcspn(func->ender, "\n")] = '\0';
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");    
    getchar();
    return func;

}


void gravar_func(Funcionario* func){
  FILE* fp;
   fp = fopen("funcionarios.dat", "ab");
      if (fp == NULL) {
      printf("Ops! Erro na abertura do arquivo!\n");
      printf("Não é possível continuar...\n");
      exit(1);
      }
      fwrite(func, sizeof(Funcionario), 1, fp);
      fclose(fp);



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

char apaga_fun(){
    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("********************   D E L E T A R  F U N C I O N A R I O   ******************* \n"); 
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