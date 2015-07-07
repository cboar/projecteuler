#include <stdio.h>
#include <stdlib.h>

#define MAX 28123
#define IS_ABUNDANT(n) (get_divisor_sum(n) > n)

int get_divisor_sum(int n)
{
	int sum = 1;
	for(int i = 2; i <= n / 2; i++)
		if(n % i == 0)
			sum += i;
	return sum;
}

int main(void)
{
	/* Compile list of abundant numbers */
	int* abunds = calloc(MAX, sizeof(*abunds)), count = 0;
	for(int i = 12; i < MAX; i++)
		if(IS_ABUNDANT(i))
			abunds[count++] = i;

	/* Set all abundant-sum numbers to 1 */
	char* numlist = calloc(MAX * 2, sizeof(*numlist));
	for(int x = 0; x < count; x++)
		for(int y = 0; y < count; y++)
			numlist[abunds[x] + abunds[y]] = 1;

	/* Sum together the untouched numbers */
	size_t sum = 0;
	for(int i = 0; i < MAX; i++)
		if(!numlist[i])
			sum += i;

	printf("%zd\n", sum);
	free(abunds);
	free(numlist);
}
