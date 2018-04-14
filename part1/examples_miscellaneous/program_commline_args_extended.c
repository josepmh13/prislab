#include <stdio.h>

int main(int argc, char *argv[])  { 	//The second argument can be
					//written as: char **argv
  if(argc == 2) {
    printf("The argument supplied is %s\n", argv[1]);
  }
  else if(argc > 2)
  {
    printf("The arguments supplied are: ");
    int i;
    for(i=1; i<argc-1; i++)
    {
      printf("%s, ", argv[i]);
    }
    printf("%s\n", argv[argc-1]);
  }
  else{
    printf("At least one argument expected.\n");
  }

  return 0;
}
