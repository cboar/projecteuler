#include <stdio.h>

int main(void){
    int sum = 0;

    int index = 1000;
    while(index--){
        if((index % 3 == 0) || (index % 5 == 0))
            sum += index;
    }
    printf("%d\n", sum);
}
