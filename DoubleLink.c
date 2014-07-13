//
//  DoubleLink.c
//  Basics
//
//  Created by NStretford on 6/29/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct dnode
{
    int data;
    struct dnode *next;
    struct dnode *pre;
}dnode;

dnode *create_DL()
{
    dnode *head, *p, *s;
    int x, cycle = 1;
    head = (dnode *)malloc(sizeof(dnode));
    p = head;
    while(cycle)
    {
        printf("\nplease input data:");
        scanf("%d", &x);
        if(x != 0)
        {
            s = (dnode *)malloc(sizeof(dnode));
            s->data = x;
            printf("\n %d", s->data);
            p->next = s;
            s->pre = p;
            p = s;
        }
        else
            cycle = 0;
    }
    head = head->next;
    head->pre = NULL;
    p->next = NULL;
    
    printf("\n yyy %d", head->data);
    return head;
}

dnode *del_DL(dnode *head, int num)
{
    dnode *p1, *p2;
    p1 = head;
    while(num != p1->data && p1->next != NULL)
        p1 = p1->next;
    
    if(num == p1->data)
    {
        if(p1 == head)
        {
            head = head->next;
            head->pre = NULL;
            free(p1);
        }
        else if(p1->next == NULL)
        {
            p1->pre->next = NULL;
            free(p1);
        }
        else
        {
            p1->next->pre = p1->pre;
            p1->pre->next = p1->next;
            free(p1);
        }
    }
    else
        printf("\n%d could not be found", num);
    return head;
}

dnode *insert_DL(dnode *head, int num)
{
    dnode *p0, *p1;
    p1 = head;
    p0 = (dnode *)malloc(sizeof(dnode));
    p0->data = num;
    while(p0->data > p1->data && p1->next != NULL)
        p1 = p1->next;
    
    if(p0->data <= p1->data)
    {
        if (head == p1)
        {
            p0->next = p1;
            p1->pre = p0;
            head = p0;
        }
        else
        {
            p1->pre->next = p0;
            p0->next = p1;
            p0->pre = p1->pre;
            p1->pre = p0;
        }
    }
    else
    {
        p1->next = p0;
        p0->pre = p1;
        p0->next = NULL;
    }
    return head;
}
