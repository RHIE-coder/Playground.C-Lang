#include <stdio.h>

/*피보나치 수열의 값 구하기*/
//n번째의 값은 n-1과 n-2의 합으로 이루어진다.
int main()
{
    int max_num;
    printf("[피보나치 수열 출력]\n");
    printf("범위 입력하기(1 ~ 입력하신 숫자 이하) : ");
    scanf("%d", &max_num);

    int current_num = 0;
    int before_num = 0;
    int before_before_num = 1;

    if (max_num > 0)
    {
        while (current_num <= max_num)
        {
            printf("%d ", current_num);
            current_num = before_num + before_before_num;
            before_before_num = before_num;
            before_num = current_num;
        }
    }
    else
    {
        printf("1이상의 숫자를 입력해주세요.\n");
    }

    return 0;
}