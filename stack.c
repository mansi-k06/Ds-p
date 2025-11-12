#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* push(node* top, int x) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = top;
    return temp;
}

node* pop(node* top) {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return NULL;
    }
    printf("Popped: %d\n", top->data);
    node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

void display(node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}

int main() {
    node* top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    display(top);
    top = pop(top);
    display(top);
    return 0;
}
