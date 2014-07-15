//
//  insertion.c
//  Basics
//
//  Created by NStretford on 7/15/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include <stdio.h>

void insert_sort(int L[], int n)   //time complexity : n ** 2, stable
{
    //int n = sizeof(L) / sizeof(int);
    int temp, j;
    for(int i = 1; i < n; i++)
    {
        if(L[i] < L[i - 1])
        {
            temp = L[i];
            for(j = i - 1; j >= 0 && temp < L[j]; j--)
            {
                L[j + 1] = L[j];
            }
            L[j + 1] = temp;
        }
    }
    //return;
    printf("%d", n);
}

void insertion_test()
{
    int L[] = {44, 21, 64, 77, 1};
    int n = sizeof(L) / sizeof(int);
    insert_sort(L, n);
    printf("\nafter sorting: ");
    for(int i = 0; i < sizeof(L) / sizeof(int);i++)
    {
        printf("%d,", L[i]);
    }
}
