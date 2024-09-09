/**
 * A program to implement two stacks using a single array.
 *
 * This program provides functionalities to push and pop elements from two separate stacks
 * implemented using a single array.
 *
 * @struct TwoStacks A structure representing two stacks.
 * @param arr An array to store elements for both stacks.
 * @param top1 The top index of the first stack.
 * @param top2 The top index of the second stack.
 *
 * @function initStack Initializes the two stacks.
 * @param stack A pointer to the TwoStacks structure.
 *
 * @function push Pushes an element onto the stack.
 * @param stack A pointer to the TwoStacks structure.
 * @param item The element to be pushed onto
 * 
 * @function pop Pops an element out from the stack.
 * @param stack A pointer to the TwoStacks structure.
 * 
 * @function display displays all elements in both stack.
 * @param stack A pointer to the TwoStacks structure.
 */

#include <stdio.h>

typedef struct TwoStacks
{
    int arr[10];
    int top1;
    int top2;
} TwoStacks;

void initStack(TwoStacks *stack)
{
    stack->top1 = -1;
    stack->top2 = 10;
}

void push1(TwoStacks *stack, int item)
{
    if (stack->top1 < stack->top2 - 1)
    {
        stack->arr[++stack->top1] = item;
    }
    else
    {
        printf("\nStack is Full Can't Insert");
    }
}

void push2(TwoStacks *stack, int item)
{
    if (stack->top1 < stack->top2 - 1)
    {
        stack->arr[--stack->top2] = item;
    }
    else
    {
        printf("\nStack 2 is Full Can't Insert");
    }
}

void pop1(TwoStacks *stack)
{
    if (stack->top1 > -1)
    {
        int poppedEle = stack->arr[stack->top1--];
        printf("\nPopped Element %d", poppedEle);
    }
    else
    {
        printf("\nCan't pop element as stack 1 is empty");
    }
}

void pop2(TwoStacks *stack)
{
    if (stack->top2 < 10)
    {
        int poppedEle = stack->arr[stack->top2++];
        printf("\nPopped Element %d", poppedEle);
    }
    else
    {
        printf("\nCan't pop element as stack 2 is empty");
    }
}

void display1(TwoStacks *stack)
{
    printf("\nFirst Stack : ");
    for (int i = 0; i <= stack->top1; i++)
    {
        printf("\n%d", stack->arr[i]);
    }
}

void display2(TwoStacks *stack)
{
    printf("\nSecond Stack : \n");
    for (int i = stack->top2; i < 10; i++)
    {
        printf("\n%d", stack->arr[i]);
    }
}

int main()
{
    int ch = 1;
    int in;
    TwoStacks stacks;
    initStack(&stacks);
    while (ch != 0)
    {
        printf("\n1. Push\n2. Pop\n3. Push 2\n4. Pop 2\n5. Display\n");
        scanf("%d", &ch);
        printf("%d", ch);
        switch (ch)
        {

        case 1:
            printf("Enter Number : ");
            scanf("%d", &in);
            push1(&stacks, in);
            break;
        case 2:
            pop1(&stacks);
            break;
        case 3:
            printf("Enter Number : ");
            scanf("%d", &in);
            push2(&stacks, in);
            break;
        case 4:
            pop2(&stacks);
        case 5:
            display1(&stacks);
            display2(&stacks);
            break;
        default:
            printf("Exited");
        }
    }
    return 0;
}
