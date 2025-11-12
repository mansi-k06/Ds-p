#include <stdio.h>

void selectionSort(int arr[], int n) {
    int minIndex, temp;
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

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return 1;  // Found
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}

int main() {
    int n;
    printf("Enter the number of students who attended the training: ");
    scanf("%d", &n);

    int rollNumbers[n];
    printf("Enter the roll numbers in random order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &rollNumbers[i]);
    }

    selectionSort(rollNumbers, n);

    int searchRollNo;
    printf("Enter the roll number to search: ");
    scanf("%d", &searchRollNo);

    if (binarySearch(rollNumbers, n, searchRollNo)) {
        printf("Student with roll number %d attended the training.\n", searchRollNo);
    } else {
        printf("Student with roll number %d did NOT attend the training.\n", searchRollNo);
    }

    return 0;
}
