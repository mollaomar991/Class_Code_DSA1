
//for Fixed INput

// #include <stdio.h>
// #include <stdlib.h>

// struct Link_list {
//     int data;
//     struct Link_list *pointer;
// };

// typedef struct Link_list Link_list; 

// Link_list* FindMiddle(Link_list* head) {
//     Link_list* slow = head;
//     Link_list* fast = head;

//     while (fast != NULL && fast->pointer != NULL) {
//         slow = slow->pointer;
//         fast = fast->pointer->pointer;
//     }
//     return slow;
// }

// int main() {
//     Link_list *start, *b, *c, *d,*end;

//     start = (Link_list*)malloc(sizeof(Link_list));
//     b = (Link_list*)malloc(sizeof(Link_list));
//     c = (Link_list*)malloc(sizeof(Link_list));
//     d = (Link_list*)malloc(sizeof(Link_list));
//     end = (Link_list*)malloc(sizeof(Link_list));

//     start->data = 2;
//     b->data = 3;
//     c->data = 1;
//     d ->data=7;
//     end->data = 9;

//     start->pointer = b; 
//     b->pointer = c;
//     c->pointer = d;
//     d->pointer=end;
//     end->pointer = NULL;  

//     Link_list* middle = FindMiddle(start);

//     printf("The middle element of the linked list is: %d\n", middle->data);
    


//     return 0;
// }


//From user input

#include <stdio.h>
#include <stdlib.h>

struct Link_list {
    int data;
    struct Link_list *pointer;
};

typedef struct Link_list Link_list;

Link_list* CreateNode(int data) {
    Link_list* newNode = (Link_list*)malloc(sizeof(Link_list));
    newNode->data = data;
    newNode->pointer = NULL;
    return newNode;
}

Link_list* InputLinkedList(int n) {
    int data;
    Link_list *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter  elements :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        newNode = CreateNode(data);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->pointer = newNode;
            temp = temp->pointer;
        }
    }
    return head;
}

Link_list* FindMiddle(Link_list* head) {
    Link_list* slow = head;
    Link_list* fast = head;

    while (fast != NULL && fast->pointer != NULL) {
        slow = slow->pointer;
        fast = fast->pointer->pointer;
    }
    return slow;
}

int main() {
    int n;
    printf("Enter Number of the element : ");
    scanf("%d", &n);

    // if (n % 2 == 0) {
    //     printf("Please enter an odd number of elements.\n");
    //     return 1;
    // }

    Link_list* head = InputLinkedList(n);
    Link_list* middle = FindMiddle(head);

    printf("The middle element of the linked list is: %d\n", middle->data);

    return 0;
}

