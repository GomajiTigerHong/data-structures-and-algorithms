//time  complexity O(n)
//space complexity O(1)

#include <stdio.h>

int main() {
    
    const char *A = "finding";

    int Hash[26] = { 0 };

    int i;

    for (i = 0 ; A[i] != '\0' ; i++) {
        Hash[A[i] - 97] += 1;
    }

    for (i = 0 ; i < 26 ; i++) {
        if (Hash[i] > 1) {
            printf("%c", i + 97);
            printf("%d", Hash[i]);
        }
    }

    return 0;
}