#include <bits/stdc++.h>

using namespace std;


struct Link_list
{

    int data;
    Link_list *pointer;


};



typedef struct Link_list node;

int main()
{

    node  *start, *b, *c ,*d;


    start = new node ();
    b= new node();
    c= new node();
    d= new node();

    start->data = 10;
    b-> data =20;
    c-> data = 30;
    d-> data= 40;



    start-> pointer = c;
    b-> pointer = c;
    c-> pointer=d;
    d-> pointer =start;


    printf(" %d %d %d %d",start->data, start ->pointer ->data, b-> pointer ->data,  c-> pointer -> data);


}















