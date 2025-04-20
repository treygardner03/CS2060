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
#define LINE_BREAK "\n---------------------------------------\n"

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
    //Operation Prompt
    printf("\nCreating .txt file and writing student records: %s", LINE_BREAK);
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
        fprintf(student_records, "-> Student #%i -> Name: %s GPA: %.2f\n", all_students[i].student_id, all_students[i].name, all_students[i].gpa_score);
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

    //Operation Prompt
    printf("\nDoubling Integer value read from text file: %s", LINE_BREAK);

    //creating file with integer value
    FILE *integers = fopen("integers.txt", "w+");
    fprintf(integers, "%d", 43);

    //reading integer from text file
    rewind(integers);
    int unmodified_value;
    fscanf(integers, "%d", &unmodified_value);

    //printing current integer value
    printf("-> Current Integer in .txt file: %d\n", unmodified_value);

    //doubling integer value
    int modified_value = unmodified_value * 2;
    rewind(integers);
    fprintf(integers, "%d", modified_value);

    //printing new integer:
    printf("-> New Integer in .txt file: %d\n", modified_value);

    //closing file
    fclose(integers);

//12.3 - Modifying text file
    //Operation Prompt
    printf("\nCreating a text file, then modifying the contents to: "
           "\n1.) covert all characters to uppercase"
           "\n2.) prompt the user to remove a line by line number %s", LINE_BREAK);

    //creating text file
    FILE *text_file = fopen("text.txt", "w+");
    fprintf(text_file, "%s", "hello my name is trey and this is my\ntest file with some WonKY choices to make"
                             "\nsurethat everytinbg is working :)");
    rewind(text_file);

//1.) CHANGING TEXT TO UPPER CASE

    //creating string with length of text file
    fseek(text_file, 1, SEEK_END);
    long length = ftell(text_file);
    char file_to_string[length +1];
    rewind(text_file);

    //writing the contents of the text file to the string
    for (int i = 0; i < length; i++)
    {
        file_to_string[i] = fgetc(text_file);
    }
    file_to_string[length] = '\0';//adding null terminator

    //printing current text file contents
    printf("-> Current text files contents:\n%s\n", file_to_string);

    //converting to uppercase
    for (int i = 0; i < length; i++)
    {
        file_to_string[i] = toupper(file_to_string[i]);
    }

    //printing new file contents
    printf("\n-> New text file contents:\n%s\n", file_to_string);

    //overwriting new text to file
    rewind(text_file);
    fprintf(text_file, "%s", file_to_string);
    rewind(text_file);

//2.) REMOVING LINE BY LINE NUMBER

    //prompting for line to remove
    int line_number = 0;
    printf("\nEnter the line number of the line you would like to delete from the file:%sLine Number: ", LINE_BREAK);
    scanf("%d", &line_number);

    //creating file for text without specified line
    char current_char;
    int char_counter = 0;
    int current_line_number = 0;
    FILE *final_text = fopen("final.txt", "w+");

    //coping text from initial to final excluding the specified line
    for (int i = 0; i < length; i++)
    {
        current_char = fgetc(text_file);

       if (current_char == '\n')
       {
           current_line_number++;
       }

        if (current_line_number == line_number)
        {
            while (*text_file->_ptr != '\n')
            {
                text_file->_ptr++;
            }
            current_line_number++;
        }
        else
        {
            file_to_string[char_counter] = current_char;
            char_counter++;
        }
    }//for
    rewind(text_file);
    file_to_string[char_counter + 1] = '\0';

    //printing final text file
    fprintf(final_text, "%s", file_to_string);
    printf("-> Your final text file omitting the specified line is: \n%s\n", file_to_string);

    //closing file
    fclose(final_text);

//12.4 - displaying the size of a given file in bytes
    //checking that file exists
    FILE* test_file = fopen("Dookie.txt", "r");
    if (test_file != NULL)
    {
        //calculating length of file
        fseek(test_file, 1, SEEK_END);
        length = ftell(test_file);

    //display size of file in bytes
    printf("The size of the file above in bytes is %d", length);

    }//checking if file exists
    else
        {
            printf("File does not Exist");
        }


}//main
