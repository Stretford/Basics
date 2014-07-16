//
//  BiSearchTree.c
//  Basics
//
//  Created by NStretford on 7/16/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include <stdio.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}BSTNode, *BSTree;

/** recursive function for Search_BSTree
BSTNode *Search_BSTree(BSTNode *p, int x)
{
    if(p == NULL)
        return NULL;
    if(x < p->data)
        return Search_BSTree(p->lchild, x);
    else if(x > p->data)
        return Search_BSTree(p->rchild, x);
    else
        return p;
}
 **/

BSTNode *Search_BSTree(BSTree BT, int x, BSTNode **parent)
{
    BSTNode *p = BT, *q = NULL;
    while(p)
    {
        if(x == p->data)
        {
            *parent = q;
            return p;
        }
        q = p;
        if(x < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    *parent = q;
    return p;
}

BSTree Insert_BSTree(BSTree BT, int kx)
{
    BSTNode *p = BT, *f;
    while(p)
    {
        if(kx == p->data)
        {
            printf("already exists");
            return BT;
        }
        else
        {
            f = p;
            if(kx < p->data)
                p = p->lchild;
            else
                p = p->rchild;
        }
    }
    BSTNode *s = (BSTNode *)malloc(sizeof(BSTNode));
    s->data = kx;
    s->lchild = s->rchild = NULL;
    if(!BT)
        BT = s;
    else if(kx < f->data)
        f->lchild = s;
    else
        f->rchild = s;
    return BT;
}

BSTree Create_BSTree()
{
    BSTree t = NULL;
    int  kx;
    scanf("%d", &kx);
    while(kx != -1)
    {
        t = Insert_BSTree(t, kx);
        scanf("%d", &kx);
    }
    return t;
}

void PreOrderTraverse_BSTree(BSTree bt)
{
    if(bt)
    {
        printf("%d,", bt->data);
        PreOrderTraverse_BSTree(bt->lchild);
        PreOrderTraverse_BSTree(bt->rchild);
    }
}

void BSTree_Test()
{
    
    printf("please input the BSTree(\"#\" to finish)\n");
    BSTree BT = Create_BSTree();
    printf("\ntree created");
    PreOrderTraverse_BSTree(BT);
}
