#include <stdio.h>

void selectionSort(float arr[], int n) {
    int minIndex;
    float temp;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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

    selectionSort(percentages, n);
    displayTop5(percentages, n);

    return 0;
}
