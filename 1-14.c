#include <stdio.h>

#define N_CHARS 255

int main() {
    int c;
    int chars[N_CHARS];

    for (int i = 0; i < N_CHARS; ++i)
        chars[i] = 0;
    
    while ((c = getchar()) != EOF) {
        if (c >= 0 && c <= N_CHARS) {
            ++chars[c];
        }
    }


    /* Histogram diagonal  */
    for (int i = 0; i < N_CHARS; ++i) {
        if (chars[i]) {
            putchar(i);
            printf("| ");

            for (int j = 0; j < chars[i]; ++j) {
                printf("=");
            }
            printf("-%d\n", chars[i]);
        }
    }
}
