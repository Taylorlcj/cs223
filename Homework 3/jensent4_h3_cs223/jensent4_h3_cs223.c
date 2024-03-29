/* -----------------------------------------------
   Submitted By: <Taylor Jensen>
   Homework Number: <3>
    Credit to:
       <Taylor Jensen>
   Submitted On: <7/10/22>

   By submitting this program with my name,
   I affirm that the creation and modification
         of this program is primarily my own work.
 ------------------------------------------------ */

/* Enter the principal amount, the annual percentage yield,
and the number of months for the CD maturity period and you
will see a table that shows you the increasing value of your
deposit each month */

// include files
#include <stdio.h>
#include <stdlib.h>

double inputDeposit(void);
double inputPercentage(void);
int inputMP(void);
double formula(double deposit, double percentage);
void displayTable(double deposit, double percentage, int MP, double fa);

int main(void)
{
    printf("Taylor Jensen\n");
    double deposit; // captures inputDeposit as a variable
    double percentage;
    int MP;
    double fa;
    deposit = inputDeposit();
    percentage = inputPercentage();
    MP = inputMP();
    fa = formula(deposit, percentage);
    displayTable(deposit, percentage, MP, fa);
    return 0;
}

// functions never print
double inputDeposit(void)
{
    double deposit;
    printf("Enter the initial deposit amount: ");
    scanf("%lf", &deposit);
    while (1)
    {
        if (deposit < 1000.00 || deposit > 1000000.00)
        {
            fflush(stdin); // gets rid of the value for scanf
            printf("Please enter a value between 1000.00 and 1000000.00: ");
            scanf("%lf", &deposit);
        }
        else
        {
            break;
        }
    }
    return deposit;
}

double inputPercentage(void)
{
    double percentage;
    printf("Enter annual percentage Yield: ");
    scanf("%lf", &percentage);
    while (1)
    {
        if (percentage < 1.00|| percentage > 15.00)
        {
            fflush(stdin); // gets rid of the value for scanf
            printf("Please enter a value between 1.00 and 15.00: ");
            scanf("%lf", &percentage);
        }
        else
        {
            break;
        }
    }
    return percentage;
}

int inputMP(void)
{
    int MP;
    printf("Enter maturity period (number of months): ");
    scanf("%d", &MP);
    while (1)
    {
        if ( MP < 12 || MP > 360)
        {
            fflush(stdin); // gets rid of the value for scanf
            printf("Please enter a value between 12 and 360: ");
            scanf("%d", &MP);
        }
        else
        {
            break;
        }
    }
    return MP;
}

double formula(double deposit, double percentage)
{
    double fa;
    fa = deposit + deposit * percentage / 1200;
    return fa;
}

void displayTable(double deposit, double percentage, int MP, double fa)
{
    printf("\nInitial Deposit = $%0.2lf    ", deposit);
    printf("Yield = %0.2lf%%    ", percentage);
    printf("Period %d Months\n", MP);
    printf("\nMonth       CD Value\n");
    for (int i=1; i<MP + 1; ++i)
    {
        printf("%d          %0.2lf\n",i,fa);
        fa = fa + fa * percentage / 1200; // turns the previous Deposit into the most recent formula calculation
    }
}



