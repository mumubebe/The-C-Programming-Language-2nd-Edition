#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
    printf("%d", setbits(43,4,3,19));
}

/* returns x with the n bits that begin at position p set to the 
 rightmost n bits of y , leaving the other bits unchanged */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
   return ((x & ((~0 << p + 1) | ~(~0 << p+1-n))) | (~(~0 << (p+1)) & (y << (p+1-n))));

}
