#include <stdio.h>

int lower(int c);

int main() {
    printf("%c\n", lower('B'));
}


int lower(int c) {
    return c >= 'A' && c <= 'Z' ? c+'a'-'A':c;

}
