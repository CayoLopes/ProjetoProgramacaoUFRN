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