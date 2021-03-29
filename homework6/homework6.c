#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    int priority;
    int data;
} Node;

Node* arr[SIZE];
int items;

void init()
{
    items = 0;
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = NULL;
    }
}

void ins(int pr, int data)
{
    if (items < SIZE) {
        Node *node = (Node*) malloc(sizeof(Node));
        node->priority = pr;
        node->data = data;
        arr[items++] = node;
    } else {
        printf("Queue is full\n");
    }
}

Node* rem()
{
    if (items == 0) {
        printf("Queue is empty\n");

        return NULL;
    }
    int ind = 0;
    int max = 0;
    for (int i = 0; i < items; ++i) {
        if (arr[i]->priority > max) {
            max = arr[i]->priority;
            ind = i;
        }
    }
    Node *tmp = arr[ind];
    for (int i = ind; i < (items - 1); ++i) {
        arr[i] = arr[i + 1];
    }
    arr[--items] = NULL;

    return tmp;
}

void printQueue()
{
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == NULL) {
            printf("[*, *] ");
        } else {
            printf("[%d, %d] ", arr[i]->priority, arr[i]->data);
        }
    }
    printf("\n");
}

#define true 1 == 1
#define false 1 != 1
typedef int boolean;

#define T char
#define SZ 1000

int cursor = -1;
T Stack[SZ];

boolean pushStack(T data) {
    if (cursor < SZ) {
        Stack[++cursor] = data;

        return true;
    } else {
        printf("Stack overflow\n");

        return false;
    }
}

T popStack() {
    if (cursor != -1) {

        return Stack[cursor--];
    } else {
        printf("Stack is empty\n");

        return -1;
    }
}

void dec2Bin(int num) {
    while (num >= 1) {
        pushStack(num % 2);
        num /= 2;
    }
}

int main(int argc, const char** argv)
{
    init();
    ins(2, 30);
    ins(3, 31);
    ins(1, 32);
    ins(2, 33);
    ins(4, 34);
    ins(2, 35);
    ins(1, 36);
    ins(5, 37);
    ins(4, 38);
    ins(3, 39);
    printQueue();
    for (int i = 0; i < 5; ++i) {
        Node* elem = rem();
        printf("Remove: [%d, %d]\n", elem->priority, elem->data);
    }
    printQueue();

    int number;
    printf("\nPlease inter unsigned integer number: ");
    scanf("%d", &number);
    dec2Bin(number);
    int cnt = cursor;
    for (int i = 0; i <= cnt; ++i) {
        printf("%d", popStack());
    }

    return 0;
}
