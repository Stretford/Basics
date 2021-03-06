//
//  BiTree.c
//  Basics
//
//  Created by NStretford on 7/14/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    char data;
    struct node *lchild, *rchild;
}BiTreeNode, *BiTree;

void create_BiTree(BiTree *T)
{
    char ch = getchar();
    rewind(stdin);
    if(ch == '#')
    {
        *T = NULL;
        return;
    }
    *T = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    if(!T)
    {
        printf("\nspace allocation failed");
        return;
    }
    (*T)->data = ch;
    create_BiTree(&(*T)->lchild);
    create_BiTree(&(*T)->rchild);
    return;
}

void PreOrderTraverse(BiTree bt)
{
    if(bt)
    {
        printf(&bt->data);
        PreOrderTraverse(bt->lchild);
        PreOrderTraverse(bt->rchild);
    }
}

void InOrderTraverse(BiTree bt)
{
    if(bt)
    {
        InOrderTraverse(bt->lchild);
        printf(&bt->data);
        InOrderTraverse(bt->rchild);
    }
}

void PostOrderTraverse(BiTree bt)
{
    if(bt)
    {
        PostOrderTraverse(bt->lchild);
        PostOrderTraverse(bt->rchild);
        printf(&bt->data);
    }
}

#define BiTree_Max_Size 50
void LevelOrderTraverse(BiTree bt)
{
    BiTree queue[BiTree_Max_Size];  //sequence queue
    int front = 0, rear = 0;
    if(bt == NULL)
        return;
    queue[rear] = bt;
    rear++;
    while(rear != front)
    {
        printf("-%c", queue[front]->data);
        if(queue[front] ->lchild !=NULL)
        {
            queue[rear] = queue[front]->lchild;
            rear++;
        }
        if(queue[front]->lchild != NULL)
        {
            queue[rear] = queue[front]->rchild;
            rear++;
        }
        front++;
        printf("\nqueue is:");
        //int n = sizeof(queue) / sizeof(int);
        for(int i = 0; i < BiTree_Max_Size; i++)
        {
            if(queue[i] != NULL && queue[i]->data)
                printf("%c->", queue[i]->data);
        }
    }
}

int NodeNum_BiTree(BiTree bt)
{
    int n = 0;
    if(bt)
    {
        n++;
        n += NodeNum_BiTree(bt->lchild);
        n += NodeNum_BiTree(bt->rchild);
    }
    return n;
}

int LeafNum_BiTree(BiTree bt)
{
    int n = 0;
    if(bt)
    {
        if(bt ->lchild == NULL && bt->rchild == NULL)
            n++;
        else
        {
            n += LeafNum_BiTree(bt->lchild);
            n += LeafNum_BiTree(bt->rchild);
        }
    }
    return n;
}

int Height_BiTree(BiTree bt)
{
    int result, heightL = 0;
    if(bt == NULL)
        return 0;
    heightL = Height_BiTree(bt->lchild);
    result = Height_BiTree(bt->rchild);
    result = (result >heightL ? result : heightL) + 1;
    return result;
}

BiTree Search_BiTree(BiTree bt, char x)
{
    BiTree temp;
    if(bt == NULL)
        return NULL;
    if(x == bt->data)
        return bt;
    temp = Search_BiTree(bt->lchild, x);
    if(temp != NULL)
        return temp;
    return Search_BiTree(bt->rchild, x);
}

void BiTree_Test()
{
    printf("please input the BiTree(\"#\" for null)\n");
    BiTree T;
    create_BiTree(&T);
    printf("\ntree created\n");
    LevelOrderTraverse(T);
    //printf("\nthe height is:%d", Height_BiTree(T));
}

