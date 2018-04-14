//Reference: https://en.wikipedia.org/wiki/Include_guard

#include "program_include_guards_level1.h"
#include "program_include_guards_level2.h"

int main(void)
{
  int a = 2, b = 4;
  printf("Result = %d\n", mult_nrs(a,b));
  printf("Result = %d\n", sum_nrs(a,b));
}
