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
}LinkStack, *top;

LinkStack *create_LinkStack()
{
    LinkStack *top = (LinkStack *)malloc(sizeof(LinkStack));
    if(!top)
    {
        printf("\nspace allocation failed!");
        return NULL;
    }
    top->next = NULL;
    return top;
}


void push_LinkStack(LinkStack *top, int x)
{
    LinkStack *s = (LinkStack *)malloc(sizeof(LinkStack));
    if(!s)
    {
        printf("\nspace allocation failed!");
        return;
    }
    s->data = x;
    s->next = top->next;
    top->next = s;
    return;
}

int IsEmpty_LinkStack(LinkStack *top)
{
    return (top->next == NULL ? 1 : 0);
}

int pop_stack(LinkStack *top)
{
    if(IsEmpty_LinkStack(top))
    {
        printf("\nthe stack is empty");
        return -1;
    }
    LinkStack *s = top->next;
    int x = s->data;
    top->next = s->next;
    free(s);
    return x;
}

void print_LinkStack(LinkStack *top)
{
    if(IsEmpty_LinkStack(top))
    {
        printf("\nThe stack is empty");
        return;
    }
    
    LinkStack *t = top->next;
    printf("\nThe stack is:\n");
    while(t != NULL)
    {
        printf(" %d, ", t->data);
        t = t->next;
    }
}

void Stack_Test()
{
    LinkStack *top = create_LinkStack();
    push_LinkStack(top, 3);
    push_LinkStack(top, 56);
    push_LinkStack(top, 1);
    pop_stack(top);
    pop_stack(top);
    push_LinkStack(top, 77);
    print_LinkStack(top);
}