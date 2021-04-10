# About C Language

## - History

 - 기계어
 - 어셈블리어(1950초 : Grace Hopper), 기호언어
 - 고급언어(`Fortran -> Algol -> CPL -> BCPL -> B -> C`)
    - [Genealogy of Programming Languages](https://www.thinglink.com/scene/536427472728621058)


## - Structure

 - 코드(code) 영역 : 실행할 프로그램의 코드, CPU가 하나씩 가져가서 처리
 - 데이터(data) 영역 : global 변수, static 변수, 프로그램 종료시 소멸
 - 스택(stack) 영역 : local 변수와 parameter, 호출이 완료되면 소멸
 - 힙(heap) 영역 : 직접관리하는 사용자 메모리 영역, 동적으로 할당되고 해제됨


## - 실행 순서

 - 소스 파일(.c)
 - 컴파일러( preprocessor | translator ) + 어셈플러
 - 기계어(.o)
 - 링커(含 표준 라이브러리 파일.o)
 - 실행 파일(.exe)

## - 주석

```c
// 라인 주석

/*
    멀티 주석
    멀티 주석

    //라인 주석
*/
```

## - 입출력

### * printf() 함수

```c
#include <stdio.h>

int main()
{
    printf("Hello\nWorld! : %d, %s", 10, "Ten");

    return 0;
}
```

### * scanf() 함수

```c
#include <stdio.h>

int main()
{
    int num1, num2;

    printf("---더하기---\n");
    printf("첫번째 정수 : ");
    scanf("%d", &num1);
    printf("두번째 정수 : ");
    scanf("%d", &num2);

    printf("result : %d", num1 + num2);

    return 0;
}
```

#### 인코딩 문제 발생시

```command
chcp 650001
```

<br><br><br><br><br>

<hr>

<br><br><br><br><br>

# 변수, 상수, 타입

## - 명명법

영문자, 숫자, 언더스코어로만 구성

키워드 NO NO

변수는 메모리의 주소를 기억하는 역할

## - 변수 할당

```
타입 변수이름;
```

## - 상수

### * literal

변수든 상수든 담아야 메모리 공간을 할당받는다.

```c
123 //정수
3.14 //실수
'a' //문자
```

### * symbolic constant

```c
const int PI = 3.14; //심볼릭 상수
#define PI 3.14; //선행처리 지시자를 이용한 매크로 심볼릭 상수
```

## - 타입

### * 정수형
 - char, short, int, long

### * 실수형
 - float, double

### * signed and unsigned

 - `signed` : 양수, 0

 - `unsigned` : 음수, 부호가 없는 것. 범위는 같지만 양수의 범위를 더 표현 가능

`int`가 제일 빠름, `double`은 표현 범위가 float보다 크고 정밀도도 정확함

### * 캐스팅

#### 묵시적 캐스팅

```c
#include <stdio.h>

int main()
{
    int num = 3.14;
    double pi = 3.14;

    printf("num : %d\n", num); //3
    printf("pi : %f\n", pi);   //3.140000

    return 0;
}
```

### 명시적 캐스팅

```c
#include <stdio.h>

int main()
{
    double result1 = 1 / 3;
    double result2 = (double)1 / 3;

    printf("num : %f\n", result1); //0.000000
    printf("pi : %f\n", result2);  //0.333333

    return 0;
}
```

<br><br><br><br><br>

<hr>

<br><br><br><br><br>

# 연산자

## - 산술연산

`+, -, *, /, %`

## - 복합연산(대입연산)

`=, +=, -=, *=, /=, %=`

## - 증감연산

### * 전위 및 후위

 - 전위 : `++x, --x`

 - 후위 `x++, x--`

## - 비교연산

`==, !=, >, >=, <, <=`

## - 논리연산

`&&, ||, !`

### * 효율적인 연산

## - 비트연산

 - AND : `&`
 - OR : `|`
 - XOR : `^`
 - NOT : `~`
 - shift : `<<`, `>> : 부호 유지`

## - 삼항연산

```
조건식 ? true 부분 : false 부분;
```

## - `sizeof()`

메모리의 크기

## - 포인터연산

 - `&` : 주소연산
 - `*` : 참조연산

<br><br><br><br><br>

<hr>

<br><br><br><br><br>

# 제어문

## - 조건문

### * if문

```c
if(조건식)
{
    statement
}
else if(조건식)
{
    statement
}
else
{
    statement
}
```

```c
#include <stdio.h>

int main()
{
    if (5 < 3)
    {
        printf("if문이 참이다.");
    }
    else if (5 > 3)
    {
        printf("else if 문이 참이다."); //여기가 출력됨
    }
    else
    {
        printf("참이 없다.");
    }

    return 0;
}
```

### * switch문

```c
#include <stdio.h>

int main()
{

    int choice = 2;

    switch (choice)
    {
    case 1:
        printf("choice : 1");
        break;
    case 2:
        printf("choice : 2"); // 여기가 출력됨
        break;
    case 3:
        printf("choice : 3");
        break;
    default:
        break;
    }

    return 0;
}
```

## - 반복문

### * while문

### * do~while문

### * for문

```c
for (초기식; 조건식; 증감식)
{
    statement
}
```

### * continue & break

<br><br><br><br><br>

<hr>

<br><br><br><br><br>

# 함수

## - 출력과 리턴의 차이

## - 함수 정의

```c
int sum(int x, int y)
{
    return x + y;
}
```

## - 함수 원형 선언과 사용

```c
int sum(int, int); //함수 원형 선언

int main()
{
    int result = sum(10, 20);
    printf("%d", result); //30
    return 0;
}

int sum(int x, int y)
{
    return x + y;
}
```

## - 전역변수, 지역변수, 정적변수, 레지스터변수

### * 전역변수 : 프로그램 종료시 소멸

`extern` 키워드로 함수 외부에 선언. 프로그램 전체 적용

### * 지역변수 : 함수 종료시 소멸

`auto` 함수 블록 내부에 선언. 함수 블록 내부에 적용

### * 정적변수 : 프로그램 종료시 소멸

`static` 함수 블록 내부에 선언. 함수 블록 내부에 적용

### * 레지스터변수 : 함수 종료시 소멸

`register` 함수 블록 내부에 선언. 함수 블록 내부에 적용

CPU의 레지스터 메모리에 저장되어 빠르게 접근 가능

레지스터는 아주 작은 크기의 메모리



<br><br><br><br><br>

<hr>

<br><br><br><br><br>

# 배열

## - 1차원 배열

```c
int num = 10;
int numArr[3] = {10, 20, 30};
int nums[] = {100, 200, 300}; //배열 크기 자동 설정

//C 컴파일러는 배열의 길이를 전혀 신경쓰지 않기 때문에 주의 해야 한다.
numArr[5] = 111; //선언안된 배열에 넣어짐
printf("%d", numArr[5]); //111 (출력되어 버린다...)
```

### * 배열의 길이

```c
int num = 10;
int numArr[3] = {10, 20, 30};
int nums[] = {100, 200, 300}; //배열 크기 자동 설정

int length = sizeof(nums) / sizeof(int);
printf("배열의 길이 : %d\n", length);

for (int i = 0; i < length; i++)
{
    printf("%d번째 배열 value : %d\n", i + 1, nums[i]);
}
```

## - 2차원 배열

```c
int oneArr[6] = {10, 20, 30, 40, 50, 60};
/* 
선형구조의 메모리에서 
10, 20, 30 은 twoArr[0]로 되고 
40, 50, 60은 twoArr[1]이 됨 
*/
int twoArr[2][3] = {10, 20, 30, 40, 50, 60};

int twoArr2[2][3] = {
    {10, 20, 30},
    {40, 50, 60}};

printf("oneArr의 크기 \t\t%d\n", sizeof(oneArr));
printf("oneArr[0]의 크기 \t%d\n", sizeof(oneArr[0]));
printf("oneArr의 길이 \t\t%d\n", sizeof(oneArr) / sizeof(int));

printf("twoArr의 크기 \t\t%d\n", sizeof(oneArr));
printf("twoArr[0]의 크기 \t%d\n", sizeof(twoArr[0]));
printf("twoArr의 길이 \t\t%d\n", sizeof(twoArr) / sizeof(int));
```

OUTPUT :
```
oneArr의 크기           24
oneArr[0]의 크기        4
oneArr의 길이           6
twoArr의 크기           24
twoArr[0]의 크기        12
twoArr의 길이           6
```

<br><br><br><br><br>

<hr>

<br><br><br><br><br>

# 포인터

## - `&` and `*`

### * 주소연산자(&)

변수의 주소값을 반환한다.(ampersand, 앰퍼샌드)

### * 참조연산자(*)

포인터의 이름이나 주소 앞에 사용, 포인터가 가리키는 주소에 저장되어 있는 값을 반환.


#### 활용 1 : Sharing

```c
int num = 10;
printf("%d\n", num);
printf("%d\n", &num);
printf("%p\n", num);
printf("%p\n", &num);

/* 
10                  : 숫자 10
6422044             : 주소값
000000000000000A    : 숫자 10(2진법)
000000000061FE1C    : 주소값(2진법)
*/

int *p = &num;
int *pp = p;

printf("pp : %d\n", pp);
printf("&pp: %d\n", &pp);
printf("p  : %d\n", p);
printf("&p : %d\n", &p);
/* 
pp : 6422044
&pp: 6422024
p  : 6422044
&p : 6422032

p가 num의 주소값을 그대로 pp에게 전달하였음.
결론적으로 p와 pp는 같은 주소를 값으로 갖는다.
*/

printf("=============\n");

printf("*pp : %d\n", *pp); //10
printf("*p  : %d\n", *p);  //10
```

#### 활용 2 : Linking

```c
int num = 10;
int *p = &num;
int **pp = &p; //위치도 주소, 값도 주소이므로 두번 참조 : 이중 포인터

printf("pp ( %d ) : %d\n", pp, &pp);
printf("p  ( %d ) : %d\n", p, &p);
printf("num( %d ) : %d\n", num, &num);

/* 
pp ( 6422032 ) : 6422024
p  ( 6422044 ) : 6422032
num( 10 ) : 6422044
    */
```

## - Call By Value, Call By Reference

```c
#include <stdio.h>

void callByVal(int);

void callByRef(int *);

int main()
{
    int num = 7;
    callByVal(num);
    printf("After Call By Value : %d\n", num);

    callByRef(&num);
    printf("After Call By Reference : %d\n", num);
}

void callByVal(int num)
{
    num = 20;
}

void callByRef(int *num)
{
    *num = 20;
}
```

## - 포인터를 이용한 매개변수로써의 함수 활용

함수 포인터

```c
#include <stdio.h>

int add(int, int);

int mul(int, int);

int calculator(int, int, int (*func)(int, int));

int main()
{
    int (*add_calc)(int, int) = add;
    int (*mul_calc)(int, int) = mul;
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
```

## - 포인터를 이용한 배열 다루기

```js
#include <stdio.h>

void printArray(int arr[], int count) // 배열의 포인터와 요소의 개수를 받음
{
    printf("포인터 변수 크기 : %d\n", sizeof(*arr)); //포인터 변수 자체의 크기가 출력
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int numArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", sizeof(numArr) / sizeof(int));
    printArray(numArr, sizeof(numArr) / sizeof(int)); // 배열과 요소의 개수를 넣음

    return 0;
}
```

<br><br><br><br><br>

<hr>

<br><br><br><br><br>

# main 함수 활용 (수정 필요)

```c
int main(int argc, char *argv[])
{
    printf("argc : %d\n", argc);
    for (int i = 1; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    return 0;
}
```
OUTPUT
```cmd
CMD> ./sample 안 녕 하 세 요
argc : 6
sample.exe
안
녕
하
세
요
```

<br><br><br><br><br>

<hr>

<br><br><br><br><br>

# 구조체(수정 필요)

```c
#include <stdio.h>  

 

struct book

{

    char title[30];

    char author[30];

    int price;

};  

 

int main(void)

{

    struct book my_book = {"HTML과 CSS", "홍길동", 28000};

    struct book java_book = {.title = "Java language", .price = 30000};  

 

    printf("첫 번째 책의 제목은 %s이고, 저자는 %s이며, 가격은 %d원입니다.\n",

        my_book.title, my_book.author, my_book.price);

    printf("두 번째 책의 제목은 %s이고, 저자는 %s이며, 가격은 %d원입니다.\n",

        java_book.title, java_book.author, java_book.price);

    return 0;

}
```

```c
#include <stdio.h>  

 

typedef struct

{

    char title[30];

    char author[30];

    int price;

}  TEXTBOOK;  

 

int main(void)

{

    TEXTBOOK my_book = {"HTML과 CSS", "홍길동", 28000};

    TEXTBOOK java_book = {.title = "Java language", .price = 30000};  

 

    printf("첫 번째 책의 제목은 %s이고, 저자는 %s이며, 가격은 %d원입니다.\n",

        my_book.title, my_book.author, my_book.price);

    printf("두 번째 책의 제목은 %s이고, 저자는 %s이며, 가격은 %d원입니다.\n",

        java_book.title, java_book.author, java_book.price);

    return 0;

}
```