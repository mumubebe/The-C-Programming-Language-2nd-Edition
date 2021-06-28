#include <stdio.h>

unsigned rightrot(unsigned x, int n);
int bitlen(unsigned d);

int main() {
    printf("%u", rightrot(27, 2));

}

int bitlen(unsigned d) {
    int len = 0;

    while (d) {
        d >>= 1;
        ++len;
    }
    return len;

}


unsigned rightrot(unsigned x, int n) {
    int len = bitlen(x);
    return (((x & ~(~0 << n)) << len-n) | (x >> n));
    
    

}
