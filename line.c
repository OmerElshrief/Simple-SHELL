#ifndef line_c
#define line_c
#include "line.h"


void getLine(char* line)
{
   ssize_t bufsize = BUFFERSIZE;
   ssize_t charSize=0;
//   while(charSize!=0)
   charSize = getline(&line,&bufsize,stdin);
  // perror("\nYou've just entered %zu characters\n",charSize);
}



int splitLine(char* line, char**args)
{

  char* str;
  int strsize = BUFFERSIZE;
  int index=0;
  str = strtok(line," ,-");
  while(str!=NULL)
  {
    args[index] = str;
    index++;
    if(index == strsize)
    {
      strsize +=BUFFERSIZE;
      args = realloc(args,strsize * sizeof(char*));
      if(!args)
      printf("error: Allocating error, exiting...");
    }
    str = strtok(NULL," ,-");

  }
  args[index] = NULL;


    return index;
}
#endif
