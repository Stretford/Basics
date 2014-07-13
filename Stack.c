//
//  Stack.c
//  Basics
//
//  Created by NStretford on 7/13/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct stack
{
    node *bottom;
    node *top;
}stack;

stack *push_stack(stack *ST, int x)
{
    node *s = (node *)malloc(sizeof(node));
    s->data = x;
    s->next = NULL;
    if(ST->bottom == NULL)
    {
        ST->bottom = s;
        ST->top = s;
    }
    else
    {
        node *p = ST->top;
        s->next = p;
        ST->top = s;
    }
    return ST;
}

int pop_stack(stack *ST)
{
    if(ST->bottom == NULL)
    {
        printf("\nThe stack is empty");
        return -1;
    }
    node *p = ST->bottom;
    if(ST->top == ST->bottom)
    {
        int x = ST->top->data;
        ST->bottom = NULL;
        ST->top = NULL;
        return x;
    }
    else
    {
        while(p->next != ST->top)
            p = p->next;
        int x = p->data;
        ST->top = p;
        ST->top->next = NULL;
        return x;
    }
}

void print_stack(stack *ST)
{
    if(ST->bottom == NULL)
    {
        printf("\nThe stack is empty");
        return;
    }
    
    node *t = ST->top;
    printf("\nThe stack is:\n");
    while(t != NULL)
    {
        printf(" %d, ", t->data);
        t = t->next;
    }
}

void Stack_Test()
{
    stack *ST = (stack *)malloc(sizeof(stack));
    push_stack(ST, 33);
    push_stack(ST, 21);
    push_stack(ST, 12);
    push_stack(ST, 109);
    print_stack(ST);
}