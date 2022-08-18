//time  complexity O(n)
//space complexity O(1)

#include <stdio.h>

int main() {

    const int dick[] = {1,2,3,4};

    const char *A = "deciamalsss";

    const char *B = "medicalsss";

    int i = 0;

    int hash[26] = { 0 };

    for (i = 0 ; A[i] != '\0' ; i++) {
        hash[A[i] - 97]++;
    }

    for (i = 0 ; B[i] != '\0' ; i++) {
        hash[B[i] - 97]--;
        if (hash[B[i] - 97] < 0) {
            printf("not anagram\n");
            break;
        }
    }

    if (B[i] == '\0') {
        printf("is anagram\n");
    }

    return 0;
}