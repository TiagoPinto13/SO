#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 64
int main(int argc, char* argv[]) {
char* p1 = (char*)malloc(MAX_SIZE * sizeof(char));
char* p2 = (char*)malloc(MAX_SIZE * sizeof(char));
strcpy(p1, argv[1]);
strcpy(p2, argv[2]);
for (int i=0;p1[i] != '\0';i++){
    p1[i]=tolower(p1[i]);
  }
  printf("%s\n",p1);
}





//recebe uma string na linha de comando e a transforma numa string equivalente mas
//com todos os caracteres em min´usculas;