#include "stack.h"
#include "array_stack.c"
#include "stack.c"
#include <assert.h>

int main(int argc, char* argv[]) {
    ArrayStack array_stack = array_stack_create(5);
    for (int i = 0; i < 6; ++i) {
        bool ok = array_stack_push(array_stack, i);
        assert(ok);
    }

    assert(array_stack_top(array_stack) == 5);

    for (int j = 5; j >= 0; --j) {
        ElementType x = array_stack_pop(array_stack);
        assert(x == j);
    }

    Stack stack = stack_create();
    for (int i = 0; i < 6; ++i) {
        bool ok = stack_push(stack, i);
        assert(ok);
    }

    assert(stack_top(stack) == 5);

    for (int j = 5; j >= 0; --j) {
        assert(stack_pop(stack) == j);
    }

    return EXIT_SUCCESS;
}
