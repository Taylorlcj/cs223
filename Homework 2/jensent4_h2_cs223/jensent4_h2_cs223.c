/* -----------------------------------------------
   Submitted By: <Taylor Jensen>
   Homework Number: <2>
    Credit to:
       <Taylor Jensen>
   Submitted On: <7/4/22>

   By submitting this program with my name,
   I affirm that the creation and modification
         of this program is primarily my own work.
 ------------------------------------------------ */
// include files
#include <stdio.h>
#include <stdlib.h>
/*This program simulates a simple ATM machine, allowing the user to deposit
money, withdraw money, check their balance and exit the machine*/


int main(void)
{
    printf("Taylor Jensen\n");

    // variables
    double balance = 1000.00;
    double deposit, withdraw;
    int choice;

    printf("Welcome to Taylors Bank!\nYour balance is 1000.00$\n");

    while (1){ // loops the switch construct
        printf("\n[1] Make a Deposit\n");
        printf("[2] Make a Withdrawal\n");
        printf("[3] Check Balance\n");
        printf("[4] Exit\n");
        printf("Please select an option above\n");
        scanf("%d", &choice);

        switch(choice){  //gives an output dependent on the users input

        case 1:
            printf("How much would you like to deposit?\n");
            scanf("%lf", &deposit);
            double BD = balance + deposit; //post deposit balance
            printf("Your balance is now: %0.2lf$\n", BD);
            break;

        case 2:
            printf("How much would you like to withdraw?\n");
            scanf("%lf", &withdraw);
            double BDW = balance + deposit - withdraw; //post withdraw balance
            if (BDW < 50 && BDW >= 0){
                printf("Be careful, balance is: %0.2lf$\n", BDW);
            }
            if (BDW < 0)
            {
                printf("No sufficient funds available\n");
            }
            else{
                printf("Here is your money!\n");
            }
            break;

        case 3:
            if (BD < balance && BD > BDW){
                printf("Your balance is: %0.2lf$\n",balance);
            }
            else{
                printf("Your  Balance is: %0.2lf$\n", BDW);
            }
            break;

        case 4:
            printf("WE HOPE YOU HAD A SMOOTH ENCOUNTER!\n");
            return 0;

        default:
            printf("Invalid option selected. Please input the number of the option you would like.\n");
            break;
        }
    }
}
