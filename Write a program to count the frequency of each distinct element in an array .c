#include <stdio.h>

int main() {
    int arr[] = {10, 20, 10, 30, 20, 10};
    int n = 6;
    int count;

    for (int i = 0; i < n; i++) {
        count = 1;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        int alreadyCounted = 0;

        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) {
                alreadyCounted = 1;
                break;
            }
        }

        if (alreadyCounted == 0) {
            printf("%d occurs %d times\n", arr[i], count);
        }
    }

    return 0;
}
