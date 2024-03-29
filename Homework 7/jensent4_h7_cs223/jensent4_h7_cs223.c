/* -----------------------------------------------
   Submitted By: <Taylor Jensen>
   Homework Number: <7>
    Credit to:
       <Taylor Jensen>
   Submitted On: <7/29/22>

   By submitting this program with my name,
   I affirm that the creation and modification
         of this program is primarily my own work.
 ------------------------------------------------ */
// include files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*This program is supposed to read a file, write
over another file using distance calculations, and print the desired output */

/* I am aware that this code is disgusting, I am having a difficult time wrapping this
around my head and am getting a tutor to help me explain it and I did what I could to
get it as close to the desired output as possible with all of the variables and everything but
I just could not figure it out. This is the best I could do*/

int main()
{
    FILE* f1;
    FILE* f2;
    char c;
    char z;
    char line[100]; // char array to store line of location .tx file
    f1 = fopen("location.txt","r"); // opening file in read mode
    if (NULL == f1)
    {
        printf("file can't be opened \n");
    }
    f2 = fopen("distance.txt","w"); // opening file in write mode
    if (NULL == f2)
    {
        printf("file can't be opened \n");
    }
    printf("Taylor Jensen\n");
    // writing header in distance.txt file
    printf("Name    X    Y    Z   Distance\n");

    while(fgets(line,100,f1)) // reading file by line
    {
        int x,y,z;
        char *word  = strtok(line," \n"); // strtok to separate out the words from line
        char name[100];
        int flag=0;
          while(word!=NULL)  // assigning values to x ,y and z
          {
              if(flag==0)
                strcpy(name,word);
              else if(flag==1)
                x = atoi(word);
              else if(flag==2)
                y = atoi(word);
              else if(flag==3)
                z = atoi(word);

              word = strtok(NULL," \n");
              flag++;
          }

          double dis = sqrt(x*x + y*y + z*z);

          // writing data to distance.txt file
          fprintf(f2,"                      %.2lf\n",dis);
    }
    fclose(f1);
    fclose(f2);
    f1 = fopen("location.txt","r");
    if (NULL == f1)
    {
        printf("file can't be opened \n");
    }
    f2 = fopen("distance.txt","r");
    if (NULL == f2)
    {
        printf("file can't be opened \n");
    }

    do {
        z = fgetc(f2);
        printf("%c", z);

        // Checking if character is not EOF.
        // If it is EOF stop reading.
    } while (z!= EOF);

    do {
    c = fgetc(f1);
    printf("%c", c);

    // Checking if character is not EOF.
    // If it is EOF stop reading.
    } while (c!= EOF);
    // Closing the files
    fclose(f1);
    fclose(f2);
}
