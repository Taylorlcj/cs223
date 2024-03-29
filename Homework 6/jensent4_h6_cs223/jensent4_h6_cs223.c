/* -----------------------------------------------
   Submitted By: <Taylor Jensen>
   Homework Number: <6>
    Credit to:
       <Taylor Jensen>
   Submitted On: <7/25/22>

   By submitting this program with my name,
   I affirm that the creation and modification
         of this program is primarily my own work.
 ------------------------------------------------ */
// include files
#include <stdio.h>
#include <string.h>

/* This program requires the user to input the correct password. If they do not, it keeps
asking the user until they give it the password. When the password is correct, the user
will be asked to write a string that is less than 30 characters and the program will output
its length, the quote itself, and how many of the letter 'E' or 'e' there is. */

/* NOTE: I could not declare int count or int length up at the top because when i did the
program would not run and it would not work no matter how many different ways I tried it*/

/* NOTE: I did not have the program repeat if the user didnt input
a string in between 0 and 31 characters as the description just said,
"assume the user enters a string that is less than 30 characters" */

// counts the amount of 'E's and 'e' in the string
int countChar(char s[],int length)
{
    int x,i;
    for(i = 0; i<length; i++)
    {
        if(s[i] == 'e' || s[i] == 'E')
        {
        x++;
        }
    }
return x;
}

int main()
{
    char password[50] = "\0";
    char str[50] = "\0";
    printf("Taylor Jensen\n");
    printf("Enter the secret password: ");
    gets(password); // takes the password

    // continue asking until user enters valid password
    while(strcmp(password,"space") != 0 )
    {
        printf("Wrong code! Enter again: ");
        gets(password);
    }
    printf("Enter a string less than 30 characters\n");
    gets(str);
    int length = strlen(str); //finds the length of the string
    if (length>30 || length<1) // makes sure string length is correct
    {
        printf("\nString must be less than 30 characters and above 0 characters!\n");
    }
    else
    {
        int count = countChar(str,length);
        printf("The length of your string: %d\n",length);
        printf("Your string: %s\n",str);
        printf("The letter 'E' or 'e' appeared %d times\n",count);
    }
    return 0;
}
