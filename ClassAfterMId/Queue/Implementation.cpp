#include <stdio.h>
#define MAX 4

int arr[MAX];
int front = -1, rear = -1;

void enqueue(int num)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
        return;
    }
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = num;
        printf("Enqueued %d\n", num);
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Dequeued Value %d\n", arr[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    dequeue();
    dequeue();
    dequeue();
    dequeue();

    enqueue(5);
    enqueue(6);

    dequeue();
    dequeue();

    return 0;
}
