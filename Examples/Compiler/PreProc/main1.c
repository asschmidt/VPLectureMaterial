/*
 * Some Header Comments
 *
 * Author: Andreas Schmidt
 *
 */
#include "secondinc.h"


#ifdef SPECIAL_VERSION
	#define INIT_VALUE 0xABCD
#else
	#define INIT_VALUE 0xDCBA
#endif

static int globalVarInit = INIT_VALUE;
static int globalVarNoInit;

static int newResult = 0xDEADBEEF;

/**
 * Main Entry for Application
 */
int main(void)
{
	/* Set a value for the non-initialized variable */
	globalVarNoInit = 0x20;

	/* Do some super complicated calculations */
	int result = globalVarInit + globalVarNoInit;
	newResult = result + 0x10;

	return result;
}