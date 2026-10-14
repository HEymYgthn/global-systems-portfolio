#include <stdio.h>
#include <stdlib.h>

// Simple Simulation of Memory Registers & Stack Allocation
typedef struct {
    unsigned int pc;       // Program Counter
    unsigned int sp;       // Stack Pointer
    int registers[8];      // General Purpose Registers (r0-r7)
} CPU_Registers;

void init_cpu(CPU_Registers *cpu) {
    cpu->pc = 0x0000;
    cpu->sp = 0x7FFF;
    for(int i = 0; i < 8; i++) {
        cpu->registers[i] = 0;
    }
}

void print_status(CPU_Registers *cpu) {
    printf("--- Low-Level Register Simulation State ---\n");
    printf("PC: 0x%04X | SP: 0x%04X\n", cpu->pc, cpu->sp);
    for(int i = 0; i < 8; i++) {
        printf("R%d: %d  ", i, cpu->registers[i]);
    }
    printf("\n-------------------------------------------\n");
}

int main() {
    CPU_Registers my_cpu;
    init_cpu(&my_cpu);
    
    // Simulate register manipulation
    my_cpu.registers[0] = 42;
    my_cpu.registers[1] = 100;
    my_cpu.pc += 4;
    
    print_status(&my_cpu);
    return 0;
}
