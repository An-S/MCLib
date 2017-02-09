#include <stdio.h>
#include <stdlib.h>

#include "include/MCLib_Keybd.h"

char MCLib_passCharAsIs(char ch){
	return ch;
}

int main()
{
    char *myInput = MCLib_inputField(200,0,MCLib_passCharAsIs);

    _cprintf("\r\nInput was: %s\r\n", myInput);
    return 0;
}
