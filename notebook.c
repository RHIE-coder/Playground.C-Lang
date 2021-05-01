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
