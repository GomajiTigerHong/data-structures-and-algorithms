#include <stdio.h>

struct Matrix {
    int A[10];
    int n;
};

void Set(struct Matrix *m , int i , int j , int x) {
    if (i == j) {
        m->A[i-1] = x;
    }
}

int Get(struct Matrix *m , int i , int j) {
    if (i == j) {
        return m->A[i-1];
    }
    if (i != j) {
        return 0;
    }
}

void Display(struct Matrix *m) {
    for (int i = 0 ; i < m->n ; i++) {
        for (int j = 0 ; j < m->n ; j++) {
            if (i == j) {
                printf("%d ", m->A[i]);
            }
            if (i != j) {
                printf("0 ");
            }  
        }
        printf("\n");
    }
}

int main() {
    struct Matrix m;
    m.n = 4;
    Set(&m,1,1,5);
    Set(&m,2,2,6);
    Set(&m,3,3,7);
    Set(&m,4,4,8);
    printf("%d \n",Get(&m,2,2));
    Display(&m);
    return 0;
}