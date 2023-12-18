#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "vendas.h"
#include "produtos.h"
#include "clientes.h"
#include "funcionarios.h"
#include "util.h"
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
          case '3': apaga_venda(venda);
                   break; 
          case '4': relatorio_vendaFil(venda);
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
    printf("**                      4 - Vendas canceladas                                  ** \n");
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



void retornaQuantidadeEstoque(const char *codigo, int quantidade) {
      FILE *file = fopen("produtos.dat", "rb+");

      if (file == NULL) {
          printf("Erro ao abrir o arquivo de produtos.\n");
          return;
      }

      Produto produto;

      while (fread(&produto, sizeof(Produto), 1, file) == 1) {
          if (strcmp(produto.codigo, codigo) == 0) {
              int estoqueAtual = atoi(produto.estoq);
              estoqueAtual += quantidade;  // Adiciona a quantidade de volta ao estoque
              sprintf(produto.estoq, "%d", estoqueAtual);

              fseek(file, -sizeof(Produto), SEEK_CUR);
              fwrite(&produto, sizeof(Produto), 1, file);

              fclose(file);
              return;
          }
      }

      fclose(file);
      printf("Produto não encontrado.\n");
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







void gravar_venda(Venda* vend){
   FILE* fp;
   fp = fopen("vendas.dat", "ab");
   if (fp == NULL) {
       printf("Ops! Erro na abertura do arquivo!\n");
       printf("Não é possível continuar...\n");
       exit(1);
   }

   // Gravar a estrutura Venda completa no arquivo
   fwrite(vend, sizeof(Venda), 1, fp);

   fclose(fp);


}







void realizar_venda(Venda* venda) {

  char op;
  clearScreen();
  printf("********************************************************************************* \n");
  printf("**********************      R E A L I Z A R  V E N D A      ********************* \n");
  printf("********************************************************************************* \n");

  printf("Digite o número da venda: ");
  scanf("%s", venda->codigov);

  printf("Digite CPF do funcionário: ");
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
      return;
  }

  printf("Digite CPF do cliente: ");
  scanf(" %s", venda->cpfc);
  getchar();
  char *nomeCliente = obterNomeCliente(venda->cpfc);
  if (nomeCliente != NULL) {
      printf("Nome do cliente: %s\n", nomeCliente);
      strcpy(venda->nomec, nomeCliente);
      free(nomeCliente);
      printf("\n");
  } else {
      printf("CPF inválido.\n");
      return;
  }

  printf("Digite código do produto: ");
  scanf(" %s", venda->codigo);
  getchar();
  char *nomeProduto = obterNomeProduto(venda->codigo);
  if (nomeProduto != NULL) {
      printf("Nome do produto: %s \n", nomeProduto);
      strcpy(venda->nomep, nomeProduto);
      // Venda não possui 'nomep', ajuste para o campo correto
      // strcpy(venda->nomep, nomeProduto);
      free(nomeProduto);
      printf("\n");
  } else {
      printf("Produto inválido.\n" );
      return;
  }

  printf("Digite a quantidade: ");
  scanf("%d", &venda->quant[0]);  // Aceita apenas uma quantidade

  char *precoProduto = obterValorProduto(venda->codigo);
  if (precoProduto != NULL) {
      // Converta o preço do produto para float
      printf("Preço do produto: R$ %s\n", precoProduto);
      venda->preco[0] = atof(precoProduto);
      free(precoProduto);
  }

  venda->valor[0] = venda->quant[0] * venda->preco[0];

  // Correção do formato de impressão
  printf("Valor: %d\n", venda->valor[0]);

  printf("Deseja finalizar a venda? (S/N)\n");
  scanf(" %c", &op);
  if (op == 'S' || op == 's') {
      // Subtrair a quantidade vendida do estoque
      subtrairQuantidadeEstoque(venda->codigo, (int)venda->quant[0]);

      printf("Estoque atualizado com sucesso.\n");
      strcpy(venda->status, "OK");
      printf("Status da venda: %s\n", venda->status);
      gravar_venda(venda);
  } else {
      printf("Venda não realizada.\n");
  }

  printf("**                                                                             ** \n");
  printf("********************************************************************************* \n");
  printf("\n");
  limparBuffer();
}



void relatorio_venda() {
  FILE *fp;
  Venda vend;

  fp = fopen("vendas.dat", "rb"); // Abra o arquivo para leitura binária

  if (fp == NULL) {
      printf("Ops! Erro na abertura do arquivo!\n");
      printf("Não é possível continuar...\n");
      exit(1);
  }

  clearScreen();
  printf("*********************************************\n");
  printf("************ Relatório de Vendas ************\n");
  printf("*********************************************\n");

  while (fread(&vend, sizeof(Venda), 1, fp) == 1) {
      // Adicione a verificação se a venda está completa antes de imprimir os detalhes
      if (strcmp(vend.status, "OK") == 0) {
          printf("*********************************************\n");
          printf("Código da venda: %s\n", vend.codigov);
          printf("Vendedor: %s (CPF: %s)\n", vend.nomef, vend.cpff);
          printf("Cliente: %s (CPF: %s)\n", vend.nomec, vend.cpfc);
          printf("Produto comprado: %s (Código: %s)\n", vend.nomep, vend.codigo);
          printf("Preço unitário: %.2f\n", vend.preco[0]);
          printf("Quantidade comprada: %.2d\n", vend.quant[0]);
          printf("Total da compra: R$ %.2d\n", vend.valor[0]);
          printf("*********************************************\n");
          printf("\n");
      }
  }

  fclose(fp);

  printf("Pressione Enter para retornar ao menu principal...");
  getchar();
}







void relatorio_vendaFil() {
  FILE *fp;
  Venda vend;

  fp = fopen("vendas.dat", "rb"); // Abra o arquivo para leitura binária

  if (fp == NULL) {
      printf("Ops! Erro na abertura do arquivo!\n");
      printf("Não é possível continuar...\n");
      exit(1);
  }

  clearScreen();
  printf("*********************************************\n");
  printf("******* Relatório de Vendas Canceladas *******\n");
  printf("*********************************************\n");

  while (fread(&vend, sizeof(Venda), 1, fp) == 1) {
      // Adicione a verificação se a venda está completa antes de imprimir os detalhes
      if (strcmp(vend.status, "NO") == 0) {
          printf("*********************************************\n");
          printf("Código da venda: %s\n", vend.codigov);
          printf("Vendedor: %s (CPF: %s)\n", vend.nomef, vend.cpff);
          printf("Cliente: %s (CPF: %s)\n", vend.nomec, vend.cpfc);
          printf("Produto comprado: %s (Código: %s)\n", vend.nomep, vend.codigo);
          printf("Preço unitário: %.2f\n", vend.preco[0]);
          printf("Quantidade comprada: %.2d\n", vend.quant[0]);
          printf("Total da compra: R$ %.2d\n", vend.valor[0]);
          printf("*********************************************\n");
          printf("\n");
      }
  }

  fclose(fp);

  printf("Pressione Enter para retornar ao menu principal...");
  getchar();
}





  int deletar_venda(char *termo_busca) {
      FILE *file = fopen("vendas.dat", "rb+");

      if (file == NULL) {
          printf("Erro ao abrir o arquivo para edição.\n");
          return 0; // Falha na abertura do arquivo
      }

      Venda venda;

      while (fread(&venda, sizeof(Venda), 1, file) == 1) {
          if (strcmp(venda.codigov, termo_busca) == 0) {
              printf("Venda encontrado. Os dados da venda serão substituídos por \"NO\":\n");

              // Restaura a quantidade vendida ao estoque
              retornaQuantidadeEstoque(venda.codigo, (int)venda.quant[0]);

              strcpy(venda.status, "NO");

              printf(" Informações alteradas \n");
              printf("********************************************************************************* \n");
              getchar();

              fseek(file, -sizeof(Venda), SEEK_CUR); // Retroceder o ponteiro no arquivo
              fwrite(&venda, sizeof(Venda), 1, file); // Gravar as informações editadas
              fclose(file);

              return 1; // Sucesso na edição
          }
      }

      fclose(file);
      return 0; // Venda não encontrada
  }

  
void apaga_venda(){
    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("**************************   D E L E T A R  V E N D A   ************************* \n"); 
    printf("********************************************************************************* \n");
    char termo_busca[10];
    printf("Digite o código da venda : ");
    scanf(" %s", termo_busca);

    if (deletar_venda(termo_busca)) {
        printf("\n");
        printf("Venda deletado com sucesso!\n"); 

    } else {
        printf("Venda não encontrado ou erro na exclusão.\n"); 
    }

    printf("Pressione Enter para retornar\n");
    getchar();


}





