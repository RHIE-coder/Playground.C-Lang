#include <stdio.h>
#include <stdlib.h> //rand(), srand()
#include <time.h> //time()

/* 랜덤수 이용하기*/
//rand()        0 ~ 32767
//srand()       rand()의 Seed값 설정
//time(NULL)    1970년 1월 1일(UTC)부터 현재까지 흐른 시간을 반환(초)
int main()
{
    int rand_num;

    
    srand(time(NULL));

    for(int i = 0; i < 30; i ++)
    {   
        rand_num = rand() % 10;
        printf("%d ", rand_num);
    }

    return 0;
}