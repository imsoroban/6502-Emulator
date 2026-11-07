#include <stdio.h>

typedef unsigned short WORD;
typedef unsigned char BYTE; 
typedef unsigned int u32;

#define MAX_DATA (1024 * 64)    
typedef struct SCpu {
    WORD PC; // programme counter!
    BYTE SP; // stack pointer

    // registers
    BYTE X, Y, Z;

    // flags
    BYTE C, ZE, I, U, B, O, N;
} CPU;

typedef struct SMem{
     BYTE Data[MAX_DATA];
} MEM;

int main(void)
{
    CPU cpu; 
}