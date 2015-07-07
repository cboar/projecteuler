#include <stdio.h>

int num_divisors(int n)
{
	int divisors = 1;
	while(n % 2 == 0){
		n /= 2;
		divisors++;
	}
	for(int i = 3; n != 1; i += 2){
		int count = 1;
		while(n % i == 0){
			count++;
			n /= i;
		}
		divisors *= count;
	}
	return divisors;
}

int main(void)
{
	int num = 0, onum = 1;
	int div_amt = 0;

	while(div_amt < 500){
		num += (onum++);
		div_amt = num_divisors(num);
	}
	printf("%d\n", num);
}
