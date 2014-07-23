//
//  main.c
//  Basics
//
//  Created by NStretford on 6/23/14.
//  Copyright (c) 2014 NStretford. All rights reserved.
//

#include <stdio.h>
#include <string.h>
//#include "SingleLink.c"
extern int BiTree_Test();
extern void test();

int main(int argc, const char * argv[])
{
    //test();
    int a = 9, b = 5;
    a = a^b;
    b = a^b;
    a = a^b;
    printf("%d,%d",a, b);
    return 0;
}

