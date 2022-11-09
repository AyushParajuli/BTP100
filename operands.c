//Workshop01 Ayush Parajuli
#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter numbers: ", a);
    scanf("%d", &a);
    printf("Enter numbers: ", b);
    scanf("%d", &b);
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n", a, b, a / b);
    if (a > b)
    {
        printf("%d is greater than %d\n", a, b);
    }else{
        printf("%d is greater than %d\n", b, a);
    }
}