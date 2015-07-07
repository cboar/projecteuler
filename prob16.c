#include <stdio.h>
#include <gmp.h>
#include <string.h>

int main(void){
	mpz_t num;
	mpz_init(num);

	mpz_ui_pow_ui(num, 2, 1000);
	char str[1000];
	mpz_get_str(str, 10, num);
	int sum = 0;
	for(int i = 0; i < strlen(str); i++)
		sum += (str[i] - 48);

	printf("%d\n", sum);
}
