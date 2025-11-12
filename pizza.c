#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char queue[MAX][20];  // Store job names (max 20 chars each)
int front = -1, rear = -1;
int max_orders;

void add_job() {
    if (rear == max_orders - 1) {
        printf("Queue full! Cannot accept more orders.\n");
        return;
    }

    char job[20];
    printf("Enter order name: ");
    scanf("%s", job);

    if (front == -1) {
        front = 0;  // first job added
    }

    rear++;
    strcpy(queue[rear], job);
    printf("Order '%s' added to the queue.\n", job);
}

void delete_job() {
    if (front == -1 || front > rear) {
        printf("No orders to serve. Queue is empty.\n");
        front = rear = -1;  // reset queue
        return;
    }

    printf("Order '%s' served and removed from the queue.\n", queue[front]);
    front++;

    if (front > rear) {
        front = rear = -1;  // reset queue when empty
    }
}

void display_queue() {
    if (front == -1) {
        printf("No orders in queue.\n");
        return;
    }

    printf("Current orders in queue:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d. %s\n", i - front + 1, queue[i]);
    }
}

int main() {
    int choice;

    printf("Enter maximum number of orders (M): ");
    scanf("%d", &max_orders);

    do {
        printf("\n--- Pizza Parlor Job Queue ---\n");
        printf("1. Add order\n");
        printf("2. Serve order\n");
        printf("3. Show orders\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_job();
                break;
            case 2:
                delete_job();
                break;
            case 3:
                display_queue();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    } while (choice != 4);

    return 0;
}
