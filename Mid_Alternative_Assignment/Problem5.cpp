#include <stdio.h>

int max_adjacent_sum(int arr[], int n) {
    int max_sum = arr[0] + arr[1];

    for (int i = 1; i < n-1; i++) {
        int sum = arr[i] + arr[i+1];
        if (sum > max_sum) {
            max_sum = sum;
        }
    }

    return max_sum;
}

int main() {
    int n;


    printf("Array Size (n) : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter Elements : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_sum = max_adjacent_sum(arr, n);
    printf("The maximum sum of two adjacent elements is: %d\n", max_sum);

    return 0;
}
