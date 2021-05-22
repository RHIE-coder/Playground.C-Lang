#include <stdio.h>
#include <stdlib.h> //rand()

/* 랜덤수 이용하기*/
//rand() 0 ~ 32767
//rand()는 프로그램이 생성될 때 Seed값이 정해진다.
//늘 일정한 난수가 나오는 잘못된 예제
int main()
{
    int rand_num;

    for(int i = 0; i < 30; i ++)
    {
        rand_num = rand() % 10; //0 ~ 9
        printf("%d ", rand_num);
    }

    return 0;
}