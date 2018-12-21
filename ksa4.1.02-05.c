#include <stdio.h>
#include <stdlib.h>

// 4.1.02: Memory map of a C program

// 4.1.03: int, float, double, long, char

// 4.1.04: array and multi-dimensional array

// 4.1.05: +, -, *, /, %, ++, --

int
main (void)
{
    printf("When main runs I will initialize some variables.\n");
    printf("int a, float b, double c, long d, char e\n");
    getchar();

    int a = 10;  // 4.1.03.a
    float b = 1.0;  // 4.1.03.b
    double c = 3.14;  // 4.1.03.c
    long d = 100;  // 4.1.03.d
    char e = 'e';  // 4.1.03.e
    
    printf("Now that I have 5 variables of different data types.\n");
    printf("I can check the size of each with two different methods.\n");
    printf("The first will be the value from the 'sizeof' function.\n");
    printf("You can also see the memory address of each variable.\n");
    getchar();
    
    printf("int a:  \t%lu bytes\t%p\n", sizeof(a), (void *) &a);
    printf("float b: \t%lu bytes\t%p\n", sizeof(b), (void *) &b);
    printf("double c: \t%lu bytes\t%p\n", sizeof(c), (void *) &c);
    printf("long d: \t%lu bytes\t%p\n", sizeof(d), (void *) &d);
    printf("char e: \t%lu bytes\t%p\n\n", sizeof(e), (void *) &e);
    
    printf("The variables a, b, c, d and e were all put on the stack.\n");
    printf("If they were malloc'd instead then their addresses in memory\n");
    printf("would reflect that difference.\n");
    getchar();

    int * aa = malloc(sizeof(int));
    float * bb = malloc(sizeof(float));
    double * cc = malloc(sizeof(double));
    long * dd = malloc(sizeof(long));
    char * ee = malloc(sizeof(char));

    printf("int aa:  \t%lu bytes\t%p\n", sizeof(*aa), (void *) aa);
    printf("float bb: \t%lu bytes\t%p\n", sizeof(*bb), (void *) bb);
    printf("double cc: \t%lu bytes\t%p\n", sizeof(*cc), (void *) cc);
    printf("long dd: \t%lu bytes\t%p\n", sizeof(*dd), (void *) dd);
    printf("char ee: \t%lu bytes\t%p\n\n", sizeof(*ee), (void *) ee);
    
    printf("This shows the size needed to hold each data type in bytes.\n");
    printf("But C sometimes takes more than it needs.\n");
    printf("This can be seen by making a struct of the different datatypes\n");
    printf("and then checking its size.\n");
    getchar();
    
    struct abcde
    {
        int a;
        float b;
        double c;
        long d;
        char e;
    };
    struct abcde f;
    
    printf("Struct of all 5 datatypes:\t%lu\t%p\n\n", sizeof(f), (void *) &f);
    printf("Note that the sum of the 5 data types is 32 bytes not 25.\n");
    printf("You would be seeing 28, not 32, if your machine is 32-bit.\n");
    printf("Also, note that the address of our struct, which was not given\n");
    printf("any initial values, lies separate from the others with values.\n");
    getchar();

    printf("Arrays are simply collections of the same datatype.\n");
    printf("Two-Dimensional arrays are really just one-dimensional, but\n");
    printf("use basic math to behave as a two-dimensional array.\n");
    printf("Same thing for higher dimensional arrays.\n");

    int two_d_array[4][4] =
    {
        { 0, 1, 2, 3 },
        { 4, 5, 6, 7 },
        { 8, 9, 10, 11 },
        { 12, 13, 14, 15 }
    };
    getchar();

    printf("Now there is a two-dimensional array (4x4) with all the\n");
    printf("numbers 0-15.\n\n");
    
    printf("{ {  0,  1,  2,  3 },\n");
    printf("  {  4,  5,  6,  7 },\n");
    printf("  {  8,  9, 10, 11 },\n");
    printf("  { 12, 13, 14, 15 } }\n\n");
    
    printf("Next, I'm going to cast the pointer to that 2-d array as a\n");
    printf("1-d array and show that they both access the same data.\n\n");

    printf("2_d_array[2][2] = %d\n", two_d_array[2][2]);
    
    int *one_d_array = (int *) two_d_array;
    
    printf("1_d_array[10] = %d\n", one_d_array[10]);
    getchar();

    printf("Finally, I will verify that the order of operations holds.\n");
    printf("( 4 + 5 ) / 3 * 2\n");
    printf("( 9 ) / 3 * 2\n");
    printf("3 * 2\n");
    printf("6\n");

    int pemdas = ( 4 + 5 ) / 3 * 2;
    printf("( 4 + 5 ) / 3 * 2 = %d\n", pemdas--);
    printf("pemdas = %d\n", pemdas);
    printf("( 4 + 5 ) / 3 * 2 = %d\n", ++pemdas);
    getchar();

    printf("The decrement after reduces pemdas right after printing.\n");
    printf("The second print shows pemdas is changed.\n");
    printf("The increment before resets pemdas right before printing.\n\n");

    printf("Using increment/decrement on duplicate variables is undefined.\n");

    pemdas %= ++pemdas;
    printf("pemdas %%= ++pemdas, could leave pemdas unchanged.\n");
    printf("If the increment doesn't go first then the result should be 0.\n");
    printf("\npemdas %%= ++pemdas means pemdas = %d\n", pemdas);
    getchar();
}
