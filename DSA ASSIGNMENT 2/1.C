#include <stdio.h>
#include <string.h>

#define max 100

char stack[max];
int top = -1;

// Push function
void push(char x) {
    stack[++top] = x;
}

// Pop function
char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

int main() {
    char str[max];
    int i, length;

    printf("Enter a string: ");
    scanf("%s", str);

    length = strlen(str);

    // Push all characters into stack
    for (i = 0; i < length; i++) {
        push(str[i]);
    }

    // Pop characters to reverse string
    for (i = 0; i < length; i++) {
        str[i] = pop();
    }

    printf("Reversed string = %s", str);

    return 0;
}