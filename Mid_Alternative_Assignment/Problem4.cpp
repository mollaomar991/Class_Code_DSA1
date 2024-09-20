#include <stdio.h>

void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) { 
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;
    
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}

int main() {
    int n;
    printf("Array Size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter Elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    sort(arr, n);

    
    int newLength = removeDuplicates(arr, n);

    printf("There are total %d distinct elements.\n", newLength);


   

    return 0;
}
