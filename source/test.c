#include<stdio.h>
#include<stdlib.h>

#ifdef _WIN32
#include<string.h>

static char buffer[2048];

/*Fake readline function*/

char* readline(char* prompt){
    fputs(prompt,stdout);
    fgets(buffer,2048,stdin);
    char* cpy=malloc(strlen(buffer)+1);
    strcpy(cpy,buffer);
    cpy[strlen(cpy)-1]='\0';
    return cpy;
}

/*Fake add_history function*/
void add_history(char* unused){}

/*Otherwise include the editline headers*/
#else
#include<editline/readline.h>
#include<editline/history.h>
#endif

int main(int argc,char** argv){
    puts("Lispy version 0.0.0.1");
    puts("Press Ctrl+c to Exit\n");
    while(1){
        /*Output our prompt*/
        char* input=readline("lispy>");

        /*Read a line of user input of maxinum size 2048*/
        add_history(input);

        /*echo input back to user*/

        printf("No you are a %s",input);
        free(input);
    }
    return 0;
}