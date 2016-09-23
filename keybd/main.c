#include <stdio.h>
#include <stdlib.h>

#include "include/MCLib_Keybd.h"

char MCLib_passCharAsIs(char ch){
	return ch;
}

int main()
{
    MCLib_inputField(200,0,MCLib_passCharAsIs);

    return 0;
}
