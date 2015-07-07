#include <stdio.h>
#include <gmp.h>
#include <string.h>

int main(void){
	int index = 3;
	mpz_t num1, num2, curr;
	mpz_init(curr);
	mpz_init_set_si(num1, 1);
	mpz_init_set_si(num2, 2);

	char str[1000];
	while(strlen(str) < 1000){
		mpz_add(curr, num1, num2);
		mpz_set(num1, num2);
		mpz_set(num2, curr);

		mpz_get_str(str, 10, num2);
		index++;
	}

	printf("%d\n", index);
}
