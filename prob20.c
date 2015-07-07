#include <stdio.h>
#include <gmp.h>

void make_factorial(mpz_t num, long int f){
	mpz_init_set_si(num, f);
	while(f-- > 1){
		mpz_mul_si(num, num, f);	
	}
	
}

int main(void){
	mpz_t num;
	make_factorial(num, 100);
	char strnum[256];
	mpz_get_str(strnum, 10, num);

	int sum = 0, i = 0;
	while(strnum[i]){
		sum += (strnum[i++]) - 48;
	}

	printf("%d\n", sum);
}
