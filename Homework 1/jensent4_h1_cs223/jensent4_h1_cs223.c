/* -----------------------------------------------
   Submitted By: <Taylor Jensen>
   Homework Number: <1>
    Credit to:
       <Taylor Jensen>
   Submitted On: <6/29/22>

   By submitting this program with my name,
   I affirm that the creation and modification
         of this program is primarily my own work.
 ------------------------------------------------ */

// include files
#include <stdio.h>  // for printf(), scanf()
#include <stdlib.h> //for system()

/* this program asks the user for measurements of a triangle, rectangle, circle, and sphere
and then give the users the area and volume of each */

int main(void) {

    printf("Taylor Jensen \n"); //prints my name

//Triangle
    double triBase, triHeight, triArea;                          //creates triangle base, height and triangle area variables
    printf("What is the base of your triangle? ");
    scanf("%lf", &triBase);                                      //saves whatever the user inputs as a float for the variable triBase
    printf("What is the height of your triangle? ");
    scanf("%lf", &triHeight);
    triArea = 0.5 * triBase * triHeight;                        // calculates the area of the triangle
    printf("The area of your triangle is %0.2f.\n", triArea);   //prints the area of the triangle
                                                                // "%0.2f" causes the output to print with 2 digits after the decimal point

//Rectangle
    double rectWidth, rectLength, rectArea;
    printf("What is the width of your rectangle? ");
    scanf("%lf", &rectWidth);
    printf("What is the length of your rectangle? ");
    scanf("%lf", &rectLength);
    rectArea = rectWidth * rectLength;
    printf("The area of your rectangle is %0.2f.\n", rectArea);

//Circle
    double circRadius, circArea;
    double pi = 3.14;
    printf("What is the radius of your circle? ");
    scanf("%lf", &circRadius);
    double rSquared = pow(circRadius, 2);                        //squares the radius of the circle
    circArea = rSquared * pi;
    printf("The area of your circle is %0.2f.\n", circArea);

//Sphere
    double sphereRadius, sphereVolume;
    printf("What is the radius of your sphere? ");
    scanf("%lf", &sphereRadius);
    double rCubed = pow(sphereRadius, 3);                        //cubes the radius of the circle
    sphereVolume = ( 4 * rCubed * pi) / 3.0;
    printf("The volume of your sphere is %0.2f.\n", sphereVolume);

  return 0;
}
