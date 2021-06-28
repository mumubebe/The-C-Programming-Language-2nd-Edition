#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
    printf("%d\n", any("1234", "4"));
    printf("%d\n", any("hello", "l"));
    printf("%d\n", any("huhiha", "x"));
    printf("%d\n", any("foxiloxu", "x"));
}



int any(char s1[], char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;

}
