//References:

//	https://stackoverflow.com/questions/1143936/pragma-once-vs-include-guards
//	https://es.wikipedia.org/wiki/Pragma_once
//	https://stackoverflow.com/questions/787533/is-pragma-once-a-safe-include-guard

#include "program_include_guards_level1.h"
#include "program_include_guards_level2.h"

int main(void)
{
  int a = 2, b = 4;
  printf("Result = %d\n", mult_nrs(a,b));
  printf("Result = %d\n", sum_nrs(a,b));
}
