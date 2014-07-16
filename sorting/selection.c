//
//  selection.c
//  Basics
//
//  Created by NStretford on 7/15/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include <stdio.h>

void selection_sort(int L[], int n) //time complexity: n ** 2, unstable
{
    printf("\nselection sort:\n");
    for(int i = 0; i < n - 2; i++)
    {
        int k = i;
        for(int j = i + 1; j < n; j++)
            if(L[j] < L[k])
                k = j;
        if(i != k)
        {
            int temp = L[k];
            L[k] = L[i];
            L[i] = temp;
        }
        
        for(int i = 0; i < n;i++)
        {
            printf("%d,", L[i]);
        }
        printf("\n");
    }
}

void selection_test()
{
    int L[] = {77, 66, 55, 44, 1};
    int n = sizeof(L) / sizeof(int);
    selection_sort(L, n);
}
