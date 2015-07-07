#include <stdio.h>
#include <string.h>

#define HUNDRED "hundred"
#define AND "and"

int main(void){
	int sum = 11;
	char* nums_arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char* teens_arr[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char* tens_arr[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

	char num[32];
	for(int i = 1; i < 1000; i++){
		memset(num, 0, strlen(num));

		int hunds = i / 100;
		int tens = (i % 100) / 10;
		int ones = i % 10;

		if(hunds >= 1){
			strcat(num, nums_arr[hunds]);
			strcat(num, HUNDRED);
			if(i % 100 > 0)
				strcat(num, AND);
		}
		if(tens == 1){
			strcat(num, teens_arr[ones]);
		} else {
			strcat(num, tens_arr[tens]);
			strcat(num, nums_arr[ones]);
		}

		int len = strlen(num);
		printf("%d: %s: %d\n", i, num, len);
		sum += len;
	}

	printf("%d\n", sum);
}
