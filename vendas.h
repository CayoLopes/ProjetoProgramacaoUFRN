typedef struct venda Venda;
struct venda {
   char codigov[10];
   char cpff[12];
   char cpfc[12];
   char codigo[10];
   char nomef[50];  
   char nomec[50];  
   char nomep[50];  
   float preco[10];
   int quant[10];
   int valor[10];
   char status[3];
};

void modulo_venda(void);
char sub_menu_venda();
void realizar_venda(Venda* venda);
void relatorio_venda();
void relatorio_vendaFil();
int deletar_venda(char *termo_busca);
void apaga_venda();
char* obterNomeCliente(const char *cpf);
char* obterNomeProduto(const char *codigo);
char* obterValorProduto(const char *codigo);
void subtrairQuantidadeEstoque(const char *codigo, int quantidade);
void retornaQuantidadeEstoque(const char *codigo, int quantidade);
char* obterNomeFuncionario(const char *cpf);
void gravar_venda(Venda*);