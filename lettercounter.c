// Display total distance, average speed, total time
#include <stdio.h>
#include <string.h> //strlen
#include <ctype.h> //isdigit and isalpha
#include <stdbool.h>

int main(void)
{
    // Count number of occurences and output a report
    // Max of 1023 characters, stored as a string (DONE)
    // Create a buffer for storing the string up tp 1023 characters
    // Lower and uppercase should count as one
    // Return all characters and the most/less used one should be shown
    // To get the percentage, divide the number of occurences by the string length (* 100)


    //Creating varibles for string, and occurences
    char str[1024], mostChar, leastChar;
    int mostOcc = 0;
    int leastOcc = 1;
    int count = 0;
    float percentage;

    //Getting user's input
    printf("%s", "Enter text for analysis: ");
    fgets(str, sizeof(str), stdin);

    //Storing length of string
    const float len = strlen(str) - 1;

    //Making string uppercase
    for(int i=0; i < strlen(str); i++){
        str[i] = toupper(str[i]);
    }

    printf("Letter Analysis Complete!\n");
    printf("%-10s %-15s %-15s \n", "Letter", "Occurences", "Percentage");
    printf("*****************************************\n");

    for (char i = 65; i <= 90; ++i){
        for (int j = 0; str[j] != '\0'; ++j) {
            if (i == str[j]){
                ++count;
            }
        }
        if (count <= leastOcc && count != 0) {
            leastOcc = count;
            leastChar = i;
        }

        else if (count > mostOcc){
            mostOcc = count;
            mostChar = i;
        }
        percentage = (count / len) * 100;
        printf("%-10c %-15d %-15.2f \n", i, count, percentage);
        percentage = 0;
        count = 0;
        
    }
    printf("The most frequently occuring character is %c \nThe least frequently occuring character is %c \n", mostChar, leastChar);

    return 0;
}