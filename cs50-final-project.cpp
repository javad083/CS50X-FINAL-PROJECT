#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef struct Student
{
    char studentName[101];
    int studentAge;
    char studentID[20];
    char studentEmail[101];
    char studentContactNumber[20];
    float studentGPA;
};

void cls()
{
    system("cls");
}

void createRecord()
{
    FILE *fp = fopen("studentrecord.bin", "ab+");
    if(fp == NULL)
    {
        printf("\n\n\tError in opening file..");
        exit(1);
    }
    Student studentInformation;
    cls();
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t|____________________|"
           "\n\t\t\t\t\t|                    |"
           "\n\t\t\t\t\t|\tWelcome      |"
           "\n\t\t\t\t\t|____________________|"
           "\n\t\t\t\t\t|\t\t     |\n\n\n");

    getch();
    cls();
    printf("\t\t\t===== CREATE A STUDENT ACCOUNT =====\n");

    printf("\n\t\t\tEnter Student's Name: ");
    scanf("%[^\n]", studentInformation.studentName);
    getchar();
    printf("\t\t\tEnter Student's Age: ");
    scanf("%d", &studentInformation.studentAge);
    getchar();
    printf("\t\t\tEnter Student's ID: ");
    scanf("%[^\n]", studentInformation.studentID);
    getchar();
    printf("\t\t\tEnter Student's Email: ");
    scanf("%[^\n]", studentInformation.studentEmail);
    getchar();
    printf("\t\t\tEnter Student's Contact Number: ");
    scanf("%[^\n]", studentInformation.studentContactNumber);
    getchar();
    printf("\t\t\tEnter Student's GPA: ");
    scanf("%f", &studentInformation.studentGPA);
    getchar();

    fwrite(&studentInformation, sizeof(Student), 1, fp);

    printf("\n\n\t\t\tData stored successfully..\n");
    printf("\n\n\t\t\tPress any key to continue..");
    getch();

    fclose(fp);
}

void displayRecord()
{
    FILE *fp = fopen("studentrecord.bin", "rb");
    if(fp == NULL)
    {
        printf("\n\n\tError in opening file..");
        exit(1);
    }
    Student studentInformation;
    cls();
    printf("\t\t\t\t====== All Students Information ======\n");

    printf("\n\n\t\t%-20s%-5s%-25s%-15s%-s\n", "Name", "Age", "Email", "Contact", "GPA");
    printf("\t\t----------------------------------------------------------------------------------------");

    while (fread(&studentInformation, sizeof(studentInformation), 1, fp) == 1)
    {
        printf("\n\n\t\t%-20s%-5d%-25s%-15s%-.2f",
               studentInformation.studentName, studentInformation.studentAge,
               studentInformation.studentEmail, studentInformation.studentContactNumber,
               studentInformation.studentGPA);
    }

    printf("\n\n\t\tEnter any keys to continue.......");
    getch();

    fclose(fp);
}

void updateRecord()
{
    FILE *fp = fopen("studentrecord.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Student studentInformation, tempInformation;
    int choice;
    int count = 0;
    if(fp == NULL || temp == NULL)
    {
        printf("\n\n\tError in opening file..");
        exit(1);
    }
    cls();
    printf("\t\t\t\t====== UPDATE STUDENT INFORMATION ======\n");
    printf("\n\n\t\tEnter Student's ID: ");
    scanf("%[^\n]", tempInformation.studentID);
    getchar();

    while(fread(&studentInformation, sizeof(studentInformation), 1, fp) == 1)
    {
        if(strcmp(studentInformation.studentID, tempInformation.studentID) == 0)
        {
            count = count + 1;
            printf("\n\t\t\tChoose your option: \n\t\t\t1. Update Student Name\n\t\t\t2. Update Student Age\n\t\t\t3. Update Student Email\n\t\t\t4. Update Student Contact Number\n\t\t\t5. Update Student GPA");
            printf("\n\n\t\t\tEnter your option: ");
            scanf("%d", &choice);
            if(choice == 1)
            {
                printf("\n\t\t\tEnter Student's Name to Update: ");
                scanf("%s", tempInformation.studentName);
                getchar();
                strcpy(studentInformation.studentName, tempInformation.studentName);
                //write to file
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tData updated successfully..\n");
            }
            else if(choice == 2)
            {
                printf("\n\t\t\tEnter Student's Age to Update: ");
                scanf("%d", &tempInformation.studentAge);
                getchar();
                studentInformation.studentAge = tempInformation.studentAge;
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tData updated successfully..\n");
            }
            else if(choice == 3)
            {
                printf("\n\t\t\tEnter Student's Email to Update: ");
                scanf("%[^\n]", tempInformation.studentEmail);
                getchar();
                strcpy(studentInformation.studentEmail, tempInformation.studentEmail);
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tData updated successfully..\n");
            }
            else if(choice == 4)
            {
                printf("\n\t\t\tEnter Student's Contact Number to Update: ");
                scanf("%[^\n]", tempInformation.studentContactNumber);
                getchar();
                strcpy(studentInformation.studentContactNumber, tempInformation.studentContactNumber);
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tData updated successfully..\n");
            }
            else if(choice == 5)
            {
                printf("\n\t\t\tEnter Student's GPA to Update: ");
                scanf("%f", &tempInformation.studentGPA);
                getchar();
                studentInformation.studentGPA = tempInformation.studentGPA;
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tData updated successfully..\n");
            }
            else
            {
                printf("\n\n\t\t\tInvalid option..\n");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
        }
    }
    fclose(fp);
    fclose(temp);

    remove("studentrecord.bin");
    rename("temp.bin", "studentrecord.bin");
    if(count == 0)
    {
        printf("\n\n\t\t\tNo record found..\n");
    }

    printf("\n\n\t\t\tPress any key to continue..");
    getch();
}

void deleteRecord()
{
    FILE *fp = fopen("studentrecord.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");
    Student studentInformation, tempInformation;
    int choice;
    int count = 0;
    if(fp == NULL || temp == NULL)
    {
        printf("\n\n\tError in opening file..");
        exit(1);
    }
    cls();
    printf("\t\t\t\t====== DELETE STUDENT INFORMATION ======\n");
    printf("\n\t\t\tEnter Student's ID: ");
    scanf("%[^\n]", tempInformation.studentID);
    getchar();
    while(fread(&studentInformation, sizeof(studentInformation), 1, fp) == 1)
    {
        if(strcmp(studentInformation.studentID, tempInformation.studentID) == 0)
        {
            count = count + 1;
            printf("\n\t\t\tAre you sure want to remove this record?"
                   "\n\t\t\t1. Yes\n\t\t\t2. Go Back"
                   "\n\t\t\t\tEnter your option: ");
            scanf("%d", &choice);
            if(choice == 1)
            {
                printf("\n\t\t\tRecord deleted successfully..\n");
            }
            else if(choice == 2)
            {
                printf("\n\t\t\tGoing back to main menu..\n");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
            else
            {
                printf("\n\n\t\t\tInvalid option..\n");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("studentrecord.bin");
    rename("temp.bin", "studentrecord.bin");
    if(count == 0)
    {
        printf("\n\n\t\t\tNo record found..\n");
    }
    printf("\n\n\t\t\tPress any key to continue..");
    getch();
}

void searchRecord()
{
    FILE *fp = fopen("studentrecord.bin", "rb");
    Student studentInformation;
    int choice;
    int count = 0;
    char studentID[20], studentEmail[20];
    if(fp == NULL)
    {
        printf("\n\n\tError in opening file..");
        exit(1);
    }
    cls();
    printf("\t\t\t\t====== SEARCH STUDENT INFORMATION ======\n");
    printf("\n\t\t\tChoose your option: \n\t\t\t1. Search by ID\n\t\t\t2. Search by Email\n\t\t\t");
    printf("\n\n\t\t\tEnter your option: ");
    scanf("%d", &choice);
    getchar();
    if(choice == 1)
    {
        cls();
        printf("\t\t\t\t====== SEARCH STUDENT INFORMATION ======\n");
        printf("\n\t\t\tEnter Student's ID: ");
        scanf("%[^\n]", studentID);
        getchar();
        while(fread(&studentInformation, sizeof(studentInformation),1 , fp) == 1)
        {
            if(strcmp(studentInformation.studentID, studentID) == 0)
            {
                count = count + 1;
                printf("\n\t\t\tStudent's ID: %s\n", studentInformation.studentID);
                printf("\t\t\tStudent's Name: %s\n", studentInformation.studentName);
                printf("\t\t\tStudent's Age: %d\n", studentInformation.studentAge);
                printf("\t\t\tStudent's Email: %s\n", studentInformation.studentEmail);
                printf("\t\t\tStudent's Contact Number: %s\n", studentInformation.studentContactNumber);
                printf("\t\t\tStudent's GPA: %.2f\n", studentInformation.studentGPA);
            }
        }
        if(count == 0)
        {
            printf("\n\n\t\t\tNo record found..\n");
        }
    }
    else if(choice == 2)
    {
        cls();
        printf("\t\t\t\t====== SEARCH STUDENT INFORMATION ======\n");
        printf("\n\t\t\tEnter Student's Email: ");
        scanf("%[^\n]", studentEmail);
        getchar();
        printf("\n\n\t\t%-20s%-2d%-10s%-25s%-.2f%-\n", "Name", "Age", "Email", "Contact", "GPA");
        printf("\t\t----------------------------------------------------------------------------------------");
        while(fread(&studentInformation, sizeof(studentInformation), 1, fp) == 1)
        {
            if(strcmp(studentInformation.studentEmail, studentEmail) == 0)
            {
                count = count + 1;
                printf("\n\t\t%-20s%-2d%-10s%-25s%-.2f%-\n",
                       studentInformation.studentName, studentInformation.studentAge,
                       studentInformation.studentEmail, studentInformation.studentContactNumber,
                       studentInformation.studentGPA);
            }
        }
        if(count == 0)
        {
            printf("\n\n\t\t\tNo record found..\n");
        }
    }
    else
    {
        printf("\n\n\t\t\tInvalid option..\n");
    }
    fclose(fp);
    printf("\n\n\t\t\tPress any key to continue..");
    getch();
}

int main(void)
{
    system("Color 70");
    int selection;
    while(selection != 0);
    {
        cls();
        printf("\n\t\t\t\t\tStudent Database Manager\n");
        printf("\t\t\t_______________________________________________");
        printf("\n\n");
        printf("------------------------------------------------------------------------------------------");
        printf("\n\n");
        printf("\t\t\t\t1. Create a student account\n");
        printf("\t\t\t\t2. Display student record\n");
        printf("\t\t\t\t3. Update student record\n");
        printf("\t\t\t\t4. Delete student record\n");
        printf("\t\t\t\t5. Search student record.\n");
        printf("\t\t\t\t0. Exit.\n\n");
        printf("------------------------------------------------------------------------------------------");
        printf("\n\t\t\tPlease choose a number : ");
        scanf("%d", &selection);
        getchar();
        cls();

        switch(selection)
        {
            case 1:
                createRecord();
                break;
            case 2:
                displayRecord();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                searchRecord();
                break;
            case 0:
                printf("\n\t\t\t====== Thank you for using our service ======");
                break;
            default:
            printf("\n\t\t\tInvalid Option.. Please try again..\n");
        }
    }
    return 0;
}



