#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n){
	if(n <= 1)
		return 0;
	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0)
			return 0;
	return 1;
}

int* get_pfactors(int n){
	int* found = calloc(sizeof(int), 256);
	int index = 0;
	while(n % 2 == 0){
		n /= 2;
		found[index++] = 2;
	}
	for(int i = 3; i < sqrt(n); i += 2){
		while(n % i == 0){
			n /= i;
			found[index++] = i;
		}
	}
	found[index] = -1;
	return found;
}

int main(void){
	for(int i = 1; i < 500; i++){
		int* pfactors = get_pfactors(i);
		int curr, i = 0;
		while(curr = pfactors[i++] != -1)
			printf("%d\n", curr);
		free(pfactors);

	}
}
