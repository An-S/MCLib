#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <MCLib.h>

char MCLib_getCharFromKeybdBuffer(void){
	if ( kbhit() ){
		return getch();
	}
	return 0;
}

void MCLib_printCharAtCursorPos(char ch){
	putch(ch);
	//_cprintf("%x|",ch);
}

//example_
char* MCLib_inputField(unsigned char len, char cursor, char filter(char)){
	char key=0;
	char* inputString=MCLib_stralloc(len);
	unsigned char inputLen=0;

	if(inputString){
		//empty keybd buffer
		while( MCLib_getCharFromKeybdBuffer() );

		while(('\r'!=key)){
			inputLen=strlen(inputString);
			if (cursor){
				MCLib_printCharAtCursorPos(cursor);
				MCLib_printCharAtCursorPos('\b');
			}
			//get next char from keybd buffer
			while( !(key=MCLib_getCharFromKeybdBuffer()) );
			switch(key){
				case 0x8:
					if(0<inputLen){
						inputString[inputLen-1]='\0';
						if (cursor){
							MCLib_printCharAtCursorPos(' ');
							MCLib_printCharAtCursorPos('\b');
						}
						MCLib_printCharAtCursorPos('\b');
						MCLib_printCharAtCursorPos(' ');
						MCLib_printCharAtCursorPos('\b');

					}
					break;
				//cursor left
				case -0x20:
					key=MCLib_getCharFromKeybdBuffer();
					switch (key){
						case 0x4b:
							if(0<inputLen){
								MCLib_printCharAtCursorPos('\b');
							}
							break;
						//cursor right
						case 0x4d:
							if(0<inputLen){
								MCLib_printCharAtCursorPos('\b');
							}
							break;
						//cursor down
						case 0x50:
							if(0<inputLen){
								MCLib_printCharAtCursorPos('\b');
							}
							break;
						//cursor up
						case 0x48:
							if(0<inputLen){
								MCLib_printCharAtCursorPos('\b');
							}
							break;
						default: break;
					}
					break;
				//case '\r':goto endofinput;
				default:{
					if(len>inputLen){
						inputString[inputLen]=key;
						MCLib_printCharAtCursorPos(key);
					}
					break;
				}
			}
		}
endofinput:
		MCLib_printCharAtCursorPos(' ');
		/*clrscr();
		write_room_info();
		write_death();*/
	}
	return inputString;
}
