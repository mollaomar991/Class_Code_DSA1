#include <bits/stdc++.h>

using namespace std;


struct Link_list
{

    int data;
    Link_list *pointer;


};



typedef struct Link_list node; //Define node as pointer of data type struct LinkedList

int main()
{

    node  *start, *b, *c;

    start = new node ();

    start->data = 10;                   // -> for acces pointer data or address


    b= new node();
    c= new node();


    b-> data =20;
    b-> pointer = c;

    c-> data = 30;
    c->pointer = null


    start-> pointer = b;//star er ponter er sathe b k linlk kore disi ;

    b-> pointer = c;    //b er pointer er sathe c k link kore disi

    printf(" %d %d %d",start->data,start ->pointer ->data, b-> pointer ->data);


}













