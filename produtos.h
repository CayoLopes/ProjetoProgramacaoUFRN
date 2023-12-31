typedef struct produto Produto;
struct produto {
  char nome[30];
  char codigo[10];
  char preco[10];
  char estoq[10];
  char status[3];
};

void modulo_produto(void); //Modulo que apareçe no menu principal liga as outras páginas
char sub_menu_produto(); //Menu dos produtos
char sub_menu_produto_cads(Produto*);
Produto* cadas_produto(void); //Faz o cadastro de novos produtos
void gravar_produto(Produto*);
void produtos_cads(Produto*);
void produtos_inativos(Produto* produto);
void produtos_cads_contr(Produto*);
void pesquisa_produto(const Produto* produto);
char info_produto(); //Mostra as informações de um produto
int editar_produto(char *termo_busca);
void edit_produto(); //Faz a edição do produto
int deletar_produto(char *termo_busca);
void apaga_produto(); //Apaga o produto do estoque
int recupera_produto(char *termo_busca);
void recuperar_produto();

int ProdutoJaCadastrado(const char *codigo);
char* obterCodProduto(const char *codigo);
void Produtos_com_vend();

typedef struct Elementop {
    struct produto dados;
    struct Elementop* proximo;
} Elementop;

Elementop* inserir_em_ordemP(Elementop* inicio, struct produto dados);
void listar_em_ordem_alfabeticaP();
void listar_produto(struct produto u);