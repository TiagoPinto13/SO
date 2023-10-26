#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <utime.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
      fprintf(stderr, "usage: %s file\n", argv[0]);
      exit(EXIT_FAILURE);
  }
    for (int i=0; i< argc-1;i++){
      struct stat info;
      int fd = open(argv[i+1], O_CREAT|O_EXCL);
      if (fd == -1) {
        if (errno==EEXIST){
            int retv = stat(argv[i+1], &info);
            if (retv == -1) {
              fprintf(stderr, "fsize: Can’t stat %s\n", argv[1]);
              exit(EXIT_FAILURE);
              }
              info.modtime;
          }
        printf("error: cannot open %s\n", argv[1]);
        exit(EXIT_FAILURE);
      }    
    } 
  file.close(); 
}

    return EXIT_SUCCESS;
}
