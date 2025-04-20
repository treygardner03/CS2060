/* Name: Trey Gardner
Class: CS2060 (M/W)
Assignment: 12
Due: 04-21-25
Description: This program will;
12.1 - Store student data into a file named "students.txt" including the students (ID, name, and GPA)
12.2 - Modify a file containing an integer to double its value
12.3 -  Modify a text file by:
      A.) converting all letters to uppercase
      B.) Removing a specified line from the file (based on line number) storing in new file
12.4 - Calculates and displays the size of a given file in bytes. Checking that the file exists before operating
 */

//libraries
#include <ctype.h>
#include <stdio.h>
#define NUM_OF_STUDENTS 3

//prototypes\Structs
//Student struct
struct Student
{
  //members
  int student_id;
  char name[25];
  float gpa_score;
};

//main
int main(void)
{
//12.1 - Storing student  data
    //creating student records
    struct Student Trey = {111466749, "Trey Gardner", 3.46f},//Student 1
                   Haylie = {734777347, "Haylie Gardner", 4.00f},//Student 2
                   Bug = {696420969, "Bug Gardner", 3.67f};//Student 3

    //array of students
    struct Student all_students[NUM_OF_STUDENTS] = {Trey, Haylie, Bug};

    //creating file
    FILE *student_records = fopen("students.txt", "w+");

    //adding student records
    fprintf(student_records, "All Student Records: \n");
    for (int i = 0; i < NUM_OF_STUDENTS; i++)
    {
        fprintf(student_records, "Student #%i -> Name: %s GPA: %.2f\n", all_students[i].student_id, all_students[i].name, all_students[i].gpa_score);
    }

    //display contents of file

    //setting pointer to beginning of file
    rewind(student_records);
    //creating "char" value
    int printable;
    //while pointer is not at end of file - print each character
    while ((printable = fgetc(student_records)) != EOF)
    {
        printf("%c", printable);
    }
    //closing file
    fclose(student_records);

//12.2 - Doubling integer from file
    //creating file with integer value
    FILE *integers = fopen("integers.txt", "w+");
    fprintf(integers, "%d", 43);

    //reading and doubling value
    rewind(integers);
    int unmodified_value;
    fscanf(integers, "%d", &unmodified_value);
    int modified_value = unmodified_value * 2;
    rewind(integers);
    fprintf(integers, "%d", modified_value);
    //closing file
    fclose(integers);

//12.3 - Modifying text file
    //creating text file
    FILE *text_file = fopen("text.txt", "w+");
    fprintf(text_file, "%s", "Hello my name is trey and this is my\ntest file with some WonKY choices to make\nsurethat everytinbg is working :)");
    rewind(text_file);

    //converting to upper case
    char initial_text[100];
    fgets(initial_text, EOF, text_file);
    (initial_text);
    //to upper case
    rewind(text_file);
    fprintf(text_file, "%s", initial_text);
    rewind(text_file);

    //prompting for line to remove
    printf("Enter the line # of the line you would like to delete from the file: ");
    int line_number = 0;
    scanf("%d", line_number);

    //Removing specified line
    FILE *final_text = fopen("final.txt", "w+");
    while (text_file != EOF)
    {
        int counter = 0;
        if (counter != line_number)
        {
            char print_string[100];
            fgets(print_string, '\n', initial_text);
            fprintf(final_text, "%s", print_string);
        }
        counter++;
    }

    //creating new file with modified contents

//12.4 - displaying the size of a given file in bytes
    //checking that file exists

    //calculating size of file

    //display size of file in bytes

}//main
