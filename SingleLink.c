//
//  SingleLink.c
//  Basics
//
//  Created by NStretford on 6/24/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


typedef struct singleLink
{
    int data;
    struct singleLink *next;
}node;

node *create()
{
    node *head, *p, *s;
    int x, cycle = 1;
    head = (node*)malloc(sizeof(node));
    p = head;
    while (cycle)
    {
        printf("\nplease input data:");
        scanf("%d", &x);
        if(x != 0)
        {
            s = (node *)malloc(sizeof(node));
            s->data = x;
            printf("\n  %d", s->data);
            p->next = s;
            p = s;
        }
        else
            cycle = 0;
        
    }
    head = head->next;
    p->next = NULL;
    printf("\n  yyy  %d",head->data);
    return head;
    
}

int length(node *head)
{
    int n = 0;
    node *p = head;
    while (p != NULL)
    {
        p = p->next;
        n++;
    }
    return n;
}

void print(node *head)
{
    node *p;
    int n = length(head);
    printf("\nThe SingleLink is:\n");
    p = head;
    if(head != NULL)
        while (p != NULL)
        {
            printf(" %d ,",p->data);
            p = p->next;
        }
    
}

node *del(node *head, int num)
{
    node *p1, *p2;
    p1 = head;
    while(num != p1->data && p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }
    if(num == p1->data)
    {
        if(p1 == head)
        {
            head = p1->next;
            free(p1);
        }
        else
            p2->next = p1->next;
    }
    else
        printf("\n%d could not been found", num);
    return head;
}

node *insert(node *head, int num)
{
    node *p0, *p1, *p2;
    p1 = head;
    p0 = (node *)malloc(sizeof(node));
    p0->data = num;
    while(p0->data > p1->data && p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }
    if(p0->data <= p1->data)
    {
        if(head == p1)
        {
            p0->next = p1;
            head = p0;
        }
        else
        {
            p2->next = p0;
            p0->next = p1;
        }
    }
    else
    {
        p1->next = p0;
        p0->next = NULL;
    }
    return head;            
}

node *sort(node * head)
{
    node *p, *p2, *p3;
    int n = length(head);
    int temp;
    if (head == NULL || head->next == NULL)
        return head;
    p = head;
    for(int j = 1;j<n;j++)
    {
        p = head;
        for(int i = 0;i<n-j;i++)
        {
            if(p->data > p->next->data)
            {
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next;
        }
    }
    return head;
}

node *reverse(node *head)
{
    node *p1, *p2, *p3;
    if(head == NULL || head->next == NULL)
        return head;
    p1 = head;
    p2 = p1->next;
    while(p2)
    {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    head->next = NULL;
    head = p1;
    return head;
}

node *RemoveHead(node *head)
{
    node *p = head->next;
    head->next = p->next;
    free(p);
    return head;
}

node *SearchMid(node *head)
{
    node *temp = head;
    while(head->next !=NULL && head->next->next != NULL)
    {
        head = head->next->next;
        temp = temp->next;
    }
    return temp;
}

void SLTest()
{
    node *SL = create();
    print(SL);
    //del(SL, 3);
    //print(SearchMid(SL));
    printf("Mid is %d", SearchMid(SL)->data);
}
