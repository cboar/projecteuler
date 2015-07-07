#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int is_prime(int n){
	if(n <= 1)
		return 0;
	for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
        	return 0;
	return 1;
}

int check_all(int n){
	char snum[32];
	sprintf(snum, "%d", n);
	for(int i = 0; i < strlen(snum) - 1; i++){
		n /= 10;
		snum[i] = 48;
		if(!is_prime(n) || !is_prime(atoi(snum)))
			return 0;	
	}
	return 1;
}

int main(void){
	int sum = 0;
	for(int i = 10; i < 1000000; i++){
		if(is_prime(i) && check_all(i)){
			printf("%d\n", i);
			sum += i;
		}
	}
	printf("%d\n", sum);
}
