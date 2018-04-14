#include "program_include_guards_level1.h"

int mult_nrs(int, int);

int sum_nrs(int a, int b)
{
  if(a>10 || b>10){
    return a + b;
  }
  return mult_nrs(a+b,b) * a * b;
}
