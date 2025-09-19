#include <stdio.h>
#include <stdlib.h>

// Function to get the matching opening bracket for a given closing bracket
char get_opening_bracket(char closing_bracket) {
    if (closing_bracket == ')') return '(';
    if (closing_bracket == '}') return '{';
    if (closing_bracket == ']') return '[';
    return '\0'; // Return null for invalid input
}

// Function to check if parentheses are balanced
int are_parentheses_balanced(char str[], int size) {
    char stack[size];
    int top = -1; // Stack pointer, initialized to -1 for an empty stack

    for (int i = 0; i < size; i++) {
        char current_char = str[i];

        // Push opening brackets onto the stack
        if (current_char == '(' || current_char == '{' || current_char == '[') {
            if (top < size - 1) { // Check for stack overflow
                stack[++top] = current_char;
            } else {
                // Handle stack overflow error, though unlikely in this context
                return 0;
            }
        }
        // Process closing brackets
        else if (current_char == ')' || current_char == '}' || current_char == ']') {
            // Check if stack is empty or if the top element doesn't match
            if (top == -1 || stack[top] != get_opening_bracket(current_char)) {
                return 0; // Mismatched or no corresponding opening bracket
            }
            top--; // Pop the matching opening bracket
        }
    }

    // The parentheses are balanced only if the stack is empty at the end
    return top == -1;
}

int main() {
    char c[] = "{(}";
    // Correct size calculation: sizeof(c) - 1 to exclude the null terminator
    int s = sizeof(c) - 1;

    if (are_parentheses_balanced(c, s)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
