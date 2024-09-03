#include <stdio.h>

#define n 3

int stk[n], top = -1;

void push(int x)
{
    if (top >= n - 1)
    {
        printf("\n Stack Overflow");
    }
    else
    {
        top++;
        stk[top] = x;
    }
}

int pop()
{
    int y;
    if (top <= -1)
    {
        printf("\n Stack Underflow");
        return -1;
    }
    else
    {
        y = stk[top];
        top--;
        return y;
    }
}

int main()
{
    push(5);
    push(2);
    push(6);


    int poppedItem = pop();

    printf("Popped item: %d\n", poppedItem);


    return 0;
}
