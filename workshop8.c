/*
Name - Ayush Parajuli
Student id - 165601212
*/

#include <stdio.h>

void bufferclear() // creating a fuction for clearing the buffer
{
    while ((getchar()) != '\n')
        ;
}
struct student
{
    int id;
    char name[32];
    float gpa;
};

void save_student(struct student *s) // gives the address to student.
{

    printf("Please enter the id: ");
    scanf("%d", &s->id);
    printf("What is your name? ");
    bufferclear();
    // read string input from the user until \n is entered
    scanf("%32[^\n]", s->name);
    printf("What is your gpa: ");
    scanf("%f", &s->gpa);
}

// displaying the information
void print_student(struct student stu)
{
    printf("id: %d", stu.id);
    printf("\nname: %s", stu.name);
    printf("\ngpa: %f", stu.gpa);
}

int main()
{

    struct student individual;

    save_student(&individual);
    print_student(individual);

    return 0;
}