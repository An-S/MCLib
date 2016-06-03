
#include <MCLib.h>

bool name(unsigned int n, char a, char b){
    static unsigned int c = 0;
    bool selection = ++c%n;
    putchar(selection?a:b);
    return selection;
}
