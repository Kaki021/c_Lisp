#include<stdio.h>

static char input[2048];

int main(int argc,char** argv){
    puts("Lispy version 0.0.0.1");
    puts("Press Ctrl+c to Exit\n");
    while(1){
        /*Output our prompt*/
        fputs("lispy>",stdout);

        /*Read a line of user input of maxinum size 2048*/
        fgets(input,2048,stdin);

        /*echo input back to user*/

        printf("No you are a %s",input);
    }
    return 0;
}