#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void Create(int A[],int n,struct Node * &head) {
    struct Node *node;
    struct Node *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (int i = 1 ; i < n ; i++) {
        node = (struct Node *)malloc(sizeof(struct Node));
        node->data = A[i];
        node->next = NULL;
        last->next = node;
        last = node;
    }
}

void Display(struct Node *head) {
    while (head) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void RDisplay(struct Node *p) {
    if (p) {
        RDisplay(p->next);
        printf("%d\n", p->data);
    }
}

int Count(struct Node *p) {
    int c = 0;
    while (p) {
        c++;
        p = p->next;
    }
    return c;
}

int RCount(struct Node *p) {
    if (p) {
        return RCount(p->next) + 1;
    } 
    else {
        return 0;
    }
}

int Sum(struct Node *p) {
    int s = 0;
    while (p) {
        s = s + p->data;
        p = p->next;
    }
    return s;
}

int RSum(struct Node *p) {
    if (p) {
        return RSum(p->next) + p->data;
    }
    else {
        return 0;
    }
}

int Max(struct Node *p) {
    int max = INT32_MIN;
    while (p) {
        if (p->data > max) {
            max = p->data;   
        }
        p = p->next;
    }
    return max;
}

int RMax(struct Node *p) {
    int x = 0;
    if (!p) {
        return INT32_MIN;
    }
    x = RMax(p->next);
    if (x > p->data) {
        return x;
    }
    else {
        return p->data;
    }
}

struct Node * Search(struct Node * p, int key, struct Node * &first) {
    struct Node *q;
    while (p) {
        if (key == p->data) {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void Insert(struct Node * &first, int index, int x) {
    struct Node * temp;
    if (index < 0 || index > Count(first)) {
        return ;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;

    if (index == 0) {
        temp->next = first;
        first = temp;
    }
    else {
        for (int i = 0 ;i < index ; i++) {
            first = first->next;   
        }
        temp->next = first->next;
        first->next = temp;
    }
}

void SortedInsert(struct Node *p, int x, struct Node * &first) {
    struct Node *temp;
    struct Node *q = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (first == NULL) {
        first = temp;
    }
    else {
        while(p && p->data < x) {
            q = p;
            p = p->next;
        }
        if (p == first) {
            temp->next = first;
            first = temp;
        }
        else {
            temp->next = q->next;
            q->next = temp;
        }
    }
}

int Delete(struct Node * p, int index, struct Node * &first) {
    struct Node * q = NULL;
    int x = -1;
    if (index < 1 || index > Count(p)) {
        return x;
    }
    if (index == 1) {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else {
        for (int i = 0 ; i < index - 1 ; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

void RemoveDuplicate(struct Node * p) {
    struct Node * q = p -> next;
    while (q) {
        if (p -> data != q -> data) {
            p = q;
            q = q -> next;   
        }
        else {
            p -> next = q -> next;
            free(q);
            q = p->next;
        }
    }    
}

void ReverseOne(struct Node * p) {
    int * A;
    int i = 0;
    struct Node * q = p;
    A = (int *)malloc(sizeof(int) * Count(p));
    while (q) {
        A[i] = q->data;
        q = q->next;
        i++;
    } 
    q = p;
    i--;
    while (q) {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void ReverseTwo(struct Node * p, struct Node * &first) {
    struct Node * q = NULL;
    struct Node * r = NULL;
    while(p) {
        r = q;
        q = p;
        p = p ->next;
        q -> next = r;   
    }
    first = q;
}

void ReverseThree(struct Node * q, struct Node * p,struct Node * &first) {
    if (p) {
        ReverseThree(p,p->next,first);
        if (p == q) {
            p->next = NULL;
        }
        else {
            p->next = q;
        }
    }
    else {
        first = q;
    }
}

struct Node * Merge(struct Node * p , struct Node * q) {
    struct Node * last;
    struct Node * third;
    if (p->data < q->data) {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else {
        third = last = p;
        q = q->next;
        third->next = NULL;
    }
    while (p && q) {
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p) {
        last->next = p;
    }
    if (q) {
        last->next = q;
    }

    return third;
}

bool isLoop(struct Node * f) {
    struct Node * p;
    struct Node * q;
    p = q = f;
    do {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while(p && q && p!=q);

    if (p == q) {
        return true;
    }
    else {
        return false;   
    }
}

int main() {
    int A[] = {10,20,30,40,50,60,70,100};
    int B[] = {1,3,5,7,9};

    struct Node * first;
    struct Node * second;
    
    Create(A,8,first);
    Create(B,5,second);

    struct Node * t1 = first->next->next;
    struct Node * t2 = first->next->next->next->next;

    t2->next = t1;

    printf("%d\n",isLoop(first));
    printf("%d\n",isLoop(second));
    return 0;
}