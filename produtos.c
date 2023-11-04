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
            case '1': 	produtos_cads(produto);
                        break;
            case '2':    produto = cadas_produto();
                        gravar_produto(produto);
                        break;
            case '3':   pesquisa_produto(produto);
                        break; 
            case '4':   edit_produto(&Produto);
                        break;
            case '5':   apaga_produto(&Produto);
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
        printf("Nome: %s\n", prd.nome);
        printf("Código: %s\n", prd.codigo);
        printf("Preço: %s\n", prd.preco);
        printf("Estoque: %s\n", prd.estoq);
        printf("\n");
    }

    fclose(fp);

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
    scanf("%s", prd->nome);
    if (validarNome(prd->nome)) {
        printf("\n");
     } else {
        printf("Nome inválido.\n");  
     } 
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



char edit_produto(){
    char op;
    clearScreen();
    printf("\n");

    printf("********************************************************************************* \n"); 
    printf("*************************  E D I T A R  P R O D U T O  ************************* \n");
    printf("********************************************************************************* \n");
    printf("**                                                                             ** \n");
    printf("**                 Novo nome:                                                  ** \n");
    printf("**                 Novo código:                                                ** \n");
    printf("**                 Novo preço:                                                 ** \n");
    printf("**                 Novo estoque:                                               ** \n");
    printf("**                 Nova descrição:                                             ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;

}

char apaga_produto(){
    char op;
    clearScreen();
    printf("\n");
    printf("********************************************************************************* \n");
    printf("************************   D E L E T A R  P R O D U T O   *********************** \n"); 
    printf("********************************************************************************* \n");
    printf("**          Para apagar o produto:                                             ** \n");
    printf("**                                                                             ** \n");
    printf("**          Digite o código:...                                                ** \n");
    printf("**                                                                             ** \n");
    printf("**          Deseja realmente deletar o produto? (s/S|n/N)                      ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");    
    scanf(" %c", &op);
    getchar();
    return op;


}

