#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    printf("Enter the number of students who attended the training: ");
    scanf("%d", &n);

    int rollNumbers[n];
    printf("Enter the roll numbers of the students in random order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &rollNumbers[i]);
    }

    int searchRollNo;
    printf("Enter the roll number to search: ");
    scanf("%d", &searchRollNo);

    if (linearSearch(rollNumbers, n, searchRollNo)) {
        printf("Student with roll number %d attended the training.\n", searchRollNo);
    } else {
        printf("Student with roll number %d did NOT attend the training.\n", searchRollNo);
    }

    return 0;
}
