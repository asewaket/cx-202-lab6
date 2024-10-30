#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

void push(int **stack, int *top, int *capacity, int value) {
    if (*top == *capacity - 1) {
        *capacity *= 2;
        int *new_stack = (int*)realloc(*stack, *capacity * sizeof(int));
        if (new_stack == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
        *stack = new_stack;
    }
    (*stack)[++(*top)] = value;
}

int pop(int **stack, int *top, int *capacity) {
    if (*top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    int value = (*stack)[(*top)--];
    // Consider shrinking the array if it's too large
    if (*top + 1 == *capacity / 4) {
        *capacity /= 2;
        int *new_stack = (int*)realloc(*stack, *capacity * sizeof(int));
        if (new_stack == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
        *stack = new_stack;
    }
    return value;
}

void display(int *stack, int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Current stack: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int *stack = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (stack == NULL) {
        printf("Initial memory allocation failed.\n");
        return 1;
    }
    int top = -1, capacity = INITIAL_CAPACITY;

    char command;
    int value;

    while (1) {
        printf("Enter a command (p: push, o: pop, d: display, e: exit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'p':
                printf("Enter an integer to push: ");
                scanf("%d", &value);
                push(&stack, &top, &capacity, value);
                break;
            case 'o':
                value = pop(&stack, &top, &capacity);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 'd':
                display(stack, top);
                break;
            case 'e':
                printf("Exiting the program. All memory has been freed.\n");
                free(stack);
                return 0;
            default:
                printf("Invalid command. Please try again.\n");
        }
    }
}
