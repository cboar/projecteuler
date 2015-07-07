#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_factorial(int n){
	if(n == 0)
		return 1;
	int result = n;
	while(n-- > 1)
		result *= n;
	return result;
}

int check_num(int n){
	char snum[16];
	sprintf(snum, "%d", n);

	int sum = 0;
	for(int i = 0; i < strlen(snum); i++)
		sum += get_factorial(snum[i] - 48);

	return sum;
}

int main(void){
	for(int i = 0; i < 1000000000; i++){
		int result = check_num(i);
		if(result == i)
			printf("%d\n", i);

	}
}
