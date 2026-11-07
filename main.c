#include <stdio.h>

typedef unsigned short WORD;
typedef unsigned char BYTE; 
typedef unsigned int u32;

#define MAX_DATA (1024 * 64)    

#define INS_LDA_IM 0xA9

typedef struct SCpu {
    WORD PC; // programme counter!
    BYTE SP; // stack pointer

    // registers
    BYTE A, X, Y;

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

    cpu->A = 0; cpu->X = 0; cpu->Y = 0;
    cpu->C = 0; cpu->ZE = 0; cpu->I = 0;
    cpu->U = 0; cpu->B = 0; cpu->O = 0; 
    cpu->N = 0;

    initialise(mem);
}

BYTE fetch(CPU *cpu, MEM *mem) 
{
    BYTE data = mem->Data[cpu->PC];
    cpu->PC++;
    return data;
}

void execute(CPU *cpu, MEM *mem, u32 cycles)
{
    while(cycles > 0)
    {
        BYTE instruction = fetch(cpu, mem);
        cycles--;

        switch(instruction){
            case INS_LDA_IM:{
                BYTE value = fetch(cpu, mem);
                cpu->A = value;
                cpu->ZE = (cpu->A == 0); 
                cpu->N = (cpu->A & 0x80) ? 1 : 0; 
                cycles--;
                break;
            }
        }
    }
}

int main(void)
{
    CPU cpu; 
    MEM mem;

    reboot(&cpu, &mem);

    printf("PC: 0x%X\n" , cpu.PC);
    execute(&cpu, &mem, 2);
    printf("PC: 0x%X\n" , cpu.PC);
    return 0;
}