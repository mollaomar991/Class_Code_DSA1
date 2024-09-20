#include<stdio.h>

int Find_MissingNumber(int arr[],int n){
    int sum = 0;


    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    int SumOfNthNumber= (n * (n + 1)) / 2;

    return SumOfNthNumber-sum;

}

int main(){

int n;
printf("arr size: ");
scanf("%d",&n);

int arr[n-1];

printf("Enter Elements: ");
for(int i = 0;i<n-1;i++){
    scanf("%d",&arr[i]);
}

int MissingNUmber= Find_MissingNumber(arr,n);
printf("Missing NUmber is: %d",MissingNUmber);







    return 0;
}