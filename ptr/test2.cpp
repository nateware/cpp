
#include <stdio.h>
#include <math.h>

int quadratic(float, float, float, float *, float *);

int doit(void) {
  float a=1.0, b=-6.0, c=8.0, r1, r2;
  if (quadratic(a, b, c, &r1, &r2)) {
    printf("The two roots are %f and %f\n", r1, r2);
  }
  else {
    printf("No real roots exist");
  }
  return 0;
}

int quadratic(float a, float b, float c, float *r1, float *r2) {
  float d;
  d = b*b-4.0*a*c;
  if (d > 0) {
    *r1 = ( -b + sqrt(d) ) / (2.0*a);
    *r2 = ( -b - sqrt(d) ) / (2.0*a);
    return 1;
  }
  else {
    return 0;
  }
}


int main(void) {
  int count, *p;
  count = 22;
  p = &count;
  printf("count is %d\n", count);
  printf("p is %p\n", p);
  printf("*p is %d\n", *p);

  doit();

  return 0;
}

