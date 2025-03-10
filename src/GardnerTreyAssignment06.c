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
  char buffered_input_string[50];
  int string_length = 0;

  //recieving input
  printf("\nEnter a string to be copied: ");
  gets(buffered_input_string);
  while (buffered_input_string[string_length] != '\0') {
    string_length++;
  }
  //adding null terminated value
  string_length++;

  //adjusting string length
  char input_string[string_length];
  for (int i = 0; i < string_length; i++) {
    if (i < string_length - 1)
    {
      input_string[i] = buffered_input_string[i];
    }
    else {
      input_string[i] = '\0';
    }
  }
  //B.) Displaying original string
  printf("Your original string is: %s\n", input_string);
  //C.) Copying string into new string
  //defining usable vairables
  int counter = 0;
  int trimmed_counter = 0;
  char string_copy[50];
  while (input_string[counter] != '\0') {
    string_copy[counter] = input_string[counter];
    counter++;
    if (input_string[counter] == '\n') {
      string_copy[counter] = '\0';
    }
    if (input_string[counter] != ' ') {
      trimmed_counter++;
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
  for (int i = 0; i < trimmed_counter; i++) {
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
    printf("\nYour string IS a palindrome!\n");
    printf("Your original string trimmed of spaces and case-sensitivity is: %s\n", string_copy);
    printf("Your reversed string trimmed of space and case-sensitivity is: %s\n", string_reversed);
  }
  else {
    printf("Your string is NOT a palindrome");
  }

  //6.3 - Count vowels and consonants
  //defining usable variables
  int vowels = 0;
  int consonants = 0;
  for (int i = 0; i < trimmed_counter; i++) {
    if (string_copy[i] == 'a' || string_copy[i] == 'e' || string_copy[i] == 'i' || string_copy[i] == 'o' || string_copy[i] == 'u') {
      vowels++;
    }
    else {
      consonants++;
    }
  }

  printf("\nYour string %s has: \nVowels: %d\nConsonants: %d", input_string, vowels, consonants);

  //6.4 - finding the longest word in a given string
  //defining variables
  counter = 0;
  char* temp_string;
  char* longest_string;
  int current_word  = 0;
  int temp_word = 0;
  for (int i = 0; i < string_length; i++) {
    //checking for end/beginning of word
    if (input_string[i] != '\0' && input_string[i] != ' ' && input_string[i] != '\n') {
      //settings pointer to beginning of word
      if (temp_word == 0) {
        temp_string = &input_string[i];
      } else if (temp_word > current_word) {
        current_word = temp_word;
        longest_string = temp_string;
        temp_word = 0;
      }//else if: assigning the longest word
    }
      temp_word++;
  }//for loop: looping through whole string


  printf("The largest word in your provided string is : %s", longest_word);
}