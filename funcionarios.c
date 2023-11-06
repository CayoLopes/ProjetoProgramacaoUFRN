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
            case '3':   pesquisa_func(funcionario);
                        break; 
            case '4':   edit_func();
                        break;
            case '5':   apaga_func();
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
    printf("**                      3 - Pesquisar funcionario                              ** \n");
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



void pesquisa_func(const Funcionario* funcionario) {
    char cpf[12];  
    Funcionario funcionarioEncontrado;  
    int funcionarioEncontradoFlag = 0;  

    clearScreen();  

  printf("********************************************************************************* \n");
  printf("*****************   P E S Q U I S A R  F U N C I O N A R I O   ****************** \n");
  printf("********************************************************************************* \n");
  printf("Digite CPF do funcionário a ser pesquisado: ");
  scanf("%s", cpf);

    FILE* file = fopen("funcionarios.dat", "rb");  

    if (file == NULL) { 
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (fread(&funcionarioEncontrado, sizeof(Funcionario), 1, file) == 1) {  
        if (strcmp(funcionarioEncontrado.cpf, cpf) == 0) {  
            printf("\n");
            printf("Nome: %s\n", funcionarioEncontrado.nome);
            printf("CPF: %s\n", funcionarioEncontrado.cpf); 
            printf("Cargo: %s\n", funcionarioEncontrado.cargo);
            printf("E-mail: %s\n" , funcionarioEncontrado.email);
            printf("Endereço: %s\n" , funcionarioEncontrado.ender);
            printf("\n");
            printf("********************************************************************************* \n");
            funcionarioEncontradoFlag = 1;  
            break; 
        }
    }

    if (!funcionarioEncontradoFlag) {  
        printf("Funcionário com CPF %s não encontrado.\n", cpf);
        printf("********************************************************************************* \n");
    }

    fclose(file);  

    getchar();
    printf("\n");
    printf("Pressione Enter para retornar\n");
    getchar();
}


int editar_func(char *termo_busca) {
    FILE *file = fopen("funcionarios.dat", "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para edição.\n");
        return 0; // Falha na abertura do arquivo
    }

    Funcionario funcionario;

    while (fread(&funcionario, sizeof(Funcionario), 1, file) == 1) {
        if (strcmp(funcionario.cpf, termo_busca) == 0 || strcmp(funcionario.nome, termo_busca) == 0) {

            printf("Funcionario encontrado. Edite as informações:\n");

            // Solicite as edições aos campos necessários
            printf("Novo nome: ");
            limparBuffer();
            fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
            funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0';

            if (validarNome(funcionario.nome)) {
                printf("\n");
            } else {
                printf("Nome inválido.\n");
            }


            printf("Novo CPF: ");
            scanf(" %s", funcionario.cpf);
            getchar();

            if (validarCPF(funcionario.cpf)) {
                printf("\n");
            } else {
                printf("CPF inválido.\n");
            }

            printf("Novo cargo: ");
            scanf(" %s", funcionario.cargo);
            getchar();


          
            printf("Novo email: ");
            scanf(" %s", funcionario.email);
            getchar();

            if (verificar_email(funcionario.email)) {
                printf("\n");
            } else {
                printf("E-mail inválido\n");
            }

            printf("Novo endereço: ");
            fgets(funcionario.ender, sizeof(funcionario.ender), stdin);
            funcionario.ender[strcspn(funcionario.ender, "\n")] = '\0';

            printf("Informações atualizadas com sucesso!\n");
            printf("********************************************************************************* \n");

            fseek(file, -sizeof(Funcionario), SEEK_CUR); 
            fwrite(&funcionario, sizeof(Funcionario), 1, file); 
            fclose(file);

            return 1;
        }
    }

    fclose(file);

    return 0; 
}



void edit_func() {
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("*********************   E D I T A R  F U N C I O N A R I O   ******************** \n");
    printf("********************************************************************************* \n");

    char termo_busca[50];
    printf("Digite o nome ou CPF do funcionário a ser editado: ");
    scanf(" %s", termo_busca);

    if (editar_func(termo_busca)) {
        printf("Funcionário editado com sucesso!\n");
    } else {
        printf("Funcionário não encontrado ou erro na edição.\n");
    }

    printf("Pressione Enter para retornar\n");
    getchar();
}


int deletar_func(char *termo_busca) {
    FILE *file = fopen("funcionarios.dat", "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para edição.\n");
        return 0; // Falha na abertura do arquivo
    }

    Funcionario funcionario;

    while (fread(&funcionario, sizeof(Funcionario), 1, file) == 1) {
        if (strcmp(funcionario.cpf, termo_busca) == 0 || strcmp(funcionario.nome, termo_busca) == 0) {
            printf("Funcionario encontrado. Os dados do funcionario serão substituidos por \"xxxx\":\n");


            strcpy(funcionario.nome, "xxxx");
            strcpy(funcionario.cpf, "xxxx");
            strcpy(funcionario.cargo, "xxxx");
            strcpy(funcionario.email, "xxxx");
            strcpy(funcionario.ender, "xxxx");
            getchar();

            printf("Dados substituídas por \"xxxx\" com sucesso!\n");
            printf("********************************************************************************* \n");

            fseek(file, -sizeof(Funcionario), SEEK_CUR); // Retroceder o ponteiro no arquivo
            fwrite(&funcionario, sizeof(Funcionario), 1, file); // Gravar as informações editadas
            fclose(file);

            return 1; // Sucesso na edição
        }
    }

    fclose(file);

    return 0; // Cliente não encontrado
}


void apaga_func(){
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("********************   D E L E T A R  F U N C I O N A R I O   ******************* \n"); 
    printf("********************************************************************************* \n");
    char termo_busca[50];
        printf("Digite o nome ou CPF do funcionário a ser deletado: ");
        scanf(" %s", termo_busca);

        if (deletar_func(termo_busca)) {
            printf("\n");
            printf("Funcionário deletado com sucesso!\n"); 

        } else {
            printf("Funcionário não encontrado ou erro na exclusão.\n"); 
        }

        printf("Pressione Enter para retornar\n");
        getchar();
     }


  