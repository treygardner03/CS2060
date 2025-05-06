/* Name: Trey Gardner
Class: CS2060 (M/W)
Assignment: Project 02
Due: May 5th, 2025
Description: This program will;
Simulate the game "Rock, Paper, Scissors" using the key words snake, water, gun and will have a user playing against a
computer, where the game will keep track of the running scores and display the score totals at the end of the game (@ end
of game OR user defined end)
 */

//libraries
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#define NUM_ROUNDS 5
#define LINE_BREAK "\n---------------------------------------------"
#define SNAKE "snake"
#define WATER "water"
#define GUN "gun"


//prototypes
char computer_input(void);
int compare_inputs(char, char);
int input_validation(char);
void score_tally(int*, int*, int);
void display_round_results(int, int, char, char);
void display_final_results(int, int, int);

//main
int main(void)
{
//Prompt: Intro to game
 printf("%s\n\tWelcome to Snake, Water, Gun!", LINE_BREAK);
 printf("\n\nInstructions: \nRules: Snake beats Water, Water beats Gun, Gun beats Snake"
        "\n1.) The game last %i rounds"
        "\n2.) Enter the LETTER or WORD for the option you want to play"
        "\n3.) Enter 'E' to quit the game...%s", NUM_ROUNDS, LINE_BREAK);

 //Game variables
 bool game_end = false;
 char user_input;
 char computer_choice;
 int round = 1;
 int round_results = 0;
 int user_score = 0;
 int computer_score = 0;
 int validation = 0;

//enter game loop
 //while (game not over)
 while (game_end == false && round <= NUM_ROUNDS)
 {
  //user input
  printf("\n\nRound %i/%i: ", round, NUM_ROUNDS);
  printf("\nPlease choose snake(S), water(W) or gun(G): ");
  scanf("%c", &user_input);
  user_input = toupper(user_input);

   //check for game end (user input)
   //input validation
  validation = input_validation(user_input);
  if (validation == -1) game_end = true;
  else if (validation == 1)
  {
      //computer input
      computer_choice = computer_input();

      //compare inputs
      round_results = compare_inputs(user_input, computer_choice);

      //tally score
      score_tally(&user_score, &computer_score, round_results);

      //display results
      display_round_results(round_results, round, user_input, computer_choice);

      //iterating rounds
      round++;

  }//else valid response
  //else invalid response
  else printf("\nPlease enter a valid response...");

  //clear input buffer
  while(getchar() != '\n');

 }//While

//Display final results
 display_final_results(user_score, computer_score, round - 1);

}//main


//Define Functions

//random computer input
char computer_input()
{
  int random = rand() % (300 - 1 + 1) + 1;

  if(random <= 100) return 'S';
  if(random <=200) return 'W';
  return 'G';

}//computer input

//comparing user and computer inputs
int compare_inputs(char u, char c)
{
  if(u == c) return 0;//tie
  if(u =='S' && c == 'W') return 1;//snake beats water
  if(u =='S' && c == 'G') return -1;//snake loses to gun
  if(u =='G' && c == 'S') return 1;//gun beats snake
  if(u =='G' && c == 'W') return -1;//gun loses to water
  if(u =='W' && c == 'G') return 1;//water beats gun
  return -1;//water loses to snake

}//compare inputs

//adjusting saved scores
void score_tally(int* user_score, int* computer_score, int round_results)
{
  if(round_results > 0) *user_score += 1;
  else if(round_results < 0) *computer_score += 1;

}//tallying score

//display individual round results
void display_round_results(int round_results, int rounds, char user_input, char computer_choice)
{
  //full strings for prints
  char* user;
  char* computer;

  //assigning string (user)
  if (user_input == 'G') user = GUN;
  else if (user_input == 'S') user = SNAKE;
  else user = WATER;

  //assigning string (computer)
  if (computer_choice == 'G') computer = GUN;
  else if (computer_choice == 'S') computer = SNAKE;
  else computer = WATER;

  //printing "gameplay"
  printf("%-6s||  %s\n%-6svs  %s", "User", "Computer", user, computer);

  //printing results
  if(round_results == 1) printf("\nYou win round #%i!", rounds);
  else if(round_results == -1) printf("\nYou lose round #%i :(", rounds);
  else printf("\nIt's a tie...");

}//display round results

//display cumulative results
void display_final_results(int user_score, int computer_score, int rounds)
{
  printf("\n%s\n\t\tGAME OVER%s\nNumber of Rounds: %i\nYour Score: %i\nComputer Score: %i\n", LINE_BREAK, LINE_BREAK, rounds, user_score, computer_score);
  if (user_score > computer_score) printf("\nResults: You WIN!!!");
  else if (user_score < computer_score) printf("\nResults: The computer WINS :(");
  else printf("\nResults: You've tied with the computer...");
}//display final results

//validating user input
int input_validation(char user_input)
{
   if (user_input == 'S' || user_input == 'W' || user_input == 'G') return 1;
   if (user_input == 'E') return -1;
    return 0;
}//input validation