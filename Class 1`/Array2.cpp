#include <stdio.h>

int main() {
    int array[100],i;
     int max=array[0];

    for(i=0;i<5;i++){
        scanf("%d",&array[i]);
    }

    for (i = 0; i < 5; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    printf("%d",max);

}

