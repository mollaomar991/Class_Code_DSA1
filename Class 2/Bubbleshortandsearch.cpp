#include <stdio.h>

int main() {

    int n = 5;
    int arr[100] = {30,40,20,10,50};
    int search_element = 20;
    int temp,i;

    int low = 0;
    int high = n - 1;
    int mid;

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
    printf("Sorted Array: ");
   for(i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
        printf("\n");
    while (low <= high) {



        mid = (low + high) / 2;

        if (arr[mid] > search_element) {
            high = mid - 1;
        }
        else if (arr[mid] < search_element) {
            low = mid + 1;
        }
        else {
            printf("Index is: %d\n", mid);

            return 0;
        }
    }

}

