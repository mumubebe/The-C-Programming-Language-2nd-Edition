#include <stdio.h>

#define MAX 100
#define IN  1 
#define OUT 0

int main() {
    int c, state, current_length, most;
    int word_lengths[MAX];

    state = OUT;

    for (int i = 0; i < MAX; ++i)
        word_lengths[i] = 0;
    
    /* Count words */
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                if (current_length > MAX - 1) 
                    current_length = MAX - 1;

                ++word_lengths[current_length];
                if (word_lengths[current_length] > most) {
                    most = word_lengths[current_length];
                }
            }
            state = OUT;
            current_length = 0;
        } else {
            ++current_length;
            state = IN;
        }
    }

    /* Display horizontal */
    for (int i = 0; i < MAX; ++i) {
        if (word_lengths[i]) {
            printf("%3d: ", i);
            for (int j = 0; j < word_lengths[i]; ++j) {
                printf("=");
            }
            printf(" - %d\n", word_lengths[i]);
        }    
    }

    printf("\n");

    /* Display vertical*/
    for (int i = most + 1; i >= -1; --i) {
        for (int j = 0; j < MAX; ++j) {
            if (word_lengths[j]) {
                if (word_lengths[j] == i - 1)
                    printf("%3d", word_lengths[j]);
                else if (i == -1)
                    printf("%3d", j);
                else if (i == 0)
                    printf("---");
                else if (word_lengths[j] >= i)
                    printf(" ||");
                else 
                    printf("   ");
                }
            }
            printf("\n");
        }
    
    
    

}
