#include "imalloc_internal.h"



int imalloc_basicTests(void){
	char teststring[] = "this is my imalloc teststring";
	char teststring2[] = "Das ist mein zweiter Probetext, für irealloc.";
	char* deststr;

	printNumberOfAllocations();
	putchar('\n');

	puts("Allocating block");
	deststr = imalloc(sizeof(teststring));
	if ( EXIT_SUCCESS == reportIfimallocError() ){

		putchar('\n');

		puts("Output string from freshly allocated memory");
		memmove(deststr, teststring,sizeof(teststring));
		puts(deststr);
	}
	printNumberOfAllocations();
	putchar('\n');

	puts("Re-allocating block");
	deststr = irealloc(deststr, sizeof(teststring2));

	if ( EXIT_SUCCESS == reportIfimallocError() ){

		putchar('\n');
		puts("Output string from freshly allocated memory");
		memmove(deststr, teststring2,sizeof(teststring2));
		puts(deststr);
	}
	printNumberOfAllocations();
	putchar('\n');

	puts("Test NULL Pointer in ifree");
	ifree(NULL);//provoke error
	reportIfimallocError();
	printNumberOfAllocations();
	putchar('\n');

	puts("Test invalid ptr given to ifree");
	ifree(deststr+6);//provoke error
	reportIfimallocError();
	printNumberOfAllocations();
	putchar('\n');

	puts("Should be valid");
	ifree(deststr);
	reportIfimallocError();
	printNumberOfAllocations();
	putchar('\n');

	//Bug found here.
	puts("One ifree too much");
	ifree(deststr);
	reportIfimallocError();
	printNumberOfAllocations();
	putchar('\n');
	return EXIT_SUCCESS;
}
