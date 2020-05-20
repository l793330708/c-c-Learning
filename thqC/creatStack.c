#include <stdio.h>

struct stack
{
    int size;
    int val[10];
    int sthead;
}my_stack;
int main()
{
    my_stack.size = 10;

    return 0;
}