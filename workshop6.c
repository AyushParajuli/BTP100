#include <stdio.h>
#define SIZE 6
// part 1
int maximum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
// part 2
void weeks(int days)
{
    printf("%d is equivalent to %d weeks and %d days \n", days, days / 7, days % 7); // printing days and weeks.
}
//part 3
int print_evens(int arr[], int size)
{
    printf("The element with even indexs: ");
    for (int i = 0; i < size; i += 2) // itterate over arrays
    {
        printf("%d ", *arr); // take the pointer.
        arr += 2;
    }
}
int main()
{

    printf("max(4,9) = %i\n", maximum(4, 9));
    printf("max(8,7) = %i\n", maximum(8, 7));
    printf("max(2,2) = %i\n", maximum(2, 2));

    weeks(16);
    weeks(24);
    weeks(47);

    int list[SIZE] = {10, 20, 30, 40, 50, 60};
    print_evens(list, SIZE);

    return 0;
}