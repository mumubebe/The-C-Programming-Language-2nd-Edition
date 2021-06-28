#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
    char s[] = "hello";
    char s2[] = "lo";
    squeeze(s, s2);
    
    printf("%s", s);
}


void squeeze(char s1[], char s2[]) {
    int i, j, k, found;
   
    for (i = k = 0; s1[i] != '\0'; i++) {
        found = 0;
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                found = 1;
                break;
            } 
        }
        if (!found) {
            s1[k++] = s1[i];
        }
    }

    s1[k] = '\0';


}
