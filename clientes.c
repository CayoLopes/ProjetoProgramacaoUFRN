#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "clientes.h"
#include <string.h>
#include "util.h"

void clearScreen();


void modulo_cliente(void){
  Cliente* cliente;
  struct cliente Cliente;
    char opcao;
    do {
        opcao = sub_menu_cliente();
        switch(opcao) {
            case '1': 	cliente_ja_cad(cliente);
                        break;
            case '2':   cliente = cadas_cliente();
                        gravar_cliente(cliente);
                        break;
            case '3':   pesquisa_cliente(cliente);
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
    printf("**                      3 - Pesquisar cliente                                   ** \n");
    printf("**                      4 - Editar ficha do cliente                            ** \n");
    printf("**                      5 - Apagar ficha do cliente                            ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;
}

char cliente_ja_cad(Cliente* cliente){
  
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("*******************   R E G I S T R O  D E  C L I E N T E S   ******************* \n"); 
    printf("********************************************************************************* \n");
    FILE* fp;
    Cliente clien;
    fp = fopen("clientes.dat", "rb"); // Abra o arquivo para leitura binária
  
    if (fp == NULL) {
         printf("Ops! Erro na abertura do arquivo!\n");
         printf("Não é possível continuar...\n");
         exit(1);
     }
  
    while (fread(&clien, sizeof(Cliente), 1, fp) == 1) {
        printf("Nome: %s\n", clien.nome);
        printf("CPF: %s\n", clien.cpf);
        printf("E-mail: %s\n", clien.email);
        printf("Endereço: %s\n", clien.ender);
        printf("\n");
       }
  
     fclose(fp);
  
     printf("Pressione Enter para retornar ao menu principal...");
     getchar();
}


Cliente* cadas_cliente(void){
  Cliente* clien;
  clien = (Cliente*) malloc(sizeof(Cliente));
  
    fflush(stdin);
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************   C A D A S T R A R  C L I E N T E   ********************* \n"); 
    printf("********************************************************************************* \n");
    printf("**          Digite o nome:...                                                  ** \n");
    fgets(clien->nome, sizeof(clien->nome), stdin);
    clien->nome[strcspn(clien->nome, "\n")] = '\0';
    if (validarNome(clien->nome)) {
        printf("\n");
     } else {
        printf("Nome inválido.\n");  
     } 
    printf("**          Digite o CPF:...                                                   ** \n");
    scanf(" %s", clien->cpf);
    getchar();
    if (validarCPF(clien->cpf)) {
        printf("\n");
    } else{
       printf("CPF inválido.\n" );
    }
    printf("**          Digite o email:...                                                 ** \n");
    scanf(" %s", clien->email);
    getchar();
    if (verificar_email(clien->email)){
        printf("\n");
    } else {
       printf("E-mail inválido\n");
    }
    printf("**          Digite o endereço:...                                              ** \n");
    fgets(clien->ender, sizeof(clien->ender), stdin);
    clien->ender[strcspn(clien->ender, "\n")] = '\0';
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");    
    getchar();
    return clien;
  
}

void gravar_cliente(Cliente* clien){
  FILE* fp;
   fp = fopen("clientes.dat", "ab");
      if (fp == NULL) {
      printf("Ops! Erro na abertura do arquivo!\n");
      printf("Não é possível continuar...\n");
      exit(1);
      }
      fwrite(clien, sizeof(Cliente), 1, fp);
      fclose(fp);

}



void pesquisa_cliente(const Cliente* cliente) {
    char cpf[12];  
    Cliente clienteEncontrado;  
    int clienteEncontradoFlag = 0;  

    clearScreen();  

  printf("********************************************************************************* \n");
  printf("*********************   P E S Q U I S A R  C L I E N T E   ********************** \n");
  printf("********************************************************************************* \n");
  printf("Digite o CPF do cliente a ser pesquisado: ");
  scanf("%s", cpf);

    FILE* file = fopen("clientes.dat", "rb");  

    if (file == NULL) {  
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (fread(&clienteEncontrado, sizeof(Cliente), 1, file) == 1) {  
        if (strcmp(clienteEncontrado.cpf, cpf) == 0) {  
            printf("\n");
            printf("Nome: %s\n", clienteEncontrado.nome);
            printf("CPF: %s\n", clienteEncontrado.cpf); 
            printf("E-mail: %s\n" , clienteEncontrado.email);
            printf("Endereço: %s\n" , clienteEncontrado.ender);
            printf("\n");
            printf("********************************************************************************* \n");
            clienteEncontradoFlag = 1;  
            break; 
        }
    }

    if (!clienteEncontradoFlag) {  
        printf("Cliente com CPF %s não encontrado.\n", cpf);
        printf("********************************************************************************* \n");
    }

    fclose(file);  

    getchar();
    printf("\n");
    printf("Pressione Enter para retornar\n");
    getchar();
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