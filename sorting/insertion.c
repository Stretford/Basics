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
    printf("\nselection sort:\n");
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
        
        for(int i = 0; i < n;i++)
        {
            printf("%d,", L[i]);
        }
        printf("\n");
    }
}
 

void insertion_test()
{
    int L[] = {77, 66, 55, 44, 1};
    int n = sizeof(L) / sizeof(int);
    insert_sort(L, n);
}
