#include <stdio.h>
#include <stdlib.h>

#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} OneLinkList;

#define BRACES_TYPES 3
const char BRACES[BRACES_TYPES][2] = {{'[', ']'}, {'(', ')'}, {'{', '}'}};

void initStack(OneLinkList *stack)
{
    stack->head = NULL;
    stack->size = 0;
}

boolean pushStack(OneLinkList *stack, char value)
{
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        printf("Stack overflow\n");

        return false;
    }
    tmp->data = value;
    tmp->next = stack->head;
    stack->head = tmp;
    stack->size++;

    return true;
}

char popStack(OneLinkList *stack)
{
    if (stack->size == 0) {
        printf("Stack is empty\n");

        return '-';
    }
    Node *tmp = stack->head;
    char data = stack->head->data;
    stack->head = stack->head->next;
    stack->size--;
    free(tmp);

    return data;
}

boolean isValidPair(char openBrace, char closeBrace)
{
    for (int i = 0; i < BRACES_TYPES; ++i) {
        if (BRACES[i][0] == openBrace && BRACES[i][1] == closeBrace) {

            return true;
        }
    }

    return false;
}

int checkBrace(char sym)
{
    for (int i = 0; i < BRACES_TYPES; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (BRACES[i][j] == sym) {
                
                return j;
            }
        }
    }

    return -1;
}

boolean checkBraces(char* str)
{
    int symbol_type;
    OneLinkList *st = (OneLinkList*) malloc(sizeof(OneLinkList));
    initStack(st);
    for (int i = 0; str[i] != '\0'; ++i) {
        symbol_type = checkBrace(str[i]);
        if (symbol_type == 0) {
            pushStack(st, str[i]);
        } else if (symbol_type == 1 && !isValidPair(popStack(st), str[i])) {
            free(st);

            return false;
        }
    }
    boolean result = st->size == 0;
    free(st);

    return result;
}

void printOneLinkList(OneLinkList* stack)
{
    if (stack->size == 0) {
        printf("[]");
    } else {
        Node *node = stack->head;
        for (int i = 0; i < stack->size; ++i) {
            printf("[%c] ", node->data);
            node = node->next;
        }
    }
    printf("\n");
}

char getNodeData(OneLinkList* stack, int pos)
{
    Node *node = stack->head;
    for (int i = 0; i < pos; ++i) {
        node = node->next;
    }

    return node->data;
}

void copyOneLinkList(OneLinkList* from, OneLinkList* to)
{
    for (int i = from->size - 1; i >= 0; --i) {
        pushStack(to, getNodeData(from, i));
    }
}

boolean isStackSorted(OneLinkList* stack)
{
    Node *node = stack->head;
    for (int i = 0; i < stack->size - 1; ++i) {
        if (node->data < node->next->data) {

            return false;
        }
        node = node->next;
    }

    return true;
}

int main(int argc, const char** argv)
{
    char str1[] = "(2+{2*2})";
    printf("String '%s' is %svalid\n", str1, checkBraces(str1) ? "" : "not ");
    char str2[] = "{2/{5*(4+7)]";
    printf("String '%s' is %svalid\n", str2, checkBraces(str2) ? "" : "not ");

    OneLinkList *stack_from = (OneLinkList*) malloc(sizeof(OneLinkList));
    initStack(stack_from);
    for (int i = 0; i < 10; ++i) {
        pushStack(stack_from, 97 + i);
    }
    OneLinkList *stack_to = (OneLinkList*) malloc(sizeof(OneLinkList));
    initStack(stack_to);
    copyOneLinkList(stack_from, stack_to);
    printOneLinkList(stack_from);
    printOneLinkList(stack_to);

    printf("Stack is %ssorted\n", isStackSorted(stack_to) ? "" : "not ");
    pushStack(stack_to, 99);
    printf("Stack is %ssorted\n", isStackSorted(stack_to) ? "" : "not ");

    return 0;
}
