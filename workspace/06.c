#include <stdio.h>


//영어 대문자 : 65 ~ 90
//영어 소문자 : 97 ~ 122

int isUppercase(char ch)
{
  return ch >= 65 && ch <= 90;
}

int isLowercase(char ch)
{
  return ch >= 97 && ch <= 122;
}

int encrypt(char ch, int key)
{
  //65 ~ 90
  if(isUppercase(ch))
  {
    ch += key;
    if(ch > 90)
    {
      int over_num = ch - 90;
      ch = 64 + over_num;
    }
  }
  //97 ~ 122
  else if(isLowercase(ch))
  {
    ch += key;
    if(ch > 122)
    {
      int over_num = ch - 122;
      ch = 96 + over_num;
    }
  }
  return ch;

}

int decrypt(char ch, int key)
{
   //65 ~ 90
  if(isUppercase(ch))
  {
    ch -= key;
    if(ch < 65)
    {
      int over_num = 65 - ch;
      ch = 91 - over_num;
    }
  }
  //97 ~ 122
  else if(isLowercase(ch))
  {
    ch -= key;
    if(ch < 97)
    {
      int over_num = 97 - ch;
      ch = 123 - over_num;
    }
  }
  return ch;
}

int main()
{
  char plain[] = "xy ab ejfien dkv fdsaf";
  int key = 3;

  printf("원본의 내용 : %s\n",plain);

  //문자열 길이 구하기
  int length = 0;
  int index = 0;
  while(plain[index] != '\0')
  {
    length++;
    index++;
  }

  printf("원본의 길이 : %d\n", length);

  char E[length];
  for(int i = 0; i < length; i++)
  {
    E[i] = encrypt(plain[i], key);
  }

  printf("암호화한 후의 내용 : %s\n",E);

  char D[length];
  for(int i = 0; i < length; i++)
  {
    D[i] = decrypt(E[i], key);
  }

  printf("해독한 후의 내용 : %s\n",D);



  return 0;
}