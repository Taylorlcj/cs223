/* -----------------------------------------------
   Submitted By: <Taylor Jensen>
   Homework Number: <4>
    Credit to:
       <Taylor Jensen>
   Submitted On: <7/15/22>
   By submitting this program with my name,
   I affirm that the creation and modification
         of this program is primarily my own work.
 ------------------------------------------------ */
// include files
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
/* function to generate and return random numbers */
int* getRandom()
{
   static int r[21] = {0};
   int i = 0;
   /* set the seed */
   srand( (unsigned)time( NULL ) );
   for ( i = 0; i < 21; ++i) {
      //r[i] = rand();
      r[i] = rand() % (99 + 1 - 1) + 0;
   }
   return r;
}
bool isValid(int x,int y,int z)
{
    //side 1 + side 2 > side 3 for validity
    if (x + y <= z)
    {
        return false;
    }
    if (z + y <= x)
    {
        return false;
    }
    if (z + x <= y)
    {
        return false;
    }
    return true;
}
/*if valid print all 3 numbers and
calculate area of that triangle*/
double calcArea(int x, int y, int z)
{
    double s  = 0.0;
    double area = 0.0;
    s = (x+y+z)/2;
    area = sqrt(s*(s-x)*(s-y)*(s-z));
    return area;
}
/* main function to call above defined function */
int main () {
   /* a pointer to an int */
    int *p;
    int i = 0;
    bool iv = false;
    p = getRandom();
    double area;
    for(i = 0 ; i < 7; i++)
    {
        iv = isValid(p[i], p[i+1], p[i+2]);
        if (iv == true)
        {
            printf("The sides are: %d %d %d\n", p[i], p[i+1], p[i+2]);
            area = calcArea(p[i* 3], p[i* 3 + 1], p[i* 3 + 2]);
            printf("The Area is: %0.2lf\n\n", area);
        }
    }
    return 0;
}
