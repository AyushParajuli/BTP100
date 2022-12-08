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
    float height;
    float weight;
};

struct database
{
    struct patient pat[16]; // pat = patients
    int num;                // number of patient currently on database.
};
// Adding the patient.
void add_patient(struct database *data)
{
    int index;
    int checkid;
    // Refactor.
    do
    {
        int i;
        index = 1;
        printf("\nEnter the id: ");
        scanf("%d", &checkid);
        for (i = 0; i <= data->num; i++)
        {
            if (data->pat[i].id == checkid)
            {

                index = 0;
                printf("There's already a patient with that id.");
            }
        }
    } while (index == 0);
    // here the data is getting access to the patient.
    data->pat[data->num].id = checkid;
    clear();
    printf("\nEnter the first and last name: ");
    scanf("%32[^\n]", data->pat[data->num].name);
    clear();
    printf("Enter age: ");
    scanf("%d", &data->pat[data->num].age);
    clear();
    printf("Enter the height (in meter): ");
    scanf("%f", &data->pat[data->num].height);
    clear();
    printf("Enter the weight (in kilogram): ");
    scanf("%f", &data->pat[data->num].weight);
    data->num++;
}
// Displaying the patient
void display_patient(struct database *vic)
{
    int nump;     // number of patients
    int checkid;  // variable to hold the id and use it took check the id with the loop
    int flag = 0; // just to check if loop satisfies or not
    // clear();
    printf("\nEnter the id of patient: ");
    scanf("%d", &checkid);
    clear();
    for (nump = 0; nump < vic->num; nump++)
    {
        float bmi = vic->pat[nump].weight / (vic->pat[nump].height * vic->pat[nump].height);
        if (checkid == vic->pat[nump].id)
        {
            printf("\npatient id: %d", vic->pat[nump].id);
            printf("\npatient name: %s", vic->pat[nump].name);
            printf("\npatient age: %i", vic->pat[nump].age);
            printf("\npatient height: %.2f meter ", vic->pat[nump].height);
            printf("\npatient weight: %.2f kg", vic->pat[nump].weight);
            printf("\nThe bmi is : %.2f", bmi);
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        printf("the id is not correct!!");
    }
}
// edit patient
void edit_patient(struct database *edit)
{
    int nump;  // number of patient
    int index; // patient index.
    int checkid;
    int userexist = 0; // to check weather user exist
    printf("Enter the id of patient: ");
    scanf("%d", &checkid);
    clear();
    for (nump = 0; nump < edit->num; nump++)
    {
        if (checkid == edit->pat[nump].id)
        {
            userexist = 1;
            index = nump; // if it happens user exist
        }
    }
    if (userexist = 1)
    {
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
        printf("bro this %d dont even exist\n", checkid);
    }
}
// PART 2
void remove_patient(struct database *rev)
{
    int nump;          // number of patient
    int i;             // to check the number of patient
    int index;         // index of the patient
    int checkid;       // to match the id with the id of patient
    int userexist = 0; // to check weather user exist
    printf("Enter the id of patient: ");
    scanf("%d", &checkid);
    clear();
    for (nump = 0; nump < rev->num; nump++)
    {

        if (checkid == rev->pat[nump].id)
        {
            userexist = 1;
            index = nump; // if it happens user exist
        }
    }
    if (userexist == 1)
    {
        for (i = index; i < rev->num - 1; i++)
        {
            rev->pat[i] = rev->pat[i + 1]; // it will replace the array with 1 with 2 and 2 with 3.
        }
        rev->num--;
        printf("Id %d is sucessfully removed", checkid);
    }
    else
    {
        printf("user with %d dont even exist.", checkid);
    }
}
// PART 3
void save_database(struct database *save)
{
    char filename[16]; // this filename will hold 16 characters.
    int nump;
    FILE *fp = NULL;
    printf("Enter the name of file ");
    scanf("%16[^\n]", filename);
    clear();
    fp = fopen(filename, "w"); // w is used to create the file in a write mode.
    if (fp != NULL)
    {
        fprintf(fp, "%i\n", save->num);          // to save the number of database in the file.
        for (nump = 0; nump < save->num; nump++) // itterating through the number of patient.
        {
            fprintf(fp, "%i, %s, %i, %.2f, %.2f\n", save->pat[nump].id, save->pat[nump].name, save->pat[nump].age, save->pat[nump].height, save->pat[nump].weight);
            printf("your data is sucessfully saved.");
        }
        fclose(fp);
    }
    else
    {
        printf("file failed to open");
    }
}

void retrieve_patient(struct database *retrieve)
{
    char fileretrieve[16];
    int nump;
    FILE *rt = NULL;
    printf("Enter the name of the file: ");
    scanf("%16[^\n]", fileretrieve);
    clear();
    rt = fopen(fileretrieve, "r"); // r opens file in a read mode.
    if (rt != NULL)
    {
        fscanf(rt, "%i\n", &retrieve->num);
        for (nump = 0; nump < retrieve->num; nump++)
        {
            fscanf(rt, "%i,%[^,],%i,%f,%f", &retrieve->pat[nump].id, retrieve->pat[nump].name, &retrieve->pat[nump].age, &retrieve->pat[nump].height, &retrieve->pat[nump].weight);
        }
        printf("your data is sucessfully retrieved.");
        fclose(rt);
    }
    else
    {
        printf("File failed to open");
    }
}
void critical_patient(struct database *cric)
{
    int nump;
    float bmi;
    for (nump = 0; nump < cric->num; nump++)
    {
        bmi = cric->pat[nump].weight / (cric->pat[nump].height * cric->pat[nump].height);
        if (bmi < 18 || bmi > 30)
        {
            printf("\nPatient id: %i", cric->pat[nump].id);
            printf("\nPatient name: %s", cric->pat[nump].name);
            printf("\nPatient age: %i", cric->pat[nump].age);
            printf("\nPatient height in meters: %.2f", cric->pat[nump].height);
            printf("\nPatient weight in kilograms: %.2f", cric->pat[nump].weight);
            printf("\nThe bmi is : %.2f", bmi);
        }
        else
        {
            printf("---------------------------------------------------");
            printf("\npatient id with %i is not a critical patient\n", cric->pat[nump].id);
            printf("---------------------------------------------------");
        }
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
        printf("\nWhat do you want to do? [a] add a patient, [b] Display patient, [c] to edit the patient, [d] to remove an patient, [e] to save an patient, [f] to retrieve an patient, [g] to view the crictical patient, [x] exit\n");
        scanf("%c", &choose, 1);
        clear();
        switch (choose)
        {
        case 'a':
            if (database.num <= 16)
            {
                add_patient(&database);
                clear();
            }
            else
            {
                printf("The data base is full!");
            }
            break;
        case 'b':
            if (database.num == 0)
            {
                printf("The data base is empty!");
            }
            else
            {
                display_patient(&database);
            }
            break;
        case 'c':
            edit_patient(&database);

            break;
        case 'd':
            remove_patient(&database);

            break;
        case 'e':
            save_database(&database);

            break;
        case 'f':
            retrieve_patient(&database);

            break;
        case 'g':
            critical_patient(&database);

            break;
        case 'x':
            printf("\nExit");

            break;
        default:
            printf("Invalid syntax");
        }
    }
}