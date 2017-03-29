#ifndef __CMACROS_H__
#define __CMACROS_H__

#include <stdlib.h>
#include <stdio.h>

#define WITH(ptr) __AX__=(uintptr_t)ptr,asm("sta ptr1"), asm("stx ptr1+1")
#define SETB(ptr, field, value) __AX__ = value, asm("ldy #%b", offsetof(ptr, field)), \
    asm("sta (ptr1),y")
#define SETW(ptr, field, value) __AX__ = (unsigned int)value, asm("ldy #%b", offsetof(ptr, field)), \
    asm("sta (ptr1),y"), \
    asm("txa"), asm("iny"), asm("sta (ptr1),y")

#define MAX(x,y) ( (x)<(y)?(y):(x))
#define MIN(x,y) ( (x)<(y)?(x):(y))
#define ABS(x) ( (x)<0?(-x):(x))

#define ELEMCNT(x) ( (sizeof(x))/(sizeof((x)[0])) )

//helper macros: EMPTY->contains nothing
//               BID->bracket ID, which means identity with protecting brackets
//               ID->Identity without protecting brackets
//               _STR(x)->Stringification of unevaluated argument
//               STR(x)->Stringification of evaluated argument
#define EMPTY
#define BID(x) (x)
#define ID(x) x
#define _STR(x) #x
#define STR(x) _STR(x)

//this is what a linear fit revealed from number of digits(incl sign) vs byte size. The resulting values for slope and offset
//where rationalized with wolfram alpha. The addition of 1 i due to the terminating \0
#define INTFIELDWIDTH(intsz) ( 1+((intsz)*4*593+1161)/1000 )
#ifndef NDEBUG
#define massert(cond, msg, ...) do{if(!(cond)) printf("Assert failed! ");printf(msg,__VA_ARGS__);}while(0);exit(1);
#else
#define massert(cond, msg)
#endif // NDEBUG

#ifndef NDEBUG
#define sassert(head, cond, msg, ...) do\
    {head;\
     if(!(cond))\
        {printf("Assert failed! ");\
        printf(msg,__VA_ARGS__);\
        exit(1);\
        }\
     }while(0)
#else
#define massert(cond, msg)
#endif // NDEBUG

#endif
