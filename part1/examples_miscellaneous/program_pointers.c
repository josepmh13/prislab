#include <stdio.h>
#include <stdlib.h> //to enable malloc(...)

int main(void)
{
  int *p_arr = NULL; // always a good practice

  p_arr = (int*) malloc(3*sizeof(int));

  p_arr[0] = 2;
  *(p_arr+1) = 3;
  p_arr[2] = 7;

  printf("Value of second element: %d\n", p_arr[1]);
  printf("Address of second element: %p\n", &(p_arr[1]));
  printf("Address of second element: %p\n", p_arr+1);
  printf("Size of pointer to int: %lu\n", sizeof(p_arr));

  int **p_p_arr = &p_arr;
  printf("\nValue of second element: %d\n", *(p_p_arr[0]+1));
  printf("Value of second element: %d\n", (*p_p_arr)[1]);
  printf("Address of second element: %p\n", &((*p_p_arr)[1]));
  printf("Size of pointer to pointer: %lu\n", sizeof(p_p_arr));

  //try the following two to see the error - in compilation!
  //printf("Value of second element: %d\n", *((*p_p_arr)[1]) );
  //printf("Value of second element: %d\n", &((*p_p_arr)+1) );

  /* More on sizes */
  short s1 = 4;
  short *p_s1 = &s1;
  printf("\nSize of short: %li\n", sizeof(s1));
  printf("Size of pointer to short: %lu\n", sizeof(p_s1));

  //always release allocated memory!
  free(p_arr);

  //try the following to see the error - in execution!
  //free(p_p_arr);

  return 0;
}
