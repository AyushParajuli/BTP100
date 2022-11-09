#include <stdio.h>
#define SIZE 32

int get_length(char *name)
{
    int length = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

void break_names(char *name, char *first_name, char *last_name)
{
    for (int i; *name !=' '; i++)
    {
        *first_name = *name;
        first_name++;
        name++;
    }
    for (int i; *name != '\0'; i++)
    {
        *last_name = *name;
        last_name++;
        name++;
    }
}

void get_name(char *name)
{
    printf("Enter your full name: ");
    // scanf("%[^\n]%*c", name);
    scanf_s("%[^\n]%*c", name, SIZE); // Visual Studio
}

int main()
{

    char name[SIZE] = {"Marcel Jar"}, first_name[SIZE], last_name[SIZE];

    get_name(name);
    printf("Your character array has %i characters.\n", get_length(name));
    printf("Full name: %s\n", name);

    break_names(name, first_name, last_name);
    printf("First name: %s\n", first_name);
    printf("Last name: %s\n", last_name);

    return 0;
}
