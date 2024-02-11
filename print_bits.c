#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int mask = 0b10000000;
	for (int i = 0; i <= 7; i++){
		(octet & mask ? write(1,"1",1) : write(1,"0",1));
		mask >>= 1;
	}
}

/*int main(void)
{
	print_bits(50);
	return (0);
}*/
