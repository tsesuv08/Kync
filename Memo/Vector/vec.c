#include "vec.h"
#include <stdio.h>

int main(void)
{	vec *v1 = vecnew();
	vec *v2 = vecnew();

	vecset(v1, 0, 0);
	vecset(v2, 1, 2);

	printf("V1: %d %d\n", v1->x, v1->y);

	printf("V2: %d %d\n", v2->x, v2->y);

	vecfree(v2);
	vecfree(v1);

	return 0;
}
