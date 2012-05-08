/*
 * hex to binary
 */

#include <stdio.h>
#include <math.h>

/* Print n as a binary number */
int printbitssimple(long n) {
  /* find max power of 2 (binary) */
  unsigned int p = 0;
  while (pow(2,p) < n) p++;
  printf("n=%ld, p=%d (%f)\n", n, p, pow(2,p));

  unsigned int r = 1;

  /* fill it up with 1's */
	unsigned int i;
	i = 1 << (sizeof(n) * p - 1);
  printf("i=%d\n", i);

	while (i > 0) {
		if (n & i) {
      r <<= 1;
			printf("1");
    } else {
      r <<= 1;
			printf("0");
    }
		i >>= 1;
	}
  printf("\n");

  if (r != n)
    fprintf(stderr, "Warning: ret(%d) != n(%ld)\n", r, n);
}

/* Print n as a binary number */
void printbits(int n) {
	unsigned int i, step;

	if (0 == n) { /* For simplicity's sake, I treat 0 as a special case*/
		printf("0000");
		return;
	}

	i = 1<<(sizeof(n) * 8 - 1);

	step = -1; /* Only print the relevant digits */
	step >>= 4; /* In groups of 4 */
	while (step >= n) {
		i >>= 4;
		step >>= 4;
	}

	/* At this point, i is the smallest power of two larger or equal to n */
	while (i > 0) {
		if (n & i)
			printf("1");
		else
			printf("0");
		i >>= 1;
	}
  printf("\n");
}

int main()
{


/*
 * ex1: convert 24f3d6 to binary

24f3d6

2 0010
4 0100
f 1111
3 0011
d 1101
6 0110

Answer = 0010 0100 1111 0101 1101 0110


0x473a5291ce8

4 0010
7 0111
3 0011
a 1000
5 0101
2 0010
9 1001
1 0001
c 1010
e 1110
8 1000



*/

	printbitssimple(0x24f3d6);

  long num = 0x473a5291ce8;
  printf("num=%ld\n", num);
  printbitssimple(num);
}
