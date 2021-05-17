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