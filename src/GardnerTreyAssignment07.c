/*Name: Trey Gardner
Class: CS2060 (M/W)
Due: March 17th, 2025
Description: This program will;
7.1 - cacluate the sum of elements in an array (only using pointers)
7.2 - concatenate two user inputted strings (only using pointers)
7.3 - swap two integer values (using double pointer)
7.4 - Demostrate the behavior of wild and dangling pointers
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//prototype
int* dangling_pointer();

int main()
{

//7.1 - Calculate Sum
    //define array
    int integer_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //defining pointer
    int *array_pointer = integer_array;

    //Summation
    int array_length = sizeof(integer_array) / sizeof(int);
    int summation = 0;
    for (int i = 0; i < array_length; i++) {
        summation = summation + *(array_pointer + i);
    }
    //printing array summation:
    printf("Array Summation is %d\n", summation);

//7.2 - Concatenate Two Strings
    //declaring strings
    char first_string[20];
    char second_string[20];

    //Requesting and assigning user input
    printf("Enter your first string: ");
    scanf("%[^\n]", first_string);
    fflush(stdin);//flushing input stream
    printf("Enter your second string: ");
    scanf("%[^\n]", second_string);
    fflush(stdin);//flushing input stream

    //pointers for access
    char *first_pointer = first_string;
    char *second_pointer = second_string;

    //new string (hold concatonations)
    int concat_string_length = ((int)strlen(first_string) + (int)strlen(second_string) + 1);
    char concat_string[concat_string_length];
    char *concat_pointer = concat_string;
    char *concat_pointer_temp = concat_pointer;

    //concatenating strings
    for (int i = 0; i < concat_string_length; i++)
    {
        if ((int)(concat_pointer_temp - concat_pointer) < (int)strlen(first_string))
            {
            *concat_pointer_temp = *(first_pointer + i);
            }
        else
        {
            *concat_pointer_temp = *(second_pointer + (i - strlen(first_string)));
        }


        if (concat_pointer_temp == concat_pointer + concat_string_length)
        {
            *concat_pointer_temp = '\0';
        }
        concat_pointer_temp++;
    }

    //printing final string
    printf("Concatenated String is %s\n", concat_string);

//7.3 swap two integers (double pointers)
    //numbers to swap
    int num_1 = 5;
    int num_2 = 6;

    //number pointers
    int *num_1_pointer = &num_1;
    int *num_2_pointer = &num_2;

    //number double pointers;
    int **num_1_double = &num_1_pointer;
    int **num_2_double = &num_2_pointer;

    printf("Original Value #1: %d\n", num_1);
    printf("Original Value #2: %d\n", num_2);

    **num_2_double = **num_2_double + **num_1_double;
    **num_1_double = **num_2_double - **num_1_double;
    **num_2_double = **num_2_double - **num_1_double;

    printf("Reassigned Value #1: %d\n", num_1);
    printf("Reassigned Value #2: %d\n", num_2);

//7.4 - Wild and Dangling Pointers
    //wild pointer
    int *wild;
    //printf("%d", *wild); CODE INTERRUPTED BY SIGNAL 11:SIGSEGV
    wild = &num_1;
    printf("Wild Address: %p\nWild Value: %d", wild, *wild);
    //wild pointers are pointers that have a random memory address assigned and the are dangerous because you don't know that the data type is that is stored in that memory address

    //dangling pointer
   int *pointer =  dangling_pointer();
    for (int i = 0; i < array_length; i++)
    {
    printf("Dangling Pointer: %d\n", *(pointer + i));
    }
    //the dangling pointer does not print the correct values because the array it was attached to is removed from heap after the function ends. This leaves a pointer at a location that is not explicitly initialized in memory

}

int* dangling_pointer()
{
    int integer_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *array_pointer = integer_array;
    return array_pointer;
}