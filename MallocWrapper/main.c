#include <stdio.h>
#include "imalloc.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

int imalloc_basicTests(void);
int reportIfimallocError(void);
int printNumberOfAllocations(void);

char** allocStringTable(int size, char* strTableIn[]){
	char** strTable = imalloc(size*sizeof(char*));
	char* thisStr = NULL;
	assert (EXIT_SUCCESS == reportIfimallocError() );//fail, if error on allocation
	puts("***");
	//va_start(strTableIn, first);

	for (int i = 0; i< size; ++i){
		thisStr = strTableIn[i];//va_arg(strTableIn, char*);
		assert (NULL != thisStr);
		puts(thisStr);

		strTable[i] = imalloc(strlen(thisStr)+1);
		assert (EXIT_SUCCESS == reportIfimallocError() );//fail, if error on allocation
		memmove(strTable[i], thisStr, strlen(thisStr)+1);
	}
	//va_end(strTableIn);
	return strTable;
}

int deallocStringTable(int size, char** table){

	for (int i = 0; i< size; ++i){
		assert (NULL != table[i]);
		puts(table[i]);
		ifree(table[i]);
		assert (EXIT_SUCCESS == reportIfimallocError() );
	}

	return EXIT_SUCCESS;
}

int main(int argc, char **argv)
{
	char** strTable;
	char* strTableInit[] = {"Eins", "Zwei", "Drei", "Vier", "Fuenf", "Sechs", "Sieben", "Accht", "Neun", "Zehn!"};

	imalloc_basicTests();

	puts("\n***");
	puts("Allocating String table");
	strTable = allocStringTable(sizeof(strTableInit)/sizeof(char*), strTableInit);
	assert (EXIT_SUCCESS == reportIfimallocError() );

	puts("Deallocating String table");
	deallocStringTable(sizeof(strTableInit)/sizeof(char*), strTable);

	return 0;
}
