#include <stdbool.h>
#include <stdio.h>


int main() {
    int c;
    
    while((c = getchar()) != EOF) {
        if (c == '\t') { 
            putchar('\\');
            putchar('t');
            continue;
        }   
        if (c == '\b'){
            putchar('\\');
            putchar('b');
            continue;
        }
         putchar(c);
    }



        


}
