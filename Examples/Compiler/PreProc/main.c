/*
 * Some Header Comments
 *
 * Author: Andreas Schmidt
 *
 */
#ifdef SPECIAL_VERSION
	#define INIT_VALUE 0xABCD
#else
	#define INIT_VALUE 0xDCBA
#endif

#ifdef SPECIAL_VERSION
    #warning "Special Version Build!!!"
#endif


#define WAIT_LOOP(x)                            \
            for (int i=0; i<(x * 1000); i++)    \
                _nop();                         \


static int globalVarInit = INIT_VALUE;
static int globalVarNoInit;

static int newResult = 0xDEADBEEF;

#ifdef DEBUG
void debugOut()
{
    printf("Hello\n");
}
#else
void debugOut()
{

}
#endif

/**
 * Main Entry for Application
 */


int main(void)
{
    //#ifdef DEBUG
    debugOut();
    //#endif

    WAIT_LOOP(10)

	/* Set a value for the non-initialized variable */
	globalVarNoInit = 0x20;

	/* Do some super complicated calculations */
	int result = globalVarInit + globalVarNoInit;
	newResult = result + 0x10;

	return result;
}