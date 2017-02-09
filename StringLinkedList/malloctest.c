/* ========================================================================== */
/*                                                                            */
/*   malloctest.c                                                               */
/*   (c) 2016 Stefan Andree                                                   */
/*                                                                            */
/*   Description                                                              */
/*   tests what malloc returns when passed 0 as size argument                 */
/* ========================================================================== */


#include <stdio.h>
#include <stdlib.h>

void main()
{
    void *ptr = malloc(0);
    void *ptr2 = malloc(10);
    
    printf("malloc(0):%p\n", ptr);
    printf("malloc(10):%p\n", ptr2);
     
    free(ptr);
    free(ptr2);
    
    ptr = calloc(0,10);
    ptr2 = calloc(10,0);
    printf("calloc(0,10):%p\n", ptr);
    printf("calloc(10,0):%p\n", ptr2);
    
    ptr = realloc(ptr, 0);
    printf("realloc(ptr,0):%p\n", ptr);
    ptr2 = realloc(ptr, 100);
    printf("realloc(ptr,100):%p\n", ptr2);
    
    free(ptr);
    free(ptr2);
    
    ptr = malloc(10);
    ptr = realloc(ptr, 0);
     printf("realloc(malloc(10),0):%p\n", ptr);
     free(ptr);
}
