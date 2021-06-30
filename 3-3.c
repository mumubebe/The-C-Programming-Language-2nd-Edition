#include <stdio.h>
#include <ctype.h>

#define DIG_LOW 48
#define DIG_HIGH 57
#define CHAR_C_LOW 65
#define CHAR_C_HIGH 90
#define CHAR_LOW 97
#define CHAR_HIGH 122
void expand(char s1[], char s2[]);

int main() {
    char s1[] = "a-z0-9ac1-2A-Y";
    char s2[255];
    expand(s1, s2);
    printf("%s\n", s2);
}

/* Copy s1 to s2, 
 expanding expressions such a-z to abc..xyz */
void expand(char s1[], char s2[]) {
    int i, j, from, to;
    i = j = 0;
    while(s1[i] != '\0') {
        if (s1[i] == '-' && i > 0) { //Check if any range expression in str
            if ((s1[i-1] < s1[i+1])) {
                from = s1[i-1];
                to = s1[i+1];
                
                if ((from >= CHAR_LOW && to <= CHAR_HIGH)
                    || (from >= CHAR_C_LOW && to >= CHAR_C_HIGH)
                    || (from >= DIG_LOW && to >= DIG_HIGH)) {
                    for (int fr = s1[i-1]; fr <= s1[i+1]; fr++, j++) {
                        s2[j] = fr;
                    }
                }
            }
        } else { // Chars without expand
            if (s1[i+1] != '-' && s1[i-1] != '-') {
                s2[j++] = s1[i];
            }
        }
        i++;
        
    }
    s2[j++] = '\0';
}
