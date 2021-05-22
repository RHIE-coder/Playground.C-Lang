#include <stdio.h>
#include <stdlib.h> //atoi()

/* 대칭수 판독기 */
int main()
{
    char sNum[50];
    printf("[대칭수 판독기]\n");
    printf("숫자를 입력하세요 : ");
    scanf("%s", &sNum);
    printf("입력하신 숫자 : %s\n",sNum);

    int length = 0;
    int index = 0;
    
    while(sNum[index] != '\0')
    {
        length++;
        index++;
    }
    printf("길이는 %d\n", length);

    int middle = length / 2;
    int reverse_index = length - 1;
    int isPalindromicNumber = 1;

    for(int i = 0; i < middle; i++)
    {
        printf("debug start\n");
        if(atoi(sNum[i]) != atoi(sNum[reverse_index]))
        {
            isPalindromicNumber = 0;
            break;
        }
    }
    printf("debug end\n");

    if(isPalindromicNumber)
    {
        printf("숫자 %s은 대칭수입니다.\n", sNum);
    }
    else
    {
        printf("숫자 %s은 대칭수가 아닙니다.\n", sNum);
    }


    return 0;
}