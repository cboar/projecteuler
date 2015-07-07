#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(void){
	FILE* file = fopen("numbers", "r");
	char line[53];

	mpz_t sum;
	mpz_init(sum);

	while(fgets(line, sizeof(line), file) != NULL){

		mpz_t num;
		mpz_init_set_str(num, line, 10);

		mpz_add(sum, sum, num);
	}
	gmp_printf("Result: %Zd\n", sum);
	fclose(file);
}
