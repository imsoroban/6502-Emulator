#include <stdio.h>

typedef unsigned short WORD;
typedef unsigned char BYTE; 

typedef struct SCpu {
    WORD PC; //programme counter!
    BYTE SP; 
}