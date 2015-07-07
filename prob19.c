#include <stdio.h>
#define IS_LEAP(year) ((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0))

int main(void)
{
	int count = 0;
	int weekday = 0;
	int day = 1, month = 1, year = 1900;

	while(!(year == 2000 && month == 12 && day == 31)){
		if(weekday == 6 && day == 1 && year >= 1901)
			count++;
		weekday = (weekday + 1) % 7;
		day++;
		switch(month){
			case 4:
			case 6:
			case 9:
			case 11:
				if(day == 31)
					day = 1, month++;
				break;
			case 2:
				if(day == (IS_LEAP(year) ? 30 : 29))
					day = 1, month++;
				break;
			default:
				if(day == 32)
					day = 1, month++;
		}
		if(month == 13)
			month = 1, year++;
	}
	printf("%d\n", count);
}

