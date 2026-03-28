#include <stdio.h>
#define max 100

int stack[max];
int top = -1;

// Push function
void push(int x) {
    stack[++top] = x;
}

// Pop function
int pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

// Peek function
int peek() {
    return stack[top];
}

// Check if stack is empty
int isEmpty() {
    return top == -1;
}

int main() {
    int arr[max], n, i;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    push(arr[0]);

    for (i = 1; i < n; i++) {
        int next = arr[i];

        while (!isEmpty() && next > peek()) {
            printf("%d -> %d\n", pop(), next);
        }

        push(next);
    }

    // Remaining elements
    while (!isEmpty()) {
        printf("%d -> -1\n", pop());
    }

    return 0;
}