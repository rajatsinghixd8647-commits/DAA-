#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    int k = 2;

    for (int r = 1; r <= k; r++) {

        int last = arr[n - 1];

        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = last;
    }

    printf("Array after rotation: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
