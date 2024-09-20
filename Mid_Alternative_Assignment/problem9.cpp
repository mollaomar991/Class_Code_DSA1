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

    printf("Enter elements \n");
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

Link_list* MergeLists(Link_list* l1, Link_list* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (l1->data < l2->data) {
        l1->pointer = MergeLists(l1->pointer, l2);
        return l1;
    } else {
        l2->pointer = MergeLists(l1, l2->pointer);
        return l2;
    }
}

void PrintList(Link_list* head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->pointer;
    }
    printf("NULL\n");
}

int main() {
    int n, m;

    printf("Enter Number of Element in A : ");
    scanf("%d", &n);
    Link_list* list1 = InputLinkedList(n);

    printf("Enter Number of Element in B: ");
    scanf("%d", &m);
    Link_list* list2 = InputLinkedList(m);

    Link_list* mergedHead = MergeLists(list1, list2);

    printf("The merged linked list is: ");
    PrintList(mergedHead);

    return 0;
}
