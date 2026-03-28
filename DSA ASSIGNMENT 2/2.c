#include <stdio.h>
#define MAX 100

char stack[MAX];
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

// Function to check matching brackets
int match(char open, char close) {
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    return 0;
}

int main() {
    char exp[MAX];
    int i = 0;
    char ch;

    printf("Enter expression: ");
    scanf("%s", exp);

    while (exp[i] != '\0') {
        ch = exp[i];

        // If opening bracket, push
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // If closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            char popped = pop();

            if (popped == '\0' || !match(popped, ch)) {
                printf("Not Balanced Expression");
                return 0;
            }
        }

        i++;
    }

    // Final check
    if (top == -1)
        printf("Balanced Expression");
    else
        printf("Not Balanced Expression");

    return 0;
}