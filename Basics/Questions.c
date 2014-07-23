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
    int unit = 0;   //number of 1s from 0 - 9 per unit
    int prefix_1 = 1;
    int base = 0;
    while(n)
    {
        int rm = n % 10;
        switch(rm)
        {
            case 0:
                break;
            case 1:
                result += unit + 1;
                break;
            default:
                for(int i = 0;i <= rm - 1; i++)
                {
                    result += unit;
                }
                result += prefix_1; //like 10 - 19
                break;
        }
        base++;
        unit = 10 * unit + prefix_1;
        int temp = base;
        prefix_1 = 1;
        while(temp)
        {
            prefix_1 *= 10;
            temp--;
        }
        n /= 10;
        //base++;
    }
    return result;
}

void test()
{
    int a = NumOf1InNumbersFrom(2000);
    int b = Ad_NumOf1InNumbersFrom(2000);
    printf("%d", a);
    printf("\n%d", b);
}