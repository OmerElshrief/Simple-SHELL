#ifndef builtinFunc_c
#define builtinFunc_c

char *builtinFunc_names[] = {
  "cd: Change the current work directory",
  "help: Getting help",
  "exit: Terminate the current session"
};

//Array of pointers to functions to execture the built in functions;



// Function to print Current working Directory.
void printDir()
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s: ", cwd);
}

//Function to change the Working Directory.
int cd(char**args)
{
  if(args[1]==NULL)
  {
    printf("error: wrong arguments");
  }
  else
  if (chdir(args[1]) != 0)
    {
      printf("error: unbale to execute");
    }
    return 1;
}

int help()
{
  for(int i=0;i<4;i++)
  printf("\n\s",builtinFunc_names[i]);
}

int Exit()
{
  return 0;
}
#endif
