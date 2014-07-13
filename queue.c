//
//  Queue.c
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

typedef struct linkqueue
{
    node *first, *rear;
}queue;

queue *push_queue(queue *HQ, int x)
{
    node *s = (node *)malloc(sizeof(node));
    s->data = x;
    s->next = NULL;
    
    if(HQ->rear == NULL)
    {
        HQ->first = s;
        HQ->rear = s;
    }
    else
    {
        HQ->rear->next = s;
        HQ->rear = s;
    }
    return HQ;
}

queue *pop_queue(queue *HQ)
{
    node *p;
    int x;
    if(HQ->first == NULL)
    {
        printf("\n overflow!");
        return NULL;
    }
    else
    {
        x = HQ->first->data;
        p = HQ->first;
        if(HQ->first == HQ->rear)
        {
            HQ->first = NULL;
            HQ->rear = NULL;
        }
        else
        {
            HQ->first = HQ->first->next;
            free(p);
        }
        return HQ;
    }
}

void Queue_Test()
{
    
}