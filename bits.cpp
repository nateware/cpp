
#include "stdio.h"

int magic(int x) {
      x--;
          x |= x >> 1;
              x |= x >> 2;
                  x |= x >> 4;
                      x |= x >> 8;
                          x |= x >> 16;
                              return x + 1;
}

int main ()
{
   for (int i = 1; i < 100; i++) {
      printf("%d: %d\n", i, magic(i));
   }
   return 0;
}
