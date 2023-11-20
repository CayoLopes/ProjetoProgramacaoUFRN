typedef struct cliente Cliente;
struct cliente {
  char cpf[12];
  char nome[100];
  char email[100];
  char ender[100];
};
void modulo_cliente(void);
char sub_menu_cliente();
char sub_menu_cliente_cads();
char ficha_cliente();
Cliente* cadas_cliente(void);
void gravar_cliente(Cliente*);
char cliente_ja_cad(Cliente*);
char cliente_ja_cad_contr(Cliente*);
void pesquisa_cliente(const Cliente* cliente);
int editar_cliente(char *termo_busca);
void edit_cliente();
int apagar_cliente(char *termo_busca);
void apaga_cliente();