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


int editar_cliente(char *termo_busca) {
    FILE *file = fopen("clientes.dat", "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para edição.\n");
        return 0; // Falha na abertura do arquivo
    }

    Cliente cliente;

    while (fread(&cliente, sizeof(Cliente), 1, file) == 1) {
        if (strcmp(cliente.cpf, termo_busca) == 0 || strcmp(cliente.nome, termo_busca) == 0) {
            
            printf("Cliente encontrado. Edite as informações:\n");

            // Solicite as edições aos campos necessários
            printf("Novo nome: ");
            limparBuffer();
            fgets(cliente.nome, sizeof(cliente.nome), stdin);
            cliente.nome[strcspn(cliente.nome, "\n")] = '\0';

            if (validarNome(cliente.nome)) {
                printf("\n");
            } else {
                printf("Nome inválido.\n");
            }


            printf("Novo CPF: ");
            scanf(" %s", cliente.cpf);
            getchar();

            if (validarCPF(cliente.cpf)) {
                printf("\n");
            } else {
                printf("CPF inválido.\n");
            }

          
            printf("Novo email: ");
            scanf(" %s", cliente.email);
            getchar();

            if (verificar_email(cliente.email)) {
                printf("\n");
            } else {
                printf("E-mail inválido\n");
            }

            printf("Novo endereço: ");
            fgets(cliente.ender, sizeof(cliente.ender), stdin);
            cliente.ender[strcspn(cliente.ender, "\n")] = '\0';

            printf("Informações atualizadas com sucesso!\n");
            printf("********************************************************************************* \n");

            fseek(file, -sizeof(Cliente), SEEK_CUR); // Retroceder o ponteiro no arquivo
            fwrite(&cliente, sizeof(Cliente), 1, file); // Gravar as informações editadas
            fclose(file);

            return 1; // Sucesso na edição
        }
    }

    fclose(file);

    return 0; // Cliente não encontrado
}



void edit_cliente() {
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("*************************   E D I T A R  C L I E N T E   ************************ \n");
    printf("********************************************************************************* \n");

    char termo_busca[50];
    printf("Digite o nome ou CPF do cliente a ser editado: ");
    scanf(" %s", termo_busca);

    if (editar_cliente(termo_busca)) {
        printf("Cliente editado com sucesso!\n");
    } else {
        printf("Cliente não encontrado ou erro na edição.\n");
    }

    printf("Pressione Enter para retornar\n");
    getchar();
}




int deletar_cliente(char *termo_busca) {
    FILE *file = fopen("clientes.dat", "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para edição.\n");
        return 0; // Falha na abertura do arquivo
    }

    Cliente cliente;

    while (fread(&cliente, sizeof(Cliente), 1, file) == 1) {
        if (strcmp(cliente.cpf, termo_busca) == 0 || strcmp(cliente.nome, termo_busca) == 0) {
            printf("Cliente encontrado. Os dados do cliente serão substituidos por \"xxxx\":\n");

            
            strcpy(cliente.nome, "xxxx");
            strcpy(cliente.cpf, "xxxx");
            strcpy(cliente.email, "xxxx");
            strcpy(cliente.ender, "xxxx");
            getchar();

            printf("Dados substituídas por \"xxxx\" com sucesso!\n");
            printf("********************************************************************************* \n");

            fseek(file, -sizeof(Cliente), SEEK_CUR); // Retroceder o ponteiro no arquivo
            fwrite(&cliente, sizeof(Cliente), 1, file); // Gravar as informações editadas
            fclose(file);

            return 1; // Sucesso na edição
        }
    }

    fclose(file);

    return 0; // Cliente não encontrado
}



void apaga_cliente() {
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("************************   D E L E T A R  C L I E N T E   *********************** \n"); 
    printf("********************************************************************************* \n");
    char termo_busca[50];
    printf("Digite o nome ou CPF do cliente a ser deletado: ");
    scanf(" %s", termo_busca);

    if (deletar_cliente(termo_busca)) {
        printf("\n");
        printf("Cliente deletado com sucesso!\n"); 
        
    } else {
        printf("Cliente não encontrado ou erro na exclusão.\n"); 
    }

    printf("Pressione Enter para retornar\n");
    getchar();
}

