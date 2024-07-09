#include<stdio.h>
int main()
{

    int n= 4;
    int arr[100]= {4,10,6,9};

    int temp,i;

    for( i=0; i<=n-2; i++)
    {
        for( int j=0; j<=n-2-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }



    return 0;
}
