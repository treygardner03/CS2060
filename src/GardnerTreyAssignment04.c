/*Name: Trey Gardner
Class: CS2060 (MW)
Due: 02-24-25
Description: This program will;
1.) Write a program that stores 10 integers (fill with a multiplication table of 5)
2.) Write a script that finds the maximum and minimum values in a 1-D array
3.) Write a script that finds the 2nd largest element in an array
4.) Write a script that finds the sum of all the values at odd indices in an array
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    //4.1 - Create an array size 10 with 5's multiplication table
    int fives_multiplication_table[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

    //4.2 - Find the maximum and minimum values
    int maximum_value = fives_multiplication_table[0];
    int minumum_value = fives_multiplication_table[0];
    for(int i = 1; i < 10; i++) {
      if(fives_multiplication_table[i] > maximum_value) {
        maximum_value = fives_multiplication_table[i];
      }
      if(fives_multiplication_table[i] < minumum_value) {
        minumum_value = fives_multiplication_table[i];
      }
    }
    //displaying maximum and minimum values
    printf("The largest value is: %d\n", maximum_value);
    printf("The smallest value is: %d\n", minumum_value);

    //4.3 - Find the 2nd largest value
    int second_largest_value = fives_multiplication_table[0];
    for(int i = 1; i < 10; i++) {
      if(fives_multiplication_table[i] < maximum_value && fives_multiplication_table[i] > second_largest_value) {
        second_largest_value = fives_multiplication_table[i];
      }
    }
    //displaying the second-largest value
    printf("The second-largest value is: %d\n", second_largest_value);
    //4.4 - Calculate the sum of all values at odd indexes
    int odd_sum = 0;
    for(int i =0; i < 10; i++) {
      if(i%2 != 0) {
        odd_sum = odd_sum + fives_multiplication_table[i];
      }
    }
    //displaying the sum of all values located at odd indices
    printf("The sum of the values with odd indices is: %d\n", odd_sum);

  return (EXIT_SUCCESS);
 }
