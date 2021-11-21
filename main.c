#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "rpc.h"

int main() {

    repl();

    /* stack tests...
    Stack stack = stack_create();
    int i;
    int val;

    / * stack push * /
    puts("[**] stack push:");
    for (i=0; i<10;i++) {
        stack_push(s, i * 2);
    }
    printf("stack size: %d\n", stack_size(s));

    stack_dump(s);
    puts("");

    / * stack pop * /
    puts("[**] stack pop:");

    val = stack_pop(s);
    printf("val: %d\n", val);
    printf("stack size: %d\n", stack_size(s));
    stack_dump(s);

    for(i=0; i<4; i++)
        printf("poped value: %d\n", stack_pop(s));

    stack_dump(s);
    puts("");

    stack_destroy(s);

    ... It works!*/

    return 0;
}
