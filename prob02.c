#include <stdio.h>

int main(void)
{
	int sum = 0;

	int low = 1;
	int high = 2;

	while(high <= 4000000){
		if(high % 2 == 0)
			sum += high;

		int tlow = low;
		low = high;
		high += tlow;
	}

	printf("%d\n", sum);
}
