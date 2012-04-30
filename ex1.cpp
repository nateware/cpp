/*
 * example 1 - C++ tutorial
 *
 */

#include <iostream>
#include "pet.h"
using namespace std;

/*
 * http://www.cplusplus.com/forum/beginner/10602/
 *
 * p1 is a constant pointer to "John"
 * p1 can't change, but you can change "John" thru p1.
 *
 * p2 is a pointer to a constant "Mary"
 * p2 can change to point to another constant string, but you can't change the value "Mary" thru p2.
 *
 *  char * const p1 = "John";
 *  *p1 = 'C'; // allowed
 *  p1  = "Margaret";  // not allowed 
 *
 *  const char * p2 = "Mary";
 *  *p2 = 'C'; // not allowed.
 *  p2  = "Margaret";  // allowed
 *
 * Also:
 *  http://stackoverflow.com/questions/890535/what-is-the-difference-between-char-const-and-const-char
 *  http://blog.wolffmyren.com/2008/05/02/g-warning-deprecated-conversion-from-string-constant-to-%E2%80%98char%E2%80%99/
 */

char john[] = "John\n";
char *const p1 = john;  // pointer const
//char const p1[] = "John";  // pointer const
char const *p2 = "Mary";  // value const

const int pathwidth = 100;

#define TACO "taco\n"

// same:
//const char * p2 = "Mary";

/*
   http://www.cplusplus.com/doc/tutorial/pointers/
  
   When declaring pointers we may want to explicitly specify which variable we want them to point to:
      int number;
      int *tommy = &number;

   The behavior of this code is equivalent to:
      int number;
      int *tommy;
      tommy = &number; // notice the lack of "*" !!!

   Thus, we must take care not to confuse the previous code with: 
      int number;
      int *tommy;
      *tommy = &number;

   That is incorrect, and anyway would not have much sense in this case if you think about it.

 */

void increase (void* data, int psize)
{
  if ( psize == sizeof(char) )
  { char* pchar; pchar=(char*)data; ++(*pchar); }
  else if (psize == sizeof(int) )
  { int* pint; pint=(int*)data; ++(*pint); }
}

int main ()
{
  int times = 0;
  int len = NULL;
  char buf[255];
  char petname[] = "Fluffywwwwwwwwwwwwwww";

  char wife[] = "Sarah";
  char *spouse;


  //CPet fluffy();

  int val = 42;
  int *ptr, *ptr2;
  char let = 'A';

  memset(buf,0,sizeof(buf));

  cout << "Hello World!\n";

  times++;
  times++;
  times++;

  cout << "Times = " << times << "; yay!\n";

  p2 = TACO;
  cout << p2;

  p1[0] = 'T';
  p1[3] = 'y';
  cout << p1;

  len = (int)strlen(p1);
  printf("strlen(p1)=%d\n", len);


  //fluffy = new CPet(petname, 3);

  ptr2 = ptr = &val;
  cout << *ptr << endl;
  *ptr  = 99;
  *ptr2 = 98;

  cout << *ptr << endl;
  cout << val << endl;


  // char[] arrays are "weird"
  spouse = wife;
  cout << spouse << endl;
  spouse[0] = 'T';
  spouse[1] = 'y';
  cout << spouse << endl;
  *(spouse+2) = 'z';
  cout << spouse << endl;

  char a = 'x';
  int b = 1602;
  increase (&a, sizeof(a));
  increase (&b, sizeof(b));
  cout << a << ", " << b << endl;
  return 0;
}

