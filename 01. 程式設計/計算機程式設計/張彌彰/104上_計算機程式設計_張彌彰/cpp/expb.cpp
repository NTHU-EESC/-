/*
 * expa.c: example for const pointers
 *
 */

#include <stdio.h>

main()
{
	int i1=1,i2=2,i3=3,i4=4;
	int *p1=&i1;
	const int *p2=&i2;
	int const *p3=&i3;
	const int const *p4=&i4;

	*p1=2;
	p1=(int *)p2;

	*p2=3;
	p2=p3;

	*p3=4;
	p3=p4;

	*p4=5;
	p4=p1;
}
