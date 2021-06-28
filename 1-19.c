#include <stdio.h>

#define MAXLINE 1000

int lineget(char line[], int maxline);
void reverse(char line[], int len);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = lineget(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s\n", line);

    }
    return 0;
}

int lineget(char s[], int lim) {
    int c, i;
    for (i=0; i < lim -1 && (c = getchar()) != EOF && c!='\n';++i) {
        s[i] = c;

    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char s[], int len) {
    int i;
    for (i = 0; i < len / 2; ++i) {
        char c = s[i];
        s[i] = s[len -1 - i];
        s[len - 1 -i] = c;
    }
    s[len] = '\0';
}
