#include "fileIO.h"
int fileIO_overwriteYNErrH(char *params, char *format, va_list va){
	char ch;

    //call std error handler to ouput error information to stderr
	fileIO_stdErrH(params, format, va);

    fprintf(stderr, "Overwrite? Y/N? ");
    do{
        ch=toupper(fgetc(stdin));
        switch(ch){
            case 'Y': return EXIT_SUCCESS;
            case 'N': return EXIT_FAILURE;
            default: break;
        }
    }while(true);
}


