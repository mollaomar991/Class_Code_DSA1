#include <stdio.h>
#include <stdlib.h>

struct Link_list {
    int data;
    struct Link_list *pointer;
};

typedef struct Link_list Link_list; 

int Check_Loop(struct Link_list* head) {
    struct Link_list* slow = head;
    struct Link_list* fast = head;

    while (fast != NULL && fast->pointer != NULL) {
        slow = slow->pointer;
        fast = fast->pointer->pointer;

        if (slow == fast) {
            return 1; 
        }
    }

    return 0; 
}

int main() {
    Link_list *start, *b, *c , *end;

    start = (Link_list*)malloc(sizeof(Link_list));
    b = (Link_list*)malloc(sizeof(Link_list));
    c = (Link_list*)malloc(sizeof(Link_list));
    end = (Link_list*)malloc(sizeof(Link_list));

    start->data =3;
    b->data = 2;
    c->data = 30;
    end ->data = -4;
   
    

    start->pointer = b; 
    b->pointer = c;
    c -> pointer = end;
    end -> pointer =b;   

    if (Check_Loop(start)) {
        printf("Yes the linked list has a loop.\n");
    } else {
        printf("No, the linked list doesn’t have a loop.\n");
    }

    return 0;
}
