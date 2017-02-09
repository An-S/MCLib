#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <MCLib.h>

typedef int char_t;

char_t MCLib_getCharFromKeybdBuffer(void){
	if ( kbhit() ){
		return getch();
	}
	return 0;
}

char_t MCLib_classifyKeyPressed(char_t key){

}

void MCLib_printCharAtCursorPos(char_t ch){
	putch(ch);
	//_cprintf("%x|",ch);
}

//example_
char* MCLib_inputField(uint8_t len, char_t cursor, char_t filter(char_t)){
	char_t key=0;
	char* inputString=MCLib_stralloc(len);
	uint8_t inputLen = 0;
	uint8_t inputPos = 0;

	if(inputString){
		//empty keybd buffer
		while( MCLib_getCharFromKeybdBuffer() );

		while(('\r'!=key)){
			if (cursor){
				MCLib_printCharAtCursorPos(cursor);
				MCLib_printCharAtCursorPos('\b');
			}
			//get next char from keybd buffer
			while( !(key=MCLib_getCharFromKeybdBuffer()) );
			switch(key){
				case 0x8:
					if(0<inputPos){
						inputString[inputLen-1]='\0';
						if (cursor){
							MCLib_printCharAtCursorPos(' ');
							MCLib_printCharAtCursorPos('\b');
						}
						MCLib_printCharAtCursorPos('\b');
						MCLib_printCharAtCursorPos(' ');
						MCLib_printCharAtCursorPos('\b');

						--inputPos;
						--inputLen;
					}
					break;
				//cursor left
				case 0xe0:
					key=MCLib_getCharFromKeybdBuffer();
					switch (key){
						//cursor left
						case 0x4b:
							if(0<inputPos){
								MCLib_printCharAtCursorPos('\b');
								--inputPos;
							}
							break;
						//cursor right
						case 0x4d:
							if(inputPos < inputLen){
								MCLib_printCharAtCursorPos(inputString[inputPos]);
								++inputPos;
							}
							break;
						//cursor down
						case 0x50:
							if(0<inputLen){
								//MCLib_printCharAtCursorPos('\b');
							}
							break;
						//cursor up
						case 0x48:
							if(0<inputLen){
								//MCLib_printCharAtCursorPos('\b');
							}
							break;
						default: break;
					}
					break;
				//case '\r':goto endofinput;
				default:{
					if(len>inputLen){
						inputString[inputPos]=key;
						MCLib_printCharAtCursorPos(key);
						++inputPos;
						if (inputPos >= inputLen){
							inputLen = inputPos;
						}
					}
					break;
				}
				//_cprintf("\r%*s", len, inputString);
			}
		}
	}
	return inputString;
}
