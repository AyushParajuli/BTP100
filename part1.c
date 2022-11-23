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
    struct patient pat[16];
    int num; // number of patient currently on database.
};

void add_patient(struct database *data)
{
    printf("\nEnter the id: ");
    scanf("%d", &data->pat[data->num].id);
    printf("\nEnter the first and last name: ");
    clear();
    scanf("%32[^\n]", data->pat[data->num].name);
    printf("Enter age: ");
    scanf("%d", &data->pat[data->num].age);
    printf("Enter the height (in feet): ");
    scanf("%f", &data->pat[data->num].height);
    printf("Enter the weight (in kilogram): ");
    scanf("%f", &data->pat[data->num].weight);
}

void display_patient(struct database vic)
{
    int i;
    int t;
    int flag = 0;
    // clear();
    printf("\nEnter the id of patient: ");
    scanf("%d", &t);
    clear();
    for (i = 0; i <= 16; i++)
    {
        if (t == vic.pat[i].id)
        {
            printf("\nPatient id: %d", vic.pat[i].id);
            printf("\nPatient name: %s", vic.pat[i].name);
            printf("\nPatient age: %i", vic.pat[i].age);
            printf("\nPatient height: %.2f feet ", vic.pat[i].height);
            printf("\nPatient weight: %.2f kg", vic.pat[i].weight);
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

int main()
{
    struct patient victim;
    struct database database;

    database.num = 0;
    char choose = 'a';
    while (choose != 'x')
    {
        printf("\nWhat do you want to do? [a] add a patient, [b] Display patient, [x] exit\n");
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
                display_patient(database);
            }
            break;
        case 'x':
            printf("Exit");
            break;
        default:
            printf("Invalid syntax");
        }
    }
}