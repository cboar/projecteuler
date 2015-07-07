#include <stdio.h>
#include <stdlib.h>

int get_pandig(int n, int amt)
{
	char str[256] = {0}, *ptr = str;
	int len = 0;
	for (int i = 1; i <= amt; i++){
		int wrote = sprintf(ptr + len, "%d", (n * i));
		len += wrote;
	}
	if (len != 9)
		return 0;
	char matched[10] = {0};
	for (int i = 0; i < 9; i++)
		matched[ str[i] - '0' ] = 1;
	for (int i = 1; i < 10; i++)
		if(!matched[i])
			return 0;

	return strtol(str, NULL, 10);
}

int main(void)
{
	int highest = 0;
	for (int x = 1; x < 20000 x++){
		for (int y = 1; y < 20; y++){
			if(get_pandig(x,y) > highest)
				highest = get_pandig(x,y);
		}
	}
	printf("%d\n", highest);
}

