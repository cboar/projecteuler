#include <stdio.h>
#define TRI(n) (n * (n + 1) / 2)

typedef unsigned long long u64;

u64 pent(u64 n)
{
	return (n * (3 * n - 1) / 2);
}

u64 hex(u64 n)
{
	return (n * (2 * n - 1));
}

int checknum(u64 n, u64 (*func)(u64))
{
	u64 i = 0, curr = 0;
	while(curr < n){
		curr = (*func)(i++);
		if(curr == n)
			return 1;
	}
	return 0;
}

int main(void)
{
	for(u64 i = 0; i < 1000000; i++){
		u64 tri = TRI(i);
		if(checknum(tri, &hex) && checknum(tri, &pent)){
			printf("%d\n", tri);
			fflush(stdout);
		}
	}
}
