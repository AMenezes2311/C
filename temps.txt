#include <stdio.h>
#include <string.h> //strlen
#include <ctype.h> //isdigit and isalpha
#include <stdbool.h>

#define NUMS 3

bool valid_input(int high, int low);

int main(){
    printf(">-----------------Temperature Analyzer -------------------<\n");
    int high;
    int low;

    for(int i = 1; i <= NUMS; i++){
        printf("Enter the high value for day %d: ", i);
        scanf("%d", &high);
        
        printf("Enter the low value for day %d: ", i);
        scanf("%d", &low);

        if(!valid_input(high, low)){
            do{
                printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
                printf("Enter the high value for day %d: ", i);
                scanf("%d", &high);
        
                printf("Enter the low value for day %d: ", i);
                scanf("%d", &low);
            }while(!valid_input(high, low));
        }
    }
    return 0;
}

bool valid_input(int high, int low){
    if (low > high || low > 40 || low < -40 || high > 40 || high < -40){
        return false;
    }
    return true;
}