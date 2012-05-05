#include <iostream>

/* http://stackoverflow.com/questions/109023/best-algorithm-to-count-the-number-of-set-bits-in-a-32-bit-integer */
long count_bits(long n) {     
  unsigned int c; // c accumulates the total bits set in v
  for (c = 0; n; c++) 
    n &= n - 1; // clear the least significant bit set
  return c;
}

int main (int argc, char * const argv[]) {
    const char * file = "/etc/smb.conf";
    FILE * fh;

    char buf[512];
    fh = fopen(file, "r");
    if (fh == NULL) {
        perror(file);
        exit(1);
    }

    while (fgets(buf,sizeof(buf),fh) != 0) {
        printf("line={%s}", buf);
    }

    if (!feof(fh)) {
        fprintf(stderr, "%s: No at end of file?\n", file);
    }

    fclose(fh);
    /* free(buf); */


    /* describe an algorithm to count all the bits that are in a file.
     * Example: if the file had exactly one byte, and that byte stored
     * the value 3, the program should return 2.
     * Looking for (1) for loop with shift-and to count each bit
     * (2) a lookup table indexed by byte value with precalculated bit count.
     */

    printf("\n-- bit files --\n");

    const char * file2 = "bitfile";
    long int out[] = {316831, 18728, 91992};
    long int a1 = count_bits(out[0]);
    printf("bits=%ld (%ld)\n", a1, out[0]);
    long int a2 = count_bits(out[1]);
    printf("bits=%ld (%ld)\n", a2, out[1]);

    fh = fopen(file2, "wb");
    fwrite(&out,sizeof(out),1,fh);
    fclose(fh);

    fh = fopen(file2, "rb");  /* binary */
    if (fh == NULL) {
        perror(file2);
        exit(1);
    }
    printf("opened %s\n", file2);

    /* read each val, remember an integer is 4 bytes, and we are counting
     * the number of bits that are "on"
     */
    long val;
    long int total_bits = 0;
    while (fread(&val,sizeof(val),1,fh) != 0) {
        printf("val=%ld\n", val);
        long int b = count_bits(val);
        printf("bits=%ld\n", b);
        total_bits += b;
    }
    printf("Total bits = %ld\n", total_bits);



    return 0;
}

