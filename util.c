#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "util.h"

// Valida letra 
// Feito com ajuda do CHATGPT
int testaLetra(char c) {
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ' || (c >= 192 && c <= 252)) {
    return 1;
  } else {
    return 0;
  }
}



// Valida nome 
// Baseado no codigo de Flavius GORGÔNIO
int validarNome(char *nome){
  for (int i=0; nome[i]!='\0'; i++){
    if (!testaLetra(nome[i])){
      printf("<%c>", nome[i]);
      return 0;
    }
  }
    return 1;
}

//Validador de CPF feito com o CHATGPT
int validarCPF(char *cpf) {
    int soma1 = 0, soma2 = 0;
    int digito1, digito2;

    // Verifica se o CPF possui 11 dígitos
    if (strlen(cpf) != 11) {
        return 0;  // CPF inválido
    }

    // Verifica se todos os caracteres são dígitos
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return 0;  // CPF inválido
        }
    }

    // Calcula o primeiro dígito verificador
    for (int i = 0; i < 9; i++) {
        soma1 += (cpf[i] - '0') * (10 - i);
    }
    digito1 = 11 - (soma1 % 11);
    if (digito1 >= 10) {
        digito1 = 0;
    }

    // Calcula o segundo dígito verificador
    for (int i = 0; i < 10; i++) {
        soma2 += (cpf[i] - '0') * (11 - i);
    }
    digito2 = 11 - (soma2 % 11);
    if (digito2 >= 10) {
        digito2 = 0;
    }

    // Verifica os dígitos verificadores
    if ((cpf[9] - '0' != digito1) || (cpf[10] - '0' != digito2)) {
        return 0;  // CPF inválido
    }

    return 1;  // CPF válido
}

//FUnção para validar e-mail feito por Gustavo Douglas 
//https://github.com/Gustavo-DSC/ProgamacaoProjetoUFRN.git
int verificar_email(char *email) {
    char *arroba = strchr(email, '@');
    char *ponto = strrchr(email, '.');
    if (arroba != NULL && ponto != NULL && arroba < ponto) {
        // Verifica se há apenas um '@' no email 
        if (strchr(arroba + 1, '@') == NULL) {
            // Verifica se tem pelo menos um caractere antes do '@'
            if (arroba != email) {
                // Verifica se tem pelo menos um caractere entre '@' e '.'
                if (arroba + 1 < ponto) {
                    // Verifica se tem pelo menos dois caracteres após o '.'
                    if (strlen(ponto) > 2) {
                        // Verifica se o email contém caracteres especiais
                        for (char *c = email; *c; c++) {
                            if ((*c < 'a' || *c > 'z') && (*c < 'A' || *c > 'Z') && (*c < '0' || *c > '9') && *c != '@' && *c != '.' && *c != '-' && *c != '_') {
                                return 0;
                            }
                        }
                        // Verifica o comprimento da parte local e do domínio
                        if ((arroba - email <= 64) && (strlen(arroba) - strlen(ponto) <= 255)) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}