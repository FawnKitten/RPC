
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"
#include "rpc.h"

/* #define DEBUG */

static char* skip_space(char* text) {
    while (isspace(*text))
        text++;
    return text;
}

#define BUFF_SIZE 50
static char* get_next_token(char** text) {
    char buff[BUFF_SIZE];
    char* res;
    int i;
#ifdef DEBUG
    fputs(*text, stdout);
#endif
    *text = skip_space(*text);
    if (*text == NULL || **text == '\0') {
        return NULL;
    } else if (**text == '+') {
        res = malloc(2);
        strcpy(res, "+");
        goto res;
    } else if (**text == '-') {
        res = malloc(2);
        strcpy(res, "-");
        goto res;
    } else if (**text == '*') {
        res = malloc(2);
        strcpy(res, "*");
        goto res;
    } else if (**text == '/') {
        res = malloc(2);
        strcpy(res, "/");
        goto res;
    } else if (isdigit(**text)) {
        for (i=0; i<BUFF_SIZE-1; i++) {
            if(isdigit(**text))
                buff[i] = **text;
            else {
                buff[i] = '\0';
                break;
            }
            (*text)++;
        }
#ifdef DEBUG
        printf("buff: %s\n", buff);
#endif
        res = malloc(strlen(buff));
        assert(res);
        strcpy(res, buff);
#ifdef DEBUG
        printf("res: %s\n", res);
#endif
        return res;
    } else {
        printf("Invalid character '%x'\n", **text);
        exit(1);
        return NULL;
    }
res:
    (*text)++;
#ifdef DEBUG
    printf("result: %s\n", res);
#endif
    return res;
}

long calculate(char* text) {
    char* token = get_next_token(&text);
    long a, b;
    long res;
    Stack stack = stack_create();
#ifdef DEBUG
#define MAX_ITER 50
    int current_iter = 0;
#endif
    while (token) {
#ifdef DEBUG
        current_iter++;
        assert(current_iter < MAX_ITER);
        printf("token: %s", token);
#endif
        if(isdigit(*token)) {
            stack_push(stack, atoi(token));
        } else if (*token == '+') {
            a = stack_pop(stack);
            b = stack_pop(stack);
            stack_push(stack, a+b);
        } else if (*token == '-') {
            a = stack_pop(stack);
            b = stack_pop(stack);
            stack_push(stack, b-a);
        } else if (*token == '/') {
            a = stack_pop(stack);
            b = stack_pop(stack);
            stack_push(stack, b/a);
        } else if (*token == '*') {
            a = stack_pop(stack);
            b = stack_pop(stack);
            stack_push(stack, b*a);
        }
        free(token);
        token = get_next_token(&text);
    }
    free(token);
    assert(stack_size(stack) == 1);
    res = stack_pop(stack);
    stack_destroy(stack);
    return res;
}

#define MAX_LEN_INPUT 100

void repl(void) {
    char text[MAX_LEN_INPUT];
    long value = 0;
    int eval_number = 0;
    for (;;) {
        eval_number++;
        fputs("---> ", stdout);
        fgets(text, MAX_LEN_INPUT, stdin);
#ifdef DEBUG
        printf("text: |%s|\n", text);
#endif
        value = calculate(text);
        printf("(%d) %ld\n", eval_number, value);
    }
}
