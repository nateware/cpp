
/* malloc test */

#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int *count;
  count = (int *)malloc(sizeof(int));
  *count = 44;
  printf("count=%d\n", *count);
  return 0;
}

