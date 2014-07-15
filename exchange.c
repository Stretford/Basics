//
//  exchange.c
//  Basics
//
//  Created by NStretford on 7/15/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include <stdio.h>

void bubble_sort(int L[], int n)    //time complexity : n ** 2, stable
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i; j++)
        {
            if(L[j + 1] < L[j])
            {
                int temp = L[j];
                L[j] = L[j + 1];
                L[j + 1] = temp;
            }
        }
        printf("\n");
        for(int i = 0; i < n;i++)
        {
            printf("%d,", L[i]);
        }
    }
}

void quick_sort(int L[], int left, int right)
{
    int temp, i = left, j = right;
    if(left < right)
    {
        temp = L[left];
        while(i != j)
        {
            while(j > i && L[j] >= temp)
                j--;
            if(i < j)
            {
                L[i] = L[j];
                i++;
            }
            while(i < j && L[i] <= temp)
                i++;
            if(i < j)
            {
                L[j] = L[i];
                j--;
            }
        }
        L[i] = temp;
        quick_sort(L, left, i - 1);
        quick_sort(L, i + 1, right);
    }
}


void exchange_test()
{
    int L[] = {77, 66, 55, 44, 1};
    int n = sizeof(L) / sizeof(int);
    quick_sort(L, 0, n - 1);
    printf("\nafter sorting: ");
    for(int i = 0; i < sizeof(L) / sizeof(int);i++)
    {
        printf("%d,", L[i]);
    }
}