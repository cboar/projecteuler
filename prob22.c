#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void* a, const void* b)
{
	char* as = *((char**) a);
	char* bs = *((char**) b);

	int result = 0;
	while(!(result = *as - *bs))
		as++, bs++;

	return result;
}

int main(void)
{
	char** list = malloc(sizeof(*list) * 5500);
	FILE* file = fopen("names.txt", "rb");

	fseek(file, 0, SEEK_END);
	long length = ftell(file);
	rewind(file);

	char* buffer = malloc(length + 1);
	fread(buffer, 1, length, file);
	fclose(file);
	buffer[length - 2] = 0; /*  REPLACE " with \0  */

	list[0] = buffer + 1;
	size_t count = 1;
	for(char* c = buffer; *c; c++){
		if(*c == ','){
			*(c - 1) = 0;
			list[count++] = c + 2;
		}
	}

	qsort(list, count, sizeof(*list), cmpfunc);

	size_t score = 0;
	for(size_t i = 0; i < count; i++){
		char* name = list[i];
		int worth = 0;
		for(char* c = name; *c; c++)
			worth += (*c - 'A' + 1);
		score += worth * (i + 1);
		printf("%d: %s = %d\n", i + 1, name, worth);
	}
	printf("%zd\n", score);

	free(buffer);
	free(list);
}
