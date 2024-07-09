
#include <bits/stdc++.h>

using namespace std;


struct Link_list
{

    int data;
    Link_list *pointer;


};

typedef struct Link_list node;


void printLinkedList(node *first)
{
    node *tempnode =first;

    while(tempnode!= NULL)
    {

        printf(" %d",tempnode ->data);

        tempnode = tempnode ->pointer;
    }

}

int maximum(node *first){

    int maxVal = -9999;

    node* tempnode = first;

    while (tempnode != NULL) {
        if (tempnode->data > maxVal) {
            maxVal = tempnode->data;
        }
        tempnode = tempnode->pointer;
    }
    return maxVal;
}

int main()
{

    node  *first,*second,*third,*fourth;


    first = new node ();
    second= new node();
    third=new node();
    fourth=new node();


    first->data = 10;
    second-> data =20;
    third-> data =30;
    fourth->data =40;



    first-> pointer =second;
    second-> pointer = third;
    third->pointer=fourth;
    fourth ->pointer= NULL;


    printLinkedList(first);
    int maxVal = maximum(first);
    printf(" \nMaximum Value is %d ",maxVal);



}















