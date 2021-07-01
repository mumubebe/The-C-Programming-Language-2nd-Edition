#include "stdio.h"

int strindex(char s[], char t[]);

int main() {
    printf("%d\n", strindex("abcdefg1234abc", "abc"));
    printf("%d\n", strindex("abcdefg1234", "abc"));
}

int strindex(char s[], char t[]) {
    int i, j, k, p;
    p = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++) {}

        if (k > 0 && t[k] == '\0') {
            p = i;
        }
    }
    return p >= 0 ? p : -1;

}
