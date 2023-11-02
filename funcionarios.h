typedef struct funcionario Funcionario;
struct funcionario { 
  char cpf[12];
  char cargo[50];
  char nome[100];
  char email[100];
  char ender[100];
};

void modulo_funcionario(void);
char sub_menu_funcionario();
char ficha_func();
Funcionario* cadas_func(void);
void gravar_func(Funcionario*);
char funcio_ja_cad(Funcionario*); 
char edit_fun();
char apaga_fun();