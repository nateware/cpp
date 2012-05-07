
/* void and function pointers */

#include <stdio.h>

typedef struct {
  int n, d;
} frac;

typedef struct {
  int n, d;
} frac2;

//int print_frac(void ** frac)
//{
  //return frac->n;
//}

void use_int(void *);
void use_float(void *);
void greeting(void (*)(void *), void *);

void get_address(void *ptr)
{
  printf("ptr=%p\n", ptr);
}

int main(void) {
  char ans;
  int i_age = 22;
  float f_age = 22.0;
  void *p;
  printf("Use int (i) or float (f)? ");
  scanf("%c", &ans);
  if (ans == 'i') {
    p = &i_age;
    greeting(use_int, p);
  }
  else {
    p = &f_age;
    greeting(use_float, p);
  }
  get_address(p);

  frac *f1;
  f1 = new frac;
  f1->n = 1;
  f1->d = 3;

  printf("The fraction is %d / %d\n", f1->n, f1->d);

  frac2 *f2;
  f2 = new frac2;
  f2->n = 2;
  f2->d = 4;

  //print_frac(f2);

  return 0;
}

void greeting(void (*fp)(void *), void *q) {
  fp(q);
}

void use_int(void *r) {
  int a;
  a = * (int *) r; /* dereference to get value */
  printf("As an integer, you are %d years old.\n", a);
}

void use_float(void *s) {
  float *b;
  b = (float *) s;
  printf("As a float, you are %f years old.\n", *b);
}

