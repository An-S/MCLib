/* ========================================================================== */
/*                                                                            */
/*   Filename.c                                                               */
/*   (c) 2012 Author                                                          */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int num = 28456;
	int dsum = 0;
	div_t r;
	r.quot = num;
	
	do{
		r = div(r.quot,10);
		printf("quot: %d, rem: %d\n", r.quot, r.rem);
		dsum += r.rem;
	}while(0 != r.quot);
	printf("\nnum:%u, dsum:%u\n", num, dsum);
}
