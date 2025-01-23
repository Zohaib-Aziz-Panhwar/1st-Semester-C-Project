#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define max_students 100
#define max_days 30
#define max_courses 5

struct Student
{
    int age, attendance[max_days];
    char Reg_No[10],name[15], courses[max_courses];
    float mid, sessional, final;//sessional inclused class participation, quizes and assignmnets.
    float feestructure;
};

struct Student students[max_students];
int studentcount=0;
int findStudentByReg_No(char reg[]);
void enterMarks();
void teachermenu();
void credentials();
void addstudent();
void updaterecord();
void viewStudent();
void clearscreen(){
    system("@cls||clear");
}
int main(){
    int choice, choice2;
    printf("WELCOME TO UNIVERSITY MANAGEMENT SYSTEM!\n");
    printf("\t\tARE YOU\n1)TEACHER:\n2)STUDENT:\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:printf("WHICH SUBJECT DO YOU TEACH:\n1)PROGRAMMING:\n2)CALCULUS:\n3)PHYSICSS:\n4)ENGLISH:\n5)AICT:");
            scanf("%d", &choice2);
            clearscreen();
        switch (choice2)
        {
            case 1:case 2:case 3:case 4:case 5:credentials(); break;
            default:printf("INVALID CHOICE!\n");
        }
    case 2:;break;
    default: printf("INVALID CHOICE!\n");
    }
    return 0;
}
void credentials(){
    char  login[15], pass[15];
    char programing[]= "PROGRAMMING", programing_pass[]= "prog123";
    char calculus[]="CALCULUS", calculus_pass[]="calc123";
    char physics[]="PHYSICS", physics_pass[]="phys123";
    char english[]="ENGLISH", english_pass[]="eng123";
    char aict[]="AICT", aict_pass[]="aict123";
    printf("ENTER YOUR USERNAME\n");
    scanf("%14s", login);
    printf("ENTER YOUR PASSWORD\n");
    scanf("%14s", pass);
          clearscreen();
    if (strcmp(login, programing)==0 && strcmp(pass, programing_pass)==0)
    {
        printf("\t\tLOGIN SUCCESSFUL FOR PF:");
        teachermenu();
    }
    else if (strcmp(login, calculus)==0 && strcmp(pass, calculus_pass)==0)
    {
    printf("\t\tLOGIN SUCCESSFUL FOR CALCULUS:");
    teachermenu();  
    }
    
    else if (strcmp(login, physics)==0 && strcmp(pass, physics_pass)==0)
    {
    printf("\t\tLOGIN SUCCESSFUL FOR PHYSICS:");
    teachermenu();
    }
    else if (strcmp(login, english)==0 && strcmp(pass, english_pass)==0)
    {
    printf("\t\tLOGIN SUCCESSFUL FOR ENGLISH:");
    teachermenu();
    }
    else if (strcmp(login, aict)==0 && strcmp(pass, aict_pass))
    {
     printf("\t\tLOGIN SUCCESSFUL FOR AICT:");
    teachermenu();           
    }
    else
    printf("INVALID USERNAME OR PASSWORD:\n");
     
}

void teachermenu(){
    int choice;
    do
    {
        printf("1)ADD STUDENT:\n2)UPDATE STUDENT RECORD:\n3)ATTENDANCE:\n4)SEARCH STUDENT:\n5)EXIT:\n");
        scanf("%d", &choice);
            clearscreen();

        switch (choice)
        {
        case 1:addstudent();break;
        case 2:updaterecord();break;
        case 4:viewStudent();break;
        case 5:printf("TEACHERS MENU ENDED!\n");break;
        default:printf("|INCORRECT CHOICE|\n");break;
        }
    } while (choice!=5);
}
void addstudent() {
    struct Student new_student;
    int option;
    
    printf("Enter Student Registration No:\n");
    scanf("%9s", new_student.Reg_No); // Using %9s for safety
    printf("Enter Name Of Student:\n");
    scanf("%14s", new_student.name); // Name length limited to 14 characters
    printf("Enter Student Age:\n");
    scanf("%d", &new_student.age);
    printf("Enter Course Name:\n");
    scanf("%4s", new_student.courses); // Using %4s since max_courses = 5
    enterMarks(new_student);  // Pass pointer to new_student
    
    students[studentcount++] = new_student;  // Add student to the array
    printf("\t\tSTUDENT ADDED SUCCESSFULLY:\n");
            clearscreen();

    printf("Would you like to add another student?\n1)YES\n2)NO\n");
    scanf("%d", &option);

    switch (option) {
    case 1: addstudent(); break;
    case 2: teachermenu(); break;
    default: printf("INVALID OPTION:\n"); break;
    }
}
void enterMarks(struct Student students){
    float mid, final, sessional;
    printf("\nEnter Marks of MIDS:");
    scanf("%f",&students.mid);
    printf("\nEnter Marks of SESSIONAL:");
    scanf("%f",&students.sessional);
    printf("\nEnter Marks of final:");
    scanf("%f",&students.final);

}
int findStudentByReg_No(char reg[]){
    for (int i = 0; i < studentcount; i++)
    {
        if (strcmp(students[i].Reg_No,reg)==0)
        {
            return i;
        }
        return -1;   
    }
}
void updaterecord(){
    int index;
    char reg[10];
    printf("Enter Reg_No to Update!\n");
    scanf("%9s", reg);
    index=findStudentByReg_No(reg);

    printf("Updating record for %s:\n", students[index].name);
    printf("Enter new age!\n");
   scanf("%d", &students[index].age);   
    clearscreen();

}
void viewStudent(){
    char regNo[10];
    if(studentcount==0)
    {
        printf("STUDENT NOT FOUND:\n");
    }
    printf("ENTER REG NO:");
    scanf("%s", regNo);

    for (int i = 0; i < studentcount; i++)
    {
        if (strcmp(students[i].Reg_No,regNo)==0)
        {
            printf("\n\n\t\t!!!!STUDENT FOUND!!!!\n");
            printf("NAME: %s\n",students[i].name);
            printf("AGE: %d\n",students[i].age);
            printf("REG_NO: %s\n",students[i].Reg_No);
        }
        
    }
    
}

