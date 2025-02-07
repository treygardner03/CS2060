/*Name: Trey Gardner
Class: CS2060 (M/W)
Due: 02-19-25
Description: This program will; Generate a random number, then respond to user input with
either "Higher" or "Lower" until the user guesses the number
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
 int maximum_value = 1000;
 int minimum_value = 1;
 int user_guess;
  srand(time(NULL));
 int random_number = rand() % maximum_value + minimum_value;

 printf("Please try to guess a number betweeen 1-1000: ");

 while (user_guess != random_number) {
 scanf("%d", &user_guess);
   if(user_guess < minimum_value) {
     printf("Please enter a number betweeen 1-1000: ");
   }
   if(user_guess > maximum_value) {
     printf("Please enter a number betweeen 1-1000: ");
   }
   if(user_guess < random_number) {
     printf("Enter a higher number: ");
   }
   if(user_guess > random_number) {
     printf("Enter a lower number: ");
   }
 }
 printf("You Win!!");
}