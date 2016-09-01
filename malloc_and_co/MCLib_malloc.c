
#include <stdio.h>
#include <stdlib.h>
/*
gcc (tdm-1) 4.9.2 output of following program:

#include <stdio.h>
#include <stdlib.h>

void main()
{
    void *ptr = malloc(0);
    printf("malloc(0):%p", ptr);
    free(ptr);
}

C:\Users\User\Documents\Programmieren\EigeneCProgramme\MyCLib\StringLinkedList>malloctest.exe
malloc(0):008E2F20
C:\Users\User\Documents\Programmieren\EigeneCProgramme\MyCLib\StringLinkedList>malloctest.exe
malloc(0):00722F20
C:\Users\User\Documents\Programmieren\EigeneCProgramme\MyCLib\StringLinkedList>malloctest.exe
malloc(0):00682F20
C:\Users\User\Documents\Programmieren\EigeneCProgramme\MyCLib\StringLinkedList>malloctest.exe
malloc(0):00A22F20
C:\Users\User\Documents\Programmieren\EigeneCProgramme\MyCLib\StringLinkedList>malloctest.exe
malloc(0):00732F20
C:\Users\User\Documents\Programmieren\EigeneCProgramme\MyCLib\StringLinkedList>malloctest.exe

Though malloc(0) makes no sense, a valid pointer is returned by malloc which makes this indistinguishable
from the return value of malloc(N) with N>0.
what happens, when using that pointer returned from malloc(0)?
In this case gcc allocates memory in chunks of 32 bytes. so if no more than 32 bytes are written to the pointer
returned by malloc(0) no harm would be done. Nonetheless other compilers would probably treat that situation differently
so for sure this case should be checked!
*/

/** \brief simple replacement for malloc with at least returning size of allocated block and if alloc succeeded
 *
 * \param size_t size: size of block to be allocated
 * \param void **ptr: pointer to pointer holding address of allocated block
 * \return size_t: real size of allocated block (f.e if passing 0 for size then size defaults to 10 bytes)
 *
 */
size_t MCLib_malloc(size_t size, void **ptr)
{
	if (!size) size = 10; //defaults to 10 bytes if no size is given

	//check if ptr is not NULL
	if (ptr){
		//the single "=" is intended here !!!
		if ( ((*ptr) = malloc(size)) ){
			return size;
		}
		//malloc failed so fall through return 0;
	}
	return 0;
}

//different idea: return error as a string in allocated block so that it can be print out
//use strlen to get size of allocated block-1 after the alloc call

