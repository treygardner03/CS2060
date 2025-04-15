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
#define LINE_BREAK "-------------------------------------------"

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
  float salary;
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

struct Unpadded_Product_2
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

  //highest and lowest
  struct Student *current = student_pointer;

  //interatring through
  printf("\nAll student details: \n");
  for(int i = 0; i < number_of_students; i++)
  {
      double current_average = ((*current->score) + *(current->score+ 1) + *(current->score + 2)) / 3.0;
      double comparative_average = ((*student_pointer->score) + *(student_pointer->score + 1) + *(student_pointer->score + 2)) / 3.0;

      if(comparative_average > current_average)
      {
        current = student_pointer;
      }
    printf("\nStudent #%d:\nName: %s\nID: %d\nScores: %d, %d, %d", i, student_pointer->name, student_pointer->student_id,
           *student_pointer->score, *(student_pointer->score + 1), *(student_pointer->score + 2));
    printf("\n%s\n", LINE_BREAK);
    student_pointer++;
  }//for

  //Step 3: Find and display the student with the highest average score
  printf("\nStudent with the highest average score is: %s with an average score of %.2f", current-> name,
         (*(current->score) + *(current->score+ 1) + *(current->score + 2)) / 3.0);

//10.2 - Employee
  //Step 1: Create an array
  struct Employee employees[number_of_employees];
  struct Employee direct_current = employees[0];
  struct Employee *pointer_current = employees;

  //Step 2: User input for employee data
  printf("\n\nPlease enter the information for all current employees: \nNumber of employees: %i", number_of_employees);
  for(int i = 0; i < number_of_employees; i++)
  {
    printf("\n\nEmployee #%i: \n%s", i, LINE_BREAK);
    printf("\nEnter name: ");
    scanf("%[^\n]s%*c", employees[i].name);
    printf("\nEnter ID number: ");
    scanf("%i%*c", &employees[i].employee_id);
    printf("\nEnter department: ");
    scanf("%[^\n]s%*c", employees[i].department);
    printf("\nEnter salary: ");
    scanf("%i%*c", &employees[i].salary);

    //finding the highest salary with direct access
    if (employees[i].salary > direct_current.salary)
    {
      direct_current = employees[i];
    }

    //finding the highest salary with pointer access
    if ((employees + i) ->salary < (pointer_current->salary))
    {
      pointer_current = (employees + i);
    }
  }//for

  //Step 3/4: Display highest and lowest salary
  printf("The employee with the highest salary is: %s with a salary of %f", direct_current.name, direct_current.salary);
  printf("The employee with the lowest salary is: %s with a salary of %f", pointer_current->name, pointer_current->salary);

//10.3 - Product
  //Step 1: Create an array
  struct Product products[number_of_products] = {{0004, "Wheels", 33.99, 4}, {0002, "Bearings", 28.75, 10},
                                                 {0003, "Decks", 78.44, 35}, {0001, "Trucks", 44.23, 15}} ;
  struct Product *product_pointer = products;
  struct Product *current_product = products;
  //Step 2: Display product details (using pointers)
  printf("\nAll product's details: \n%s\n", LINE_BREAK);
  for(int i = 0; i < number_of_products; i++)
  {
    printf("\nProduct #%i: \nName: %s\nPrice: %f\nAmount in Stock: %i", product_pointer->product_id, product_pointer->name, product_pointer->price, product_pointer->stock_quantity);
    if (current_product->stock_quantity > product_pointer->stock_quantity)
    {
      current_product = product_pointer;
    }
    product_pointer++;
  }//for

  //Step 3: Display product the highest stock value
  printf("The product the with highest stock value is : %s With a quantity of %i", current_product->name, current_product->stock_quantity);

  //Step 4: User input for updating stock value
  int id_input = 0;
  printf("\n\nUpdating product stock: \n%s\n", LINE_BREAK);
  while (id_input >= 0)
  {
    printf("\nEnter the product ID you want to update, Enter '-1' when finished: ");
    scanf("%i", &id_input);

    switch(id_input)
    {
    case 0001:
      printf("\nEnter the stock of product #%i: ", id_input);
      scanf("%i", &products[3].stock_quantity);
      break;
    case 0002:
      printf("\nEnter the stock of product #%i: ", id_input);
      scanf("%i", &products[1].stock_quantity);
      break;
    case 0003:
      printf("\nEnter the stock of product #%i: ", id_input);
      scanf("%i", &products[2].stock_quantity);
      break;
    case 0004:
      printf("\nEnter the stock of product #%i: ", id_input);
      scanf("%i", &products[0].stock_quantity);
      break;
    default: printf("\n------Invalid product ID------\nplease try again...");
    }//switch

  }//while

//10.4 - Memory Allocation Exercise
  //Step 1: Declare both Products
  struct Product_1 product_1;
  struct Product_2 product_2;
#pragma pack(1)
  struct Unpadded_Product_2 unpadded_product_2;

  //Step 2: Display sizes of both
  printf("Size of struct with int first: %lu", sizeof(product_1));
  printf("Size of struct with char first: %lu", sizeof(product_2));
  printf("Size of struct with char first unpadded: %lu", sizeof(unpadded_product_2));

}//main


