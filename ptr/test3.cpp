// http://theoryx5.uwinnipeg.ca/programming/node83.html

#include <stdio.h>

void testit(int *in) {
  printf("Within testit(), upon entering, in[0]=%d\n", in[0]);
  in[0] = 11;
  printf("Within testit(), before leaving, in[0]=%d\n", in[0]);
}

void printit(const int *in) {
  for(int i=0; i<5; i++)
    printf("in[%d]=%d\n", i, in[i]);
}

int main(void) {
  int i[] = {1,2,3,4,5};
  printf("Before testit(), i[0]=%d\n", i[0]);
  //testit(&i[0]); // by reference
  testit(i); // same thing
  printf("After testit(), i[0]=%d\n", i[0]);

  printit(i);

  return 0;
}

