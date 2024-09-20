// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node* link;
// } *top = NULL;

// int isEmpty() {
//     return top == NULL;
// }

// void push(int data) {
//     struct node* newNode = (struct node*)malloc(sizeof(struct node));
//     if (newNode == NULL) {
//         printf("Stack Overflow.\n");
//         exit(1);
//     }
//     newNode->data = data;
//     newNode->link = top;
//     top = newNode;
// }

// int pop() {
//     if (isEmpty()) {
//         printf("Stack Underflow.\n");
//         exit(1);
//     }
//     struct node* temp = top;
//     int val = temp->data;
//     top = top->link;
//     free(temp);
//     return val;
// }

// struct ListNode {
//     int data;
//     struct ListNode* next;
// };

// int is_palindrome(struct ListNode* head) {
//     struct ListNode* slow = head;
//     struct ListNode* fast = head;

//     while (fast != NULL && fast->next != NULL) {
//         push(slow->data);
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     if (fast != NULL) slow = slow->next;

//     while (slow != NULL) {
//         int topData = pop();
//         if (topData != slow->data) {
//             return 0;
//         }
//         slow = slow->next;
//     }

//     return 1;
// }

// int main() {
//     struct ListNode *start, *b, *c, *end;

//     start = (struct ListNode*)malloc(sizeof(struct ListNode));
//     b = (struct ListNode*)malloc(sizeof(struct ListNode));
//     c = (struct ListNode*)malloc(sizeof(struct ListNode));
//     end = (struct ListNode*)malloc(sizeof(struct ListNode));

//     start->data = 1;
//     b->data = 2;
//     c->data = 2;
//     end->data = 1;

//     start->next = b; 
//     b->next = c;
//     c->next = end;
//     end->next = NULL; 

//     if (is_palindrome(start)) {
//         printf("Yes, the linked list is a palindrome.\n");
//     } else {
//         printf("No, the linked list is not a palindrome.\n");
//     }

//     return 0;
// }




#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
} *top = NULL;

int isEmpty() {
    return top == NULL;
}

void push(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Stack Overflow.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = top;
    top = newNode;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow.\n");
        exit(1);
    }
    struct node* temp = top;
    int val = temp->data;
    top = top->link;
    free(temp);
    return val;
}

struct ListNode {
    int data;
    struct ListNode* next;
};

int is_palindrome(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast != NULL) slow = slow->next;

    while (slow != NULL) {
        int topData = pop();
        if (topData != slow->data) {
            return 0;
        }
        slow = slow->next;
    }

    return 1;
}

int main() {
    struct ListNode *start, *b, *c, *end;

    start = (struct ListNode*)malloc(sizeof(struct ListNode));
    b = (struct ListNode*)malloc(sizeof(struct ListNode));
    c = (struct ListNode*)malloc(sizeof(struct ListNode));
    end = (struct ListNode*)malloc(sizeof(struct ListNode));

    start->data = 1;
    b->data = 2;
    c->data = 2;
    end->data = 1;

    start->next = b; 
    b->next = c;
    c->next = end;
    end->next = NULL; 

    if (is_palindrome(start)) {
        printf("Yes, the linked list is a palindrome.\n");
    } else {
        printf("No, the linked list is not a palindrome.\n");
    }

    return 0;
}
