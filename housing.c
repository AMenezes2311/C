#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Goal: Organize cities by its price and return the least affordable city to live in
Structure of this program:
    - Print list of cities and prices
    - Print a *sorted* list of the citites and prices
    - Print the least affordable city based on its price

Requirements:
    - Use typedef and struct to define a "new city housing price type"
        - Represents the city and the average housing price 
    - Create a dynamically allocated array of city housing price type that is able to
      initially store one city
        - Create the space for one city and if the user's input is "yes", then allocate
          space for one more city using realloc()
    - Create a function to handle printing and sorting 
    - Free the space that was dynamically allocated in the process (free)
*/

//Creating a new datatype
typedef struct City {
    char name[200];
    int price;
}city;

//Function definition
void printCity(struct City city);
void selectionSort(city array[], int size);

int main(void){
    //Variables and buffer
    char input;
    char input_buffer[200];
    int i = 0; //Counter for buffer
    int j = 0; //Counter for loop
    char add_city = 'y';
    city *cities_array = calloc(1, sizeof(city));

    do{
        printf("Enter the name of the city: ");
        input = 'a';
        i = 0;
        while((input = getchar()) != '\n') input_buffer[i++] = input;
        input_buffer[i] = '\0';

        strcpy(cities_array[j].name, input_buffer);

        printf("Enter the average house price: ");
        scanf("%d", &cities_array[j].price);
        getchar();


        printf("Add another city? (y/n) : ");
        scanf("%s", &add_city);
        getchar();

        if(add_city == 'n'){
            printf("\n");
            break;
        }
        ++j;
        cities_array = realloc(cities_array, sizeof(cities_array) * (j + 1));

    }while(add_city == 'y');

    //Print cities and prices as they were given
    printf("\nList of city and prices:\n");
    for(int z = 0; z <= j; ++z){
        printCity(cities_array[z]);
    }

    //Sort the array of cities
    selectionSort(cities_array, j + 1);

    //Print cities by sorted prices 
    printf("\nSorted: \n");
    for(int z = 0; z <= j; ++z){
        printCity(cities_array[z]);
    }

    //Print the most expensive city
    printf("\nThe city with the highest house price: %s\n", cities_array[j].name);

    //Free the space that was dynamically allocated
    free(cities_array);

    return 0;
}

//Function to print out a city and its price
void printCity(struct City city)
{
  printf("City: %s\n", city.name);
  printf("Price: %d\n", city.price);
}

//Function to swap the the position of two elements
void swap(city *a, city *b) {
  city temp = *a;
  *a = *b;
  *b = temp;
}


//Selection sort algorithm function
void selectionSort(city* array, int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      if (array[i].price < array[min_idx].price)
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
  }
}