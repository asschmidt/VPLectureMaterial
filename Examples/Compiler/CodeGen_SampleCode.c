
//
// Simple Function
//
int globalVar = 0;

int main(void)
{
    globalVar = globalVar + 10;

    return globalVar;
}


//
// Simple Function with local Vars
//
int main(void)
{
    int myValueA = 10;
    int myValueB = 30;


    return myValueA + myValueB;
}

//
// Struct with/without padding
//
//#pragma pack(push, 1)
typedef struct _myStruct
{
	char charItem;
    int intItem;
    short shortItem;
} myStruct;
//#pragma pack(pop)

int sizeOfStruct = sizeof(myStruct);

int main()
{
	myStruct x;
	x.intItem = 20;
	x.charItem = 0xAA;
	
	return 0;
}

//
// Simple Function with struct
//
typedef struct _myStruct
{
    int memberA;
    int memberB;
    char memberC;
} myStruct;

myStruct globalStruct;

int main(void)
{
    globalStruct.memberA = 10;
    globalStruct.memberB = 20;

    return globalStruct.memberA + globalStruct.memberB;
}

//
// Simple Function with sub-function
//
int globalVar = 0;

int myFunction(int a, int b)
{
    int result = a + b;
    return result;
}

int main(void)
{
    globalVar = myFunction(10, 20);

    return globalVar;
}


//
// Floating Point Example
// -mfloat-abi=softfp -march=armv7e-m+fp
// -mfloat-abi=softfp -march=armv7e-m+nofp
int main()
{
    float a = 5.5;
    float b = 2.3;
    float result = a+ b;
}