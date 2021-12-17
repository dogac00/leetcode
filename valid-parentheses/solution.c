
/*
  This should be done with slack.h and slack.c files, but since LeetCode accepts solutions with one file,
  I put both definitions and declarations one file

  LeetCode: https://leetcode.com/problems/valid-parentheses/discuss/1631918/Runtime-0-ms-Faster-than-100-in-C
*/

/* stack definitions */

struct stack {
    int maxsize;
    int top;
    int *items;
};

struct stack *stack_create(int capacity);
void stack_destroy(struct stack* stack);
int stack_size(struct stack *pt);
int stack_is_empty(struct stack *pt);
int stack_is_full(struct stack *pt);
void stack_push(struct stack *pt, int x);
int stack_peek(struct stack *pt);
int stack_pop(struct stack *pt);

/* stack definitions end */

bool is_reverse_parenthesis(int first, int second) {
    if (first == '(' && second == ')')
        return true;
    if (first == '{' && second == '}')
        return true;
    if (first == '[' && second == ']')
        return true;
    return false;
}

bool isValid(char * s) {
    if (!s)
        return true;
    if (*s == '\0')
        return true;

    struct stack* stack = stack_create(10000);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' ||
            s[i] == '{' ||
            s[i] == '[') {
            stack_push(stack, s[i]);
        }
        else {
            if (stack_is_empty(stack))
                return false;

            int pop = stack_pop(stack);
            bool is_reverse = is_reverse_parenthesis(pop, s[i]);
            if (!is_reverse)
                return false;
        }
    }

    bool result = stack_is_empty(stack);
    stack_destroy(stack);
    return result;
}

/* stack declarations */

struct stack *stack_create(int capacity) {
    struct stack *pt = (struct stack *) malloc(sizeof(struct stack));

    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (int *) malloc(sizeof(int) * capacity);

    return pt;
}

void stack_destroy(struct stack* stack) {
    free(stack->items);
    free(stack);
}

int stack_size(struct stack *pt) {
    return pt->top + 1;
}

int stack_is_empty(struct stack *pt) {
    return pt->top == -1;                   // or return size(pt) == 0;
}

int stack_is_full(struct stack *pt) {
    return pt->top == pt->maxsize - 1;      // or return size(pt) == pt->maxsize;
}

void stack_push(struct stack *pt, int x) {
    // check if the stack is already full. Then inserting an element would
    // lead to stack overflow
    if (stack_is_full(pt)) {
        printf("Overflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    pt->items[++pt->top] = x;
}

int stack_peek(struct stack *pt) {
    if (!stack_is_empty(pt)) {
        return pt->items[pt->top];
    } else {
        exit(EXIT_FAILURE);
    }
}

int stack_pop(struct stack *pt) {
    if (stack_is_empty(pt)) {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    return pt->items[pt->top--];
}

/* stack declarations end */
