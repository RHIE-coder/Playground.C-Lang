#include <stdio.h>

/* 진법 변환 */
int not_size(int decimal, int notation_num)
{
    int size = 0;
    
    while(1)
    {
        decimal /= notation_num;
        printf("%d ", decimal);
        size++;
        if(decimal == 0)
        {
            break;
        }
    }
    printf("\n");
    return size;
}

void dec_to_not(int decimal, int notation_num){
    int length = not_size(decimal, notation_num);
    int not_nums[length];

    for(int i = 0; i < length; i++)
    {
        not_nums[i] = decimal % notation_num;
        decimal /= notation_num;
        
    }

    for(int i = length - 1 ; i >= 0; i--)
    {
        if (not_nums[i] > 9)
        {
            printf(" %d ", not_nums[i]);
        }
        else
        {
            printf("%d", not_nums[i]);
        }
    }
    
    printf("\n");
}

int main()
{
    int decimal;
    int notation_num;
    printf("[진법 변환]\n");

    printf("숫자를 입력해주세요 : ");
    scanf("%d", &decimal);

    printf("원하는 진법을 입력해주세요 : ");
    scanf("%d", &notation_num);

    dec_to_not(decimal, notation_num);


    return 0;
}