/*Name: Trey Gardner
Class: CS2060 (MW)
Due: 02-03-25
Description: This program will take user input to calculate income tax, leap years,
the case of a character, and the greatest of 4 numbers.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  //2.1 Calculate the income tax paid by an employee (User input)
  //defining constants: income percentage brackets,
  const int minimum_income_5percent = 2500000;
  const int maximum_income_5percent = 5000000;
  const int minimum_income_20percent = 5000000;
  const int maximum_income_20percent = 10000000;
  const int minimum_income_30percent = 10000000;
  const float percent_taxed_5 = 0.05;
  const float percent_taxed_20 = 0.20;
  const float percent_taxed_30 = 0.30;

      //Requesting user input
      int user_income;
      int user_tax_payment;
      printf("Please input your anual income: ");
      scanf("%d", &user_income);

      //Determining user's tax bracket:
      //below 5 percent tax bracket
      if(user_income < minimum_income_5percent){
          printf("\nYour income is less than 2.5 Million and therefore not taxable.");
      }

      //5 percent tax bracket
      if(user_income >= minimum_income_5percent && user_income <= maximum_income_5percent){
          user_tax_payment = user_income * percent_taxed_5;
          printf("\nYour income meets the requirements for the 5%% tax bracket, you will pay %.2d in income tax this year", user_tax_payment);
      }

      //20 percent tax bracket
      if(user_income > minimum_income_20percent && user_income <= maximum_income_20percent){
          user_tax_payment = user_income * percent_taxed_20;
          printf("\nYour income meets the requirements for the 20%% tax bracket, you will pay %.2d in income tax this year", user_tax_payment);
        }

      //30 percent tax bracket
      if(user_income > minimum_income_30percent) {
          user_tax_payment = user_income * percent_taxed_30;
          printf("\nYour income meets the requirements for the 30%% tax bracket, you will pay %.2d in income tax this year", user_tax_payment);
      }

  //2.2 Determine leap year (User input)
  int user_year;
  printf("\nPlease input your year: ");
  scanf("%d", &user_year);

      if(user_year%4 == 0 && user_year%100 != 0 || user_year%400 == 0){
        printf("\nYour year is a leap year!!");
      }
      else{
        printf("\nYour year is NOT a leap year!!");
      }

  //2.3 Determine character's case (User input)
  char user_character;
  printf("\nPlease input your character: ");
  scanf("%c", &user_character);

  //checking if inputed char is lowercase:
  if( (int) user_character >= 97 && (int) user_character <= 122) {
    printf("\nYour character is a lowercase letter");
  }
  else if( (int) user_character >= 65 && (int) user_character <= 90) {
    printf("\nYour character is an uppercase letter");
  }
  else {
    printf("\nYour entered character is not a valid letter");
  }

  //2.4 Determining the greatest value of 4 numbers

  //declaring variables
  int user_number_1;
  int user_number_2;
  int user_number_3;
  int user_number_4;
  int greatest_number;

  //Requesting values from user
  printf("\nPlease enter your first number: (1/4) ");
  scanf("%d", &user_number_1);
  printf("\nPlease enter your second number: (2/4) ");
  scanf("%d", &user_number_2);
  printf("\nPlease enter your third number: (3/4) ");
  scanf("%d", &user_number_3);
  printf("\nPlease enter your fourth number: (4/4) ");
  scanf("%d", &user_number_4);

  //checking if first value is greatest
  if(user_number_1 > user_number_2 && user_number_1 > user_number_3 && user_number_1 > user_number_4){
    greatest_number = user_number_1;
    printf("\nYour first number ( %d ) is the greater number of the group", greatest_number);
  }
  //checking if second value is greatest
  if(user_number_2 > user_number_1 && user_number_2 > user_number_3 && user_number_2 > user_number_4){
    greatest_number = user_number_2;
    printf("\nYour second number ( %d ) is the greater number of the group", greatest_number);
  }
  //checking if third value is greatest
  if(user_number_3 > user_number_1 && user_number_3 > user_number_2 && user_number_3 > user_number_4){
    greatest_number = user_number_3;
    printf("\nYour third number ( %d ) is the greater number of the group", greatest_number);
  }
  //checking if fourth value is greatest
  if(user_number_4 > user_number_1 && user_number_4 > user_number_2 && user_number_4 > user_number_3){
    greatest_number = user_number_4;
    printf("\nYour fourth number ( %d ) is the greater number of the group", greatest_number);
  }
}