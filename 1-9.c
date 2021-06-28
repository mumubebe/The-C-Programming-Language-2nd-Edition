#include <stdbool.h>
#include <stdio.h>


int main() {
    int c;
    bool blank;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!blank) {
                blank = true;
                putchar(c);
            }
        }
        if (c != ' ') {
            blank = false;
            putchar(c);
        }
    
    }


}
