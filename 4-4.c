#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h>

#define MAXOP   100 // max size of ops
#define NUMBER  '0' // signal that a number was forund
#define MAXVAL  100 // max depth of val stack

double val[MAXVAL];
int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void topprint(void);
void duplicate(void);
void clear(void);
void swap(void);

int sp = 0;

/* reverse Polish calculator */
int main() {
    int type;
    int op2_int;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '%':
                op2_int = pop();
                push(((int)pop()) % op2_int);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0){
                    push(pop() / op2);
                } else {
                    printf("error: zero devisor\n");
                }
                break;
            case '?':
                topprint();
                break;
            case '!':
                duplicate();
                break;
            case '<':
                swap();
                break;
            case '#':
                clear();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    
    }
    return 0;

}

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, cant push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty \n");
        return 0.0;
    }

}

/* getop: get next char or num op */
int getop(char s[]) {
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t') {}
    s[1] = '\0';

    if (!isdigit(c) && c != '.') {
        return c;
    }
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {}
    }

    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) {}
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

void topprint(void) {
    if (sp > 0) {
        printf("%g", val[sp-1]);
    } else {
        printf("stack is emtpy");
    }

}

void clear(void) {
    sp = 0;
}

void duplicate(void) {
    double dup = pop();
    push(dup);
    push(dup);
}

void swap(void) {
    double o1 = pop();
    double o2 = pop();
    push(o1);
    push(o2);
}


#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0; //next free pos in buf

/* get a (possibly pushed-back) char */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push char back on input*/
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many chars \n");
    } else {
        buf[bufp++] = c;
    }

}

