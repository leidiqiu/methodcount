#include <stdio.h>
#include <string.h>

#define OFFSET_FIELD 0x50
#define OFFSET_METHOD 0x58

void calCount(char *fileName,int *fieldCount,int *methodCount){
  FILE *fp = fopen(fileName, "r+b");
  fseek(fp, OFFSET_FIELD, SEEK_SET);
  fread(fieldCount, 4, 1, fp);
  fseek(fp, OFFSET_METHOD, SEEK_SET);
  fread(methodCount, 4, 1, fp);
  fclose(fp);
}

int main(int argc,char *args[]){

  if (argc==2 && strcmp("help",args[1])==0){
    printf("usage : dexmethodcount [ file ... ] \n");
    return 0;
  }

  FILE *fp;
  int fc, mc;
  if(argc < 2){
    calCount("classes.dex", &fc, &mc);
  }else{
    int tfc, tmc;
    for(int i = 1; i < argc; i++){
      calCount(args[i], &tfc, &tmc);
      fc += tfc;
      mc += tmc;
    }
  }

  printf("dex file field count:%d\n", fc);
  printf("dex file method count:%d\n", mc);

  return 0;
}
