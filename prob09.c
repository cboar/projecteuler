#include <stdio.h>
#define IS_TRIPLET(a,b,c) ((a*a) + (b*b) == (c*c))

int main(void)
{
	for(int a = 1; a < 1000; a++){
		for(int b = 1; b < (1000 - a); b++){
			int c = (1000 - a - b);
			if(IS_TRIPLET(a,b,c))
				printf("%d\n", a*b*c);
		}
	}
}
