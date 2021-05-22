#include <stdio.h>

/*소수 이용하기*/
int main()
{
    int max_num;
    int div_check;

    printf("[소수 판단 프로그램]\n");
    printf("숫자를 입력하세요(1이상의 숫자) : ");
    scanf("%d", &max_num);

    if (max_num > 0)
    {
        printf("%d\n", 1);

        for (int num = 1; num <= max_num; num++)
        {
            for (div_check = 2; div_check <= num; div_check++)
            {
                if (num % div_check == 0)
                {
                    break; //나누어 떨어짐
                }
            }
            if (num == div_check) //소수라면 true
            {
                printf("%d\n", num);
            }
        }
    }
    else
    {
        printf("0이상의 숫자를 입력해주세요.");
    }


    return 0;
}