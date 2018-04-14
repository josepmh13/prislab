#include <stdio.h>
#include <limits.h> // for int
#include <float.h>  // for float
#include <math.h>   // for pow(...)

int main(void) {
  printf("INFO - int\n");
  printf("Storage size for int: %d bytes \n", (int) sizeof(int));
  int pos_int_max = (int) pow(2, 8*sizeof(int)-1);
  printf("Range: %d to %d\n", -(pos_int_max+1), pos_int_max);
  printf("Example int overflow: %d \n", -(pos_int_max+1)-1);

  printf("\nINFO - float\n");
  printf("Storage size for float : %d \n", (int) sizeof(float));
  printf("Minimum float positive value: %E\n", FLT_MIN );
  printf("Maximum float positive value: %E\n", FLT_MAX );
  printf("Precision value: %d\n", FLT_DIG );

  return 0;
}
