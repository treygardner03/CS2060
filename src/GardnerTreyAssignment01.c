/*Name: Trey Gardner
Class: CS2060 (MW)
Due: 01-29-25
Description: Uses hardcoded and user inputs to calculate the area and volume of specified shapes
as well as temperature conversions and interest rates.
 */
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159
int main() {
  //1.1 calculating the area of a rectangle
    printf("\nCalculating the Area of a Rectangle:\n"
         "======================================\n");
  //Part A: hardcoded inputs

    //hardcoded values
      float rectangle_length = 3.5f;
      float rectangle_width = 2.5f;
      printf("\nUsing hardcoded values: ");

    //Calculating area with hardcoded values
      float rectangle_area = rectangle_length * rectangle_width;
      printf("\nThe area of the rectangle is: %.2f\n", rectangle_area);

  //Part B: User inputted values
    printf("\nPlease input new rectangle length: ");
    scanf("%f", &rectangle_length);
    printf("Please input new rectangle width: ");
    scanf("%f", &rectangle_width);
    printf("\nUsing your inputted values: ");

    //Calculate area with user inputted values
      rectangle_area = rectangle_length * rectangle_width;
      printf("\nThe area of the new rectangle is: %.2f\n", rectangle_area);

  //1.2 Calculate the area of a circle and volume of a cylinder
    printf("\nCalculating the Area of a Circle and the Volume of a Cylinder:\n"
         "================================================================\n");
    //Part A: hardcoded values

      //hardcoded values
        float circle_radius = 7.32f;
        float cylinder_height = 15.41f;
        printf("\nUsing hardcoded values: ");

      //Calculating area with hardcoded values
        float circle_area = PI * circle_radius * circle_radius;
        printf("\nThe area of the circle is: %.2f\n", circle_area);

      //Calculating volume with hardcoded values
        float cylinder_volume = PI * cylinder_height * (circle_radius * circle_radius);
        printf("The volume of the cylinder is: %.2f\n", cylinder_volume);

    //Part B: User inputted values
      printf("\nPlease input new circle radius: ");
      scanf("%f", &circle_radius);
      printf("Please input new cylinder height: ");
      scanf("%f", &cylinder_height);
      printf("\nUsing your inputted values: \n");

      //Calculating area with user inputted values
        circle_area = PI * circle_radius * circle_radius;
        printf("The area of the new circle is: %.2f\n", circle_area);

      //Calculating volume with user inputted values
        cylinder_volume = PI * cylinder_height * (circle_radius * circle_radius);
        printf("The volume of the new cylinder is: %.2f\n", cylinder_volume);

  //1.3 Convert from Fahrenheit to Celsius
    printf("\nConverting temperature from Celsius to Fahrenheit: "
           "\n===================================================\n");

    //Part A: hardcoded values
      float temperature_celsius = 242.31f;
      printf("\nUsing hardcoded values: ");
      float temperature_fahrenheit = (9.0/5.0 * temperature_celsius) + 32;
      printf("\nConverting hardcoded temperature of 242.31C to Fahrenheit: ");
      printf("%.2f\n", temperature_fahrenheit);

    //Part B: User inputted values
      printf("\nPlease input new Celsius temperature: ");
      scanf("%f", &temperature_celsius);

      //Calculating with user inputted values
        printf("\nYour new temperature in Fahrenheit is: ");
        temperature_fahrenheit = (9.0/5.0 * temperature_celsius) + 32;
        printf("%.2f\n",temperature_fahrenheit);

  //1.4 Calculating simple interest
    printf("\nCalculating Simple Interest Accrual: "
         "\n==================================\n");
  //declaring values
    float principal_amount;
    float annual_interest_rate;
    float loan_term_length;
    float simple_interest;
  //requesting and recording user input
    printf("\nPlease input your principle amount: ");
    scanf("%f", &principal_amount);
    printf("Please input your annual interest rate: ");
    scanf("%f", &annual_interest_rate);
    printf("Please input your loan term length in years: ");
    scanf("%f", &loan_term_length);
  //Calculating User inputted values
   simple_interest = (principal_amount * annual_interest_rate * loan_term_length) / 100;
   printf("\nYour total simple interest is: $%.2f\n", simple_interest);

  }


