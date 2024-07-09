#include <stdio.h>
#include <stdlib.h>


void showReminders(){


    // file to save details.
    FILE *filePtr;

    int reminderNO = 1;

    char reminder[300]; // length of the line fo a reminder.

    if((filePtr = fopen("Metrix.txt", "r"))== NULL)
        {

            printf("\nNo reminders yet!\n");
            filePtr = fopen("Metrix.txt", "w");
        }

    else
        {
            while(fgets(reminder, 300, filePtr))
            {
                printf("%d)  %s", reminderNO, reminder);
                reminderNO += 1;
            }
    }


    fclose(filePtr);
}

void saveThereminder(char *reminder)
{

    FILE *fileptr;

    fileptr = fopen("Metrix.txt", "a");

    fprintf(fileptr,"%s\n",reminder);

    fclose(fileptr);
}

int main()
{

    // operation1 - add reminders/ exit the program.
    // operation2 - save and exit/ discard and exit.
    char operation1, operation2;

    char subject[50], assignmentTitle[100], closingDate[50], closingTime[50], reminder[300];


    // Display welcome statement.
   // printf("\nWelocome to Metrix assignment remind system!\n\n");


   printf("\t\t\t........... WELCOME METRIX.................\t\t\n\n\n");


        printf("...................................................................................................................\n\n\n");


        printf("\t\t*************************************************\n");
        printf("\t\t*                                               *\n");
        printf("\t\t*                                               *\n");
        printf("\t\t*       -----------------------------           *\n");
        printf("\t\t*      METRIX Assignment Reminder System        *\n");
        printf("\t\t*       -----------------------------           *\n");
        printf("\t\t*                                               *\n");
        printf("\t\t*                                               *\n");
        printf("\t\t*                                               *\n");
        printf("\t\t*                                               *\n");
        printf("\t\t*************************************************\n");
        printf("\t\t\n");

         printf("...................................................................................................................\n\n\n");


        printf("No   Sub   Title\t\t  time\n");
        showReminders();

// Display upcoming events.
    //showReminders();

    // Ask to add a reminder or exit the program.


    printf("\n");
    printf("\t\tPress 'A' to add new reminders, Press 'x' to exit:\n ");
    scanf("%c", &operation1);

    if( operation1 == 'A')
        {

        printf("\nAdd your reminder details.\n");

        printf("Input Subject Name: ");
        scanf("%s", subject);
        getchar();

        printf("Input Assignment title: ");
        fgets(assignmentTitle, 100, stdin);

        printf("Input Closing Date and Time[(dd/mm/yyyy) (hh.mm.am/pm)]: ");
        scanf("%s %s",closingDate, closingTime );

        getchar(); // To flush out the new line character from above input.


        // Remove the attached new-line character from fgets.

        assignmentTitle[strlen(assignmentTitle) - 1] = '\0';

        // put data in a one-line.

        strcat(reminder, subject);
        strcat(reminder, " \t ");
        strcat(reminder, assignmentTitle);
        strcat(reminder, " \t ");
        strcat(reminder, closingDate);
        strcat(reminder, " ");
        strcat(reminder, closingTime);

        printf("\n %s \n\n", reminder);

        printf("Press 'S' to save and exit, Press 'X' to discard and exit: ");
        scanf("%c", &operation2);

        if(operation2 == 'S')
            {
                // Save and exit
                saveThereminder(reminder);
            }

        else if(operation2 == 'X')
            {
                // discard and return to home-screen.
            }
    }

    else if(operation1 == 'X')
        {

            printf("Have a nice day!\n");
            return 0;
        }

    else
        {
            //show the reminders
        }


}
