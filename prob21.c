#include <stdio.h>

int div_sum(int n){
	int sum = 0, i;
	for(i = 1; i < n; i++){
		if(n % i == 0)
			sum += i;
	}
	return sum;
}

int main(void){
	int sum = 0;
	int current = 10000;

	while(current--){
		int first = div_sum(current);
		int second = div_sum(first);

		if(second == current){
			if(first != second)
				sum += current;
		}
	}


	printf("%d\n", sum);
}
