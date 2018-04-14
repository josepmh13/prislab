#include <stdio.h>

/* The x variable will be redefined to 123 each time
   that f() is called */
void f(void)
{
  int x=123;
  x++;
  printf("f(): x=%d\n",x);
}

/* The use of 'static' makes x accessible globally, and the line
   'static int x=123;' is called only once i.e. the first time that
   g() is called */
void g(void)
{
  static int x=123;
  x++;
  printf("g(): x=%d\n",x);
}

int main(void)
{
  //non-incremental calls
  f(); f(); f();
  //incremental calls
  g(); g(); g();
}
