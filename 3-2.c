#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
    char t[] = "hello\t\nwat";
    char s[255];
    unescape(s,t);
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

void unescape(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\\':
                switch (t[i++]) {
                    case 't':
                        s[j] = '\t';
                        break;
                    case 'n':
                        s[j] = '\n';
                        break;
                    default:
                        s[j] = t[i];
                        break;
                }
                
            default:
               s[j] = t[i];
               break;
        
        }
        j++;
        i++;
    }
    s[j] = '\0';
}
