
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

  if (argc != 2) {
    return 0;
  }

  char suffix[]=".bak";
  char filename[strlen(argv[1]) + strlen(suffix) + 1];

  strcpy(filename, argv[1]);
  strcat(filename, suffix);

  FILE *src = fopen(argv[1],"rb");
  FILE *des = fopen(filename,"wb+");

  char ch = fgetc(src);
  while(!feof(src)){
    ch = ~ch;
    fputc(ch,des);
    ch = fgetc(src);
  }

  fclose(src);
  fclose(des);

  return 0;
}
