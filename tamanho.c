#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define st_atime st_atim.tv_sec
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec

int main(int argc, char* argv[]) {
if (argc < 2) {
    fprintf(stderr, "usage: %s file\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  for (int i=0; i< argc-1;i++){
    struct stat info;
  int retv = stat(argv[i+1], &info);
  if (retv == -1) {
    fprintf(stderr, "fsize: Can’t stat %s\n", argv[1]);
    exit(EXIT_FAILURE);
    }
  printf("%s size: %d bytes, disk_blocks: %d, User ID: %d, Last Modified: %s \n",
  argv[i+1], (int)info.st_size, (int)info.st_blocks, (int)info.st_uid, ctime(&info.st_mtime));
}
exit(EXIT_SUCCESS);

}