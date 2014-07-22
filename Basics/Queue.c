//
//  Queue.c
//  Basics
//
//  Created by NStretford on 7/13/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef struct queue
{
    int data[MaxSize];
    int front, rear;
}CircQueue;

CircQueue *init_CircQueue()
{
    CircQueue *q = (CircQueue *)malloc(sizeof(CircQueue));
    if(!q)
    {
        printf("\nspace allocation failed");
        return NULL;
    }
    q->rear = q->front = 0;
    return q;
}

void push_CircQueue(CircQueue *Queue, int x)
{
    if((Queue->rear + 1) % MaxSize == Queue->front)
    {
        printf("\nQueue is full");
        return;
    }
    Queue->rear = (Queue->rear + 1) % MaxSize;
    Queue->data[Queue->rear] = x;
    return;
}

int IsEmpty_CircQueue(CircQueue *queue)
{
    return (queue->rear == queue->front);
}

void pop_CircQueue(CircQueue *queue, int *x)
{
    if(IsEmpty_CircQueue(queue))
    {
        printf("\nQueue is empty");
        return;
    }
    queue->front = (queue->front + 1) % MaxSize;
    *x = queue->data[queue->front];
    return;
}

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct linkqueue
{
    node *first, *rear;
}LinkQueue;

LinkQueue *push_linkqueue(LinkQueue *HQ, int x)
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

LinkQueue *pop_linkqueue(LinkQueue *HQ)
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