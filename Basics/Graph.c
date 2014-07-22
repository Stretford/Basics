//
//  Graph.c
//  Basics
//
//  Created by NStretford on 7/21/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include <stdio.h>
#define MAX_VERTEX_NUM 50

//Definition for Adjacency Matrix
typedef struct Graph
{
    int v[MAX_VERTEX_NUM];                  //array for vertex
    int A[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //n*n adjacency matrix
    int vexnum, arcnum;
} MGraph;



//Definition for Adjacency List
typedef struct ArcNode  //node for arc
{
    int adjvex;                 //position of node pointed
    struct ArcNode *nextarc;    //pointer pointing to the next
    int info;                   //node weight
} ArcNode;

typedef struct VNode    //node for vertex
{
    char data;
    ArcNode *firstarc;
} VNode;

typedef struct ALGraph
{
    VNode adjlist[MAX_VERTEX_NUM];
    int vexnum, arcnum;
} ALGraph;

