#include <stdio.h>
#include <string.h>

#define MAX 50
#define SUBJECTS 3

int main()
{
    char names[MAX][50];
    int marks[MAX][SUBJECTS];
    int count = 0;
    int choice, i, j;
    int total;
    int topper;
    float average[MAX];
    char searchName[50];
    int found;

    do
    {
        printf("\n===== STUDENT MARKS MANAGER =====\n");
        printf("1. Add Student\n");
        printf("2. Student Report\n");
        printf("3. Topper\n");
        printf("4. Search Student\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                if(count >= MAX)
                {
                    printf("List full\n");
                    break;
                }

                printf("Enter student name: ");
                scanf(" %49[^\n]", names[count]);

                for(j = 0; j < SUBJECTS; j++)
                {
                    do
                    {
                        printf("Enter subject %d mark (0-100): ", j + 1);
                        scanf("%d", &marks[count][j]);

                        if(marks[count][j] < 0 ||
                           marks[count][j] > 100)
                        {
                            printf("Invalid mark! Enter again.\n");
                        }

                    } while(marks[count][j] < 0 ||
                            marks[count][j] > 100);
                }

                count++;

                printf("Student added successfully!\n");
                break;

            case 2:

                if(count == 0)
                {
                    printf("No data\n");
                    break;
                }

                printf("\n===== STUDENT REPORT =====\n");

                for(i = 0; i < count; i++)
                {
                    total = 0;

                    for(j = 0; j < SUBJECTS; j++)
                    {
                        total += marks[i][j];
                    }

                    average[i] = total / 3.0;

                    printf("\nName: %s\n", names[i]);
                    printf("Total: %d\n", total);
                    printf("Average: %.2f\n", average[i]);

                    if(average[i] >= 90)
                        printf("Grade: A\n");
                    else if(average[i] >= 75)
                        printf("Grade: B\n");
                    else if(average[i] >= 50)
                        printf("Grade: C\n");
                    else
                        printf("Grade: F\n");
                }

                break;

            case 3:

                if(count == 0)
                {
                    printf("No data\n");
                    break;
                }

                topper = 0;

                for(i = 0; i < count; i++)
                {
                    total = 0;

                    for(j = 0; j < SUBJECTS; j++)
                    {
                        total += marks[i][j];
                    }

                    average[i] = total / 3.0;

                    if(average[i] > average[topper])
                    {
                        topper = i;
                    }
                }

                printf("\n===== TOPPER =====\n");
                printf("Name: %s\n", names[topper]);
                printf("Average: %.2f\n", average[topper]);

                break;

            case 4:

                if(count == 0)
                {
                    printf("Not found\n");
                    break;
                }

                printf("Enter student name to search: ");
                scanf(" %49[^\n]", searchName);

                found = 0;

                for(i = 0; i < count; i++)
                {
                    if(strcmp(names[i], searchName) == 0)
                    {
                        printf("Student Found!\n");
                        printf("Name: %s\n", names[i]);

                        for(j = 0; j < SUBJECTS; j++)
                        {
                            printf("Subject %d: %d\n",
                                   j + 1, marks[i][j]);
                        }

                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("Not found\n");
                }

                break;

            case 5:

                printf("Thank you! Program exited.\n");
                break;

            default:

                printf("Invalid menu choice!\n");
        }

    } while(choice != 5);

    return 0;
}
    
