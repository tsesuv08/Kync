#include "type.h"

typedef struct
{	enum
	{	TK_VOID
	} tkType;

	chr *tkn;
	uint line;
} Token;

typedef struct tkList
{	struct tkList *head;
	struct tkList *this;

	Token tkn;

	struct tkList *next;
} tkList;

int main(void)
{	return 0;
}
