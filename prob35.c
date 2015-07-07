#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define AMOUNT 1000000

char primes[AMOUNT+1];
int results[50000];
int all_prime = 1;

int is_prime(int n){
	if(n <= 1)
		return 0;
	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0)
			return 0;
	return 1;
}

void swap(char* x, char* y){
	char t = *x;
	*x = *y;
	*y = t;
}

void shift(char* str, int add){
	for(int amt = 0; amt < strlen(str); amt++){
		char first = str[0];
		for(int i = 0; i <= strlen(str); i++)
			str[i] = str[i+1];
		str[strlen(str)] = first;

		if(str[0] != 48){
			int num = atoi(str);
			//printf("    %d\n", num);
			if(!primes[num])
				all_prime = 0;
			else if (add)
				primes[num] = 2;
		}

	}
}

int main(void){
	for(int i = 2; i <= AMOUNT; i++)
		primes[i] = is_prime(i);

	char num[6];
	for(int i = 2; i <= AMOUNT; i++){
		if(primes[i] == 1){
			all_prime = 1;
			//printf("%d: %d\n", i, primes[i]);
			int len = sprintf(num, "%d", i);
			shift(num, 0);
			if(all_prime)
				shift(num, 1);
		}
	}
	int count = 0;

	for(int i = 2; i <= AMOUNT; i++)
		if(primes[i] == 2)
			count++;

	printf("%d\n", count);
}
