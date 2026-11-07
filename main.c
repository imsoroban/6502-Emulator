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

void initialise(MEM *mem)
{
    for(u32 i = 0; i < MAX_DATA; i++){
        mem->Data[i] = 0;
    }
}

void reboot(CPU *cpu, MEM *mem)
{
    cpu->PC = 0xFFFC;
    cpu->SP = 0xFF;

    cpu->X = 0; cpu->Y = 0; cpu->Z = 0;
    cpu->C = 0; cpu->ZE = 0; cpu->I = 0;
    cpu->U = 0; cpu->B = 0; cpu->O = 0; 
    cpu->N = 0;

    initialise(mem);
}

BYTE fetch(CPU *cpu MEM *mem) 
{
    BYTE data mem->Data[cpu->PC];
    cpu->PC++;
    return data;
}

static const BYTE INS_LDA_IM; 

void execute(CPU *cpu, MEM *mem, u32 cycles)
{
    while(cycles > fetch() -> int
    BYTE instruction = fetch(cpu, mem);

    switch(instruction){
        case INS_LDA_IM:{
            BYTE
            CPU-> A =

        }
    }
}


int main(void)
{
    CPU cpu; 
    MEM mem;

    reboot(&cpu, &mem);
    
    execute(&cpu, &mem, 2);
}