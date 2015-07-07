#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(char* str)
{
	int end = strlen(str);
	for(int i = 0; i <= (end / 2); i++)
		if(str[i] != str[end - 1 - i])
			return 0;

	return 1;
}

int main(void)
{
	int largest = 0;

	for(int x = 100; x < 1000; x++)
	for(int y = 100; y < 1000; y++){
		int num = x * y;
		char snum[16];
		sprintf(snum, "%d", num);

		if(is_palindrome(snum) && num > largest)
			largest = num;
	}

	printf("%d\n", largest);
}
