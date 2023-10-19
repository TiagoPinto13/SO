#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 64
int main(int argc, char* argv[]) {
  char* p1 = (char*)malloc(MAX_SIZE * sizeof(char));
  char* p2 = (char*)malloc(MAX_SIZE * sizeof(char));
  strcpy(p1, argv[1]);
  strcpy(p2, argv[2]);
  if (strstr(p2,p1)!= NULL) {
        printf("A primeira string ocorre na segunda.\n");
    } else {
        printf("A primeira string não ocorre na segunda.\n");
    }
    return 0;
}