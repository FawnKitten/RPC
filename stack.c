
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"

struct Stack_t {
    int top;
    int* values;
};

static void* resize(void* ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    } else if (size == 0) {
        free(ptr);
        return NULL;
    } else {
        void* old_ptr = ptr;
        ptr = malloc(size);
        memcpy(ptr, old_ptr, size);
        return ptr;
    }
}


Stack stack_create() {
    Stack stack = malloc(sizeof(struct Stack_t));
    stack->values = NULL;
    stack->top = 0;
    return stack;
}

void stack_destroy(Stack stack) {
    free(stack->values);
    free(stack);
}

int stack_pop(Stack stack) {
    if (stack->values != NULL) {
        int value = stack->values[stack->top -1];
        stack->top--;
        stack->values = resize(stack->values, stack->top * sizeof(int));
        return value;
    } else {
        return 0;
    }
}

int stack_peek(Stack stack) {
    if (stack->values != NULL) {
        int value = stack->values[stack->top -1];
        return value;
    } else {
        return 0;
    }
}

void stack_push(Stack stack, int value) {
    stack->top += 1;
    stack->values = resize(stack->values, stack->top * sizeof(int));
    stack->values[stack->top -1] = value;
}

int stack_size(Stack stack) {
    return stack->top;
}

void stack_dump(Stack stack) {
    int i;
    if (stack->top == 0)
        puts("stack is empty");
    for (i=0; i<stack->top; i++)
        printf("stack[%d]: %d\n", i, stack->values[i]);
    puts("");
}
