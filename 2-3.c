#include <stdio.h>

int htoi(char h[]);

int main() {
    printf("%d\n", htoi("af91"));

}

int htoi(char h[]) {
    int i, n;
    
    n = 0;
    for (i = 0; h[i] != '\0'; ++i) {
        if (h[i] == '0' || h[i] == 'x') {
            continue;
        }
        else if (h[i] >= '0' && h[i] <= '9') {
            n = 16 * n + h[i] - '0';  
        }            
        else if (h[i] >= 'a' && h[i] <= 'f') {
            n = 16 * n + h[i] - 'a' + 10;
        }
        else if (h[i] >= 'A' && h[i] <= 'F') {
            n = 16 * n + h[i] - 'A' + 10;
        }
    }

    return n;


}
