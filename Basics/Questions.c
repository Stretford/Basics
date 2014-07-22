//
//  Questions.c
//  Basics
//
//  Created by apple_lab on 7/22/14.
//  Copyright (c) 2014 apple_lab. All rights reserved.
//

#include <stdio.h>

int NumOf1InNumbersFrom(int n)
{
    int result = 0;
    for (int i = 0;i < n; i++)
    {
        result += NumOf1In(i);
    }
    return result;
}

int NumOf1In(int m)
{
    int result = 0;
    while(m)
    {
        if(m % 10 == 1)
            result++;
        m /= 10;
    }
    return result;
}

int Ad_NumOf1InNumbersFrom(int n)
{
    int result = 0;
    while(n)
    {
        
    }
    return result;
}

void test()
{
    int a = NumOf1InNumbersFrom(100);
    printf("%d", a);
}