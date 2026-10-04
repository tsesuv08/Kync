#include "node.h"
#include <stdlib.h>

typedef struct Node
{	chr *k;
	int v;
} Node;

Node *nodenew(void)
{	Node *a = (Node *)malloc(sizeof(Node));

	a->k = malloc(1);
	a->v = 0;

	return a;
}

chr nodeset(Node *a, chr *k, int v)
{	a->k = realloc(a->k, 1 + slen(k));

	mcpy(a->k, k);
	a->v = v;

	return 0;
}

int *nodeget(Node *a, chr *k)
{	if(scmp(a->k, k, slen(k) == slen(k)))
		return &a->v;

	return NULL;
}

chr nodefree(Node *a)
{	free(a->k);
	a->k = NULL;
	a->v = 0;

	free(a);
	a = NULL;

	return 0;
}

int main(void)
{	Node *a1 = nodenew();
	Node *a2 = nodenew();

	nodeset(a1, "Hello", 6);
	nodeset(a2, "world", 3);

	printf("AR: %d\n", *nodeget(a1, "Hello"));
	printf("AR: %d\n", *nodeget(a2, "world"));

	nodefree(a1);

	return 0;
}
