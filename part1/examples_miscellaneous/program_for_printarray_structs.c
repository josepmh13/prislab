#include <stdio.h>
#include <stdlib.h>


struct arr_ints{
  int size;
  int *data;
};


//Redefined the name of the struct
typedef struct arr_ints ARR_INTS_P;


void print_arr(ARR_INTS_P arr_pack_x)
{
  int i;

  printf("Array: ");
  for(i=0; i<arr_pack_x.size-1; i++)
  {
    printf("%d, ", arr_pack_x.data[i]);
  }
  printf("%d\n", arr_pack_x.data[arr_pack_x.size-1]);
}


int main(void)
{
  ARR_INTS_P arr_pack;

  arr_pack.size = 4;

  arr_pack.data = (int*) malloc(arr_pack.size * sizeof(int));

  (arr_pack.data)[0] = 2;
  (arr_pack.data)[1] = 3;
  (arr_pack.data)[2] = 5;
  (arr_pack.data)[3] = 89;

  print_arr(arr_pack);

  free(arr_pack.data);
}
