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

    int num; // number of patient currently on database.
}pat[16];

void add_patient(struct database *data)
{
    // printf("Enter the number of patient: ");
    // scanf("%d", &data->num);
    data->num = 0;
    printf("Enter the id: ");
    scanf("%d", &data->pat[data->num].id);
    printf("Enter the first and last name: ");
    clear();
    scanf("%16[^\n]", &data->pat[data->num].name);
    printf("Enter age: ");
    scanf("%d", &data->pat[data->num].age);
    printf("Enter the height: ");
    scanf("%f", &data->pat[data->num].height);
    printf("Enter the weight: ");
    scanf("%f", &data->pat[data->num].weight);
}

void display_patient(struct patient pat, struct database data)
{
    printf("name: %s", pat.name);
    printf("\nid: %d", pat.id);
}

int main()
{
    struct patient victim;
    struct database database;
    add_patient(&database);
    display_patient(victim, database);
}
