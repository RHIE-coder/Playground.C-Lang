#include <stdio.h>
#include <math.h>
//02장_G1_Visual - C_7번 해답코드 202020679 채상준 풀이
int main(void)
{
	float insert;
	printf("Enter a real number.\n");
	scanf_s("%f", &insert);
	printf("Result of Automatic Type Conversion is:%d", (int)insert);

	return 0;
}