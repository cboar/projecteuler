#include <stdio.h>
#include <math.h>

int main(void)
{
    long long n = 600851475143LL;

	while (n % 2 == 0)
		n /= 2;
	for (int i = 3; i <= sqrt(n); i += 2)
		while (n % i == 0)
			n /= i;

	printf ("%d\n", n);
}
