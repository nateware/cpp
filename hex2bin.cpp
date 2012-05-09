/*
 * hex to binary
 */

#include <stdio.h>
#include <math.h>
#include <cstdlib>

// http://20bits.com/article/interview-questions-counting-bits

/* Print n as a binary number */
int printbits(long unsigned int n) {
    printf("%lu => ", n);
    int count = 0;    
    while (n) {
		    if (n & 0x1u) {
            printf("1");
            count++;
        } else {
            printf("0");
        }
		    n >>= 1;
	  }
    printf("\n");
	  return count;
}

void shuffle_array(int * array, int len) {
    int n = len - 1;
    while (n > 0) {
        int k = rand() % n;
        n--;
        int tmp  = array[k];
        array[k] = array[n];
        array[n] = tmp;
    }
}

// Pre-compute this elsewhere and put it here.
static unsigned int bit_table16[0x1u << 16];

// This only works for 32-bit integers but takes constant time.
int bitcount_32(long unsigned int n) {
    return bit_table16[n & 0xFFFFu] + bit_table16[(n >> 16) & 0xFFFFu];
}

void fastprintbits(long unsigned int n) {
    int bits = bitcount_32(n);
    printf("bits=%d\n", bits);
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


	printbits(0x24f3d6);

  long unsigned int num = 0x473a5291ce8;
  printf("num=%lu\n", num);
  printbits(num);

  fastprintbits(num);

#define array_len 10
  int array[array_len] = {0,1,2,3,4,5,6,7,8,9};
  for (int i=0; i < array_len; i++)
    printf("array[%d]=%d\n", i, array[i]);

  printf("shuffle\n");
  shuffle_array(array, array_len);

  for (int i=0; i < array_len; i++)
    printf("array[%d]=%d\n", i, array[i]);

}

