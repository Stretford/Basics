//
//  String.c
//  Basics
//
//  Created by apple_lab on 7/23/14.
//  Copyright (c) 2014 apple_lab. All rights reserved.
//

#include <stdio.h>
//#include <string.h>

void IntToString(int num)
{
    char temp[7], str[7];
    int i = 0, j = 0;
    while(num)
    {
        temp[i] = num % 10 + '0';
        i++;
        num /= 10;
    }
    temp[i] = 0;
    i = i - 1;
    
    while(i >= 0)
    {
        str[j] = temp[i];
        j++;
        i--;
    }
    str[j] = 0;
    printf("string=%s\n", str);
    return;
}

int StringToInt(char temp[])
{
    int i = 0, sum = 0;
    while(temp[i])
    {
        sum = sum * 10 + (temp[i] - '0');
        i++;
    }
    return sum;
}

char* strcpy(char* strDest, const char* strSrc)
{
    if((strDest == NULL) || (strSrc == NULL))
        return NULL;
    char *address = strDest;
    while(*strSrc != '\0')
    {
        *strDest = *strSrc;
        strDest++;
        strSrc++;
        //or *strDest++ = *strSrc++;
    }
    *strDest = '\0';
    return address;
}

void string_test()
{
    //IntToString(558);
    //char temp[7] = {'1', '2', '3', '4', '5', '\0'};
    //printf("\n%d", StringToInt(temp));
    char a[] = "abcde";
    char b[7];
    char *p = a, *q = b;
    strcpy(q, p);
    printf("%s", q);
}
