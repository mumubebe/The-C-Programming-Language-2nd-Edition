#include <stdio.h>

unsigned invert(unsigned x, int n, int p);

int main() {
    printf("%u", invert(25, 3, 3));
}

unsigned invert(unsigned x, int n, int p) {
    
    unsigned mask = (~(~0<<p+1) ^ (~(~0 << p+1-n)));
    return mask ^ x;


}
