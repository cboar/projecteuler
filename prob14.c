#include <stdio.h>

#define GET_EVEN(n) (n / 2)
#define GET_ODD(n) (3 * n + 1)
typedef unsigned long long u64;

int main(void)
{
	u64 highChain = 0, highNum = 0;

	for(u64 i = 2; i < 1000000; i++){
		u64 num = i, chains = 0;
		while(num != 1){
			num = (num & 1) ? GET_ODD(num) : GET_EVEN(num);
			chains++;
		}
		if(chains > highChain){
			highChain = chains;
			highNum = i;
		}
	}

	printf("chain: %llu, num: %llu\n", highChain, highNum);
}
