/* -----------------------------------------------
   Submitted By: <Taylor Jensen>
   Homework Number: <Final Project>
    Credit to:
       <Taylor Jensen>
   Submitted On: <8/12/22>

   By submitting this program with my name,
   I affirm that the creation and modification
         of this program is primarily my own work.
 ------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

struct user
{
    char name[20];
    char password[20];

    struct user *next;
};

struct target
{
    int ID;
    int coorX, coorY;

    int actualVelocity, actualAngle;

    struct target *next;
};

struct user *readUserDetails()
{
    FILE* fptr;
    fptr = fopen("namepass.txt", "r");

    struct user *userDetails = NULL, *currentUser = NULL;

    char name[20];
    char password[20];

    while (!feof(fptr)) {
        fscanf(fptr, "%s %s\n", name, password);

        if(userDetails == NULL)
        {
            userDetails = (struct user *)malloc(sizeof(struct user));
            currentUser = userDetails;
        }
        else
        {
            currentUser->next = (struct user *)malloc(sizeof(struct user));
            currentUser = currentUser->next;
        }

        strcpy(currentUser->name, name);
        strcpy(currentUser->password, password);

        currentUser->next = NULL;
    }

    fclose(fptr);

    return userDetails;
}

int validateUserLogin(struct user *userDetails, char *name, char *password)
{
    while(userDetails != NULL)
    {
        if(strcmp(name, userDetails->name) == 0 && strcmp(password, userDetails->password) == 0)
        {
            return 1;
        }
        userDetails = userDetails->next;
    }

    return 0;
}

struct target *generateTargets()
{
    struct target *targets = NULL, *currentTarget = NULL;

    for(int i = 0; i < 5; i++)
    {
        if(targets == NULL)
        {
            targets = (struct target *)malloc(sizeof(struct target));
            currentTarget = targets;
        }
        else
        {
            currentTarget->next = (struct target *)malloc(sizeof(struct target));
            currentTarget = currentTarget->next;
        }

        currentTarget->ID = i + 1;
        currentTarget->coorX = (rand() % (5000 - 500 + 1)) + 500;
        if(currentTarget->coorX > 3000)
            currentTarget->coorY = (rand() % (500 - 500 + 1)) + 500;
        else if(currentTarget->coorX > 2000)
            currentTarget->coorY = (rand() % (1000 - 500 + 1)) + 500;
            else if(currentTarget->coorX > 1000)
            currentTarget->coorY = (rand() % (2000 - 500 + 1)) + 500;
        else
            currentTarget->coorY = (rand() % (5000 - 500 + 1)) + 500;

        currentTarget->actualVelocity = 0;
        currentTarget->actualAngle = 0;
        //printf("%d, %d\n", currentTarget->coorX, currentTarget->coorY);

        currentTarget->next = NULL;
    }

    return targets;
}

int verifyTagetHit(struct target *targets, float coorX, float coorY)
{
    while(targets != NULL)
    {
        if(((float)targets->coorX - coorX) <= 10 && ((float)targets->coorY - coorY) <= 10)
        {
            return targets->ID;
        }
        targets = targets->next;
    }

    return 0;
}

int computeProjectileMotion(struct target *targets, float velocity, float angle, float *coorX, float *coorY)
{
    float _time = 0;
    float angleInRadian = (angle * 3.1415) / 180.0;
    float g = 9.8;
    *coorY = 0;

    while(_time <= 100 && *coorY >= 0)
    {
        *coorX = velocity * cos(angleInRadian) * _time;
        *coorY = (velocity * sin(angleInRadian) * _time) - ((g * _time * _time) / 2);

        //printf("%.0f : %.0f %.0f\n", _time, *coorX, *coorY);

        int ID = verifyTagetHit(targets, *coorX, *coorY);

        if(ID != 0)
            return ID;

        _time++;
    }

    return 0;
}
void printProjectileMotionResult(struct target *targets)
{
    struct target *currnetTargets = targets;
    int index = 1;

    printf("#ID\t\tVelocity\tAngle\tCoor X\tCoor Y\n");

    while(currnetTargets != NULL)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", currnetTargets->ID,
                (int)currnetTargets->actualVelocity, (int)currnetTargets->actualAngle,
                (int)currnetTargets->coorX, (int)currnetTargets->coorY);

        currnetTargets = currnetTargets->next;
    }
}
void printProjectileMotion(struct target *targets)
{
    float coorX, coorY;
    struct target *currnetTargets = targets;

    for(float velocity = 100; velocity < 2000; velocity++)
    {
        for(float angle = 1; angle < 90; angle++)
        {
            int ID = computeProjectileMotion(targets, velocity, angle, &coorX, &coorY);
            //printf("%d %d => %d\n", (int)velocity, (int)angle, ID);
            if(ID != 0)
            {
                //printf("%d %d => %d\n", (int)velocity, (int)angle, ID);

                currnetTargets = targets;

                while(currnetTargets != NULL && currnetTargets->ID <= ID)
                {
                    if(currnetTargets->ID == ID && currnetTargets->actualAngle == 0)
                    {
                        currnetTargets->actualVelocity = velocity;
                        currnetTargets->actualAngle = angle;
                    }

                    currnetTargets = currnetTargets->next;
                }
            }
        }
    }

    printProjectileMotionResult(targets);

}

void playGame(struct target *targets, char *name)
{
    char fileName[50];
    sprintf(fileName, "%s.txt", name);

    FILE* fptr = fopen(fileName, "w+");

    char choice[2] = {"y"};

    int ID = 1;
    float coorX, coorY;
    float velocity, angle;

    fprintf(fptr, "%s\n", name);
    fprintf(fptr, "Try #\tHit or Miss\tInitial Angle\tInitial velocity\tX coordinate\tY coordinate\n");

    printf("Welcome %s!!\n", name);

    while(ID <= 3 && choice[0] != 'n' && choice[0] != 'N')
    {
        printf("\nEnter Initial velocity : ");
        scanf("%f", &velocity);
        printf("Enter Initial angle : ");
        scanf("%f", &angle);

        if(computeProjectileMotion(targets, velocity, angle, &coorX, &coorY) != 0)
        {
            fprintf(fptr, "%d\t\thit\t\t%.0f\t\t%.0f\t\t%.0f\t\t%.0f\n", ID, angle, velocity, coorX, coorY);
            printf("Try #\tHit or Miss\tInitial Angle\tInitial velocity\tX coordinate\tY coordinate\n");
            printf("%d\t\thit\t\t%.0f\t\t%.0f\t\t%.0f\t\t%.0f\n", ID, angle, velocity, coorX, coorY);

            ID = 10;
        }
        else
        {
            fprintf(fptr, "%d\t\tmiss\t\t%.0f\t\t%.0f\t\t%.0f\t\t%.0f\n", ID, angle, velocity, coorX, coorY);
            printf("Try #\tHit or Miss\tInitial Angle\tInitial velocity\tX coordinate\tY coordinate\n");
            printf("%d\t\tmiss\t\t%.0f\t\t%.0f\t\t%.0f\t\t%.0f\n", ID, angle, velocity, coorX, coorY);

            if(ID < 3)
            {
                printf("\nDo you want to continue ? (Y / N) : ");
                scanf("%s", choice);

                ID++;
            }
        }

    }

    if(ID == 10)
    {
        printf("You won !!");
    }
    else
    {
        printf("You lose !!");

        printf("Here are the results \n");
        printProjectileMotion(targets);
    }

    fclose(fptr);
}

int main()
{
    printf("Taylor Jensen\n");
    struct user *userDetails = readUserDetails();
    char name[20] = {"leia"};
    char password[20];

    srand(time(0));

    printf("Enter UserName : ");
    scanf("%s", name);
    printf("Enter Password : ");
    scanf("%s", password);

    if(validateUserLogin(userDetails, name, password) == 0)
    {
        printf("Invalid Login Details !!");
        return 0;
    }

    struct target *targets = generateTargets();

    //printProjectileMotion(targets);

    playGame(targets, name);

    return 0;
}
