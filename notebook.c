#include <stdio.h>

int add(int, int);

int mul(int, int);

int calculator(int, int, int (*func)(int, int));

int main()
{
    int (*add_calc)(int, int) = add;
    printf("add_calc : %d\n", add_calc(10, 20));
    int (*mul_calc)(int, int) = mul;
    printf("mul_calc : %d\n", mul_calc(10, 20));
    int add_result = calculator(10, 20, add);
    int mul_result = calculator(10, 20, mul);
    printf("add : %d\n", add_result);
    printf("mul : %d\n", mul_result);

    return 0;
}

int add(int num1, int num2)
{
    return num1 + num2;
}

int mul(int num1, int num2)
{
    return num1 * num2;
}

int calculator(int num1, int num2, int (*func)(int, int))
{
    return func(num1, num2);
}