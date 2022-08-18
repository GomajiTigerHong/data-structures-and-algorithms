//time  complexity O(n)
//space complexity O(1)

#include <stdio.h>

int main() {

    const char *A = "finding";

    int hash = 0;

    int temp = 0;

    int i;

    for (i = 0 ; A[i] != '\0' ; i++) {
        temp = 1 << (A[i] - 97);

        if ((temp & hash) > 0) {
            printf ("%c is duplicate\n", A[i]);
        }
        if ((temp & hash) == 0) {
            hash = temp | hash;
        }
    }

    return 0;
}