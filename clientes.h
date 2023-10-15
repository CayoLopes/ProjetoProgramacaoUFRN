void modulo_cliente(void);
char sub_menu_cliente();
char cliente_ja_cad();
char ficha_cliente();
char cadas_cliente();
char edit_cliente();
char apaga_cliente();
struct cliente {
  char cpf[12];
  char nome[100];
  char email[100];
  char ender[100];
};