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
char sub_menu_funcionario_cads(Funcionario*);
Funcionario* cadas_func(void);
void gravar_func(Funcionario*);
char funcio_ja_cad(Funcionario*); 
char funcio_ja_cad_contr(Funcionario*);
void pesquisa_func(const Funcionario* funcionario);
int editar_func(char *termo_busca);
void edit_func();
int deletar_func(char *termo_busca);
void apaga_func();