#include <stdio.h>

int fits_criteria(int test)
{
	for (int i = 2; i <= 20; i++)
		if(test % i)
			return 0;
	return 1;
}

int main(void)
{
	for(int num = 1;; num++){
		if(fits_criteria(num)){
			printf("%d\n", num);
			break;
		}
	}
}
