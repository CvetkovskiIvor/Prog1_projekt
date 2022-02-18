#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char valueOperator(char c){

  return 'n';
}

void defineOperators(FILE *fp){
  char c;
  int inDefine = -1;
  int inString = -1;

  while((c = fgetc(fp)) != EOF){
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
            printf("(op_zbr)");
            break;

          // op oduzimanja
          case '-':
            printf("(op_oduz)");
            break;

          // op mnozenja
          case '*':
            printf("(op_mnoz)");
            break;

          // op dijeljenja
          case '/':
            printf("(op_dij)");
            break;

          // op modulo
          case '%':
            printf("(op_mod)");
            break;

          // logicko NE
          case '~':
            printf("(op_NOT)");
            break;

          // logicko I
          case '&':
            printf("(op_AND)");
            break;

          // logicko ILI
          case '|':
            printf("(op_OR)");
            break;

          // logicko ekskluzivno ILI
          case '^':
            printf("(op_XOR)");
            break;

          // op manje
          case '<':
            printf("(op_manje)");
            break;

          // op vece
          case '>':
            printf("(op_vece)");
            break;
          
          
        }
      }
    }
  }
}

int main(){
  int num = 9;
  FILE *filepointer;

  filepointer = fopen("in.txt", "r");

  if(filepointer == NULL){
    printf("Error!");
  }

  defineOperators(filepointer);
  //locateOperators(filepointer);

  fclose(filepointer);

  return 0;
}