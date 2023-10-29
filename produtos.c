#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "produtos.h"
#include "util.h"


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
            case '3':   info_produto(&Produto);
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
    printf("**                      3 - Informacoes de produtos                            ** \n");
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

char info_produto(){
    char op;
    clearScreen();
    printf("\n");

    printf("********************************************************************************* \n"); 
    printf("*******************  I N F O R M A C O E S  D O  P R O D U T O  ***************** \n");
    printf("********************************************************************************* \n");
    printf("**                                                                             ** \n");
    printf("**                 nome:                                                       ** \n");
    printf("**                 Código:                                                     ** \n");
    printf("**                 Preço:                                                      ** \n");
    printf("**                 Estoque:                                                    ** \n");
    printf("**                 Descrição:                                                  ** \n");
    printf("**                                                                             ** \n");
    printf("********************************************************************************* \n");
    printf("\n");
    scanf("%c", &op);
    getchar();
    return op;
  


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

