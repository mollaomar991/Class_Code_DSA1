#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the linked list
struct node {
    int data;
    struct node* link;
};

// Declare front and rear pointers
struct node* front = NULL;
struct node* rear = NULL;

// Function to enqueue an element to the queue
void enqueue(int num) {
    // Create a new node
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    
    if (temp == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    
    temp->data = num;
    temp->link = NULL;

    // If the queue is empty, set both front and rear to the new node
    if (front == NULL) {
        front = rear = temp;
    } else {
        // Add the new node at the end of the queue and update the rear pointer
        rear->link = temp;
        rear = temp;
    }

    printf("Enqueued %d\n", num);
}

// Function to dequeue an element from the queue
void dequeue() {
    // Check if the queue is empty
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct node* temp = front;
    printf("Dequeued Value %d\n", temp->data);

    // Update the front pointer to the next node
    front = front->link;

    // If front becomes NULL, set rear to NULL as well (queue becomes empty)
    if (front == NULL) {
        rear = NULL;
    }

    // Free the dequeued node
    free(temp);
}

// Function to print the elements of the queue
void printQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    printQueue();

    dequeue();
    dequeue();
    dequeue();
    dequeue();

    printQueue();

    enqueue(5);
    enqueue(6);

    printQueue();

    dequeue();
    dequeue();

    printQueue();

    return 0;
}
