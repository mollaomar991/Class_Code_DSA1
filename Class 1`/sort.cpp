#include<stdio.h>

int main(){

int n=4,a[n],temp,i,j;

for( i= 0; i<n;i++){
    scanf("%d",&a[i]);
}


for(i=0;i<n-2;i++)
{

    for(j=i+1;j<n;j++){
        if(a[i] > a[j]){
            temp=a[i];
            a[i]=a[j];
            a[j]= temp;
        }
    }
}

for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }



}
