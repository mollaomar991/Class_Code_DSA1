#include<stdio.h>

int main()
{

    int n=4,i;
    int arr[100]= {4,6,3,9};
    int search_element=3;

    for(i=0; i<n; i++)
    {
        if(search_element==arr[i])
        {
            printf("Index %d",i);
             break;
        }
       // else(printf("Not Fount");)


        }





    return 0;
}
