#include <conio.h>

void waitkey(void){
	while(kbhit()){getch();}
	while('\n'!=getch());
}
