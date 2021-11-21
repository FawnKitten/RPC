
#ifndef STACK_H
#define STACK_H

#define BP(n) printf("*** bp %d\n", n)

typedef struct Stack_t* Stack;

Stack stack_create();
void stack_destroy(Stack stack);

int stack_pop(Stack stack);
int stack_peek(Stack stack);
void stack_push(Stack stack, int value);

int stack_size(Stack stack);
void stack_dump(Stack stack);

#endif /* STACK_H */
