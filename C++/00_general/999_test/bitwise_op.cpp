

// Babak Poursartip
// 09/16/2020

// bitwise operation
#include <stdio.h> 

int main(){

	// a = 5(00000101), b = 9(00001001) 
	unsigned char a = 5, b = 9; 

	// The result is 00000001 =1
	printf("a = %d, b = %d\n", a, b); 
	printf("a&b = %d\n", a & b); 

	// The result is 00001101 = 13
	printf("a|b = %d\n", a | b); 

	// The result is 00001100 =12
	printf("a^b = %d\n", a ^ b); 

	// The result is 11111010 =250
	printf("~a = %d\n", a = ~a); 

	// The result is 00010010 == 18
	printf("b<<1 = %d\n", b << 1); 

	// The result is 00000100 = 4
	printf("b>>1 = %d\n", b >> 1); 


  int var = 9;
	printf("var>>1 = %d\n", var >> 1); 

return 0;
}
