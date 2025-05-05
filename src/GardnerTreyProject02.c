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
#define NUM_ROUNDS 5
#define LINE_BREAK "\n---------------------------------------"

//prototypes
char computer_input(void);
int compare_inputs(char, char);
void score_tally(int*, int*, int);
void display_round_results(int, int, char, char);
void display_final_results(int, int, int);

//main
int main(void)
{
//Prompt: Intro to game
 printf("%s\nWelcome to Snake, Water, Gun!\n\tenter 'E' to end the game...%s", LINE_BREAK, LINE_BREAK);

//Enter game loop
 //game variables
 bool game_end = false;
 char user_input;
 char computer_choice;
 int round = 1;
 int round_results = 0;
 int user_score = 0;
 int computer_score = 0;

 //while (game not end)
 while (!game_end || round == NUM_ROUNDS)
 {
  //user input
  printf("\n\nRound %i/%i: ", round, NUM_ROUNDS);
  printf("\nPlease choose snake(S), water(W) or gun(G): ");
  scanf("%c", &user_input);
  user_input = toupper(user_input);

   //check for game end (user input)
     //input validation...
  if(user_input == 'E') game_end = true;

  else//comparisons and results
  {
      //computer input
      computer_choice = computer_input();

      //compare inputs
      round_results = compare_inputs(user_input, computer_choice);

      //tally score
      score_tally(&user_score, &computer_score, round_results);

      //display results
      display_round_results(round_results, round, user_input, computer_choice);

      //check for game end (standard)
      round++;
      if(round == NUM_ROUNDS) game_end = true;

      //clear input buffer
      while(getchar() != '\n');

  }//else comparisions/results

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
  else if(random > 100 && random <=200) return 'W';
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
    printf("User: %c || Computer: %c\n", user_input, computer_choice);
  if(round_results == 1) printf("You win round #%i!", rounds);
  else if(round_results == -1) printf("You lose round #%i!", rounds);
  else printf("It's a tie!");

}//display round results


//display cumulative results
void display_final_results(int user_score, int computer_score, int rounds)
{
  printf("%s\nRound Results:\nNumber of Rounds: %i\nYour Score: %i\nComputer Score: %i", LINE_BREAK, rounds, user_score, computer_score);
  if (user_score > computer_score) printf("\nYou WIN!!!");
  else if (user_score < computer_score) printf("\nThe computer WINS!!!");
  else printf("\nITS A TIE!");

}//display final results
