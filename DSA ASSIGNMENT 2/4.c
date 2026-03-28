#include <stdio.h>
#include <string.h>

#define MAX 5

char queue[MAX][50];
int front = -1;
int rear = -1;

// Enqueue (Add document)
void enqueue() {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;

    printf("Enter document name: ");
    scanf("%s", queue[rear]);

    printf("Document added to queue\n");
}

// Dequeue (Print document)
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow (No documents to print)\n");
        return;
    }

    printf("Printing document: %s\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Display queue
void display() {
    int i;

    if (front == -1) {
        printf("No pending documents\n");
        return;
    }

    printf("Pending documents:\n");
    for (i = front; i <= rear; i++) {
        printf("%s\n", queue[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Printer Queue Menu ---\n");
        printf("1. Add Document\n");
        printf("2. Print Document\n");
        printf("3. Display Documents\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}