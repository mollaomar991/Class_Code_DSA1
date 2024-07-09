
#include <bits/stdc++.h>

using namespace std;


struct Link_list
{

    int data;
    Link_list *pointer;


};

typedef struct Link_list node;


void printLinkedList(node *first) // linklist er starting node janar jonno ba newar jonno
{
    node *tempnode =first; //

    while(tempnode!= NULL)
    {

        printf(" %d",tempnode ->data);
        tempnode = tempnode ->pointer; // temp node jare point koira ase tar kase jabe,, jemon 1st er por 2nd er por 3rd
    }

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















