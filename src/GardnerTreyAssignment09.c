/*Name: Trey Gardner
Class: CS2060 (M/W)
Due: 04-02-25
Description: This program will:
9.1: find the highest and lowest values in an integer array (using a function)
9.2: find the number of values in a given string (using a function)
9.3: demonstrate returning a string from a function
    9.3.1 - return a constant string literal (pointer)
    9.3.2 - return a modifiable string literal (pointer) - prove it is modifiable
    9.3.3 - returns and invalid char array (non-static local array) - undefined behavior
9.4: find a target value in an array of integers (return the pointer of the target value or null)
9.5: do 4 different types of unit conversions
9.6: provides and operation that allows you to perform either and uppercase or lowercase conversion on a given string
9.7: (9.5.1) extend the functionality of the unit conversions functions to an array allowing for selection by index
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//function prototypes
void highest_and_lowest_values(int[], int, int*, int*);
int counting_vowels(char[]);
const char* static_message();
char* modifiable_message();
char* invalid_return_type();
int* int_search(int[], int, int);
int kilometers_to_miles(int);
int kilograms_to_pounds(int);
int celsius_to_fahrenheit(int);
int liters_to_gallons(int);
void string_operation(char str[], void (*callback)(char[]));
void to_lowercase(char str[]);
void to_uppercase(char str[]);

//main
int main()
{
//9.1 - finding the highest and lowest integer
printf("\n-------------------------------------------------------\n");
printf("Finding the highest and lowest integer in a given array\n");
printf("-------------------------------------------------------\n");

int highest_value = 0;
int lowest_value = 0;
//creating array
const int int_array[] = {13, 24, 52, 1, 3, 5, 6};
int size = sizeof(int_array) / sizeof(int);

//calling function
highest_and_lowest_values(int_array, size, &highest_value, &lowest_value);

//displaying output:
printf("\nWithin the array of: 13, 24, 52, 1, 3 ,5, and 6");
printf("\nThe highest value in the array is: %d\n", highest_value);
printf("The lowest value in the array is: %d\n", lowest_value);

//9.2 - counting vowels in a string
printf("\n--------------------------------------------------------------------------------");
printf("\nCounting the number of vowels in a given string: \"CS2060 is taught by Doug Miller\"\n");
printf("--------------------------------------------------------------------------------\n\n");

//creating array
char test_string[] = "CS2060 is taught by Doug Miller";

//calling function
int number_of_vowels = counting_vowels(test_string);

//displaying output
printf("The number of vowels in the string \'%s\' is: %d\n", test_string, number_of_vowels);

//9.3 - demonstrating returning a string from a function
printf("\n-------------------------------------------------------\n");
printf("Returning various different types of strings literals: \n");
printf("-------------------------------------------------------\n\n");
printf("Static Message: %s\n", static_message());
printf("Modifiable Message: %s\n", modifiable_message());
//printf("Invalid Return Type: %s\n", invalid_return_type());
  //when returning the pointer to the local array, the array decays into just a pointer, and when the program reenters main
  //the program leaves the scope of the function, and the memory location that is passed is not longer the string literal

//9.4 - searching for a specific integer
printf("\n---------------------------------------------\n");
printf("Find an integer within the given array above: \n");
printf("----------------------------------------------\n\n");

int target = 0;
//prompting user
printf("Enter the number you are looking for: \n");
scanf("%d", &target);

//calling method
int* search_result = int_search(int_array, size, target);

//printing results
if(search_result != NULL)
{
  long index = search_result - int_array;
  printf("The target value %d was found @ index: %ld in the given array\n", target, index);
}
else
{
  printf("the target value %d wasn't found\n", target);
}

//9.5 - user input unit conversion
printf("\n--------------------------------\n");
printf("Offering 4 different coversions!\n");
printf("--------------------------------\n");

char kilometers_conversion[] = "KM";
char kilograms_conversion[] = "KP";
char celsius_conversion[] = "CF";
char liters_conversion[] = "LG";
int user_conversion_value = 0;
char user_conversion_type[2];
bool valid_response = false;
int converted_value = 0;

while(valid_response == false)
{
  printf("Choose which coversion you want to do:\n");
  printf("For Coverting Kilometers to Meters: Enter \"KM\"\nFor Converting Kilograms to Pounds: Enter \"KP\"\nFor Converting from Celsius to Fahrenheit: Enter \"CF\"\nFor Converting from Liters to Gallons Enter: \"LG\"");
  printf("\nEnter your conversion choice: ");
  scanf("%s", user_conversion_type);

    //Kilometers to Miles
    if(strcmp(user_conversion_type, kilometers_conversion) == 0)
    {
        printf("Enter your length in kilometers: ");
        scanf("%d", &user_conversion_value);
        converted_value = kilometers_to_miles(user_conversion_value);
        printf("Your length converted into miles is: %d\n", converted_value);
        valid_response = true;
    }

    //Kilograms to Pounds
    else if(strcmp(user_conversion_type, kilograms_conversion) == 0)
    {
        printf("Enter your weight in Kilograms: ");
        scanf("%d", &user_conversion_value);
        converted_value = kilograms_to_pounds(user_conversion_value);
        printf("Your weight converted into pounds is: %d\n", converted_value);
        valid_response = true;
    }

    //Celsius to Fahrenheit
    else if(strcmp(user_conversion_type, celsius_conversion) == 0)
    {
        printf("Enter your temperature in Celsius: ");
        scanf("%d", &user_conversion_value);
        converted_value = celsius_to_fahrenheit(user_conversion_value);
        printf("Your temperature converted into Fahrenheit is: %d\n", converted_value);
        valid_response = true;
    }

    //Liters to Gallons
    else if(strcmp(user_conversion_type, liters_conversion) == 0)
    {
        printf("Enter your volume in Liters: ");
        scanf("%d", &user_conversion_value);
        converted_value = liters_to_gallons(user_conversion_value);
        printf("Your volume converted into Gallons is: %d\n", converted_value);
        valid_response = true;
    }
    else
    {
    printf("Please enter a valid conversion type\n");
    }

}//Conversion Loop

//clearing input buffer
  while (getchar() != '\n')
    continue;

//9.6 - string operation

//asking for string to operate on
int operation_type;
char operative_string[50];
char buffer;
printf("Please enter a string that you would like to operate on: ");
scanf("%[^\n]s", operative_string);

//clear input buffer
while (getchar() != '\n')
  continue;

//calling function
valid_response = false;
while(valid_response == false)
{
  printf("\nChoose a conversion\nTo convert to uppercase, Enter: \"1\"\nTo convert to lowercase, Enter: \"2\"");
  printf("\nEnter your conversion choice: ");
  scanf("%d", &operation_type);

  switch(operation_type)
    {
      case 1:
        string_operation(operative_string, &to_uppercase);
        printf("Your new string is: %s", operative_string);
        valid_response = true;
        break;
      case 2:
        string_operation(operative_string, &to_lowercase);
        printf("Your new string is: %s", operative_string);
        valid_response = true;
        break;

      default:
        printf("\nPlease enter a valid conversion type\n");
        break;
    }//switch
}//while

//9.7 - 9.5.1 streamlining the operation selection process
//creating array
int conversion_type = 0;
int (*function_array[])(int) = {&kilometers_to_miles, &kilograms_to_pounds, &celsius_to_fahrenheit, &liters_to_gallons};
valid_response = false;

//streamlined system
printf("\n---------------------------------------------------------------------------\n");
printf("We have a new, streamlined system for handling unit conversions to try out!");
printf("\n---------------------------------------------------------------------------\n");
printf("\nNow simply choose from: \n\'0\' for converting from Kilometers to Miles\n\'1\' for converting from Kilograms to pounds\n\'2\' for converting from Celsius to Fahrenheit\nOR\n\'3\'for converting from Liters to Gallons");
//selection loop
while(valid_response == false)
{
    printf("\nPlease select the conversion that you would like to perform: ");
    scanf("%d", &conversion_type);

    switch(conversion_type)
    {
      case 0:
        printf("Enter your length in kilometers: ");
        scanf("%d", &user_conversion_value);
        converted_value = function_array[0](user_conversion_value);
        printf("Your length converted into miles is: %d\n", converted_value);
        valid_response = true;
        break;

      case 1:
        printf("Enter your weight in Kilograms: ");
        scanf("%d", &user_conversion_value);
        converted_value = function_array[1](user_conversion_value);
        valid_response = true;
        printf("Your weight converted into pounds is: %d\n", converted_value);
        break;

      case 2:
        printf("Enter your temperature in Celsius: ");
        scanf("%d", &user_conversion_value);
        converted_value = function_array[2](user_conversion_value);
        valid_response = true;
        printf("Your temperature converted into fahrenheit is: %d\n", converted_value);
        break;

      case 3:
        printf("Enter your volume in Gallons: ");
        scanf("%d", &user_conversion_value);
        converted_value = function_array[3](user_conversion_value);
        valid_response = true;
        printf("Your volume converted into Liters is: %d\n", converted_value);
        break;

      default:
        printf("Please enter a valid conversion type\n");
        break;
   }//switch
}//while
}//main

//finding both the highest and lowest value in an integer array
void highest_and_lowest_values(int int_array[], int size, int* highest_value, int* lowest_value)
{
  //setting both starting points as the initial value
  *highest_value = int_array[0];
  *lowest_value = int_array[0];

    for(int i = 1; i < size; i++)
    {
      //assigning the largest value while iterating through array
      if(int_array[i] > *highest_value)
      {
       *highest_value = int_array[i];
      }

      //assigning the lowest value while iterating through array
      if(int_array[i] < *lowest_value)
      {
       *lowest_value = int_array[i];
      }

    }
}

//counting vowels in a given string
int counting_vowels(char string[])
{
  int vowel_count = 0;
  for(int i = 0; i < strlen(string); i++)
  {
    if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'u'
       || string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'U')
      {
       vowel_count++;
      }
  }
  return vowel_count;
}

//returning an unmodifiable string literal
const char* static_message()
{
 const char* message = "Hello World!";
 return message;
}

//returning a modifiable string literal
char* modifiable_message()
{
 static char* message = "Hello World!";
 return message;
}

//returning a string literal that escapes its scope
char* invalid_return_type()
{
char message[] = "Hello World!";
return &message;
}

//searching for a target value in an array of integers
int* int_search(int int_array[], int size, int target)
{
  for(int i = 0; i < size; i++)
  {
    if(int_array[i] == target)
    {
      return &int_array[i];//returning found value
    }
  }
return NULL;//returning NULL if value is not found
}

//converting from kilometers to miles
int kilometers_to_miles(int kilometers)
{
int miles = kilometers * 0.621371;
return miles;
}

//converting from kilograms to pounds
int kilograms_to_pounds(int kilograms)
{
int pounds = kilograms * 2.20462;
return pounds;
}

//converting from celcius to fahrenheit
int celsius_to_fahrenheit(int celsius)
{
int fahrenheit = (celsius * 9/5.0) + 32;
return fahrenheit;
}

//converting from liters to gallons
int liters_to_gallons(int liters)
{
int gallons = liters * 0.264172;
return gallons;
}

//performing either upper or lowercase conversion using callback
void string_operation(char str[], void callback())
{
 (*callback)();
}

//converting all letters to lowercase
void to_lowercase(char str[])
{
  for(int i = 0; i < strlen(str); i++)
  {
    if(str[i] >= 'A' && str[i] <= 'Z')
    {
      str[i] = str[i] + 32;
    }
  }
}

//converting all letters to uppercase
void to_uppercase(char str[])
{
  for(int i = 0; i < strlen(str); i++)
  {
    if(str[i] >= 'a' && str[i] <= 'z')
    {
      str[i] = str[i] - 32;
    }
  }
}
