#include "../TDR.h"
#include <stdio.h>

int main(void){
    type_date d;
    char *cpf;
    type_hours h;

    printf("\nDATA: ");
    d = tdate();
    printf("\n%d\n%d\n%d\n", d.day, d.month, d.year);
    puts(d.tdate);

    printf("\nCPF: ");
    cpf = tcpf();
    printf("\n");
    puts(cpf);

    printf("\nHORARIO: ");
    h = thours();
    printf("\n%d\n%d\n", h.hour, h.min);
    puts(h.hours);

    return 0;
}