#include <stdio.h>
#include <math.h>

int is_prime(int num)
{
	if (num % 2 == 0)
		return 0;
	for (int i = 3; i <= sqrt(num); i += 2)
		if (num % i == 0)
			return 0;
	return 1;
}

int main(void)
{
	int index = 1;
	for(int i = 3;; i++){
		if(is_prime(i))
			index++;
		if(index == 10001){
			printf("%d\n", i);
			break;
		}
	}
}
