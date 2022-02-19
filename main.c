#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char valueOperator(char c){

  return 'n';
}

void defineOperators(FILE *fp, FILE *lfp){
  int i = 0;
  int j = 0;
  char c, c1;
  int inDefine = -1;
  int inString = -1;

  while((c = fgetc(fp)) != EOF){
    if(c == '\n'){
      i++;
      j = 0;
    }
    j++;
    printf("%c", c);

    // check if in define

    // check if in string
    if(c == '"'){
      inString *= -1;
    }

    if(inString == -1){
      if(!isalpha(c) && !isdigit(c) && !isspace(c)){
        
        switch (c){
          // op zbrajanja
          case '+':
            c1 = fgetc(fp);
            if(c1 == '+'){
              printf("%c(op_inkr)", c1);
            }else{
              printf("(op_zbr)");
              printf("%c", c1);
            }
            if(c1 == '\n'){
              i++;
            }
            break;

          // op oduzimanja
          case '-':
            c1 = fgetc(fp);
            if(c1 == '-'){
              printf("%c(op_dekr)", c1);
            }else{
              printf("(op_oduz)");
              printf("%c", c1);
            }
            if(c1 == '\n'){
              i++;
            }
            break;

          // op mnozenja
          case '*':
            c1 = fgetc(fp);
            if(c1 == '='){
              printf("%c(op_mnoz)", c1);
            }else{
              printf("(op_mnoz)");
              printf("%c", c1);
            }
            if(c1 == '\n'){
              i++;
            }
            break;

          // op dijeljenja
          case '/':
            c1 = fgetc(fp);
            if(c1 == '='){
              printf("%c(op_dijelj)", c1);
            }else{
              printf("(op_dijelj)");
              printf("%c", c1);
            }
            if(c1 == '\n'){
              i++;
            }
            break;

          // op modulo
          case '%':
            c1 = fgetc(fp);
            if(c1 == '='){
              printf("%c(op_mod)", c1);
            }else{
              printf("(op_mod)");
              printf("%c", c1);
            }
            if(c1 == '\n'){
              i++;
            }
            break;

          // logicko NE
          case '~':
            c1 = fgetc(fp);
            if(c1 == '='){
              printf("%c(op_NOT)", c1);
            }else{
              printf("(op_NOT)");
              printf("%c", c1);
            }
            if(c1 == '\n'){
              i++;
            }
            break;

          // logicko I
          case '&':
            c1 = fgetc(fp);
            if(c1 == '&'){
              printf("%c(op_uAND)", c1);
            }else{
              printf("(op_AND)");
              printf("%c", c1);
            }
            if(c1 == '\n'){
              i++;
            }
            break;

          // logicko ILI
          case '|':
            c1 = fgetc(fp);
            if(c1 == '|'){
              printf("%c(op_uOR)", c1);
            }else{
              printf("(op_OR)");
              printf("%c", c1);
            }
            if(c1 == '\n'){
              i++;
            }
            break;

          // logicko ekskluzivno ILI
          case '^':
          
            printf("(op_XOR)");
            break;

          // op manje
          case '<':
            c1 = fgetc(fp);
            if(c1 == '<'){
              printf("%c(op_lPosmak)", c1);
            }else{
              if(c1 == '='){
                printf("%c(op_manje-jed)", c1);
              }else {
                printf("(op_manje)");
                printf("%c", c1);
              }
            }
            if(c1 == '\n'){
              i++;
            }
            break;

          // op vece
          case '>':
            c1 = fgetc(fp);
            if(c1 == '>'){
              printf("%c(op_dPosmak)", c1);
            }else{
              if(c1 == '='){
                printf("%c(op_vece-jed)", c1);
              }else {
                printf("(op_vece)");
                printf("%c", c1);
              }
            }
            if(c1 == '\n'){
              i++;
            }
            break;
          
          case '=':
            c1 = fgetc(fp);
            if(c1 == '='){
              printf("%c(op_uJedn)", c1);
            }else{
              printf("(op_jedn)");
              printf("%c", c1);
            }
            if(c1 == '\n'){
              i++;
            }
            break;
        }
      }
    }
  }
  printf("Broj redova: %d", i);
}

int main(){
  int num = 9;
  FILE *filepointer;
  FILE *locationfilepointer;

  filepointer = fopen("in.txt", "r");

  if(filepointer == NULL){
    printf("Error!");
  }

  defineOperators(filepointer, locationfilepointer);
  //locateOperators(filepointer);

  fclose(filepointer);

  return 0;
}