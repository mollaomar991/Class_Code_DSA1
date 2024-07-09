
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
    int sum =0;

    while(tempnode!= NULL)
    {

        printf(" %d",tempnode ->data);
        sum= tempnode -> data +sum;
        tempnode = tempnode ->pointer;
    }
    printf(" \nSum is : %d", sum);

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



}















