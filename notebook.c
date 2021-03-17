#include <stdio.h>

void changeNum(int);

void changeArr(int *);

int main()
{
    int x = 7;
    int *ptr = &x;
    int **pptr = &ptr;
}

void changeNum(int num)
{
    num = 20;
}

void changeArr(int *nums)
{
    nums[0] = 100;
}
