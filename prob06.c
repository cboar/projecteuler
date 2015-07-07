#include <stdio.h>

int main(void)
{
	int sum1 = 0, sum2 = 0;

	for(int i = 100; i; i--){
		sum1 += (i * i);
		sum2 += i;
	}
	sum2 *= sum2;

	printf("%d\n", sum2 - sum1);
}
