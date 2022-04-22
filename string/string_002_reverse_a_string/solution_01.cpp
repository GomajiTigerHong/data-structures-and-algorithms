//time  complexity O(n)
//space complexity O(n)

#include <stdio.h>

int main()
{
    const char *A = "python";

    char B[10];

    int i;

    int j;

    for(i = 0; A[i] != '\0'; i++)
    {
        
    }

    i = i - 1;

    for(j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }

    B[j] = '\0';

    printf("%s\n",B);

    printf("%lu\n",sizeof(char));//1

    printf("%lu\n",sizeof(B));//10

    return 0;
}
