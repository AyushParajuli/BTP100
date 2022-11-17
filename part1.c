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
    char name2[32];
    int age;
    float height, weight;
} p[16];

struct database
{
    int patient[16];
    int num; // number of patient currently on database.

} data;

void add_patient(struct database *data)
{
    // printf("Enter the number of patient: ");
    // scanf("%d", &data->num);
    printf("Enter the id: ");
    scanf("%d", &data->patient[data->num].id);
    printf("Enter the first name: ");
    clear();
    scanf("%16[^\n]", p[]->name);
    printf("Enter the lase name: ");
    clear();
    scanf("%16[^\n]", p[]->name2);
    printf("Enter age: ");
    scanf("%d", &p->age);
    printf("Enter the height: ");
    scanf("%f", &p->height);
    printf("Enter the weight: ");
    scanf("%f", &p->weight);
}

void display_patient(struct patient pat, struct database data)
{
    printf("name: %s",pat.name);
    printf("\nid: %d",pat.id);
}

int main()
{
    struct patient victim;
    struct database database;
    add_patient(&victim);
    display_patient(victim, database);
}