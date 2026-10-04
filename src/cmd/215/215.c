/* 215 Assembler */
/* Version: M0N0P0P */
/* Created by UnSynk, TSesuv Xanuc Notsel */

#define DEFAULT_SRC_FILE_NAME "MAIN.ASM"
#define DEFAULT_BIN_FILE_NAME "MAIN.215"

#include "215.h"
#include <stdlib.h>

typedef struct
{	chr opCode[3]; // 全てのオペコードは3文字に圧縮してある
	union
	{	/* opLand */ ; // 共用体を有効活用した事が無いから使ってみるかも？
	};
} Token;

FILE *sfile;
FILE *bfile;

int main(uint ac, chr **av)
{	chr *sfname = malloc(slen(DEFAULT_SRC_FILE_NAME));
	chr *bfname = malloc(slen(DEFAULT_BIN_FILE_NAME));

	mncpy(sfname, DEFAULT_SRC_FILE_NAME, slen(DEFAULT_SRC_FILE_NAME));
	mncpy(bfname, DEFAULT_BIN_FILE_NAME, slen(DEFAULT_BIN_FILE_NAME));

	for(uint i = 0; i < ac; i++)
	{	if(scmpa(av[i], "/SRC:", 5) == 5)
		{	sfname = realloc(sfname, slen(av[i] + 5));
			mncpy(sfname, av[i] + 5, slen(av[i] + 5));
		} else if(scmpa(av[i], "/BIN:", 5) == 5)
		{	bfname = realloc(bfname, slen(av[i] + 5));
			mncpy(bfname, av[i] + 5, slen(av[i] + 5));
		}
	} sfile = fopen(sfname, "r");
	if(!sfile)
	{	printf("215: ERR: Can't open file: %s\n", sfname);

		free(bfname);
		free(sfname);

		return 1;
	}

	uint sfsyze = fsyz(sfile);

	fclose(sfile);

	free(bfname);
	free(sfname);

	return 0;
}
