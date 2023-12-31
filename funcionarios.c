#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "funcionarios.h"
#include "util.h"
#include "vendas.h"

void clearScreen();

void modulo_funcionario(void) {
  FILE* fp = fopen("funcionarios.dat", "ab");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }
  fclose(fp);
  Funcionario* funcionario;
  struct funcionario Funcionario;
    char opcao;
    do {
        opcao = sub_menu_funcionario();
        switch(opcao) {
            case '1': 	sub_menu_funcionario_cads(funcionario);
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
            case '6':  recuperar_func();
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
    printf("**                      6 - Recuperar ficha do funcionario                     ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");    
    scanf("%c", &op);
    getchar();
    return op;
}

char sub_menu_funcionario_cads(Funcionario* funcionario){
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
  printf("**                      1 - Dos mais antigos                                   ** \n");
  printf("**                      2 - Dos mais recentes                                  ** \n");
  printf("**                      3 - Funcionarios inativos                              ** \n");
  printf("**                      4 - Funcionarios com vendas                            ** \n");
  printf("**                      5 - Funcionarios em ordem alfabética                   ** \n");
  printf("**                      0 - Voltar                                             ** \n");
  printf("********************************************************************************* \n");
  printf("\n");
  scanf("%c", &op);
  getchar();
  if (op == '1')
    funcio_ja_cad(funcionario);
  else if (op == '2')
    funcio_ja_cad_contr(funcionario);
  else if (op == '3')
    funcio_inativo(funcionario);
  else if (op == '4')
    Funcionarios_com_vend(funcionario);
  else if (op == '5'){ 
    FILE *fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
    listar_em_ordem_alfabeticaF(fp);
    fclose(fp);
    getchar();
  }
  else if (op != '0')
    limparBuffer();


  
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
        return 1 ;
    }

    while (fread(&func, sizeof(Funcionario), 1, fp) == 1) {
        if (strcmp(func.status, "NO") != 0) { // Adicione esta condição
            printf("Nome: %s\n", func.nome);
            printf("CPF: %s\n", func.cpf);
            printf("Cargo: %s\n", func.cargo);
            printf("E-mail: %s\n", func.email);
            printf("Endereço: %s\n", func.ender);
            printf("****************************************\n");
            printf("\n");
        }
    }

    fclose(fp);

    printf("Pressione Enter para retornar ao menu principal...");
    getchar();
  
    }


char funcio_ja_cad_contr(Funcionario* funcionario){

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
        return 1;
    }

    // Alocar memória dinâmica para armazenar funcionários
    Funcionario* funcionarios = NULL;
    int numFuncionarios = 0;

    while (fread(&func, sizeof(Funcionario), 1, fp) == 1) {
        // Adicionar o funcionário ao vetor
        funcionarios = (Funcionario*)realloc(funcionarios, (numFuncionarios + 1) * sizeof(Funcionario));

        if (funcionarios == NULL) {
            printf("Erro ao alocar memória!\n");
            fclose(fp);
            exit(1);
        }

        funcionarios[numFuncionarios] = func;
        numFuncionarios++;
    }

    fclose(fp);

    // Exibir os funcionários na ordem inversa
    for (int i = numFuncionarios - 1; i >= 0; i--) {
        if (strcmp(funcionarios[i].status, "NO") != 0) { // Adicione esta condição
            printf("Nome: %s\n", funcionarios[i].nome);
            printf("CPF: %s\n", funcionarios[i].cpf);
            printf("Cargo: %s\n", funcionarios[i].cargo);
            printf("E-mail: %s\n", funcionarios[i].email);
            printf("Endereço: %s\n", funcionarios[i].ender);
            printf("****************************************\n");
            printf("\n");
        }
    }

    // Liberar a memória alocada dinamicamente
    free(funcionarios);

    printf("Pressione Enter para retornar ao menu principal...");
    getchar();
}




char funcio_inativo(Funcionario* funcionario){
  char op;
  clearScreen();
  printf("\n");
  printf("********************************************************************************* \n");
  printf("******************  F U N C I O N A R I O S  I N A T I V O S   ****************** \n");
  printf("********************************************************************************* \n");
  FILE* fp;
  Funcionario func;
  fp = fopen("funcionarios.dat", "rb"); // Abra o arquivo para leitura binária

  if (fp == NULL) {
      printf("Ops! Erro na abertura do arquivo!\n");
      printf("Não é possível continuar...\n");
      return 1;
  }

  while (fread(&func, sizeof(Funcionario), 1, fp) == 1) {
      if (strcmp(func.status, "OK") != 0) { // Adicione esta condição
          printf("Nome: %s\n", func.nome);
          printf("CPF: %s\n", func.cpf);
          printf("Cargo: %s\n", func.cargo);
          printf("E-mail: %s\n", func.email);
          printf("Endereço: %s\n", func.ender);
          printf("****************************************\n");
          printf("\n");
      }
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
    do{
      printf("**          Digite o nome:                                                     ** \n");
      fgets(func->nome, sizeof(func->nome), stdin);
      func->nome[strcspn(func->nome, "\n")] = '\0';
      if (validarNome(func->nome)) {
          printf("\n");
       } else {
          printf("Nome inválido.\n");  
       }
    } while (!validarNome(func->nome));
    do{
      printf("**          Digite o CPF:                                                      ** \n");
      scanf(" %s", func->cpf);
          getchar();
          if (cpfFuncJaCadastrado(func->cpf)) {
              printf("CPF já cadastrado. Tente novamente.\n");
          } else if (validarCPF(func->cpf)) {
              printf("\n");
          } else {
              printf("CPF inválido.\n");
          }
      } while (!validarCPF(func->cpf) || cpfFuncJaCadastrado(func->cpf));
    printf("**          Digite o cargo/função:                                             ** \n");
    scanf(" %s",func->cargo);
    getchar();
    do{
      printf("**          Digite o email:                                                    ** \n");
      scanf(" %s", func->email);
      getchar();
      if (verificar_email(func->email)){
          printf("\n");
      } else {
         printf("E-mail inválido\n");
      }
    } while (!verificar_email(func->email));
    printf("**          Digite o endereço:                                                 ** \n");
    fgets(func->ender, sizeof(func->ender), stdin);
    func->ender[strcspn(func->ender, "\n")] = '\0';
    strcpy(func->status, "OK");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("Pressione Enter para retornar\n");
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
            printf("Status: %s\n", funcionarioEncontrado.status);
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
    printf("Digite o CPF do funcionário a ser editado: ");
    scanf(" %s", termo_busca);

    if (editar_func(termo_busca)) {
        printf("Funcionário editado com sucesso!\n");
    } else {
        printf("Funcionário não encontrado ou erro na edição.\n");
        getchar();
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
            printf("Funcionario encontrado. Os status do funcionario serão substituidos por \"NO\":\n");


            strcpy(funcionario.status, "NO");
            
            getchar();

            printf("Dados alterados com sucesso!\n");
            printf("********************************************************************************* \n");

            fseek(file, -sizeof(Funcionario), SEEK_CUR); // Retroceder o ponteiro no arquivo
            fwrite(&funcionario, sizeof(Funcionario), 1, file); // Gravar as informações editadas
            fclose(file);

            return 1; // Sucesso na edição
        }
    }

    fclose(file);

    return 0; // Funcionario não encontrado
}


void apaga_func(){
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("********************   D E L E T A R  F U N C I O N A R I O   ******************* \n"); 
    printf("********************************************************************************* \n");
    char termo_busca[50];
        printf("Digite o CPF do funcionário a ser deletado: ");
        scanf(" %s", termo_busca);

        if (deletar_func(termo_busca)) {
            printf("\n");
            printf("Funcionário deletado com sucesso!\n"); 

        } else {
            printf("Funcionário não encontrado ou erro na exclusão.\n");
            getchar(); 
        }

        printf("Pressione Enter para retornar\n");
        getchar();
     }



int recupera_func(char *termo_busca) {
  FILE *file = fopen("funcionarios.dat", "rb+");

  if (file == NULL) {
      printf("Erro ao abrir o arquivo para edição.\n");
      return 0; // Falha na abertura do arquivo
  }

  Funcionario funcionario;

  while (fread(&funcionario, sizeof(Funcionario), 1, file) == 1) {
      if (strcmp(funcionario.cpf, termo_busca) == 0 || strcmp(funcionario.nome, termo_busca) == 0) {
          printf("Funcionario encontrado. Os status do funcionario serão substituidos por \"OK\":\n");


          strcpy(funcionario.status, "OK");

          getchar();

          printf("Dados alterados com sucesso!\n");
          printf("********************************************************************************* \n");

          fseek(file, -sizeof(Funcionario), SEEK_CUR); // Retroceder o ponteiro no arquivo
          fwrite(&funcionario, sizeof(Funcionario), 1, file); // Gravar as informações editadas
          fclose(file);

          return 1; // Sucesso na edição
      }
  }

  fclose(file);

  return 0; // Funcionario não encontrado
}


void recuperar_func(){
  clearScreen();
  printf("\n");
  printf("********************************************************************************* \n");
  printf("*****************   R E C U P E R A R  F U N C I O N A R I O   ****************** \n"); 
  printf("********************************************************************************* \n");
  char termo_busca[50];
      printf("Digite o CPF do funcionário a ser recuperado: ");
      scanf(" %s", termo_busca);

      if (recupera_func(termo_busca)) {
          printf("\n");
          printf("Funcionário recuperado com sucesso!\n"); 

      } else {
          printf("Funcionário não encontrado ou erro na recuperação.\n"); 
          getchar();
      }

      printf("Pressione Enter para retornar\n");
      getchar();
   }






char* obterCPFFuncionario(const char *cpff) {
    FILE *file = fopen("vendas.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return NULL; // Falha na abertura do arquivo
    }

    Venda venda;
    char *cpfRetornado = NULL;

    while (fread(&venda, sizeof(Venda), 1, file) == 1) {
        if (strcmp(venda.cpff, cpff) == 0) {
            cpfRetornado = malloc(strlen(venda.cpff) + 1);
            strcpy(cpfRetornado, venda.cpff);
            break; // Sucesso, funcionario encontrado
        }
    }

    fclose(file);
    return cpfRetornado; // Retorna o CPF encontrado ou NULL se não encontrado
}

void Funcionarios_com_vend() {
  FILE *fp;
  Funcionario func;
  fp = fopen("funcionarios.dat", "rb");
  if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        exit(1);
  }

  clearScreen();
  printf("\n");
  printf("********************************************************************************* \n");
  printf("****************  F U N C I O N A R I O S  C O M  V E N D A S  ***************** \n");
  printf("********************************************************************************* \n");

  while (fread(&func, sizeof(Funcionario), 1, fp) == 1) {
    char *cpff = obterCPFFuncionario(func.cpf);
    if (cpff != NULL) {
         printf("****************************************\n");
         printf("Nome: %s\n", func.nome);
         printf("CPF: %s\n", cpff);
         printf("E-mail: %s\n", func.email);
         printf("Cargo: %s\n", func.cargo);
         printf("Endereço: %s\n", func.ender);
         printf("****************************************\n");
         printf("\n");
         free(cpff); // Libera a memória alocada
    }
  }

  fclose(fp);

  printf("Pressione Enter para retornar ao menu principal...");
  getchar();
}



int cpfFuncJaCadastrado(const char *cpf) {
    FILE *file = fopen("funcionarios.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de funcionarios.\n");
        return 0;  // Considerando que 0 indica "CPF não cadastrado"
    }

    Funcionario funcionario;

    while (fread(&funcionario, sizeof(Funcionario), 1, file) == 1) {
        if (strcmp(funcionario.cpf, cpf) == 0) {
            fclose(file);
            return 1;  // CPF já cadastrado
        }
    }

    fclose(file);
    return 0;  // CPF não cadastrado
}



Elementof* inserir_em_ordemF(Elementof* inicio, struct funcionario dados) {
    Elementof* novo_elemento = (Elementof*)malloc(sizeof(Elementof));
    novo_elemento->dados = dados;
    novo_elemento->proximo = NULL;

    if (inicio == NULL || strcmp(dados.nome, inicio->dados.nome) < 0) {
        novo_elemento->proximo = inicio;
        return novo_elemento;
    }

    Elementof* atual = inicio;
    while (atual->proximo != NULL && strcmp(dados.nome, atual->proximo->dados.nome) > 0) {
        atual = atual->proximo;
    }

    novo_elemento->proximo = atual->proximo;
    atual->proximo = novo_elemento;

    return inicio;
}





void listar_em_ordem_alfabeticaF(FILE* fp) {
  Elementof* inicio = NULL;
  struct funcionario Funcionario;
  while (fread(&Funcionario, sizeof(struct funcionario ), 1, fp)) {
    inicio = inserir_em_ordemF(inicio, Funcionario);
  }
  Elementof* atual = inicio;
  clearScreen();
  printf("\n");
  printf("********************************************************************************* \n");
  printf("***************   R E G I S T R O  D E  F U N C I O N A R I O S   *************** \n");
  printf("********************************************************************************* \n");
  printf("\n");
  while (atual != NULL) {
    listar_func(atual->dados);
    atual = atual->proximo;
  }
  while (inicio != NULL) {
    Elementof* temp = inicio;
    inicio = inicio->proximo;
    free(temp);
  }
}

void listar_func(struct funcionario u){
  if (strcmp(u.status, "NO") != 0){
    printf("****************************************\n");
    printf("Nome: %s\n", u.nome);
    printf("CPF: %s\n", u.cpf);
    printf("Cargo: %s\n", u.cargo);
    printf("E-mail: %s\n", u.email);
    printf("EndereÃ§o: %s\n", u.ender);
    printf("****************************************\n");
    printf("\n");
  }
}