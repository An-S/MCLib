#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

unsigned char* MCLib_inputField(unsigned char len, char cursor, char getkey(void), char filter(char)){

unsigned char* fine_input(unsigned char len,unsigned char cursor){
	unsigned char key=0;
	unsigned char* eingabestring=calloc(len,1);
	unsigned char eglen;

	if(NULL!=eingabestring){
		if(kbhit()){cgetc();}
		while(('\n'!=key)){
			eglen=strlen(eingabestring);
			cputcx(eglen,cursor);
			key=cgetc();
			switch(key){
				case CH_DEL:{
					if(0<eglen){
						eingabestring[eglen-1]='\0';
						cputcx(eglen,' ');
						break;
					}
				}
				case CH_ENTER:{break;}
				default:{
					if(len>eglen){
						eingabestring[eglen]=key;
						cputcx(eglen,key);
					}
				}
			}
		}
		cputcx(eglen,' ');
		/*clrscr();
		write_room_info();
		write_death();*/
	}
	return eingabestring;
}
