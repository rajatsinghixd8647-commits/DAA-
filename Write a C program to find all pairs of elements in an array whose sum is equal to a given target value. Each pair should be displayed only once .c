#include <stdio.h>

int main() {
    int arr[] = {2, 7, 4, 5, 1, 3};
    int n = 6;
    int target = 6;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            if (arr[i] + arr[j] == target) {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }

        }
    }

    return 0;
}
