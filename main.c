#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void defineOperators(FILE *fp, FILE *lfp){
  int i = 1;
  int j = 0;
  char c, c1;
  int inDefine = -1;
  int inString = -1;
  int inChar = -1;
  int inComment1 = -1;
  int inComment2 = -1;

  // take characters while not end of file
  while((c = fgetc(fp)) != EOF){
    
    // counter correction if at end of line
    if(c == '\n'){
      i++;
      j = 0;
    }else{
      j++;
    }
    
    printf("%c", c);

    // check if in define/include
    if(c == '#'){
      inDefine = 1;
    }else if(inDefine && c == '\n'){
      inDefine = -1;
    }

    // check if end of one line comment
    if(inComment1 && c == '\n'){
      inComment1 = -1;
    }

    // check if end of multiple line comment 
    if(inComment2 && c == '*'){
      c1 = fgetc(fp);
      if(c1 == '/'){
        inComment2 = -1;
        printf("%c", c1);
        continue;
      }
    }

    // check if in ""
    if(c == '"'){
      inString *= -1;
    }

    // check if in ''
    if(c == '\''){
      inChar *= -1;
    }

    //printf("%d %d %d %d %d\n", inString, inDefine, inChar, inComment1, inComment2);
    if(inString == -1 && inDefine == -1 && inChar == -1 && inComment1 == -1 && inComment2 == -1){

      // if all of these are true we know its not an operator
      if(!isalpha(c) && !isdigit(c) && !isspace(c)){
        switch (c){
          // op zbrajanja
          case '+':
            c1 = fgetc(fp);
            if(c1 == '+'){
              printf("%c(op_inkr)", c1);
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
            }else if(c1 == '='){
              printf("%c(op_zbr)", c1);
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
            }else{
              printf("(op_zbr)");
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j);
              printf("%c", c1);
            }
            j++;
            if(c1 == '\n'){
              i++;
              j = 0;
            }
          break;

          // op oduzimanja
          case '-':
            c1 = fgetc(fp);
            if(c1 == '-'){
              printf("%c(op_dekr)", c1);
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
            }else if(c1 == '='){
              printf("%c(op_oduz)", c1);
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
            }else{
              printf("(op_oduz)");
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j);
              printf("%c", c1);
            }
            j++;
            if(c1 == '\n'){
              i++;
              j = 0;
            }
          break;

          // op mnozenja
          case '*':
            c1 = fgetc(fp);
            if(c1 == '='){
              printf("%c(op_mnoz)", c1);
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
            }else{
              printf("(op_mnoz)");
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j);
              printf("%c", c1);
            }
            j++;
            if(c1 == '\n'){
              i++;
              j = 0;
            }
          break;

          // logicko ne
          case '!':
            c1 = fgetc(fp);
            if(c1 == '='){
              printf("%c(op_uNOT)", c1);
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
            }else{
              printf("(op_NOT)");
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j);
              printf("%c", c1);
            }
            j++;
            if(c1 == '\n'){
              i++;
              j = 0;
            }
          break;

          // op dijeljenja
          case '/':
            c1 = fgetc(fp);
            if(c1 == '='){
              printf("%c(op_dijelj)", c1);
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
            }else if(c1 == '/'){
              inComment1 = 1;
              printf("%c", c1);
            }else if(c1 == '*'){
              inComment2 = 1;
              printf("%c", c1);
            }else{
              printf("(op_dijelj)");
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j);
              printf("%c", c1);
            }
            j++;
            if(c1 == '\n'){
              i++;
              j = 0;
            }
          break;

          // op modulo
          case '%':
            c1 = fgetc(fp);
            if(c1 == '='){
              printf("%c(op_mod)", c1);
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
            }else{
              printf("(op_mod)");
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j);
              printf("%c", c1);
            }
            j++;
            if(c1 == '\n'){
              i++;
              j = 0;
            }
          break;

          // binarni komplement
          case '~':
            c1 = fgetc(fp);
            if(c1 == '='){
              printf("%c(op_compl)", c1);
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
            }else{
              printf("(op_compl)");
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j);
              printf("%c", c1);
            }
            j++;
            if(c1 == '\n'){
              i++;
              j = 0;
            }
          break;

          // logicko I
          case '&':
            c1 = fgetc(fp);
            if(c1 == '&'){
              printf("%c(op_uAND)", c1);
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
            }else{
              printf("(op_AND)");
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j);
              printf("%c", c1);
            }
            j++;
            if(c1 == '\n'){
              i++;
              j = 0;
            }
          break;

          // logicko ILI
          case '|':
            c1 = fgetc(fp);
            if(c1 == '|'){
              printf("%c(op_uOR)", c1);
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
            }else{
              printf("(op_OR)");
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j);
              printf("%c", c1);
            }
            j++;
            if(c1 == '\n'){
              i++;
              j = 0;
            }
          break;

          // logicko ekskluzivno ILI
          case '^':
            printf("(op_XOR)");
            fprintf(lfp, "OP location: i = %d j = %d\n", i, j);
          break;

          // zarez
          case ',':
            printf("(op_zarez)");
            fprintf(lfp, "OP location: i = %d j = %d\n", i, j);
          break;

          // op manje
          case '<':
            c1 = fgetc(fp);
            if(c1 == '<'){
              printf("%c(op_lPosmak)", c1);
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
            }else{
              if(c1 == '='){
                printf("%c(op_manje-jed)", c1);
                fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
              }else {
                printf("(op_manje)");
                fprintf(lfp, "OP location: i = %d j = %d\n", i, j);
                printf("%c", c1);
              }
            }
            j++;
            if(c1 == '\n'){
              i++;
              j = 0;
            }
          break;

          // op vece
          case '>':
            c1 = fgetc(fp);
            if(c1 == '>'){
              printf("%c(op_dPosmak)", c1);
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
            }else{
              if(c1 == '='){
                printf("%c(op_vece-jed)", c1);
                fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
              }else {
                printf("(op_vece)");
                fprintf(lfp, "OP location: i = %d j = %d\n", i, j);
                printf("%c", c1);
              }
            }
            j++;
            if(c1 == '\n'){
              i++;
              j = 0;
            }
          break;
          
          // op jednako
          case '=':
            c1 = fgetc(fp);
            if(c1 == '='){
              printf("%c(op_uJedn)", c1);
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j + 1);
            }else{
              printf("(op_jedn)");
              fprintf(lfp, "OP location: i = %d j = %d\n", i, j);
              printf("%c", c1);
            }
            j++;
            if(c1 == '\n'){
              i++;
              j = 0;
            }
          break;
        }
      }
    }
  }
}

int main(){
  FILE *filepointer;
  FILE *locationfilepointer;
  int num = 9;
  char *ime = "in";
  char *nastavak = ".txt";
  char filename[strlen(ime) + strlen(nastavak) + 1];

  snprintf(filename, sizeof(filename), "%s%s", ime, nastavak);

  filepointer = fopen(filename, "r");
  locationfilepointer = fopen("op_pos.txt", "w");

  if(filepointer == NULL){
    printf("Error!");
  }

  defineOperators(filepointer, locationfilepointer);

  fclose(filepointer);

  return 0;
}