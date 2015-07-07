#include <stdio.h>
#include <math.h>

int calc_formula(int n, int a, int b){
	return (n*n) + (a * n) + b;
}

int is_prime(int n){
	if(n <= 1)
		return 0;

	for(int i = 3; i <= sqrt(n); i++)
		if(n % i == 0)
			return 0;

	return 1;
}

int test_formula(int a, int b){
	for(int i = 0;; i++){
		int num = calc_formula(i, a, b);
		if(!is_prime(num))
			return i;
	}
}

int main(void){

	int max = 0;
	int quot = 0;
	for(int a = -999; a < 1000; a++)
	for(int b = -999; b < 1000; b++){
		int consec = test_formula(a, b);
		if (consec > max){
			max = consec;
			quot = a * b;
		}
		

	}
	printf("%d\n", quot);
}
