#include "stdio.h"
#include "math.h"
#include "ctype.h"

int main() {
    double atof(char s[]);

    printf("%g\n", atof("12.3"));
    printf("%g\n", atof("10"));

    printf("%g\n", atof("1.45e+6"));
    printf("%g\n", atof("123.45e-3"));
    printf("%g\n", atof("1.2345e-7"));

}


double atof(char s[]) {
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++) {}

    sign = (s[i] == '-' ? -1 : 1);
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.') {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    } 
    if (s[i] == 'e' || s[i] == 'E') {
        i++; 
        int expsign = s[i] == '-' ? -1 : 1;
        i++;
        int exp; 
     
        for (exp = 0; isdigit(s[i]); i++) {
            exp = 10 * exp + (s[i] - '0');           
        } 

        for (int e = exp; e > 0; e--) {
            if (expsign == 1) {
                val = val * 10.0;
            } else {
                val = val / 10.0;
            }
        } 
    }

    
    
    return sign * val / power;
    

}
