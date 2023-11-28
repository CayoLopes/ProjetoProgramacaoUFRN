typedef struct venda Venda;
struct venda {
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
};
void modulo_venda(void);
char sub_menu_venda();
char realizar_venda(Venda* venda);
char relatorio_venda();
char edit_venda();
char* obterNomeCliente(const char *cpf);
char* obterNomeProduto(const char *codigo);
char* obterValorProduto(const char *codigo);
void subtrairQuantidadeEstoque(const char *codigo, int quantidade);
char* obterNomeFuncionario(const char *cpf);

