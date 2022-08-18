//time  complexity O(n)
//space complexity O(1)

#include <stdio.h>

int main() {

    const char *A = "painter";

    const char *B = "painter";

    int i;

    int j;

    for (i = 0 , j = 0 ; A[i] != '\0' && B[j] != '\0' ; i++ , j++) {
        if (A[i] != B[j]) {
            break;
        }
    }

    if (A[i] == B[j]) {
        printf("equal");
    }
    if (A[i] < B[j]) {
        printf("smaller");
    }
    if (A[i] > B[j]) {
        printf("greater");
    }

    return 0;
}