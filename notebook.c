#include <stdio.h>

void printArray(int arr[], int count) // 배열의 포인터와 요소의 개수를 받음
{
    printf("함수 호출 후 : %s\n", type(*arr));
    printf("%d\n", sizeof(&arr) / sizeof(int));
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int numArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("함수 호출 전 : %s\n", type(numArr));
    printArray(numArr, sizeof(numArr) / sizeof(int)); // 배열과 요소의 개수를 넣음

    return 0;
}