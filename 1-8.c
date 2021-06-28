#include <stdio.h>

int main() {
    int t, nl, b, c;

    t = 0;
    nl = 0;
    b = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++t;
        if (c == ' ')
            ++b;
    }
    printf("Blanks: %d\t Lines: %d\t Tabs: %d\n", b, nl, b);

}
