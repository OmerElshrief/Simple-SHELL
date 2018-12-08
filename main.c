#include "line.c"
#include "stdio.h"
#include "proccesses.c"
#include "builtinFunc.c"

void main(void)
{
  int flag =0;
  int size;
  char *in;
  in = malloc(0*sizeof(char));
  while(1)
  {
    printDir();
    getLine(in);
    char **lines;
    lines = malloc(BUFFERSIZE * sizeof(char*));
    size =  splitLine(in,lines);

    for(int i=0;i<size;i++)
  {
    printf("%d -%s\n",i,lines[i] );
   if(strcmp(lines[i],"&")==0)
    {
      flag=1;
      break;
    }
    lunch(lines,flag);
  }

  }





}
