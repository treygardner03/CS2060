/*Name: Trey Gardner
Class: CS2060 (MW)
Due: 02-17-25
Description: This program will; 1. create a reverse order multiplication table of an input
2. calculate the sum of the values in the multiplication table of #8 (1-10)
3. calculate the factorial of any inputted number (whole number)
4. determine if an inputted number is a prime number or not
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    //3.1 Print a multiplication table of an inputted value
    int user_table_limit;

    //receiving input value
    printf("Please input the size of the multiplication table: ");
    scanf("%d", &user_table_limit);

    //calculating and printing multiplication table
    for (int j = user_table_limit; j >= 1; j--) {
        printf("\n");
        for (int i = user_table_limit; i >= 1; i--) {
            printf("%-5d", (i*j));
        }
    }

    //3.2 Summing the values of 8's multiplication table
    const int integer_for_table = 8;
    const int table_minimum = 1;
    const int table_maximum = 10;
    int multiplication_table_value = 0;
    int summation_value = 0;

    //calculating 8's multiplication table
    for(int i = table_minimum; i < table_maximum + 1; i++) {
        multiplication_table_value = integer_for_table * i;
        summation_value += multiplication_table_value;
    }
    //printing the sum of the values in the multiplication table
    printf("\n\nThe summation of 8's multiplication table is: %d\n", summation_value);

    //3.3 Calculate the factorial of an inputted number (whole number)
    int user_factorial_value;

    //receiving input value
    printf("\nPlease input the factorial base value: ");
    scanf("%d", &user_factorial_value);
    int factorial_value = user_factorial_value;
    //calculate factorial
    for(int i = user_factorial_value - 1; i > 0; i--) {
        factorial_value = factorial_value * i;
    }
    //print value
    printf("Factorial value: %d\n", factorial_value);

    //3.4 Determining if an inputted value is a prime number or not
    int user_prime_number;
    int prime_counter = 2;
    bool is_prime = true;

    //receiving input value
    printf("\nPlease input the number in question: ");
    scanf("%d", &user_prime_number);

    //determine if prime
    while (is_prime == true && prime_counter < user_prime_number) {
        if (user_prime_number % prime_counter == 0 && prime_counter != user_prime_number) {
            is_prime = false;
        }
        prime_counter++;
    }
    is_prime ? printf("\nYour number IS prime!") : printf("\nYour number is NOT prime!");
}