#include <stdio.h>

int binary_search(int arr[], int n, int k) {
    int left = 0;
    int right = n - 1;
    int mid, count = 0;

    while (left <= right) {
        
        mid = (left + right) / 2;

        count ++;

        if (arr[mid] == k) {
            return count;
        }
        if (arr[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
}

int main() {
    int N, i, k;

    printf("Array Size: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter Elements: ");
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        arr[i]=i+1; //1 theke N er jonno
    }

    printf("Enter K: ");
    scanf("%d", &k);

    int steps = binary_search(arr, N, k);
        printf("The minimum steps will be needed is : %d\n", steps);

    return 0;
}


