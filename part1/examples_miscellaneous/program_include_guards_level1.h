//the following two lines represent #include guards
#ifndef LEVEL_1
#define LEVEL_1

#include <stdio.h>
#include "program_include_guards_level2.h"

int mult_nrs(int a, int b){
  if(a>10 || b>10){
    return a*b;
  }
  return sum_nrs(a+b,b) * a * b;
}

#endif /* LEVEL_1 */
