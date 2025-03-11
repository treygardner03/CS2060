/*Name: Trey Gardner
Class: CS2060 (M/W)
Due: March 10th, 2025
Description: This program will;
6.1 - copy one string into another without using built-in functions
6.2 - checks whether a given string is a palindrome or not
6.3 - counts the number of vowels and consonants in a given string
6.4 - finds the longest word in a given string (returns the first if there are multiple)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  //6.1 - copying one string to another (manually)
  //A.) take a string as an input
  //defining variables
  char input_string[50];
  int string_length = 0;

  //receiving input
  printf("\nEnter a string to be copied: ");
  fgets(input_string, sizeof(input_string), stdin);

  //inserting null termination
  input_string[strcspn(input_string, "\n")] = '\0';

  //getting string length
  int length_counter = 0;
  while (input_string[length_counter] != '\0') {
    string_length++;
    length_counter++;
  }

  //B.) Displaying original string
  printf("Your original string is: %s\n", input_string);
  //C.) Copying string into new string
  //defining usable vairables
  int counter = 0;
  int trimmed_counter = 0;
  char string_copy[string_length];

  for (int i = 0; i < string_length; i++) {
    string_copy[i] = input_string[i];
    counter++;
    trimmed_counter++;
    if (input_string[i] == ' ') {
      trimmed_counter--;
    }
  }

  //D.) Displaying string copy
  printf("My copied String is: %s\n\n", string_copy);

  //6.2 - check for palindrome
  //defining usable variables
  counter = 0;

  //A.) trimming input string (no spaces, case-insensitive)

  //converting to lower case
  strlwr(string_copy);

  //allocating trimmed and reversed strings
  char string_reversed[trimmed_counter];
  char input_string_trimmed[trimmed_counter];

  //coping only trimmed values
  for (int i = 0; i < string_length; i++) {
    if (string_copy[i] != ' ') {
      input_string_trimmed[i] = string_copy[i];
      string_reversed[trimmed_counter - 1 - i] = string_copy[i];
    }
  }

  //COULD JUST USE strcmp(); but i wanted to do it manually
  //C.) comparing strings
  for (int i = 0; i < trimmed_counter; i++) {
    if (input_string_trimmed[i] == string_reversed[i]) {
      counter++;
    }
  }

  if (counter == trimmed_counter) {
    printf("Your string IS a palindrome!\n");
    printf("Your original string trimmed of spaces and case-sensitivity is: %s\n", string_copy);
    printf("Your reversed string trimmed of space and case-sensitivity is: %s\n", string_reversed);
  }
  else {
    printf("Your string is NOT a palindrome\n");
  }

  //6.3 - Count vowels and consonants
  //defining usable variables
  int vowels = 0;
  int consonants = 0;

  for (int i = 0; i < string_length; i++) {
    if (input_string[i] == 'a' || input_string[i] == 'e' || input_string[i] == 'i' || input_string[i] == 'o' || input_string[i] == 'u') {
      vowels++;
    }
    else if (input_string[i] != ' ') {
      consonants++;
    }
  }

  printf("\nYour string %s has: \nVowels: %d\nConsonants: %d\n", input_string, vowels, consonants);

  //6.4 - finding the longest word in a given string
  //defining variables
  counter = 0;
  int test_word = 0;
  int longest_word = 0;
  char* string_pointer;
  for (int i = 0; i < string_length; i++) {
    if (test_word == 0) {
      string_pointer = &input_string[i];
    }

    if (test_word > longest_word) {
      longest_word = test_word;
    }

    if (input_string[i] != ' ') {
      test_word++;
    }
    else {
      test_word = 0;
    }

  }

  char longest_string[longest_word];
  for (int i = 0; i < longest_word + 1; i++) {
    longest_string[i] = *(string_pointer + i);
  }
  printf("\nThe largest word in your provided string is : %s", longest_string);
}