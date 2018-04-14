#include <stdio.h>

void incr_nr(int *x)
{
  (*x)++;
}

int* decr_nr(int *y)
{
  (y[0])--;
  return y;
}

int main(void)
{
  int w = 10;
  int *x = &w;
  int *z = NULL;

  incr_nr(x);
  printf("After increment: %d\n", *x);

  z = decr_nr(x);
  printf("After decrement: %d\n", *z);

  //Try the following: compile once and execute multiple
  //                   times to the the different outputs
  //z++;
  //printf("Value of second (non-existent) entry: %d\n", *z);

  return 0;
}

