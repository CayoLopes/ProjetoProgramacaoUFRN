void modulo_produto(void); //Modulo que apareçe no menu principal liga as outras páginas
char sub_menu_produto(); //Menu dos produtos
char produto_cads(); //Exibe os produtos que já foram cadastrados
char cadas_produto(); //Faz o cadastro de novos produtos
char info_produto(); //Mostra as informações de um produto
char edit_produto(); //Faz a edição do produto
char apaga_produto(); //Apaga o produto do estoque
struct produto {
  char nome[30];
  char codigo[10];
  char preco[10];
  char estoq[10];
};