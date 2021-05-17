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

## - 전역변수, 지역변수, 정적변수, 레지스터변수(no detail)

@차이 알려주기

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


## - 


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
#include <stdio.h>

int main()
{
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

    printf("twoArr의 크기 \t\t%d\n", sizeof(twoArr));
    printf("twoArr[0]의 크기 \t%d\n", sizeof(twoArr[0]));
    int element_len = sizeof(twoArr[0]) / sizeof(twoArr[0][0]);
    printf("twoArr의 길이 \t\t%d\n", (sizeof(twoArr) / element_len) / sizeof(int));

    printf("twoArr2의 크기 \t\t%d\n", sizeof(twoArr2));
    printf("twoArr2[0]의 크기 \t%d\n", sizeof(twoArr2[0]));
    int element_len2 = sizeof(twoArr2[0]) / sizeof(twoArr2[0][0]);
    printf("twoArr2의 길이 \t\t%d\n", (sizeof(twoArr2) / element_len2) / sizeof(twoArr2[0][0]));
    return 0;
}
```

OUTPUT :
```
oneArr의 크기 		24
oneArr[0]의 크기 	4
oneArr의 길이 		6
twoArr의 크기 		24
twoArr[0]의 크기 	12
twoArr의 길이 		2
twoArr2의 크기 		24
twoArr2[0]의 크기 	12
twoArr2의 길이 		2
```

@ 내림차순, 오름차순 알려주기

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

###### tip
void 포인터는 주소값을 저장하는 것 이외에는 아무것도 할 수 없는 포인터

사용시 명시적 형변환이 필요하다

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
    printf("add_calc : %d\n", add_calc(10, 20));
    int (*mul_calc)(int, int) = mul;
    printf("mul_calc : %d\n", mul_calc(10, 20));
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
출력결과
```
add_calc : 30
mul_calc : 200
add : 30
mul : 200
```

## - 포인터를 이용한 배열 다루기
```c
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

# 메모리 관리

(code) - (data) - (stack) - (heap)

 - code : 실행 프로그램의 코드
 - data : Global 변수, Static 변수
 - heap : 동적 할당
 - stack : 지역변수, 매개변수

## - 동적 할당

### * malloc()

### * calloc()

### * realloc()

<br><br><br><br><br>

<hr>

<br><br><br><br><br>

# 문자열

## - 문자

### * getchar()

```c
scanf("%c",&ch);
ch = getchar();
```
위 두 코드는 같다.

### * putchar()
```c
printf("%c",ch);
putchar(ch);
```
위 두 코드는 같다.

### * 두 함수의 콤비네이션

```c
#include <stdio.h>

int main()
{
    char ch;
    
    while((ch = getchar()) != '\n'){
        putchar(ch);
    }
    return 0;
}
```

## - 문자열


### * NULL
C언어에서는 문자열이 끝나면 '\0'(NULL)을 포함한다.

```c
#include <stdio.h>

int main()
{
    char str[] = "Hello World";

    int length = 0;
    while(str[length] != '\0')
    {
        length++;
    }

    printf("문자열의 길이는 %d입니다.\n",length); //11
}
```


### * gets()

```c
char str[50];
gets(str);
printf("%s", str);
```
자동개행됨

### * puts()

```c
char str[50] = "Hello World";
puts(str);
```
자동개행됨

## - string.h

### * strlen(), strcat(), strcpy(), strcmp()

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "Hello World";
    char str2[] = "123";

    //strlen()
    printf("strlen : %d\n", strlen(str1)); //11

    //strcat()
    printf("cat전 str1 : %s\n", str1);           //"Hello World"
    printf("strcat : %s\n", strcat(str1, str2)); //Hello World123
    printf("cat후 str1 : %s\n", str1);           //Hello World123
    //오버플로우 세이프티 strncat()
    char cat_str1[12] = "#";
    strcat(cat_str1, str1);
    printf("%c\n", cat_str1[14]); //오버플로우 되어 출력됨 : 3
    char cat_str2[12] = "#";
    strncat(cat_str2, str1, 12);
    puts(cat_str2);               //#Hello World1 (길이는 13)
    printf("%c\n", cat_str2[12]); //1

    //strcpy()
    char str3[] = "strings data";
    char str4[20];
    strcpy(str4, str3);
    printf("%s\n", str4); //strings data
    //오버플로우 세이프티 strncpy()
    char cpy_str[9];
    strncpy(cpy_str, str3, sizeof(cpy_str) - 1);
    printf("%s\n", cpy_str); //strings

    //strcmp()
    char str5[] = "korea";
    char str6[] = "china";
    char str7[] = "korea";

    printf("compare korea-china : %d\n", strcmp(str5, str6)); //compare korea-china : 1 
    printf("compare korea-korea : %d\n", strcmp(str5, str7)); //compare korea-korea : 0
    /*
        양수 : 첫번째 파라미터가 더 큼
        0 : 같음
        음수 : 두번째 파라미터가 더 큼
    */

}
```
## - stdlib.h

### * atoi(), atol(), atoll(), atof()

문자열을 ~
 - atoi() : int형 정수로 변환
 - atol() : long형 정수로 변환
 - atoll() : long long형 정수로 변환
 - atof() : 실수로 변환(stdlib.h) - 8byte의 double

## - ctype.h

### * toupper(), tolower()

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char *str = "My Name Is James";

    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c", toupper(str[i]));
    } //MY NAME IS JAMES

    putchar('\n');

    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c", tolower(str[i]));
    } //my name is james

    return 0;
}
```

<br><br><br><br><br>

<hr>

<br><br><br><br><br>


# main 함수 활용

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

# 구조체

새롭게 정의 하는 사용자 타입

## - 구조체 정의하기&선언하기

```c
struct human
{  
    char name[10];
    int age;
};

struct human student;
```
활용하기
```c
#include <stdio.h>

struct human
{
    char name[100];
    int age;
};

void info(struct human someone)
{
    printf("이 사람의 이름은 %s이며, 나이는 %d살입니다.\n",someone.name, someone.age);
}

int main()
{

    struct human student = {"Eddie", 15};
    struct human businessman = {.name="Alice", .age=30};

    info(student); //이 사람의 이름은 Eddie이며, 나이는 15살입니다.
    info(businessman); //이 사람의 이름은 Alice이며, 나이는 30살입니다.
    

    return 0;
}
```

## - typedef

매번 struct 키워드를 명시하는게 불편

그러므로 typedef으로 간략화

```c
#include <stdio.h>

struct human
{
    char name[100];
    int age;
};


typedef struct human HUMAN;

void info(HUMAN someone)
{
    printf("이 사람의 이름은 %s이며, 나이는 %d살입니다.\n",someone.name, someone.age);
}

int main()
{   
    HUMAN student = {"Eddie", 15};
    HUMAN businessman = {.name="Alice", .age=30};

    info(student); //이 사람의 이름은 Eddie이며, 나이는 15살입니다.
    info(businessman); //이 사람의 이름은 Alice이며, 나이는 30살입니다.
    

    return 0;
}
```
동시에 할 수도 있음

```c
#include <stdio.h>

typedef struct
{
    char name[10];
    int age;
}HUMAN;

void info(HUMAN someone)
{
    printf("이 사람의 이름은 %s이며, 나이는 %d살입니다.\n",someone.name, someone.age);
}

int main()
{   
    HUMAN student = {"Eddie", 15};
    HUMAN businessman = {.name="Alice", .age=30};

    info(student); //이 사람의 이름은 Eddie이며, 나이는 15살입니다.
    info(businessman); //이 사람의 이름은 Alice이며, 나이는 30살입니다.
    

    return 0;
}
```

## - 구조체 배열

```C
#include <stdio.h>

typedef struct
{
    char name[10];
    int age;
} HUMAN;

void info(HUMAN someone)
{
    printf("이 사람의 이름은 %s이며, 나이는 %d살입니다.\n", someone.name, someone.age);
}

int main()
{
    HUMAN humans[3] = {
        {"Alice", 10},
        {"Bob", 20},
        {"Charlie", 30}};

    int len = sizeof(humans) / sizeof(humans[0]);

    for (int i = 0; i < len; i++)
    {
        info(humans[i]);
    }
    /*
    이 사람의 이름은 Alice이며, 나이는 10살입니다.
    이 사람의 이름은 Bob이며, 나이는 20살입니다.
    이 사람의 이름은 Charlie이며, 나이는 30살입니다.
    */

    return 0;
}
```

## - 구조체 안에 구조체

```c
#include <stdio.h>

typedef struct
{
    char reg_num[30];
    char issue_addr[10];
    char country[20];
}IDENTITY;

typedef struct
{
    char name[10];
    int age;
    IDENTITY identity;
} HUMAN;

void info(HUMAN someone)
{
    IDENTITY tmp = someone.identity;
    printf("이 사람의 이름은 %s이며, 나이는 %d살입니다.\n", someone.name, someone.age);
    printf("그리고 신분증 정보는 다음과 같습니다. [주민번호:%s, 발급지:%s, 국적:%s]\n",
            tmp.reg_num, tmp.issue_addr, tmp.country);
}

int main()
{
    HUMAN humans[3] = {
        {.name = "Alice", .age = 10, .identity={"1234", "서울", "한국"}},
        {"Bob", 20, {.reg_num="2345", .issue_addr = "뉴욕", .country = "미국"}},
        {"Charlie", 30, {"3456", "베이징","중국"}}};

    int len = sizeof(humans) / sizeof(humans[0]);

    for (int i = 0; i < len; i++)
    {
        info(humans[i]);
    }
    /*
    이 사람의 이름은 Alice이며, 나이는 10살입니다.
    그리고 신분증 정보는 다음과 같습니다. [주민번호:1234, 발급지:서울, 국적:한국]
    이 사람의 이름은 Bob이며, 나이는 20살입니다.
    그리고 신분증 정보는 다음과 같습니다. [주민번호:2345, 발급지:뉴욕, 국적:미국]
    이 사람의 이름은 Charlie이며, 나이는 30살입니다.
    그리고 신분증 정보는 다음과 같습니다. [주민번호:3456, 발급지:베이징, 국적:중국]
    */

    return 0;
}
```


<br><br><br><br><br>

<hr>

<br><br><br><br><br>

# 열거체

```c
#include <stdio.h>

enum Services
{
    LOGIN, REGISTER, ORDER=5
};//0, 1, 2

int main()
{
    int sel = 1;

    switch(sel){
        case LOGIN:
            puts("로그인 서비스");
            break;

        case REGISTER:
            puts("회원가입 서비스");
            break;
        
        case ORDER:
            puts("주문 서비스");
            break;
    }//회원가입 서비스

    printf("%d %d %d\n", LOGIN, REGISTER, ORDER); //0 1 5

    return 0;
}
```



<br><br><br><br><br>

<hr>

<br><br><br><br><br>

# 파일

## - 파일 읽고 쓰기 fgetc(), fputc()

### * text 파일 

```c
#include <stdio.h>
#include <stdlib.h> //exit(1)

int main()
{
    char ch;

    FILE * origin_file = fopen("sample.txt","r");
    FILE * copy_file = fopen("sample_copy.txt","w");

    if(origin_file != NULL)
    {
        while((ch = fgetc(origin_file))!=EOF)
        {
            // printf(ch); error
            fputc(ch, stdout);
            fputc(ch,copy_file);
        }
    }

    printf("\n");

    if(fclose(origin_file)==0)
    {
        printf("success to close file");
    }
    else
    {
        exit(1);
    }
    return 0;
}
```

- fclose()
 
성공적으로 닫으면 0 반환, 닫지 못하면 EOF

### * 바이너리 파일

```c
#include <stdio.h>
#include <stdlib.h> //exit(1)

int main()
{
    char byte;

    FILE * origin_file = fopen("sample.jpg","rb");
    FILE * copy_file = fopen("sample_copy.jpg","wb");

    if(origin_file != NULL)
    {
        while(!feof(origin_file))
        {
            byte = fgetc(origin_file);
            // printf(ch); error
            fputc(byte,copy_file);
        }
    }

    printf("\n");

    if(fclose(origin_file)==0)
    {
        printf("success to close file");
    }
    else
    {
        exit(1);
    }
    return 0;
}
```

<br><br><br>




