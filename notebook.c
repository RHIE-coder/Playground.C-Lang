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