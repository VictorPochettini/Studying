/*
 * Exercícios de Baixo Nível - Computer Systems: A Programmer's Perspective
 * Baseado nos Capítulos 1-2 (até página 53)
 * VERSÃO SEM DICAS - Teste seu conhecimento!
 * 
 * Compile com: gcc -o exercises exercises.c
 * Execute com: ./exercises
 */

#include <stdio.h>
#include <stdint.h>

/* ========================================
 * EXERCÍCIO 1: Representação de Bytes
 * ======================================== */

void show_bytes(void *start, size_t len) {
    // TODO: Implemente
}

/* ========================================
 * EXERCÍCIO 2: Byte Ordering (Endianness)
 * ======================================== */

int is_little_endian() {
    // TODO: Implemente
    return 0;
}

/* ========================================
 * EXERCÍCIO 3: Manipulação de Bits
 * ======================================== */

int get_bit(int x, int n) {
    // TODO: Implemente
    return 0;
}

int set_bit(int x, int n) {
    // TODO: Implemente
    return 0;
}

int clear_bit(int x, int n) {
    // TODO: Implemente
    return 0;
}

/* ========================================
 * EXERCÍCIO 4: Two's Complement
 * ======================================== */

int negate(int x) {
    // TODO: Implemente
    return 0;
}

int same_sign(int x, int y) {
    // TODO: Implemente
    return 0;
}

/* ========================================
 * EXERCÍCIO 5: Máscaras de Bits
 * ======================================== */

unsigned char get_byte(int x, int n) {
    // TODO: Implemente
    return 0;
}

int replace_byte(int x, int n, unsigned char b) {
    // TODO: Implemente
    return 0;
}

/* ========================================
 * DESAFIOS EXTRAS
 * ======================================== */

int count_ones(int x) {
    // TODO: Conte quantos bits estão em 1
    return 0;
}

int byte_swap(int x) {
    // TODO: Inverta a ordem dos bytes
    return 0;
}

int is_power_of_two(int x) {
    // TODO: Verifique se x é potência de 2
    return 0;
}

int min(int x, int y) {
    // TODO: Retorne o menor SEM usar if/else ou operadores relacionais (<, >, etc)
    return 0;
}

/* ========================================
 * MAIN - TESTES
 * ======================================== */

int main() {
    printf("=== Exercícios de Baixo Nível ===\n\n");
    
    // Teste 1: Representação de Bytes
    printf("--- EXERCÍCIO 1: Representação de Bytes ---\n");
    int num = 0x12345678;
    printf("Inteiro: 0x%x\n", num);
    show_bytes(&num, sizeof(int));
    
    short s = 0x1234;
    printf("Short: 0x%x\n", s);
    show_bytes(&s, sizeof(short));
    printf("\n");
    
    // Teste 2: Endianness
    printf("--- EXERCÍCIO 2: Byte Ordering ---\n");
    if (is_little_endian()) {
        printf("Esta máquina é LITTLE-ENDIAN\n");
    } else {
        printf("Esta máquina é BIG-ENDIAN\n");
    }
    printf("\n");
    
    // Teste 3: Manipulação de Bits
    printf("--- EXERCÍCIO 3: Manipulação de Bits ---\n");
    int x = 0b00001010;  // 10 em decimal
    printf("x = %d (binário: 00001010)\n", x);
    printf("Bit na posição 1: %d (esperado: 1)\n", get_bit(x, 1));
    printf("Bit na posição 3: %d (esperado: 1)\n", get_bit(x, 3));
    
    int y = set_bit(x, 0);
    printf("Após set_bit(x, 0): %d (esperado: 11)\n", y);
    
    int z = clear_bit(x, 1);
    printf("Após clear_bit(x, 1): %d (esperado: 8)\n", z);
    printf("\n");
    
    // Teste 4: Two's Complement
    printf("--- EXERCÍCIO 4: Two's Complement ---\n");
    int pos = 42;
    int neg = negate(pos);
    printf("Positivo: %d\n", pos);
    printf("Negação: %d (esperado: -42)\n", neg);
    printf("Negação da negação: %d (esperado: 42)\n", negate(neg));
    
    printf("42 e 10 têm mesmo sinal? %s (esperado: SIM)\n", 
           same_sign(42, 10) ? "SIM" : "NÃO");
    printf("42 e -10 têm mesmo sinal? %s (esperado: NÃO)\n", 
           same_sign(42, -10) ? "SIM" : "NÃO");
    printf("\n");
    
    // Teste 5: Máscaras
    printf("--- EXERCÍCIO 5: Máscaras de Bits ---\n");
    int val = 0x12345678;
    printf("Valor: 0x%x\n", val);
    printf("Byte 0: 0x%x (esperado: 0x78)\n", get_byte(val, 0));
    printf("Byte 1: 0x%x (esperado: 0x56)\n", get_byte(val, 1));
    printf("Byte 2: 0x%x (esperado: 0x34)\n", get_byte(val, 2));
    printf("Byte 3: 0x%x (esperado: 0x12)\n", get_byte(val, 3));
    
    int replaced = replace_byte(val, 1, 0xAB);
    printf("Após replace_byte(val, 1, 0xAB): 0x%x (esperado: 0x1234AB78)\n", replaced);
    printf("\n");
    
    // Testes dos desafios
    printf("--- DESAFIOS EXTRAS ---\n");
    printf("count_ones(0b1011): %d (esperado: 3)\n", count_ones(0b1011));
    printf("byte_swap(0x12345678): 0x%x (esperado: 0x78563412)\n", byte_swap(0x12345678));
    printf("is_power_of_two(16): %d (esperado: 1)\n", is_power_of_two(16));
    printf("is_power_of_two(15): %d (esperado: 0)\n", is_power_of_two(15));
    printf("min(42, 17): %d (esperado: 17)\n", min(42, 17));
    printf("min(-5, 3): %d (esperado: -5)\n", min(-5, 3));
    
    return 0;
}