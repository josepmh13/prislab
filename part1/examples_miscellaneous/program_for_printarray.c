#include <stdio.h>

void print_arr(int params[], int size)
{
  int i;

  printf("Array: ");
  for(i=0; i<size-1; i++)
  {
    printf("%d, ", params[i]);
  }
  printf("%d\n", params[size-1]);
}

int main(void)
{
  int arr_i[] = {2, 3, 5, 89};
  const int size = 4;

  print_arr(arr_i, size);
}
