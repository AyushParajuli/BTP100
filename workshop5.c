// Workshop 6 - AYUSH PARAJULI
#include <stdio.h>
#define SIZE 16

int main()
{
    int ids[4];
    char names[4][SIZE];
    int num_users = 0;
    int checkid; // to check the id

    char option = 'a';
    while (option != 'x')
    {
        printf("What do you want to do? [a] add a user, [l] list all users, [e] edit a user?, [x] exit\n");
        scanf_s("%c", &option, 1); // Visual Studio
        // scanf("%c", &option);
        while ((getchar()) != '\n')
            ;

        switch (option)
        {
        case 'a':
            if (num_users < 4)
            {
                printf("Enter the user's name.\n");
                scanf("%s", names[num_users], sizeof(names[num_users])); // Visual Studio
                // scanf("%s", names[num_users]);
                while ((getchar()) != '\n')
                    ;
                ids[num_users] = num_users + 1;
                num_users += 1;
            }
            else
            {
                printf("Database full.\n");
            }
            break;
        case 'l':
            if (num_users == 0) // to do the loop
            {
                printf("there's no users");
            }
            else
            {
                for (int i = 0; i < num_users; i++) // to check the condition
                {
                    printf("%i - %s\n", ids[i], names[i]); // tp print the id and the same.
                }
            }
            break;
        case 'e':
            printf("Enter the id: ");
            scanf("%d", &checkid);
            while ((getchar()) != '\n')
                ;
            if (checkid >= num_users || checkid == 0) // checking whether the condition satisfies.
            {
                printf("The id does not match.\n");
            }
            else
            {
                printf("Enter the new user: ");
                scanf("%s", names[checkid - 1], sizeof(names[num_users])); // adding the new user and replacing the old one.
                while ((getchar()) != '\n')
                    ;
            }
            break;
        case 'x':
            printf("Quiting the application. Bye.\n");
            break;
        default:
            printf("Error! invalid option.\n");
            break;
        }
    }

    return 0;
}
