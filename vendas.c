#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "vendas.h"
#include "produtos.h"
#include "clientes.h"
#include "funcionarios.h"
void clearScreen();

void modulo_venda(void) {
  Venda *venda = malloc(sizeof(Venda));
  char opcao;
  do {
      opcao = sub_menu_venda();
      switch (opcao) {
          case '1': realizar_venda(venda);
                   break;
          case '2': relatorio_venda(venda);
                   break;
          case '3': edit_venda(venda);
                   break; 
      }
  } while (opcao != '0');

  free(venda);
}


char sub_menu_venda() {

    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M A C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n");
    printf("**********************      M E N U  D E  V E N D A S      ********************** \n");
    printf("********************************************************************************* \n");
    printf("**                      1 - Realizar uma venda                                 ** \n");
    printf("**                      2 - Relatorio de vendas                                ** \n");
    printf("**                      3 - Cancelar venda                                     ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;
}





// Função para obter o nome do cliente com base no CPF
char* obterNomeCliente(const char *cpf) {
    FILE *file = fopen("clientes.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return NULL; // Falha na abertura do arquivo
    }

    Cliente cliente;

    while (fread(&cliente, sizeof(Cliente), 1, file) == 1) {
        if (strcmp(cliente.cpf, cpf) == 0) {
            fclose(file);
            char *nome = malloc(strlen(cliente.nome) + 1);
            strcpy(nome, cliente.nome);
            return nome; // Sucesso, cliente encontrado
        }
    }

    fclose(file);
    return NULL; // Cliente não encontrado
}

// Função para obter o nome do produto com base no código
char* obterNomeProduto(const char *codigo) {
    FILE *file = fopen("produtos.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de produtos.\n");
        return NULL; // Falha na abertura do arquivo
    }

    Produto produto;

    while (fread(&produto, sizeof(Produto), 1, file) == 1) {
        if (strcmp(produto.codigo, codigo) == 0) {
            fclose(file);
            char *nome = malloc(strlen(produto.nome) + 1);
            strcpy(nome, produto.nome);
            return nome; // Sucesso, produto encontrado
        }
    }

    fclose(file);
    return NULL; // Produto não encontrado
}



char* obterValorProduto(const char *codigo) {
    FILE *file = fopen("produtos.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de produtos.\n");
        return NULL; // Falha na abertura do arquivo
    }

    Produto produto;

    while (fread(&produto, sizeof(Produto), 1, file) == 1) {
        if (strcmp(produto.codigo, codigo) == 0) {
            fclose(file);
            char *preco = malloc(strlen(produto.preco) + 1);
            strcpy(preco, produto.preco);
            return preco; // Sucesso, produto encontrado
        }
    }

    fclose(file);
    return NULL; // Produto não encontrado
}



// Função para subtrair a quantidade vendida do estoque
void subtrairQuantidadeEstoque(const char *codigo, int quantidade) {
    FILE *file = fopen("produtos.dat", "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo de produtos.\n");
        return;
    }

    Produto produto;

    while (fread(&produto, sizeof(Produto), 1, file) == 1) {
        if (strcmp(produto.codigo, codigo) == 0) {
            // Encontrou o produto, subtrai a quantidade vendida do estoque
            int estoqueAtual = atoi(produto.estoq);
            if (estoqueAtual >= quantidade) {
                estoqueAtual -= quantidade;
                sprintf(produto.estoq, "%d", estoqueAtual);

                // Move o ponteiro para a posição correta no arquivo e escreve a nova informação
                fseek(file, -sizeof(Produto), SEEK_CUR);
                fwrite(&produto, sizeof(Produto), 1, file);
            } else {
                printf("Erro: Quantidade vendida maior que o estoque disponível.\n");
            }

            break;
        }
    }

    fclose(file);
}






// Função para obter o nome do funcionário com base no CPF
char* obterNomeFuncionario(const char *cpf) {
  FILE *file = fopen("funcionarios.dat", "rb");
  if (file == NULL) {
      printf("Erro ao abrir o arquivo de funcionários.\n");
      return NULL; // Falha na abertura do arquivo
  }

  Funcionario funcionario;

  while (fread(&funcionario, sizeof(Funcionario), 1, file) == 1) {
      if (strcmp(funcionario.cpf, cpf) == 0) {
          fclose(file);
          char *nome = malloc(strlen(funcionario.nome) + 1);
          strcpy(nome, funcionario.nome);
          return nome; // Sucesso, funcionário encontrado
      }
  }

  fclose(file);
  return NULL; // Funcionário não encontrado ou CPF inválido

}






 
char realizar_venda(Venda* venda) {
  char nomef[100];
  char nomec[100];
  char cpff[12];
  char cpfc[12];
  char nomep[30];
  char codigo[10];
  char preco_str[10];
  char quant_str[10];
  double preco, quant, valor;
  char status[11];
  char op;
    clearScreen();
    printf("********************************************************************************* \n");
    printf("**********************      R E A L I Z A R  V E N D A      ********************* \n");
    printf("********************************************************************************* \n");
    
    printf("Digite CPF do funcionário:                                                     ** \n");
    scanf(" %s", venda->cpff);
    getchar();
    char *nomeFuncionario = obterNomeFuncionario(venda->cpff);
    if (nomeFuncionario != NULL) {
      printf("Nome do funcionário: %s\n", nomeFuncionario);
      strcpy(venda->nomef, nomeFuncionario);
      free(nomeFuncionario);
      printf("\n");
    } else {
        printf("CPF inválido.\n");
    }

    printf("Digite CPF do cliente:                                                         ** \n");
    scanf(" %s", venda->cpfc);
    getchar();
  char *nomeCliente = obterNomeCliente(venda->cpfc);
  if (nomeCliente != NULL) {
      printf("Nome do cliente: %s\n", nomeCliente);
      strcpy(venda->nomec, nomeCliente);
      free(nomeCliente); // Liberar memória alocada para o nome do cliente
      printf("\n");
  } else {
      printf("CPF inválido.\n");
  }
  
    printf("Digite código do produto:                                                      ** \n");
    scanf(" %s", venda->codigo);
    getchar();
    char *nomeProduto = obterNomeProduto(venda->codigo);
    if (nomeProduto != NULL) {
        printf("Nome do produto: %s \n", nomeProduto);
        strcpy(venda->nomep, nomeProduto);
        free(nomeProduto);
        printf("\n");
    } else{
       printf("Produto inválido.\n" );
    }
     printf("Digite a quantidade:                                                          ** \n");
     scanf("%s", venda->quant_str);

     char *precoProduto = obterValorProduto(venda->codigo);
     if (precoProduto != NULL) {
         // Converta o preço do produto para double
         venda->preco = atof(precoProduto);
         free(precoProduto);
     }

     quant = atof(venda->quant_str);
     valor = quant * venda->preco; // Agora use venda->preco como valor numérico

     venda->valor = valor;
    printf("Valor: %.2lf\n", valor);
    printf("Deseja finalizar a venda? (S/N)\n");
    scanf(" %c", &op);
    if (op == 'S' || op == 's') {
     // Subtrair a quantidade vendida do estoque
    subtrairQuantidadeEstoque(venda->codigo, (int)quant);
    printf("Estoque atualizado com sucesso.\n"); 
      strcpy(venda->status, "OK");
      printf("Status da venda: %s\n", venda->status);
     }
    else {
      printf("Venda não realizada.\n");
    }
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;
  
}

char relatorio_venda(Venda *venda) {
  char op;
    clearScreen();
    printf("********************************************************************************* \n");
    printf("*******************     R E L A T Ó R I O  D E  V E N D A S    ****************** \n");
    printf("********************************************************************************* \n");
    printf("**               Sobre a venda                                                 ** \n");
    printf("**               Digite número da venda:                                       ** \n");
    printf("********************************************************************************* \n");
    printf("**               Nome do cliente:                                              ** \n");
    printf("**               Produto:                                                      ** \n");
    printf("**               Quantidade:                                                   ** \n");
    printf("**               Valor total:                                                  ** \n");
    printf("**               Sobre a venda:                                                ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;
  
  
}

char edit_venda(Venda *venda) {
    char op;
    clearScreen();
    printf("********************************************************************************* \n");
    printf("************************    C A N C E L A R  V E N D A    *********************** \n");
    printf("********************************************************************************* \n");
    printf("**                                                                             ** \n");
    printf("**               Sobre a venda:                                                ** \n");
    printf("**               Digite o código:                                              ** \n");
    printf("**                                                                             ** \n");
    printf("**               Deseja realmente cancelar a venda? (s/S|n/N)                  ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;




}