#include <stdio.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++s->top] = value;
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return s->items[s->top--];
}

int isParenthesesBalanced(char sentence[]) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == '(' || sentence[i] == '{' || sentence[i] == '[') {
            push(&stack, sentence[i]);
        } else if (sentence[i] == ')' || sentence[i] == '}' || sentence[i] == ']') {
            if (isEmpty(&stack)) {
                return 0;
            }
            char top = pop(&stack);
            if ((sentence[i] == ')' && top != '(') ||
                (sentence[i] == '}' && top != '{') ||
                (sentence[i] == ']' && top != '[')) {
                return 0;
            }
        }
    }

    return isEmpty(&stack);
}

int main() {
    char sentence[100];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    if (isParenthesesBalanced(sentence)) {
        printf("Balanced\n");
    } else {
        printf("Not balanced\n");
    }

    return 0;
}
