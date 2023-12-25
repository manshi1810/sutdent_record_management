#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<string.h>
void insert();
void disolay();
int search(int);
struct Student
{
    int rollnumber;
    char name[100];
    char phone[100];
    float percentage;
    struct Student *next;

}*student,*first,*save,*pred;
void update(int rollnumber) {
    save = first;
    while (save != NULL) {
        if (save->rollnumber == rollnumber) {
            printf("Roll Number: %d\n", save->rollnumber);
            printf("Name: %s", save->name);
            printf("Phone: %s", save->phone);
            printf("Percentage: %2f\n", save->percentage);

            printf("\nEnter new name: ");
            scanf("%s", save->name);
            printf("Enter new phone number: ");
            scanf("%s", save->phone);
            printf("Enter new percentage: ");
            scanf("%f", &save->percentage);

            printf("\nStudent details updated successfully!\n");
            return;
        }
        save = save->next;
    }
    printf("\nStudent with roll number %d is not found !!!\n", rollnumber);
}
int search( int rollnumber)
{


    save=first;
    while(save!=NULL){
        if(save->rollnumber==rollnumber){
            printf("Roll Number: %d\n", save->rollnumber);
            printf("Name: %s", save->name);
            printf("Phone: %s", save->phone);
            printf("Percentage: %2f", save->percentage);
            return;
        }
        save = save->next;
    }
    printf("\nStudent with roll number %d is not found !!!\n", rollnumber);
    return;
}

int Delete(int rollnumber)
{

    if(first==NULL)
    {
        printf("\nLinked list is empty..");
        return;
    }
    save=first;
    if(rollnumber==first->rollnumber)
    {
        save=NULL;
        free(save);

    }
    save=first;
    while(save != rollnumber && save->next !=NULL)
    {
        pred=save;
        save=save->next;
    }
    if(save->rollnumber==rollnumber)
    {
        pred->next=save->next;
        save->next=NULL;
        free(save);
        return;
    }
    else
    {
        printf("Roll number %d not found !!",rollnumber);
    }
}
void display()
{
    if(first==NULL)
    {
        printf("\nEmpty List..");
        return;
    }
    save= first;
    while(save!=NULL){

        printf("\nRoll Number: %d", save->rollnumber);
        printf("\nName: %s", save->name);
        printf("\nPhone: %s", save->phone);
        printf("\nPercentage: %2f", save->percentage);
        printf("\n-----------------------------------------\n");
        save = save->next;

    }
}
void insert() {
    student = (struct Student *)malloc(sizeof(struct Student));
    if (student == NULL) {
        printf("\n Memory Full..!!");
        return;
    }
    printf("\nEnter Rollnumber :");
				scanf("%d",&student->rollnumber);
				printf("\nEnter name: ");
                scanf("%s",student->name);
                printf("\nEnter phone number: ");
                scanf("%s",student->phone);
                printf("\nEnter new percentage: ");
                scanf("%f",&student->percentage);


    student->next = NULL;

    // If the list is empty or the new rollnumber is less than the first rollnumber
    if (first == NULL || student->rollnumber <= first->rollnumber) {
        student->next = first;
        first = student;
        return;
    }

    // Find the correct position to insert the new rollnumber
    save = first;
    while (save->next != NULL && save->next->rollnumber <= student->rollnumber) {
        save = save->next;
    }

    // Insert the new student node in the correct position
    student->next = save->next;
    save->next = student;
}
void count_rec()
{
    int count=1;

    if(first==NULL)
    {
        printf("\nNot any record present yet...");
        return;
    }

    save=first;
    while(save->next!=NULL)
    {
        count++;
        save=save->next;
    }
    printf("%d students are present in system",count);

}

int main()
{
    int rollnumber;

    char name[100];
    char phone[100];
    float percentage;
    int choice;


    printf("\n\t\t\t\t\t   ----------------------------------- ");
    printf("\n\t\t\t\t\t || STUDENT RECORD MANAGEMENT SYSTEM || ");
    printf("\n\t\t\t\t\t   ----------------------------------- \n\n");

    printf("\n************************************************************************************************************************\n\n");

   while(1)
    {

    printf("\n==========================================");
    printf("\n1 to insert student details\n2 to search for student details\n3 to delete student details\n4.update student\n5.count how many student present in system\n6.to display all student details\n7.exit");

    printf("\n==========================================");
        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:


                insert();
                break;
            case 2:
                printf("Enter roll number to search: ");
                scanf("%d", &rollnumber);
                search(rollnumber);
                break;
            case 3:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollnumber);
                Delete(rollnumber);
                break;
            case 4:
                printf("Enter roll number for update: ");
                scanf("%d",&rollnumber);
                update(rollnumber);
                break;

            case 5:
                count_rec();
                break;

            case 6:
                display();
                break;

            case 7:
                exit(0);
            default:printf("\nEnter choice between 1 to 7");
        }

    }
}

