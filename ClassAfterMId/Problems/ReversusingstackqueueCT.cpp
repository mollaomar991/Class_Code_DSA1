#include <stdio.h>

#define MAX_SIZE 5

int Stack[MAX_SIZE];
int Queue[MAX_SIZE];
int top = -1;
int front = -1, rear = -1;

void enqueue(int num) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue Overflow\n");
        return;
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX_SIZE;
        Queue[rear] = num;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int num = Queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        return num;
    }
}

// Function to add an element to the stack
void push(int element) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    } else {
        top++;
        Stack[top] = element;
    }
}

// Function to remove an element from the stack
int pop() {
    if (top <= -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int y = Stack[top];
        top--;
        return y;
    }
}

// Function to reverse the stack using queue operations
void reverseStack() {
    while (top != -1) {
        enqueue(pop());
    }
    while (front != -1) {
        push(dequeue());
    }
}

// Function to print the contents of the stack
void printStack() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", Stack[i]);
        }
        printf("\n");
    }
}

int main() {
    // Example usage
    push(10);
    push(20);
    push(30);

    printf("Original stack:\n");
    printStack();

    reverseStack();

    printf("Reversed stack:\n");
    printStack();

    return 0;
}
