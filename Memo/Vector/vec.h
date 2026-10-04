#ifndef VEC_H
#define VEC_H

#include "type.h"
#include <stdlib.h>

typedef struct vec
{	struct vec *this;

	int x;
	int y;
} vec;

vec *vecnew(void)
{	vec *v = (vec *)malloc(sizeof(vec));

	v->this = v;

	v->x = 0;
	v->y = 0;

	return v;
}

chr vecset(vec *v, int x, int y)
{	v->x = x;
	v->y = y;

	return 0;
}

chr vecfree(vec *v)
{	v->this = NULL;

	v->x = 0;
	v->y = 0;

	free(v);
	v = NULL;

	return 0;
}

#endif /* vec.h */
