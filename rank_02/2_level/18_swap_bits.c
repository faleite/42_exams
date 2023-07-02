/*** Subject ***//*

Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100

*//*** Code ***/

unsigned char	swap_bits(unsigned char octet)
{
/* Operador OR Bit a Bit "|": 
 * Ex: a | b retorna um valor onde cada bit é 1 se pelo menos um dos bits
 * correspondentes em a ou b for 1. 
 * "<<" Operador Deslocamento à Esquerda
 * ">>" Operador Deslocamento à Direita */
	return((octet >> 4) | (octet << 4));
}

#include <stdio.h>

int main()
{
    unsigned char value = 0x3A;

    printf("Valor original: 0x%X\n", value);

    unsigned char swapped = swap_bits(value);

    printf("Valor com bits trocados: 0x%X\n", swapped);

    return 0;
}
