#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 64
int main(int argc, char* argv[]) {
  char* needle = (char*)malloc(MAX_SIZE * sizeof(char));
  char* haystack = (char*)malloc(MAX_SIZE * sizeof(char));
  strcpy(needle, argv[1]);
  strcpy(haystack, argv[2]);
  int count=0;
  char* it= haystack;
  while((it=strstr(it,needle))!=NULL){
  count++;
  it += strlen(needle);
  }
  if (count>0) {
        printf("A primeira string ocorre na segunda %d.\n",count);
    } 
    else {
        printf("A primeira string não ocorre na segunda.\n");
    }
  }