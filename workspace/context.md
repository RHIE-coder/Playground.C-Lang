# 01. 소수 구하기

```c
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
        printf("1이상의 숫자를 입력해주세요.");
    }


    return 0;
}
```


<br>
<br>
<br>
<br>
<hr>

# 02. 랜덤 수 이용하기

## - Step 01

stdlib.h에 있는 rand()함수를 사용하면 된다.

```c
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
```

문제는 프로그램을 몇 번을 돌려도 다음과 같은 일정한 결과가 나온다

```
1 7 4 0 9 4 8 8 2 4 5 5 1 7 1 1 5 2 7 6 1 4 2 3 2 2 1 6 8 5
1 7 4 0 9 4 8 8 2 4 5 5 1 7 1 1 5 2 7 6 1 4 2 3 2 2 1 6 8 5
1 7 4 0 9 4 8 8 2 4 5 5 1 7 1 1 5 2 7 6 1 4 2 3 2 2 1 6 8 5
1 7 4 0 9 4 8 8 2 4 5 5 1 7 1 1 5 2 7 6 1 4 2 3 2 2 1 6 8 5
```

원인은 Seed값이 일정하게 잡혀있기 때문이다.

## - Step 02

rand()함수는 srand()함수에 의존적이다.

즉, srand()함수를 통해 rand()함수의 Seed값을 설정할 수 있다.

만일 srand()함수를 따로 호출하거나 Seed값을 설정해 준적이 없다면

srand(1)가 된다.

```c
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
```
아래를 보면 `Step 01`의 결과와 동일하다.
```
1 7 4 0 9 4 8 8 2 4 5 5 1 7 1 1 5 2 7 6 1 4 2 3 2 2 1 6 8 5
1 7 4 0 9 4 8 8 2 4 5 5 1 7 1 1 5 2 7 6 1 4 2 3 2 2 1 6 8 5
1 7 4 0 9 4 8 8 2 4 5 5 1 7 1 1 5 2 7 6 1 4 2 3 2 2 1 6 8 5
1 7 4 0 9 4 8 8 2 4 5 5 1 7 1 1 5 2 7 6 1 4 2 3 2 2 1 6 8 5
```

즉, srand()에 들어가는 파라미터 값을 계속 변화시켜주면 된다.

## - Step 03

time.h에 있는 time()함수를 사용하여 Seed값을 설정해주자

time(NULL)로 호출하면 1970년 1월 1일 00:00:00(UTC)부터 현재까지 흐른 시간을 반환받을 수 있다(단위 : 초).

```c
#include <stdio.h>
#include <stdlib.h> //rand(), srand()
#include <time.h> //time()

/* 랜덤수 이용하기*/
//rand()        0 ~ 32767
//srand()       rand()의 Seed값 설정
//time(NULL)    1970년 1월 1일  00:00:00(UTC)부터 현재까지 흐른 시간을 반환(초)
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
```
rand()함수를 호출할 때마다 Seed값이 달라지기 때문에(시간은 흐르기 때문에) 매 실행마다 랜덤한 값을 볼 수 있다.
```
8 4 6 3 2 0 6 9 0 1 9 1 3 0 1 1 5 8 3 6 9 0 4 1 4 4 6 4 1 1
1 2 2 8 6 6 9 2 4 3 1 5 2 6 4 9 5 5 4 1 5 3 1 5 9 3 7 9 6 8
4 3 8 4 1 3 1 5 5 4 3 9 3 5 8 9 5 0 5 7 2 4 6 2 2 3 5 7 9 6
7 1 3 7 8 0 4 8 9 4 5 3 4 1 2 8 5 7 5 4 8 5 2 6 7 2 6 3 2 1
```



<br>
<br>
<br>
<br>
<hr>

# 03. 피보나치 수열 계산하기

## - Step 01
```c
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
```

## - Step 02 : 함수 사용

<br>
<br>
<br>
<br>
<hr>

# 04. 진법 변환
## - 변환된 진법 출력

```c
#include <stdio.h>

/* 진법 변환 */
// 10진법 -> 8진법
// 10진법 -> 16진법
int main()
{
    int decimal;
    printf("[진법 변환]\n");
    printf("숫자를 입력해주세요 : ");
    scanf("%d", &decimal);
    printf("8진법  : %o\n", decimal);
    printf("16진법 : %x\n", decimal);

    return 0;
}
```
```
[진법 변환]
숫자를 입력해주세요 : 15
8진법  : 17
16진법 : f
```
C언어에는 10진수->8진수, 10진수->16진수는 각각 %o, %x를 이용한 출력이 가능하지만

2진법 출력해주는 것을 따로 만들어주어야 한다.

## - 비트연산을 이용한 10진수 -> 2진수

다음과 같은 특징을 이용하면 비트를 오른쪽으로 이동할 때마다 2씩 나누는 효과를 볼 수 있다.
```c
#include <stdio.h>

int main()
{
    printf("%d\n", 52 >> 1); //26
    printf("%d\n", 52 >> 2); //13
    printf("%d\n", 52 >> 3); //6
    printf("%d\n", 52 >> 4); //3
    printf("%d\n", 52 >> 5); //1
    printf("%d\n", 52 >> 6); //0
    printf("%d\n", 52 >> 7); //0
    printf("%d\n", 52 >> 8); //0
    printf("%d\n", 52 >> 9); //0

    return 0;
}
```
홀수일 경우에는 첫번째 자리의 2진수가 1일 것이고 짝수면 0일 것이다. 이 특징을 이용하자.

```c
#include <stdio.h>

/* 진법 변환 */
// 10진법 -> 2진법
// 10진법 -> 8진법
// 10진법 -> 16진법
int bit_size(int decimal)
{
    int size = 0;
    
    while(1)
    {
        decimal /= 2;
        size++;
        if(decimal == 0)
        {
            break;
        }
    }

    return size;
}

void dec_to_bin(int decimal){
    int length = bit_size(decimal);
    int bin_nums[length];

    for(int i = 0; i < length; i++)
    {
        bin_nums[i] = (decimal >> i) & 1;
    }

    for(int i = length - 1 ; i >= 0; i--)
    {
        if((i+1) % 4 == 0 && i != length-1)
        {
            printf(" ");
        }
        printf("%d", bin_nums[i]);
    }
    
    printf("\n");
}

int main()
{
    int decimal;
    printf("[진법 변환]\n");
    printf("숫자를 입력해주세요 : ");
    scanf("%d", &decimal);
    dec_to_bin(decimal);
    printf("8진법  : %o\n", decimal);
    printf("16진법 : %x\n", decimal);

    return 0;
}
```

## - 다양한 진법으로의 변환

```c
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
```

<br>
<br>
<br>
<br>
<hr>

# 05. 대칭수 만들기

```c

```

<br>
<br>
<br>
<br>
<hr>

# 06. 영어 문장 암호화하기(카이사르 암호)

```c

```


<br>
<br>
<br>
<br>
<hr>

# 07. 팩토리얼 값 계산하기

```c

```

<br>
<br>
<br>
<br>
<hr>

# 08. 성적표 만들기

```c

```

<br>
<br>
<br>
<br>
<hr>

# 09. 별찍기

```c

```

<br>
<br>
<br>
<br>
<hr>

# 10. 행렬 연산

```c

```


