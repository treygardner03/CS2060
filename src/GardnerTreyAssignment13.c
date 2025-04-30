/*Name: Trey Gardner
Class: CS2060 (M/W)
Assignment: 13
Due: 04-28-25
Description: This program will;
13.1 - dynamically allocate memory and sum the values for an array of integers with size and values determined by the user
13.2 - dynamically allocate memory for an array of elements with default values 0 then free the memory
13.3 - dynamically allocate memory to an array with values from user then resize the array and recieve new values from user
13.4 - define a structure with specified members
13.4.5 - dynamically allocate memory for an array of employees using user input for (1 + 2): then print average salary
    1. size of array
    2. all member values
 */

//libraries
#include <stdio.h>
#include <stdlib.h>
#define LINE_BREAK "\n------------------------------------\n"

//prototypes

//13.4: employee structure
struct Employee {
  char name[25];
  int  employee_id;
  float salary;
};

//receive array values
void user_fill_array(int, int, int*);

//print array values
void print_array(int, int*);

//entering employee information
void user_enter_employees(int, struct Employee*);

//calculating average salary of all employees
float calculate_average_salary(int, struct Employee*);

//printing employee details for all with above average salary
void print_above_average(int, float, struct Employee*);

//main
int main(void)
{
//13.1: integer array summation
    //prompt:
    printf("First task we are doing today is creating an array and summing its values%s", LINE_BREAK);
    //user entered array size
    int* summation_array;
    int N = 0;//
    //prompting user
    printf("Enter the number of values for array: ");
    scanf("%d", &N);
    summation_array = malloc(N * sizeof(int));

    //user entered values (fill array)
    int offset = 0;
    user_fill_array(N, offset, summation_array);

    //sum values and print result
    int sum_of_array = 0;
    for(int i = 0; i < N; i++) {
      sum_of_array += summation_array[i];
    }//for
    printf("The sum of the values in this array is: %d", sum_of_array);

    //free values
    free(summation_array);

//13.2: element array
    //prompt:
    printf("\n\nSecond task we are doing is creating an array of elements%s", LINE_BREAK);

    //user entered array size (calloc())
    int* empty_array = calloc(N, sizeof(int));

    //print array values
    print_array(N, empty_array);

    //free memory
    free(empty_array);

//13.3: integer array memory reallocation
    //prompt:
    printf("\n\nThird on the list for today is creating a new array and changing it's size:%s", LINE_BREAK);
    //array size 5 (dynamic allocation)
    N = 5;
    printf("\nArray size: %d", N);
    int* changing_array = malloc(N * sizeof(int));

    //user entered values (fill array)
    user_fill_array(N, offset, changing_array);

    //expand array size to 10 (realloc())
    N = 10;
    printf("\nThe array size has been changed to %d!", N);
    changing_array = realloc(changing_array, N * sizeof(int));

    //user entered values (fill array)
    offset = 5;
    user_fill_array(N, offset, changing_array);

    //print array values
    print_array(N, changing_array);

    //free memory
    free(changing_array);

//13.4: employee details, average salary, above average details
    //prompt:
    printf("\n\nFinally we will be working with an array of Employees!%s", LINE_BREAK);

    //user entered employee details
    printf("\nFirst enter how many employees we are working with: ");
    scanf("%d", &N);
    struct Employee* employees;
    employees = malloc(N * sizeof(struct Employee));
    user_enter_employees(N, employees);

    //calculate average salary
    float average_salary = calculate_average_salary(N, employees);
    printf("\nThe average salary of all the provided employees is: %.2f", average_salary);

    //print details of employees with salary above average
    print_above_average(N, average_salary, employees);

    //free memory
    free(employees);

}//main

//taking user input to fill array with values
void user_fill_array(int size, int offset, int* array)
{
    printf("\nNow we will enter all values to fill the array: ");
    for (int i = offset; i < size; i++) {
      printf("\nEnter the value #%d: ", i);
        scanf("%d", &array[i]);
    }//for
    while (getchar() != '\n');//clearing input buffer
}//user fill array

//printing contents of an array
void print_array(int size, int* array)
{
    for (int i = 0; i < size; i++)
    {
        printf("\nArray value %d: %d ", i, *(array + i));
    }//for
}//print array

//user inputting employee information
void user_enter_employees(int size, struct Employee* employees)
{
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter the next employee ID#");
        scanf("%d", &employees[i].employee_id);
        while (getchar() != '\n');//clearing input buffer
        printf("\nEnter the name of the employee #%d: ", employees[i].employee_id);
        scanf("%[^\n]s", &employees[i].name);
        while (getchar() != '\n');//clearing input buffer
        printf("\nEnter the salary of the employee #%d: ", employees[i].employee_id);
        scanf("%f", &employees[i].salary);
        while (getchar() != '\n');//clearing input buffer
    }//for

}//entering employee info

//calculating the average salary of all provided employees
float calculate_average_salary(int size, struct Employee* employees)
{
    int average_salary = 0;
    for (int i = 0; i < size; i++)
    {
       average_salary += employees[i].salary;
    }//for

    return average_salary / size;
}//calculate average

//printing details of employees with above average salary
void print_above_average(int size, float average_salary, struct Employee* employees)
{
    printf("\nEmployees with above average salary: ");
    for (int i = 0; i < size; i++)
    {
        if (employees[i].salary > average_salary)
        {
            printf("\nEmployee #%d: Name - %s, Salary - %.2f", employees[i].employee_id, employees[i].name, employees[i].salary);
        }//if
    }//for
}//print above average