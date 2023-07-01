/*** Subject ***//*

Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100

*//*** Notes ***//*

Multiplicar bytes por 2 é equivalente a realizar um deslocamento para a
esquerda de todos os bits em bytes. 

Exemplo:

0000  0001
    *2
0000  0010

O resultado de "bytes % 2" é equivalente a pegar o bit menos significativo de
bytes. O operador % retorna o resto da divisão de bytes por 2, que será 0 ou 1,
representando o valor do bit menos significativo.

O resultado de bytes / 2, isso move todos os bits de bytes uma posição para a 
direita, descartando o bit menos significativo que já foi processado.

*//*** Code ***/

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet /= 2;
		i--;
	}
	return (res);
}

#include <stdio.h>

int main()
{
/* 
O valor hexadecimal 0x4D representa o número binário 01001101. 
Ao inverter a ordem dos bits, obtemos 10110010, que corresponde ao valor
hexadecimal 0xB2 
*/
    unsigned char value = 0x4D; // Valor de exemplo: 10100101 em binário

    printf("Valor original: 0x%X\n", value);

    unsigned char reversed = reverse_bits(value);

    printf("Valor reverso:  0x%X\n", reversed);

    return 0;
}

