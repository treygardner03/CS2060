/*Name: Trey Gardner
Class: CS2060 (M/W)
Due: February 26th, 2025
Description: This program will;
1.) Takes a 3x3 matrix input and returns the largest value in each row
2.) Takes a 3x3 matrix and sums the diagonal values
3.) Checks for symetry in a 3x3 matrix
4.) Takes a 3x3 matrix input and replaces all negative values with 0
 */
#include <stdio.h>
#include <stdlib.h>
const int ROWS = 3, COLS = 3;

int main() {
  //5.1 - Find the largest value in each row
 //User Input: collect matrix values
 int user_matrix[ROWS][COLS];
 int row_0_largest = 0;
 int row_1_largest = 0;
 int row_2_largest = 0;

 for(int i = 0; i < ROWS; i++) {
   for(int j = 0; j < COLS; j++) {
    printf("\nPlease enter the value for matrix[%d][%d]: \n", i, j);
    scanf("%d", &user_matrix[i][j]);
     if (i == 0 && j == 0) {
      row_0_largest = user_matrix[i][j];
    }

     if (i == 1 && j == 0) {
      row_1_largest = user_matrix[i][j];
    }

     if (i == 2 && j == 0) {
      row_2_largest = user_matrix[i][j];
    }

    if (user_matrix[i][j] > row_0_largest && i == 0) {
     row_0_largest = user_matrix[i][j];
    }

    if (user_matrix[i][j] > row_1_largest && i == 1) {
     row_0_largest = user_matrix[i][j];
    }

    if (user_matrix[i][j] > row_2_largest && i == 2) {
     row_0_largest = user_matrix[i][j];
    }
  }
 }

printf("\nThe largest values are in each row: \nRow 0: %d\nRow 1: %d\nRow 2: %d",
 row_0_largest, row_1_largest, row_2_largest);

  //5.2 - Sum the diagonal values
 //Primary diagonal is top left to bottom right, secondary diagonal is top right to bottom left
 int sum_primary_diagonal = 0;
 int sum_secondary_diagonal = 0;

 for (int i = 0; i < ROWS; i++) {
  for (int j = 0; j < COLS; j++) {
   if (i == j) {
    sum_primary_diagonal += user_matrix[i][j];
   }
   if ((ROWS - i) - 1 == j) {
    sum_secondary_diagonal += user_matrix[i][j];
   }
  }

 }

 printf("\nThe summation of the diagonals:\n\nPrimary Diagonal 1: %d\nPrimary Diagonal 2: %d\n",
  sum_primary_diagonal, sum_secondary_diagonal);

  //5.3 - Check for symmetry in matrix
 int vertical_symmetry = 0;
 int horizontal_symmetry = 0;

 for (int i = 0; i < ROWS; i++) {
  for (int j = 0; j < COLS; j++) {

    if (i == 0 && user_matrix[i][j] == user_matrix[i + COLS - 1][j]) {
     printf("\nThe matrix is horizontally symmetrical in column %d", j);
     horizontal_symmetry++;
    }
    if (j == 0 && user_matrix[i][j] == user_matrix[i][j + ROWS - 1]) {
     printf("\nThe matrix is vertically symmetrical in row %d", i);
     vertical_symmetry++;
    }
   }
  }
 if (vertical_symmetry == ROWS && horizontal_symmetry == COLS) {
  printf("\n\nThe matrix is is fully symmetrical!");
 }
 else {
  printf("\n\nThe matrix is  not fully symmetrical!");
 }

  //5.4 - Replace all negatives with 0

 printf("\nYour matrix with NO negative numbers\n");

 for (int i = 0; i < ROWS; i++) {
  for (int j = 0; j < COLS; j++) {
   if (user_matrix[i][j] < 0) {
    user_matrix[i][j] = 0;
   }
   if (j == 0) {
    printf("\n");
   }
   printf("%d\t", user_matrix[i][j]);
  }
 }
 }