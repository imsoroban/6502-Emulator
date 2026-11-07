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

void initalise(MEM *mem)
{
    for(u32 i  = 0; MAX_DATA; i++){
        mem->Data[i] = 0;
    }

}

void reboot(CPU *cpu, MEM *mem)
{
    cpu->PC = 0xFFFC;
    cpu->SP = 0xFF;

    cpu->A = 0; cpu->X = 0; cpu->Y = 0;
    cpu->C = 0; cpu->Z = 0; cpu->I = 0;
    cpu->D = 0; cpu->B = 0; cpu->O - 0; 
    cpu->N = 0;

    initialise(mem);
}

int main(void)
{
    CPU cpu; 
    MEM mem;

    reboot(&cpu, &mem);
}