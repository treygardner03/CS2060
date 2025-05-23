/*Name: Trey Gardner
Class: CS2060 (M/W)
Assignment: #10
Due: April 7th, 2025
Description: This program will;
10.1: compute the greatest common divisor (GCD) of two positive integers using a recursive function
10.2: cacluate the sum o the elements in an integer array using recursion
10.3: counting vowels in a string using a recursive function
10.4: recursively add the digits of an integer until the result is a single digit
 */

#include <ctype.h>
#include <stdio.h>
#define LINE_BREAK "\n-------------------------------------------------------------------------\n"




//function prototypes
int greatest_common_divisor(int a, int b);
int recursive_summation(int int_array[], int size);
int recursive_vowel_count(char *string);
int recursive_integer_reduction(int num);

int main()
{
//10.1 - finding the GCD
  //user defined integers
  int first_int = 0;
  int second_int = 0;

  //prompting user for input
  printf("%sWe are going to find the greatest common divisor for two numbers using recursion!%s", LINE_BREAK, LINE_BREAK);
  printf("\nPlease enter your first integer: ");
  scanf("%d", &first_int);
  printf("\nPlease enter your second integer: ");
  scanf("%d", &second_int);
  getchar();

  //finding GCD
  int gcd = greatest_common_divisor(first_int, second_int);

  //displaying results
  printf("\nThe greatest common divisor for your two numbers is: %d\n", gcd);


//10.2 - recursive summation
  //predefined array
  int int_array[] = {2, 3, 6, 3, 6, 1, 56, 74, 24, 30, 16};
  int size = sizeof(int_array) / sizeof(int);

  //prompting user
  printf("%sWe are now going to find the sum of an integer array using a recursive algorithm!%s", LINE_BREAK, LINE_BREAK);
  printf("\nThe array that we are working with is: ");
  //displaying array
  for (int i = 0; i < sizeof(int_array) / sizeof(int_array[0]); i++)
  {
    printf("%d ", int_array[i]);
  }

  //summing array
  int recursive_sum = recursive_summation(int_array, size);

  //displaying results
  printf("\nThe sum of the array above is: %d\n", recursive_sum);

//10.3 - recursive vowel count
  //user defined string
  char string[50];

  //prompting user
  printf("%sWe are now going to count the vowels in a string using recursion!%s", LINE_BREAK, LINE_BREAK);
  printf("\nPlease enter your string: ");
  scanf("%[^\n]s", string);
  getchar();

  //counting vowels
  int total_vowels = recursive_vowel_count(string);

  //displaying results
  printf("The total number of vowels in your string is: %d\n", total_vowels);

//10.4 - recursive integer reduction (addition)
  //user defined integers
  int reductive_integer = 0;

  //prompting user
  printf("%sFinally, we are going to use recursion to and integer reduction using sumation!%s", LINE_BREAK, LINE_BREAK);
  printf("\nPlease enter and integer to reduce: ");
  scanf("%d", &reductive_integer);

  //reducing integer
  int reduced_integer = recursive_integer_reduction(reductive_integer);

  //displaying the results
  printf("The final integer reduced to a single digit is: %d\n", reduced_integer);

}
  //EXTRA CHALLENGE: Return the number of recursions each function used and what the values were as it changes

//finding the greatest common devisor
int greatest_common_divisor(int a, int b)
{
  if(b == 0)
  {
    return a;
  }//if
     return greatest_common_divisor(b, a % b);
}//greatest_common_devisor

//summing integer array
int recursive_summation(int int_array[], int size)
{
  if (size == 0)
  {
    return 0;
  }
  return recursive_summation(int_array, size -1) + int_array[size - 1];

}

//counting vowels in a string
int recursive_vowel_count(char *string)
{
  if (*string == '\0')
  {
    return 0;
  }
  char c = tolower(*string);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o' || c == 'y')
  {
    return 1 + recursive_vowel_count(string + 1);
  }
  return recursive_vowel_count(string + 1);

}

//reducing integer using addition
int recursive_integer_reduction(int num)
{
  if (num < 10) return num;
  int sum = recursive_integer_reduction(num / 10) + recursive_integer_reduction(num % 10);
  return recursive_integer_reduction(sum);
}
