typedef struct produto Produto;
struct produto {
  char nome[30];
  char codigo[10];
  char preco[10];
  char estoq[10];
};

void modulo_produto(void); //Modulo que apareçe no menu principal liga as outras páginas
char sub_menu_produto(); //Menu dos produtos
Produto* cadas_produto(void); //Faz o cadastro de novos produtos
void gravar_produto(Produto*);
void produtos_cads(Produto*);
void pesquisa_produto(const Produto* produto);
char info_produto(); //Mostra as informações de um produto
char edit_produto(); //Faz a edição do produto
char apaga_produto(); //Apaga o produto do estoque