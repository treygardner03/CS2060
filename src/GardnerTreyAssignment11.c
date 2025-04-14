/*Name: Trey Gardner
Class: CS2060 (M/W)
Due: 04-14-25
Assignment: 11
Description: This program will;
11.1 - Create struct "Student" then create and display and array of "Student"'s
11.2 - Create struct "Employee" then create and array and display "Employee" with highest and lowest
salary using both direct access and pointer arithmetic.
11.3 - Create struct "Product" then create and array user pointers to display all "Products", display
highest stock value, and allow the user to update the quantity of any product by ProductID
11.4 - Create two structs with the same members in different orders, and demonstrate how the order
of members in the definition may affect the memory layout due to "padding". Then disable padding for the
two structs and re-display their memory sizes.
 */

//libraries
#include <stdio.h>
#define number_of_students 3
#define number_of_employees 5
#define number_of_products 4

//prototypes \ Struct definition
struct Student
{
  char name[50];
  int student_id;
  int score[3];
};

struct Employee
{
  char name[50];
  int employee_id;
  char department[50];
  int salary;
};

struct Product
{
  int product_id;
  char name[50];
  float price;
  int stock_quantity;
};

struct Product_1
{
  int product_id;
  char rating;
};

struct Product_2
{
  char rating;
  int product_id;
};

//main
int main(void)
{
//10.1 - Student
  //Step 1: Create Array
  struct Student Trey = {"Trey", 0001, {78, 80, 75}},//student 1
               Haylie = {"Haylie", 0002, {85, 97, 95}},//student 2
               Wren = {"Wren", 0003, {87, 91, 93}};//student 3

  struct Student students[number_of_students] = {Trey, Haylie, Wren};

  //Step 2: Display student details (using pointers)
  //creating pointer
  struct Student *student_pointer;
  //initializing pointer
  student_pointer = students;

  //interatring through
  printf("\nAll student details: \n");
  for(int i = 0; i < number_of_students; i++)
  {
    printf("Student #%d:\nName: %s\nID: %d\nScores: %d, %d, %d", i, student_pointer->name, student_pointer->student_id,
           *student_pointer->score, *(student_pointer->score + 1), *(student_pointer->score + 2));

  }//for

  //Step 3: Find and display the student wit hthe highest average score

//10.2 - Employee
  //Step 1: Create an array
  struct Employee Mango, Bug, Luna, Tig, Binks;

  struct Employee employees[number_of_employees] = {Mango, Bug, Luna, Tig, Binks};

  //Step 2: User input for employee data

  //Step 3: Diplay highest and lowest salary

  //Step 4: Display employee data via (direct access & pointer access)

//10.3 - Product
  //Step 1: Create an array
  struct Product products[number_of_products] = {{0004, "Wheels", 33.99, 4}, {0002, "Bearings", 28.75, 10},
                                                 {0003, "Decks", 78.44, 35}, {0001, "Trucks", 44.23, 15}} ;

  //Step 2: Display product details (using pointers)

  //Step 3: Display product highest stock value

  //Step 4: User input for updating stock value

//10.4 - Memory Allocation Exercise
  //Step 1: Declare both Products
  struct Product_1 product_1;
  struct Product_2 product_2;

  //Step 2: Display sizes of both

  //Step 3: Disable padding and redisplay

}