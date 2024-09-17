#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push a character onto the stack
void push(char x) {
    if (top >= MAX - 1) {
        printf("\nStack Overflow");
    } else {
        top++;
        stack[top] = x;
    }
}

// Function to pop a character from the stack
char pop() {
    if (top <= -1) {
        printf("\nStack Underflow");
        return '\0'; // Return null character if stack is empty
    } else {
        char y = stack[top];
        top--;
        return y;
    }
}

int main() {
    char str[MAX], reversedStr[MAX];
    int i;

    // Accept input string
    printf("Input a string: ");
    fgets(str, MAX, stdin);

    // Remove newline character at the end (from fgets)
    str[strcspn(str, "\n")] = '\0';

    // Push each character of the string onto the stack
    for (i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    // Pop each character from the stack to get the reversed string
    for (i = 0; top != -1; i++) {
        reversedStr[i] = pop();
    }
    reversedStr[i] = '\0'; // Null-terminate the reversed string

    // Print the reversed string
    printf("Reversed string: %s\n", reversedStr);

    return 0;
}
