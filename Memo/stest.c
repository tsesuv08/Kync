#include <stdio.h>
#include <stdlib.h>

typedef unsigned char chr;
typedef unsigned int uint;

typedef struct
{	chr *str;
	uint cap;
} sct;

uint slen(chr *s)
{	chr *t = s;
	while(*t++);

	return --t - s;
}

chr *test = "OS[config[system[laungage[fonts[bitmap[path:teststr]]]]]]";

uint dinx = 0;
uint total = 0;

int main(void)
{	sct *ssct = malloc(sizeof(sct));
	ssct[0].str = malloc(1);
	ssct[0].str[0] = 0;
	ssct[0].cap = 1;

	for(uint i = 0; i < slen(test); i++)
	{	printf("[%d] %c\n", dinx, test[i]);

		switch(test[i])
		{	case '[':
				dinx++;
				if(total < dinx)
					ssct = realloc(ssct, ++total * sizeof(sct));

				break;

			case ']':
				dinx--;

				break;

			case ':':
				printf("!!");

				break;

			default:
				if(!(slen(ssct[dinx].str) < ssct[dinx].cap))
				{	ssct[dinx].cap *= 2;
					ssct[dinx].str = realloc(ssct[dinx].str, ssct[dinx].cap);
				} ssct[dinx].str[1 + slen(ssct[dinx].str)] = 0;
				ssct[dinx].str[slen(ssct[dinx].str)] = test[i];
				break;
		}
	}

	for(uint i = 0; i < total; i++)
		free(ssct[i].str);

	free(ssct);

	return 0;
}
