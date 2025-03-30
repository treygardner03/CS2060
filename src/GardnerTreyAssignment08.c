/*Name: Trey Gardner
Class: CS2060 (M/W)
Due: 03-31-25
Description: This program will:
8.1: find the average of 3 numbers: (using functions)
8.2: convert between celsius and fahrenheit (using functions)
8.3: swap two integers using pass by reference (using functions)
8.4: calculate the area of a circle (using functions)
 */

//header files
#include <stdio.h>
const char LINE_BREAK[] = "\n-----------------------------";
const double PI = 3.14159265358979323846;

//function prototypes
int average_of_three_numbers(int, int, int);
int fahrenheit_to_celsius(int);
int celsius_to_fahrenheit(int);
void swap_two_numbers(int*, int*);
double calculate_area(int, double);


int main()
{
 //I will try to use C-style function brackets for this assignment

 //8.1 - averaging 3 numbers
 //user input
 int num_1 = 0, num_2 = 0, num_3 = 0;
 printf("We are going to find the average of 3 numbers of your choice :)");
 printf("\nEnter your first number : ");
 scanf("%d", &num_1);
 printf("\nEnter your second number : ");
 scanf("%d", &num_2);
 printf("\nEnter your third number : ");
 scanf("%d", &num_3);

 //calling to find average of the 3 user input
 int input_average = average_of_three_numbers(num_1, num_2, num_3);
 printf("\nThe average of three numbers is : %d", input_average);

 printf(LINE_BREAK);

 //8.2 - converting between Celsius and Fahrenheit
 int user_input_fahrenheit = 0;
 int user_input_celsius = 0;

 //user input
 printf("\nWe are going to convert between celsius and fahrenheit");
 printf("\nEnter your temperature in Fahrenheit : ");
 scanf("%d", &user_input_fahrenheit);

 //Fahrenheit to Celsius
 printf("\nYour temperature converted to Celsius is : %d", fahrenheit_to_celsius(user_input_fahrenheit));

 //user input
 printf("\nEnter your temperature in Celsius : ");
 scanf("%d", &user_input_celsius);

 //converting from Fahrenheit to Celsius
 printf("\nYour temperature converted from Fahrenheit to Celsius is : %d", celsius_to_fahrenheit(user_input_celsius));

 printf(LINE_BREAK);

 //8.3 - swapping two integer values
 //user input
 printf("\nWe are going to swap the values of two numbers :)");
 printf("\nEnter your first number : ");
 scanf("%d", &num_1);
 printf("\nEnter your second number : ");
 scanf("%d", &num_2);

 //swapping values
 swap_two_numbers(&num_1, &num_2);
 printf("\nThis is your first number's new value: %d", num_1);
 printf("\nThis is your second number's new value: %d", num_2);

 printf(LINE_BREAK);

//8.4 - calculating the area of a circle
 int user_radius = 0;

 //user input
 printf("\nWe are going to calculate the area of a circle :)");
 printf("\nEnter the radius of a circle : ");
 scanf("%d", &user_radius);

 //calculating area
 printf("The area of your circle is %.2f", calculate_area(user_radius, PI));

 return 0;
}
//functions defined:

//8.1:
int average_of_three_numbers(int num_1, int num_2, int num_3)
{
 int average = (num_1 + num_2 + num_3) / 3;
 return average;
}

//8.2:
int fahrenheit_to_celsius(int fahrenheit)
{
 double converted = (fahrenheit - 32) / 1.8;
 return (int)converted;
}

int celsius_to_fahrenheit(int celsius)
{
 double converted = (celsius * 1.8) + 32;
 return (int)converted;
}

//8.3:
void swap_two_numbers(int *num_1, int *num_2)
{
 int temp = *num_1;
 *num_1 = *num_2;
 *num_2 = temp;
}

//8.4:
double calculate_area(int radius, double PI)
{
 double area = (radius * radius) * PI;
 return area;
}