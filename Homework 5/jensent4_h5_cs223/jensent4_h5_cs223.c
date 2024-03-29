/* -----------------------------------------------
   Submitted By: <Taylor Jensen>
   Homework Number: <5>
    Credit to:
       <Taylor Jensen>
   Submitted On: <7/20/22>

   By submitting this program with my name,
   I affirm that the creation and modification
         of this program is primarily my own work.
 ------------------------------------------------ */
// include files
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

//constants
#define ROW 10
#define COL 3

/* This program generates 10 sets of 3 random numbers between and including 1 and 99
using a two dimensional array. Each row of the two
dimensional array represents the three sides of a single triangle. This program determines
whether the triangle is a valid triangle and if so, determines its area and displays the
row number. */

//This function determines whether the 3 sides create a valid triangle
int valid_triangle(int sideA,int sideB,int sideC)
{
    if(sideA+sideB>sideC && sideA+sideC>sideB && sideB+sideC>sideA)
    return 1;
    else
    return 0;
}

// This function calculates the area of the valid triangle
double triArea(double sideA,double sideB,double sideC)
{
    double s = (sideA+sideB+sideC)/2;
    double triArea = sqrt(s*(s-sideA)*(s-sideB)*(s-sideC));

    return triArea;
}

// This function calls back to other functions and prints out the areas of the valid triangles
int main()
{
    printf("Taylor Jensen\n");

    srand(time(0)); // Sets the seed of the random number generator used by the rand() function
    double array[ROW][COL];
    for(int row=0;row<10;row++)
    {
        for(int column=0;column<3;column++)
        {
            int triSide = rand()%100 + 1;
            array[row][column] = triSide;
        }
        int sideA = (int) array[row][0];
        int sideB = (int) array[row][1];
        int sideC = (int) array[row][2];
        if(valid_triangle(sideA,sideB,sideC)==1)
        printf("Row Number: %d   Area of triangle: %.2lf\n",row+1,triArea(array[row][0],array[row][1],array[row][2]));
    }

}
