#ifndef TDR_H
#define TDR_H

typedef struct{
    int day;
    int month;
    int year;
    char tdate[11];
}type_date;

typedef struct{
    int hour;
    int min;
    char hours[6];
}type_hours;

char *retcpf;

type_date tdate(void);
char* tcpf(void);
type_hours thours(void);

#include "TDR.c"

#endif