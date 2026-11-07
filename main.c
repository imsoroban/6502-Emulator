#include <stdio.h>

typedef unsigned short WORD;
typedef unsigned char BYTE; 

typedef struct SCpu {
    WORD PC; // programme counter!
    BYTE SP; // stack pointer

    // registers
    BYTE X, Y, Z;

    // flags
    BYTE C, ZE, I, U, B, O, N;
} cpu;