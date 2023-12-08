#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "produtos.h"
#include "util.h"
#include <string.h>


void clearScreen();


void modulo_produto(void){
  Produto* produto;
  struct produto Produto;
  char opcao;
    do {
        opcao = sub_menu_produto();
        switch(opcao) {
            case '1': 	sub_menu_produto_cads(produto);
                        break;
            case '2':    produto = cadas_produto();
                        gravar_produto(produto);
                        break;
            case '3':   pesquisa_produto(produto);
                        break; 
            case '4':   edit_produto();
                        break;
            case '5':   apaga_produto();
                        break;            
        }
    } while (opcao != '0');

    
}

char sub_menu_produto(){

    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("**********************                                     ********************** \n");
    printf("***********                 F A R M A C I A   E M   C                 *********** \n");
    printf("**********************                                     ********************** \n");
    printf("********************************************************************************* \n"); 
    printf("**********************    M E N U  D E  P R O D U T O S    ********************** \n");
    printf("********************************************************************************* \n");
    printf("**                      1 - Produtos cadastrados                               ** \n");
    printf("**                      2 - Cadastrar produto                                  ** \n");
    printf("**                      3 - Pesquisar produto                                  ** \n");
    printf("**                      4 - Editar produto                                     ** \n");
    printf("**                      5 - Apagar produto                                     ** \n");
    printf("**                      0 - Voltar                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;
}










char sub_menu_produto_cads(Produto* produto){
  char op;
  clearScreen();
  printf("\n");
  printf("********************************************************************************* \n");
  printf("**********************                                     ********************** \n");
  printf("***********                 F A R M A C I A   E M   C                 *********** \n");
  printf("**********************                                     ********************** \n");
  printf("********************************************************************************* \n");
  printf("***********************   M E N U  D E  P R O D U T O S   *********************** \n");
  printf("********************************************************************************* \n");
  printf("**                      1 - Dos mais antigos                                   ** \n");
  printf("**                      2 - Dos mais recentes                                  ** \n");
  printf("**                      0 - Voltar                                             ** \n");
  printf("********************************************************************************* \n");
  printf("\n");
  scanf("%c", &op);
  getchar();
  if (op == '1')
    produtos_cads(produto);
  else if (op == '2')
    produtos_cads_contr(produto);


  
}






void produtos_cads(Produto* produto) {
    clearScreen();

    printf("********************************************************************************* \n");
    printf("**********************  P R O D U T O S  C A D A S T R A D O S  ******************* \n");
    printf("********************************************************************************* \n");

    FILE* fp;
    Produto prd;

    fp = fopen("produtos.dat", "rb"); // Abra o arquivo para leitura binária

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        exit(1);
    }

    while (fread(&prd, sizeof(Produto), 1, fp) == 1) {
        if (strcmp(prd.codigo, "xxxx") != 0) { // Adicione esta condição
            printf("Nome: %s\n", prd.nome);
            printf("Código: %s\n", prd.codigo);
            printf("Preço: %s\n", prd.preco);
            printf("Estoque: %s\n", prd.estoq);
            printf("\n");
        }
    }

    fclose(fp);

    printf("Pressione Enter para retornar ao menu principal...");
    getchar();
}




void produtos_cads_contr(Produto* produto) {
  clearScreen();
  printf("\n");
  printf("********************************************************************************* \n");
  printf("***************   R E G I S T R O  D E  P R O D U T O S   *************** \n");
  printf("********************************************************************************* \n");

  FILE* fp;
  Produto prod;
  fp = fopen("produtos.dat", "rb"); // Abra o arquivo para leitura binária

  if (fp == NULL) {
      printf("Ops! Erro na abertura do arquivo!\n");
      printf("Não é possível continuar...\n");
      exit(1);
  }

  Produto* produtosArray = NULL;
  int numProdutos = 0;

  while (fread(&prod, sizeof(Produto), 1, fp) == 1) {
      if (strcmp(prod.codigo, "xxxx") != 0) { // Adicione esta condição
          produtosArray = realloc(produtosArray, (numProdutos + 1) * sizeof(Produto));

          if (produtosArray == NULL) {
              printf("Erro ao alocar memória!\n");
              exit(1);
          }

          produtosArray[numProdutos] = prod;
          numProdutos++;
      }
  }

  fclose(fp);

  for (int i = numProdutos - 1; i >= 0; i--) {
      printf("Nome: %s\n", produtosArray[i].nome);
      printf("Código: %s\n", produtosArray[i].codigo);
      printf("Preço: %s\n", produtosArray[i].preco);
      printf("Estoque: %s\n", produtosArray[i].estoq);
      printf("\n");
  }

  free(produtosArray);
  printf("Pressione Enter para retornar ao menu principal...");
  getchar();
  }



     


Produto* cadas_produto(void){
  Produto* prd;
  prd = (Produto*) malloc(sizeof(Produto));
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n"); 
    printf("**********************  C A D A S T R A R  P R O D U T O S  ********************* \n");
    printf("********************************************************************************* \n");
    printf("**                                                                             ** \n");
    printf("**                 Digite o nome:                                              ** \n");
    do{
      scanf("%s", prd->nome);
      if (validarNome(prd->nome)) {
          printf("\n");
       } else {
          printf("Nome inválido.\n");  
       } 
    } while (!validarNome(prd->nome));
    printf("**                 Digite o código:                                            ** \n");
    scanf("%s", prd->codigo);
    printf("**                 Digite o preço:                                             ** \n");
    scanf("%s", prd->preco);
    printf("**                 Digite o estoque:                                           ** \n");
    scanf("%s", prd->estoq);
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    getchar();
    return prd;



}

void gravar_produto(Produto* prd){
  FILE* fp;
   fp = fopen("produtos.dat", "ab");
      if (fp == NULL) {
      printf("Ops! Erro na abertura do arquivo!\n");
      printf("Não é possível continuar...\n");
      exit(1);
      }
      fwrite(prd, sizeof(Produto), 1, fp);
      fclose(fp);



}

void pesquisa_produto(const Produto* produto) {
    char codigo[10];  // Variável para buscar o código do produto
    Produto produtoEncontrado;  // Armazena os dados do produto encontrado
    int produtoEncontradoFlag = 0;  // Flag de rastreamento de produto

    clearScreen();  // Limpa a tela

  printf("********************************************************************************* \n");
  printf("*********************   P E S Q U I S A R  P R O D U T O   ********************* \n");
  printf("********************************************************************************* \n");
  printf("Digite o código do produto a ser pesquisado: ");
  scanf("%s", codigo);

    FILE* file = fopen("produtos.dat", "rb");  // Abre o arquivo (rb == modo leitura)

    if (file == NULL) {  // Se o arquivo for NULL, dá erro na abertura
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (fread(&produtoEncontrado, sizeof(Produto), 1, file) == 1) {  // Lê os produtos cadastrados no sistema
        if (strcmp(produtoEncontrado.codigo, codigo) == 0) {  // Confere se o código é igual
            printf("\n");
            printf("Código: %s\n", produtoEncontrado.codigo);  // Printa as informações do produto encontrado
            printf("Nome: %s\n", produtoEncontrado.nome);
            printf("Preço: %s\n", produtoEncontrado.preco);
            printf("Estoque: %s\n" , produtoEncontrado.estoq);
            printf("\n");
            printf("********************************************************************************* \n");
            produtoEncontradoFlag = 1;  // Flag que sai do loop (semelhante ao que você fez na função de cadastro)
            break; // Não é necessário continuar a busca
        }
    }

    if (!produtoEncontradoFlag) {  // Se o código não estiver no arquivo, dá erro
        printf("Produto com código %s não encontrado.\n", codigo);
        printf("********************************************************************************* \n");
    }

    fclose(file);  // Fecha o arquivo

    getchar();
    printf("\n");
    printf("Pressione Enter para retornar\n");
    getchar();
}



int editar_produto(char *termo_busca) {
    FILE *file = fopen("produtos.dat", "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para edição.\n");
        return 0; // Falha na abertura do arquivo
    }

    Produto produto;

    while (fread(&produto, sizeof(Produto), 1, file) == 1) {
        if (strcmp(produto.codigo, termo_busca) == 0 || strcmp(produto.nome, termo_busca) == 0) {

            printf("Produto encontrado. Edite as informações:\n");

            // Solicite as edições aos campos necessários
            printf("Novo nome: ");
           scanf("%s", produto.nome);

            if (validarNome(produto.nome)) {
                printf("\n");
            } else {
                printf("Nome inválido.\n");
            }


            printf("Novo código: ");
            scanf(" %s", produto.codigo);
            getchar();


            printf("Novo preço: ");
            scanf(" %s", produto.preco);
            getchar();



            printf("Novo estoque: ");
            scanf(" %s", produto.estoq);
            getchar();

            

            printf("Informações atualizadas com sucesso!\n");
            printf("********************************************************************************* \n");

            fseek(file, -sizeof(Produto), SEEK_CUR); 
            fwrite(&produto, sizeof(Produto), 1, file); 
            fclose(file);

            return 1;
        }
    }

    fclose(file);

    return 0; 
}



void edit_produto() {
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("*************************   E D I T A R  P R O D U T O   ************************ \n");
    printf("********************************************************************************* \n");

    char termo_busca[50];
    printf("Digite o nome ou código do produto a ser editado: ");
    scanf(" %s", termo_busca);

    if (editar_produto(termo_busca)) {
        printf("Produto editado com sucesso!\n");
    } else {
        printf("Produto não encontrado ou erro na edição.\n");
    }

    printf("Pressione Enter para retornar\n");
    getchar();
}


int deletar_produto(char *termo_busca) {
    FILE *file = fopen("produtos.dat", "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para edição.\n");
        return 0; // Falha na abertura do arquivo
    }

    Produto produto;

    while (fread(&produto, sizeof(Produto), 1, file) == 1) {
        if (strcmp(produto.codigo, termo_busca) == 0 || strcmp(produto.nome, termo_busca) == 0) {
            printf("Produto encontrado. Os dados do produto serão substituidos por \"xxxx\":\n");


            strcpy(produto.nome, "xxxx");
            strcpy(produto.codigo, "xxxx");
            strcpy(produto.preco, "xxxx");
            strcpy(produto.estoq, "xxxx");
            getchar();

            printf("Dados substituídas por \"xxxx\" com sucesso!\n");
            printf("********************************************************************************* \n");

            fseek(file, -sizeof(Produto), SEEK_CUR); // Retroceder o ponteiro no arquivo
            fwrite(&produto, sizeof(Produto), 1, file); // Gravar as informações editadas
            fclose(file);

            return 1; // Sucesso na edição
        }
    }

    fclose(file);

    return 0; // Cliente não encontrado
}


void apaga_produto(){
    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("************************   D E L E T A R  P R O D U T O   *********************** \n"); 
    printf("********************************************************************************* \n");
    char termo_busca[50];
    printf("Digite o nome ou código do produto a ser deletado: ");
    scanf(" %s", termo_busca);

    if (deletar_produto(termo_busca)) {
        printf("\n");
        printf("Cliente deletado com sucesso!\n"); 

    } else {
        printf("Cliente não encontrado ou erro na exclusão.\n"); 
    }

    printf("Pressione Enter para retornar\n");
    getchar();


}

