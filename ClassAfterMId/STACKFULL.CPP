#include<stdio.h>
#include<stdlib.h>  

#define MAX 4
int top = -1;
int str_arr[MAX];

int isEmpty(){
    return (top == -1);
}

int isFull(){
    return (top == MAX - 1);
}

int peek(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    return str_arr[top];
}

void push(int data){
    if(isFull()){
        printf("Stack Overflow\n");
        exit(1);
    }
    else{
        top++;
        str_arr[top] = data;
    }
}

int pop(){
    int y;

    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    else{
        y = str_arr[top];
        top--;
        return y;
    }
}

void print(){
    int i;
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    else{
        for(i = top; i >= 0; i--){
            printf("%d ", str_arr[i]);
        }
        printf("\n");
    }
}

int main(){
    int Choice, data;

    while(1){
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the Top element\n");
        printf("4. Print All elements\n");
        printf("5. Exit\n");

        printf("Enter your Choice: ");
        scanf("%d", &Choice);

        switch(Choice){
            case 1:
                printf("Enter Element: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                data = pop();
                printf("Popped element: %d\n", data);
                break;

            case 3:
                printf("Top element: %d\n", peek());
                break;

            case 4:
                print();
                break;

            case 5: 
                exit(0);

            default:
                printf("Wrong Choice\n");
        }
    }
    return 0;
}
