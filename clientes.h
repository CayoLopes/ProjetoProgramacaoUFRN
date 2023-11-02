typedef struct cliente Cliente;
struct cliente {
  char cpf[12];
  char nome[100];
  char email[100];
  char ender[100];
};
void modulo_cliente(void);
char sub_menu_cliente();
char ficha_cliente();
Cliente* cadas_cliente(void);
void gravar_cliente(Cliente*);
char cliente_ja_cad(Cliente*);
char edit_cliente();
char apaga_cliente();