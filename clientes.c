#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "clientes.h"
#include <string.h>
#include "util.h"
#include "vendas.h"

void clearScreen();


void modulo_cliente(void){
  FILE* fp = fopen("clientes.dat", "ab");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }
  fclose(fp);
  Cliente* cliente;
  struct cliente Cliente;
    char opcao;
    do {
        opcao = sub_menu_cliente();
        switch(opcao) {
            case '1':   sub_menu_cliente_cads(cliente);                    
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
            case '6':  recuperar_cliente();
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
    printf("**                      3 - Pesquisar cliente                                  ** \n");
    printf("**                      4 - Editar ficha do cliente                            ** \n");
    printf("**                      5 - Apagar ficha do cliente                            ** \n");
    printf("**                      6 - Recuperar ficha do cliente                         ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;
}


char sub_menu_cliente_cads(Cliente* cliente){
  
  char op;
  clearScreen();
  printf("\n");
  printf("********************************************************************************* \n");
  printf("**********************                                     ********************** \n");
  printf("***********                 F A R M A C I A   E M   C                 *********** \n");
  printf("**********************                                     ********************** \n");
  printf("********************************************************************************* \n");
  printf("*******************   C L I E N T E S  C A D A S T R A D O S  ******************* \n");
  printf("********************************************************************************* \n");
  printf("**                      1 - Dos mais antigos                                   ** \n");
  printf("**                      2 - Dos mais recentes                                  ** \n");
  printf("**                      3 - Clientes inativos                                  ** \n");
  printf("**                      4 - Clientes com compras                               ** \n");
  printf("**                      5 - Clientes em ordem alfabética                       ** \n");
  printf("**                      0 - Voltar                                             ** \n");
  printf("********************************************************************************* \n");
  printf("\n");
  scanf("%c", &op);
  getchar();
  if (op == '1')
    cliente_ja_cad(cliente);
  else if (op == '2')
    cliente_ja_cad_contr(cliente);
  else if (op == '3')
    cliente_inativo(cliente);
  else if (op == '4')
    Cliente_com_venda(cliente);
  else if (op == '5'){ 
    FILE *fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
    listar_em_ordem_alfabetica(fp);
    fclose(fp);
    getchar();
  }
  else if (op != '0')
    limparBuffer();
   
 
  
}



char cliente_ja_cad(Cliente* cliente){
  
  char op;
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
      if (strcmp(clien.status, "NO") != 0) { // Adicione esta condição
          printf("Nome: %s\n", clien.nome);
          printf("CPF: %s\n", clien.cpf);
          printf("E-mail: %s\n", clien.email);
          printf("Endereço: %s\n", clien.ender);
          printf("****************************************\n");
          printf("\n");
      }
  }

  fclose(fp);

  printf("Pressione Enter para retornar ao menu principal...");
  getchar();
}

char cliente_inativo(Cliente* cliente){

  char op;
  clearScreen();
  printf("\n");
  printf("********************************************************************************* \n");
  printf("*********************   C L I E N T E S   I N A T I V O S   ********************* \n"); 
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
      if (strcmp(clien.status, "OK") != 0) { // Adicione esta condição
          printf("Nome: %s\n", clien.nome);
          printf("CPF: %s\n", clien.cpf);
          printf("E-mail: %s\n", clien.email);
          printf("Endereço: %s\n", clien.ender);
          printf("****************************************\n");
          printf("\n");
      }
  }

  fclose(fp);

  printf("Pressione Enter para retornar ao menu principal...");
  getchar();
}


char cliente_ja_cad_contr(Cliente* cliente){

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

  // Alocar memória dinâmica para armazenar clientes
  Cliente* clientes = NULL;
  int numClientes = 0;

  while (fread(&clien, sizeof(Cliente), 1, fp) == 1) {
      // Adicionar o cliente ao vetor apenas se o CPF for diferente de "xxxx"
      if (strcmp(clien.status, "NO") != 0) {
          clientes = (Cliente*)realloc(clientes, (numClientes + 1) * sizeof(Cliente));

          if (clientes == NULL) {
              printf("Erro ao alocar memória!\n");
              fclose(fp);
              exit(1);
          }

          clientes[numClientes] = clien;
          numClientes++;
      }
  }

  fclose(fp);

  // Exibir os clientes na ordem inversa
  for (int i = numClientes - 1; i >= 0; i--) {
      printf("Nome: %s\n", clientes[i].nome);
      printf("CPF: %s\n", clientes[i].cpf);
      printf("E-mail: %s\n", clientes[i].email);
      printf("Endereço: %s\n", clientes[i].ender);
      printf("****************************************\n");
      printf("\n");
  }

  // Liberar a memória alocada dinamicamente
  free(clientes);

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
    do{
      printf("**          Digite o nome:...                                                  ** \n");
      fgets(clien->nome, sizeof(clien->nome), stdin);
      clien->nome[strcspn(clien->nome, "\n")] = '\0';
      if (validarNome(clien->nome)) {
          printf("\n");
       } else {
          printf("Nome inválido.\n");  
       }
    }while (!validarNome(clien->nome));
    do {
      printf("** Digite o CPF:... \n");
      scanf(" %s", clien->cpf);
      getchar();
      if (cpfClienJaCadastrado(clien->cpf)) {
          printf("CPF já cadastrado. Tente novamente.\n");
      } else if (validarCPF(clien->cpf)) {
          printf("\n");
      } else {
          printf("CPF inválido.\n");
      }
    }while (!validarCPF(clien->cpf) || cpfClienJaCadastrado(clien->cpf));     
    do{
      printf("**          Digite o email:...                                                 ** \n");
      scanf(" %s", clien->email);
      getchar();
      if (verificar_email(clien->email)){
          printf("\n");
      } else {
         printf("E-mail inválido\n");
      }
    }while (!verificar_email(clien->email));
    printf("**          Digite o endereço:...                                              ** \n");
    fgets(clien->ender, sizeof(clien->ender), stdin);
    clien->ender[strcspn(clien->ender, "\n")] = '\0';
    strcpy(clien->status, "OK");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("Pressione Enter para retornar\n");
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
            printf("Endereço: %s\n" , clienteEncontrado.ender);\
            printf("Status: %s\n" , clienteEncontrado.status);
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
    printf("Digite o CPF do cliente a ser editado: ");
    scanf(" %s", termo_busca);

    if (editar_cliente(termo_busca)) {
        printf("Cliente editado com sucesso!\n");
    } else {
        printf("Cliente não encontrado ou erro na edição.\n");
        getchar();
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
            printf("Cliente encontrado. Os status do cliente serão substituidos por \"NO\":\n");

            
            strcpy(cliente.status, "NO");
           
            getchar();

            printf("Dados alterados com sucesso!\n");
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
    printf("Digite o CPF do cliente a ser deletado: ");
    scanf(" %s", termo_busca);

    if (deletar_cliente(termo_busca)) {
        printf("\n");
        printf("Cliente deletado com sucesso!\n"); 
        
    } else {
        printf("Cliente não encontrado ou erro na exclusão.\n"); 
        getchar();
    }

    printf("Pressione Enter para retornar\n");
    getchar();
}


int recupera_cliente(char *termo_busca) {
    FILE *file = fopen("clientes.dat", "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para edição.\n");
        return 0; // Falha na abertura do arquivo
    }

    Cliente cliente;

    while (fread(&cliente, sizeof(Cliente), 1, file) == 1) {
        if (strcmp(cliente.cpf, termo_busca) == 0 || strcmp(cliente.nome, termo_busca) == 0) {
            printf("Cliente encontrado. Os status do cliente serão substituidos por \"OK\":\n");


            strcpy(cliente.status, "OK");

            getchar();

            printf("Dados alterados com sucesso!\n");
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



void recuperar_cliente() {
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************   R E C U P E R A R  C L I E N T E   ********************* \n"); 
    printf("********************************************************************************* \n");
    char termo_busca[50];
    printf("Digite o CPF do cliente a ser recuperado: ");
    scanf(" %s", termo_busca);

    if (recupera_cliente(termo_busca)) {
        printf("\n");
        printf("Cliente recuperado com sucesso!\n"); 

    } else {
        printf("Cliente não encontrado ou erro na recuperação.\n"); 
        getchar();
    }

    printf("Pressione Enter para retornar\n");
    getchar();
}




char* obterCPFCliente(const char *cpfc) {
    FILE *file = fopen("vendas.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return NULL; // Falha na abertura do arquivo
    }

    Venda venda;
    char *cpfRetornado = NULL;

    while (fread(&venda, sizeof(Venda), 1, file) == 1) {
        if (strcmp(venda.cpfc, cpfc) == 0) {
            cpfRetornado = malloc(strlen(venda.cpfc) + 1);
            strcpy(cpfRetornado, venda.cpfc);
            break; // Sucesso, cliente encontrado
        }
    }

    fclose(file);
    return cpfRetornado; // Retorna o CPF encontrado ou NULL se não encontrado
}

void Cliente_com_venda() {
  FILE *fp;
  Cliente clin;
  fp = fopen("clientes.dat", "rb");
  if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        exit(1);
  }

  clearScreen();
  printf("\n");
  printf("********************************************************************************* \n");
  printf("******************   C L I E N T E S   C O M   C O M P R A S   ****************** \n"); 
  printf("********************************************************************************* \n");

  while (fread(&clin, sizeof(Cliente), 1, fp) == 1) {
    char *cpfc = obterCPFCliente(clin.cpf);
    if (cpfc != NULL) {
         printf("****************************************\n");
         printf("Nome: %s\n", clin.nome);
         printf("CPF: %s\n", cpfc);
         printf("E-mail: %s\n", clin.email);
         printf("Endereço: %s\n", clin.ender);
         printf("****************************************\n");
         printf("\n");
         free(cpfc); // Libera a memória alocada
    }
  }

  fclose(fp);

  printf("Pressione Enter para retornar ao menu principal...");
  getchar();
}





int cpfClienJaCadastrado(const char *cpf) {
    FILE *file = fopen("clientes.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return 0;  // Considerando que 0 indica "CPF não cadastrado"
    }

    Cliente cliente;

    while (fread(&cliente, sizeof(Cliente), 1, file) == 1) {
        if (strcmp(cliente.cpf, cpf) == 0) {
            fclose(file);
            return 1;  // CPF já cadastrado
        }
    }

    fclose(file);
    return 0;  // CPF não cadastrado
}





/* 
Código feito a partir da função feita por Gustavo Douglas disponivel em: https://github.com/Gustavo-DSC/ProgamacaoProjetoUFRN.git
*/

// Função inserir_em_ordem modificada
Elemento* inserir_em_ordem(Elemento* inicio, struct cliente dados) {
    Elemento* novo_elemento = (Elemento*)malloc(sizeof(Elemento));
    novo_elemento->dados = dados;
    novo_elemento->proximo = NULL;

    if (inicio == NULL || strcmp(dados.nome, inicio->dados.nome) < 0) {
        novo_elemento->proximo = inicio;
        return novo_elemento;
    }

    Elemento* atual = inicio;
    while (atual->proximo != NULL && strcmp(dados.nome, atual->proximo->dados.nome) > 0) {
        atual = atual->proximo;
    }

    novo_elemento->proximo = atual->proximo;
    atual->proximo = novo_elemento;

    return inicio;
}





void listar_em_ordem_alfabetica(FILE* fp) {
  Elemento* inicio = NULL;
  struct cliente Cliente;
  while (fread(&Cliente, sizeof(struct cliente ), 1, fp)) {
    inicio = inserir_em_ordem(inicio, Cliente);
  }
  Elemento* atual = inicio;
  clearScreen();
  printf("\n");
  printf("********************************************************************************* \n");
  printf("*******************   R E G I S T R O  D E  C L I E N T E S   ******************* \n");
  printf("********************************************************************************* \n");
  printf("\n");
  while (atual != NULL) {
    listar_cliente(atual->dados);
    atual = atual->proximo;
  }
  while (inicio != NULL) {
    Elemento* temp = inicio;
    inicio = inicio->proximo;
    free(temp);
  }
}

void listar_cliente(struct cliente u){
  if (strcmp(u.status, "NO") != 0){ 
    printf("****************************************\n");
    printf("Nome: %s\n", u.nome);
    printf("CPF: %s\n", u.cpf);
    printf("E-mail: %s\n", u.email);
    printf("EndereÃ§o: %s\n", u.ender);
    printf("****************************************\n");
    printf("\n");
  }
}