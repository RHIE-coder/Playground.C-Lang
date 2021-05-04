#include <stdio.h>

void readFile(FILE * file){
    char ch;
    while((ch=fgetc(file))!=NULL){
        putchar(ch);
    }
}

int main()
{
    FILE * file = fopen("sample.txt", "r");
    if(file != NULL){
        puts("sample.txt 열기 성공");
        
    }

    if(fclose(file) != EOF){ //fclose(file) == 0
        puts("sample.txt 닫기 성공");
    }
    
    return 0;
}