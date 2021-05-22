#include <stdio.h>
#include <stdlib.h> //rand(), srand()

/* 랜덤수 이용하기*/
//rand() 0 ~ 32767
int main()
{
    int rand_num;

    srand(1);

    for(int i = 0; i < 30; i ++)
    {   
        rand_num = rand() % 10;
        printf("%d ", rand_num);
    }

    return 0;
}