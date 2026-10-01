#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    char stack[10000];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        // Opening brackets → push
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }
        // Closing brackets → check top
        else {
            if (top == -1)
                return false;

            char topChar = stack[top--];

            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return top == -1;
}