#ifndef proccesses_c
#define proccesses_c

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "builtinFunc.c"



// Function where the system command is executed
int execute(char** parsed,char background)
{
    // Forking a child
    pid_t pid = fork();


    if (pid == -1) {  //Forking faild
        printf("\nFailed forking child, Exiting...");
        return -1;
    } else if (pid == 0) {  //Forking is done
        if (execvp(parsed[0], parsed) < 0) {
            printf("%s\n",parsed[0] );
            printf("\nCould not execute command,Exiting..\n");
        }
        return -1;
    } else {
        // waiting for child to terminate if not  background process
        if(!background)
        wait(NULL);
        return 1;
    }
}

int lunch(char** args,char background)
{
  if(args[0]==NULL)
  {
    printf("error: Epty arguments, Exiting..");
    return -1;
  }

  for(int i=0;i<4;i++)
  {
    if(strcmp(args[0],builtinFunc_names[i]))
    {
    switch (1)
  {
    case 0:
    return cd(args);
    break;
    case 1:
    return help();
    break;
    case 2:
    return  Exit();
    break;
        //Pointer to function to execute a built in function
    }
  }
  return execute(args,background);
}
}
#endif
