#include "stdio.h"


void foo(int *p) {
    *p = *p + 1; // acessa variavel global
}

void main(void) {
    int a = 0; // var global
    int b = 0; // var global
    int *p;
    p=&a;

    while (1) {
        foo(p);
        
        if (a > 5) {
            b = 1;
        }
    }

    printf("Valor de 'b' é: %d",b);
}
