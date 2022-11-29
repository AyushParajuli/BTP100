// workshop2
// Ayush Parajuli
// 165601212

#include <stdio.h>

int main()
{
    int f, i, m, c;                             // declearing variables
    printf("Enter height in feet and inch:\n"); // input
    scanf("%d%d", &f, &i);
    // printf("your height is : %dfeet %dinch\n", f,i);
    float c2;
    c2 = (f * 30.48) + (i * 2.54);                        // formula
    m = (int)c2 / 100;                                    // converting to meter
    c = (int)c2 - 100;                                    // converting to centimeter
    printf("Your height is %dmeter, %dcentimeter", m, c); // final result.
}
