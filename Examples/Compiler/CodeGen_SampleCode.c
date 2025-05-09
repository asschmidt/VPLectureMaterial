
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


// ABI Demo
// -O0, -O1
int func1(int a, int b)
{
    int result = a + b;

    return result;
}

int func2(int a, int b, int c, int d)
{
    int result = a + b + c + d;

    return result;
}

int func3(int a, int b, int c, int d, int e, int f, int g, int h)
{
    int result = a + b + c + d + e + f + g + h;

    return result;
}

int main()
{
    int res1 = func1(10, 20);
    int res2 = func2(10, 20, 30, 40);
    int res3 = func3(10, 20, 30, 40, 50, 60, 70, 80);

    return res1 + res2 + res3;
}


// Variadic Functions
#include <stdarg.h>

int func(int n, int a, int b, ...)
{
    int result = a + b;

    va_list args;
    va_start(args, b); 

    for (int i = 0; i < n; i++) 
    {
        //double param = va_arg(args, double);
        int param = va_arg(args, int);
        result = result + (int)param;
    }
    
    va_end(args);

    return result;
}

int main()
{
    int res1 = func(4, 10, 20, 30, 40);
    
    return res1;
}