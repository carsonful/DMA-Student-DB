//Carson Fulmer
// DMA-Student-DB

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// typedef struct
typedef struct{
    int stuID;
    char first[30];
    char last[30];
    int gradeLVL;
    char letterGrade;

}student_t;

void changeGrade(student_t student[], int *amtStudents); // DONE
void insert(student_t student[], int *amtStudents); // DONE
void removeStu(student_t student[], int *amtStudents); // removes a studen from the db
void search(student_t student[], int *amtStudents); // searchs for a student in the db
void display(student_t student[], int *amtStudents); // displays all the students or 1 student in the db
void exitDB(student_t student[] ,int *amtStudents); // prints the database into a text file
void populate(student_t student[]); // populates the original DB
void classGrades(student_t student[],int *amtStudents); // prints all the classes names and grades


int main()
{

    int selection; // selection var

    int total = 6; // starting with 6 students at beginning of the program
    int *amtStudents = &total; // pointer to be accessed from anywhere in the program.

    //
    student_t class[30]; // initialize the struct arr
    // 

    populate(class); // populate the students in the arr

    while(selection != 7)
    {
    printf("Welcome to the class Database, What would you like to do?\n");
    printf("-------------------------------------\n");
    printf("[1] Class Grades\n");
    printf("[2] Add student\n");
    printf("[3] Delete Student\n");
    printf("[4] Search (Name, Grades, ID)\n");
    printf("[5] Display Specifc/All student(s)\n");
    printf("[6] Change Student Grade\n");
    printf("[7] Exit Database and Print Records\n");
    scanf("%d", &selection);
    printf("-------------------------------------\n");

        switch(selection) // matches the menu printed at the beginning of the program.
        {
            case 1:
            classGrades(class,amtStudents);
            break;

            case 2:
            insert(class, amtStudents);
            break;

            case 3:
            removeStu(class, amtStudents);
            break;

            case 4:
            search(class, amtStudents);
            break;

            case 5:
            display(class, amtStudents);
            break;

            case 6:
            changeGrade(class, amtStudents);
            break;

            case 7:
            exitDB(class,amtStudents);
            break;

            default:
            printf("That was not an option please try again!\n");
            break;
        }


    }
    return 0;
}


void display(student_t student[], int *amtStudents)
{   
    int search; // vars
    int option;// to hold

    do
    {
    printf("-------------------------------------\n");
    printf("[1] All Class Records\n");
    printf("[2] Specific Student Record\n");
    printf("What would you like to display: ");
    scanf("%d", &option); // get user input if they want full DB or one student
    } while(option < 1 || option > 2);


    if (option == 1)
    {
        printf("Full Class Database\n"); // print header
        printf("-------------------------------------\n");
        for (int i = 0; i < *amtStudents; i++) // for loop printing every student
        {
            printf("ID: %d\n", student[i].stuID);
            printf("NAME: %s, %s\n",student[i].first, student[i].last); // students attributes
            printf("LETTER GRADE: %c\n", student[i].letterGrade);
            printf("GRADE LEVEL: %d\n", student[i].gradeLVL);
            printf("-------------------------------------\n");

        }

    }
    else if(option == 2)
    {
        do { // do while to check for invalid input
            
        
        printf("-------------------------------------\n");
        printf("Enter student ID: ");
        scanf("%d", &search); // take input
        if (search > *amtStudents) // if the search is bigger than the students ids = NOT VALID
        {
            printf("There isn't a student with that ID. Try Again\n");
            continue; // continue so we dont do the code below
        }
        search = search - 1; // to directly print the index
        printf("Now retrieving data for student with ID:%d...\n", student[search].stuID); // print the id of student grabbing info from
        printf("-------------------------------------\n");
        printf("ID: %d\n", student[search].stuID);
        printf("NAME: %s, %s\n",student[search].first, student[search].last);
        printf("LETTER GRADE: %c\n", student[search].letterGrade);
        printf("GRADE LEVEL: %d\n", student[search].gradeLVL);
        printf("-------------------------------------\n");
        } while(search > *amtStudents); // do while to make input is valid

        

    }

    


}

void populate(student_t student[])
{
    // HARD CODE 6 PEOPLE INTO THE STUDENT DATABASE
    strcpy(student[0].first, "Carson"); // copy strings into arr
    strcpy(student[0].last , "Fulmer"); // copy strings into arr
    student[0].stuID = 1;
    student[0].letterGrade = 'B';
    student[0].gradeLVL = 12;

    strcpy(student[1].first , "Jackson");
    strcpy(student[1].last , "Connor");
    student[1].stuID = 2;
    student[1].letterGrade = 'B';
    student[1].gradeLVL = 12;


    strcpy(student[2].first , "Thomas");
    strcpy(student[2].last , "Mullins");
    student[2].stuID = 3;
    student[2].letterGrade = 'A';
    student[2].gradeLVL = 11;


    strcpy(student[3].first , "Tony");
    strcpy(student[3].last , "Steinberg");
    student[3].stuID = 4;
    student[3].letterGrade = 'A';
    student[3].gradeLVL = 8;

    strcpy(student[4].first , "Andrew");
    strcpy(student[4].last , "Stark");
    student[4].stuID = 5;
    student[4].letterGrade = 'B';
    student[4].gradeLVL = 12;


    strcpy(student[5].first , "Christopher");
    strcpy(student[5].last , "Jack");
    student[5].stuID = 6;
    student[5].letterGrade = 'C';
    student[5].gradeLVL = 7;
}


void classGrades(student_t student[], int *amtStudents)
{
    printf("Calculating...\n");
    printf("-------------------------------------\n");
    for(int i = 0; i < *amtStudents; i++) // for loop to print each students name and grade
    { // First Last | A
        printf("%s %s | %c\n",student[i].first, student[i].last, student[i].letterGrade);
    }
}

void exitDB(student_t student[],int *amtStudents)
{
    FILE *fPtr = fopen("records.txt", "w"); // declare file pointer writing to the file 

    fprintf(fPtr,"Full Class Database\n"); // fprintf INTO THE FILE
    fprintf(fPtr,"-------------------------------------\n");
    for (int i = 0; i < *amtStudents; i++) // for loop to print each student :D
    {
        fprintf(fPtr,"ID: %d\n", student[i].stuID);
        fprintf(fPtr,"NAME: %s, %s\n",student[i].first, student[i].last);
        fprintf(fPtr,"LETTER GRADE: %c\n", student[i].letterGrade);
        fprintf(fPtr,"GRADE LEVEL: %d\n", student[i].gradeLVL);
        fprintf(fPtr,"-------------------------------------\n");

    }
    fclose(fPtr); // close file.
}

void search(student_t student[], int *amtStudents)
{
    int search = 0; // initalize var

    do {
            
        
        printf("-------------------------------------\n");
        printf("Enter student ID: ");
        scanf("%d", &search); // get user input
        if (search > *amtStudents)
        {
            printf("There isn't a student with that ID. Try Again\n"); // invalid msg
            continue;
        }
        search = search - 1; // to directly print the index
        printf("Now retrieving data for student with ID:%d...\n", student[search].stuID);
        printf("-------------------------------------\n");
        printf("ID: %d\n", student[search].stuID);
        printf("NAME: %s, %s\n",student[search].first, student[search].last); // print students attributes.
        printf("LETTER GRADE: %c\n", student[search].letterGrade);
        printf("GRADE LEVEL: %d\n", student[search].gradeLVL);
        printf("-------------------------------------\n"); 
        } while(search > *amtStudents); // if input is invalid continue looping


}

void removeStu(student_t student[], int *amtStudents)
{
    int removeIndex;

    do {
            
        
        printf("-------------------------------------\n");
        printf("Enter student ID: ");// get index of stuff we want to remove
        scanf("%d", &removeIndex);
        if (removeIndex > *amtStudents)
        {
            printf("There isn't a student with that ID. Try Again\n");
            continue;
        }
        removeIndex = removeIndex - 1; // to directly print the index
        } while(removeIndex > *amtStudents); // if input is invalid continue looping



    for(int i = 0; i < *amtStudents; i++) // loop through struct arr;
    {
        if(i < removeIndex) // if we havent hit the index we want to remove then continue through loop
        {
            continue;
        }
        student[i].stuID = student[i + 1].stuID; // copy everything to left
        strcpy(student[i].first,student[i + 1].first); // copy everything to left
        strcpy(student[i].last,student[i + 1].last); // copy everything to left
        student[i].gradeLVL = student[i + 1].gradeLVL; // copy everything to left
        student[i].letterGrade = student[i + 1].letterGrade; // copy everything to left
    }



    *amtStudents = *amtStudents - 1; // subtract a student from the class.


}

void insert(student_t student[], int *amtStudents)
{
    


    student[*amtStudents].stuID = *amtStudents + 1; // add to the total number of students.

    while(strlen(student[*amtStudents].first) <= 2 || strlen(student[*amtStudents].last) <= 2) // make sure string is not just 1 char
    {
        printf("Please enter first name: ");
        scanf("%s", student[*amtStudents].first); // take input for first name

        printf("Please enter last name: ");
        scanf("%s", student[*amtStudents].last); // take input for last name
    }


    char newStuGrade = 'E'; // start valid char to not print invalid first run

    do
    {
        if (!((int) newStuGrade >= 65 && (int) newStuGrade <= 70)) // if not in ascii value print bad run
        {
            printf("Invalid Grade. Please Enter A-F.\n"); // invalid msg
        }
        printf("Please Enter the grade: "); // take user input
        scanf(" %c", &newStuGrade); 
        newStuGrade = toupper(newStuGrade); // move to upper
    } while(!((int) newStuGrade >= 65 && (int) newStuGrade <= 70));

    student[*amtStudents].letterGrade = newStuGrade; // set new letter grade.


    int gradelevel = 6;
    do
    {
        if(gradelevel < 6 || gradelevel > 12)
        {
            printf("Invalid Input. Please try again. 6-12\n"); // invalid input
        }

        printf("Please enter the grade level: ");
        scanf(" %d", &student[*amtStudents].gradeLVL); // get user grade lvl
    } while(gradelevel < 6 || gradelevel > 12);

    *amtStudents = *amtStudents + 1; // add one tot the total amt of students.



}

void changeGrade(student_t student[], int *amtStudents)
{

    int change = 1; // set to valid int so we dont print invalid first run
    do
    {
        if(change > *amtStudents || change < 0)
        {
            printf("Invalid ID. Please Try Again\n");  // if not in range of student ids then keep looping and print
        }
        printf("Please Enter the ID of the Student: "); // take user input
        scanf("%d", &change);
    } while(change > *amtStudents || change < 0); // if not in range of student ids then keep looping
     

    char newGrade = 'E'; // set to valid char so we dont print invalid first run

    do // do while to handle invalid input
    {
        if (!((int) newGrade >= 65 && (int) newGrade <= 70)) // if isnt in ASCII value keep looping
        {
            printf("Invalid Grade. Please Enter A-F.\n");
        }
        printf("Please Enter the new grade: "); // take user input in the new grade
        scanf(" %c", &newGrade);
        newGrade = toupper(newGrade); // make letter uppercasse
    } while(!((int) newGrade >= 65 && (int) newGrade <= 70));

    student[change - 1].letterGrade = newGrade; // set index of struct to -1

}