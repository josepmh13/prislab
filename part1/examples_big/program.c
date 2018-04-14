/* Compilation instructions:

   gcc -c utils.c -o utils.o
   gcc -c program.c -o program.o
   gcc program.o utils.o -o exec_name

*/

/* Execution:

   ./exec_name -f FILENAME -s SORT_TYPE

   (where DATA_TYPE can have values: DINT_X or DDOUBLE_X)
*/

/* More on getopt(...):

   https://www.gnu.org/software/libc/manual/
         html_node/Example-of-Getopt.html#Example-of-Getopt

*/

/*
   TODO: extend to files with numbers with valid letters within; example: .1E4f
*/

#include "utils.h"

//in case of int, define on compile time
#ifdef INT_X
typedef int DATA_T;
#endif

//in case of double, define on compile time
#ifdef DOUBLE_X
typedef double DATA_T;
#endif

void print_usage(void);

int main(int argc, char** argv)
{
  if(argc != 5)
  {
    print_usage();
  }

  /* extract input params using getopt(...) */
  int c;
  char file_name[100];
  char sort_type[100];
  while ((c = getopt(argc, argv, "f:s:")) != -1)
  {
    switch(c)
    {
      case 'f':
        strcpy(file_name, optarg);
        break;
      case 's':
        strcpy(sort_type, optarg);
        break;
      default:
        print_usage();
    }
  }

  /* reading input file */
  FILE* fp;
  fp = fopen(file_name, "r");

  if(fp == NULL)
  {
    printf("Not able to open file!\n");
    exit(EXIT_FAILURE);
  }

  /* count number of (numerical) lines in file */
  int ch;
  int nr_lines=0, pos_within=0;
  while( (ch=fgetc(fp)) != EOF)
  {
    if(pos_within==0 && ch=='-')
    {
      pos_within++;
      continue;
    }
    else if(pos_within!=0 && ch!='\n' && !isdigit( (int)ch ))
    {
      if(ch == '.')
      {
        pos_within++;
      }
      else
      {
        pos_within=0;
      }
      continue;
    }
    else if(pos_within==0 && ch=='\n')
    {
      continue;
    }
    else if(ch == '\n')
    {
      nr_lines++;
      pos_within=0;
      continue;
    }

    pos_within++;
  }

  /* reset location of file-pointer */
  rewind(fp);

  /* memory to store all the input data */
  DATA_T* in_data = malloc(sizeof(DATA_T)*nr_lines);

  /* variables needed to read the file again - now extracting
     the values! */
  char* line = NULL;
  size_t len=0;
  ssize_t read;
  int i=0;

  /* buffer for the extraction */
  DATA_T buff;

  char line2[100];

  /* reading the file again */
  int j=0;
  while((read = getline(&line, &len, fp)) != -1)
  {
    j++;

    strcpy(line2, line);
    line2[strlen(line2)-1] = '\0';

    /* if line[0]=='0', it means that the actual number is 0 */
    if(read==1 && line[0]=='0')
    {
      in_data[i] = 0;
      i++;
    }
    else
    {
      #ifdef INT_X
      buff = atoi(line2);
      #endif
      #ifdef DOUBLE_X
      buff = atof(line2);
      #endif

      /* if buff==0 at this point, it means that the
         value was not able to be extracted */
      if(buff == 0)
      {
        continue;
      }
      else
      {
        in_data[i] = buff;
        i++;
      }
    }
  }

  sort_nrs((void*)in_data, sort_type, nr_lines);

  /*
  printf("\nNrs to sort:\n");
  for(i=0; i<nr_lines; i++)
  {
    #ifdef INT_X
    printf("%d\n", in_data[i]);
    #endif
    #ifdef DOUBLE_X
    printf("%f\n", in_data[i]);
    #endif
  }
  */

  /* now you can do something here with the sorted array! */

  /* free memory */
  free(in_data);

  /* return after successful execution */
  return 0;
}


void print_usage(void)
{
  printf("\nUSAGE: ./exec_name -f FILENAME -s SORT_TYPE\n");
  exit(EXIT_FAILURE);
}
