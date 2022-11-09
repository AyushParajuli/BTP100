// Workshop4
// student id:-165601212.
// Ayush Parajuli

#include <stdio.h>

int main()
{
    int i, final, sum = 0; // varaibales

    do // for the infinite loop
    {
        printf("Enter the 1st integer: \n", i);
        scanf("%d", &i);
        printf("Enter the final integer:\n");
        scanf("%d", &final);
        if (i > final)
        {
            printf("Final integer must be smaller\n");
        }
    } while (i > final);
    for (int j = i; j < final; j++) // to do the math
    {
        sum += j;
        printf("%d + ", j);
    }
    sum += final;
    printf("%d ", final);
    printf("= %d", sum);
    return 0;
}