#include <stdio.h>

void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayTop5(float arr[], int n) {
    int count = n < 5 ? n : 5;
    printf("\nTop %d Scores:\n", count);
    for (int i = n - 1; i >= n - count; i--) {
        printf("%.2f\n", arr[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    float percentages[n];
    printf("Enter the percentage of each student:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &percentages[i]);
    }

    bubbleSort(percentages, n);
    displayTop5(percentages, n);

    return 0;
}
