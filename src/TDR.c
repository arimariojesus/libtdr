/* TYPE DATA READ */
#include "headerpack.h"
#include "TDR.h"

type_date tdate (void) {
    type_date return_date;
    char ch, str[11], *token;
    int x=0, i=0;

    do{
        if((x==2 || x==4) && isdigit(str[i-1])){
            printf("/");
            str[i++] = '/';
        }
        
        ch = getch();

        if(isdigit(ch) && i<10){
            printf("%c", ch);
            ++x;
            str[i++] = ch;
        }

        if(ch==8 && i>0){
            if(str[i-1]=='/'){
                printf("\b \b\b \b");
                --i;
            }else printf("\b \b");
            --x; --i;
        }

    }while(ch!=13 || x<8);

    memset(return_date.tdate, '\0', sizeof(return_date.tdate));// Inicializa a string
    strncpy(return_date.tdate, str, 10);

    token = strtok(str, "/");
    x = 1;
    while(token){
        if(x==1)return_date.day = atoi(token);
        if(x==2)return_date.month = atoi(token);
        if(x==3)return_date.year = atoi(token);

        token = strtok(NULL, "/");
        x++;
    }

    return return_date;
}

char* tcpf (void){
    char ch;
    int x=0, i=0;

    retcpf = malloc(sizeof(12));// Aloca memória para 'retcpf'

    do{
        if((x==3 || x==6) && ch!=8){
            printf(".");
        }else if(x==9 && ch!=8)printf("-");

        ch = getch();

        if(isdigit(ch) && x<11){
            x++;
            printf("%c", ch);
            retcpf[i++] = ch;
        }

        if(ch==8 && i>0){
            if(x==3 || x==6 || x==9){
                printf("\b \b\b \b");
            }else printf("\b \b");
            --x; --i;
        }
    }while(ch!=13 || x<11);

    return retcpf;
}

type_hours thours (void){
    type_hours return_hours;
    char ch, str[6], *token;
    int x=0, i=0;

    do{
        if(x==2 && isdigit(str[i-1])){
            printf(":");
            str[i++] = ':';
        }

        ch = getch();

        if(isdigit(ch) && i<5){
            x++;
            printf("%c", ch);
            str[i++] = ch;
        }

        if(ch==8 && i>0){
            if(x==2){
                printf("\b \b\b \b");
                --i;
            }else printf("\b \b");
            --x; --i;
        }
    }while(ch!=13 || x<4);

    memset(return_hours.hours, '\0', sizeof(return_hours.hours));
    strncpy(return_hours.hours, str, 5);

    token = strtok(str, ":");
    x = 1;
    while(token){
        if(x==1)return_hours.hour = atoi(token);
        if(x==2)return_hours.min = atoi(token);

        token = strtok(NULL, ":");
        x++;
    }

    return return_hours;
}