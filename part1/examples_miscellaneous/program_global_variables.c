#include <stdio.h>

//global variable
int x=123;

//print global
void f(void)
{
  printf("in f(): x=%d\n",x);
}

//print local
void g(void)
{
  int x=456;
  printf("in g(): x=%d\n",x);
}

int main(void)
{
  printf("main(): x=%d\n",x);
  f();
  g();
}
