/*Name - Ayush Parajuli
 Student id - 165601212
*/

#include <stdio.h>

void clear()
{
    while ((getchar()) != '\n')
        ;
}
struct patient
{
    int id;
    char name[32];
    int age;
    float height, weight;
};

struct database
{
    struct patient pat[16]; // pat = patients
    int num;                // number of patient currently on database.
};
// Adding the patient.
void add_patient(struct database *data)
{
    printf("\nEnter the id: ");
    scanf("%d", &data->pat[data->num].id); // here the data is getting access to the patient,
    printf("\nEnter the first and last name: ");
    clear();
    scanf("%32[^\n]", data->pat[data->num].name);
    printf("Enter age: ");
    scanf("%d", &data->pat[data->num].age);
    clear();
    printf("Enter the height (in feet): ");
    scanf("%f", &data->pat[data->num].height);
    clear();
    printf("Enter the weight (in kilogram): ");
    scanf("%f", &data->pat[data->num].weight);
}
// Displaying the patient
void display_patient(struct database vic)
{
    int i;        // for initalization
    int t;        // variable to hold the id and use it took check the id with the loop
    int flag = 0; // just to check if loop satisfies or not
    // clear();
    printf("\nEnter the id of patient: ");
    scanf("%d", &t);
    clear();
    for (i = 0; i <= 16; i++)
    {
        if (t == vic.pat[i].id)
        {
            printf("\npatient id: %d", vic.pat[i].id);
            printf("\npatient name: %s", vic.pat[i].name);
            printf("\npatient age: %i", vic.pat[i].age);
            printf("\npatient height: %.2f feet ", vic.pat[i].height);
            printf("\npatient weight: %.2f kg", vic.pat[i].weight);
            printf("\nThe bmi is : %.2f", vic.pat[i].weight / (vic.pat[i].height * vic.pat[i].height));
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        printf("the id is not correct!!");
    }
}

void edit_patient(struct database *edit)
{
    int j;
    int index;
    // int flag = 0;
    int checkid;
    int userexist = 0; // to check weather user exist
    printf("Enter the id of patient: ");
    scanf("%d", &checkid);
    clear();
    for (j = 0; j <= edit->num; j++)
    {
        if (checkid == edit->pat[j].id)
        {
            userexist = 1;
            index = j; // if it happens user exist
        }
    }
    if (userexist = 1)
    {
        // printf("It works id is %d\n", checkid);
        printf("Enter the patient name: ");
        scanf("%32[^\n]", edit->pat[index].name);
        clear();
        printf("Enter age: ");
        scanf("%d", &edit->pat[index].age);
        clear();
        printf("Enter the height (in feet): ");
        scanf("%f", &edit->pat[index].height);
        clear();
        printf("Enter the weight (in kilogram): ");
        scanf("%f", &edit->pat[index].weight);
        clear();
    }
    else
    {
        // clear(); // clear buffer
        printf("bro this %d dont even exist\n", checkid);
    }
}

void remove_patient(struct database *rev){
    
}

int main()
{
    struct patient victim;
    struct database database;

    database.num = 0;
    char choose = 'a';
    while (choose != 'x')
    {
        printf("\nWhat do you want to do? [a] add a patient, [b] Display patient, [c] to edit the patient,[x] exit\n");
        scanf("%c", &choose, 1);
        clear();
        switch (choose)
        {
        case 'a':
            if (database.num <= 16)
            {
                add_patient(&database);
                clear();
                // database.pat[database.num] = database.num + 1;
                database.num += 1;
            }
            else
            {
                printf("The data base is full!");
            }
            break;
        case 'b':
            // clear();
            if (database.num == 0)
            {
                printf("The data base is empty!");
            }
            else
            {
                // for (int i = 0; i < database.num; i++)
                // {
                //     display_patient(database);
                //     clear();
                // }
                display_patient(database); // main function
            }
            break;
        case 'c':
            edit_patient(&database);

            break;
        case 'x':
            printf("\nExit");
            break;
        default:
            printf("Invalid syntax");
        }
    }
}
