
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

void KthLargest(int array[], int N, int K) {
    sort(array, N);
    int newSize = removeDuplicates(array, N);

      printf("The %dth largest element is: %d\n", K, array[newSize - K]);
    
}

int main() {
    int N, K;


    printf("Array Size (N) : ");
    scanf("%d", &N);

    int array[N];

    printf("Enter Elements : ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    printf("Kth largest Number: ");
    scanf("%d", &K);

    KthLargest(array, N, K);

    return 0;
}

