#include <stdio.h>

void escape(char s[], char t[]);

int main() {
    char t[] = "hello\t\nwat";
    char s[255];
    escape(s,t);
    printf("%s", s);
}

void escape(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            default:
                s[j] = t[i];
                break;
        }
        ++i;
        ++j;
    
    }
    s[j] = '\0';

}
