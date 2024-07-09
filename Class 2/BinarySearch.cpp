#include <stdio.h>

int main() {

    int n = 5;
    int arr[100] = {30,40,20,10,50};
    int search_element = 50;

    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] > search_element) {
            high = mid - 1;
        }
        else if (arr[mid] < search_element) {
            low = mid + 1;
        }
        else {
            printf("%d", mid);

            return 0;
        }
    }

}
