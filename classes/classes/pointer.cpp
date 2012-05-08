//
//  pointer.cpp
//  classes
//
//  Created by nwiger on 5/4/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "pointer.h"

static void voidptr(int **ptr)
{
    // Since it's **ptr, if we pass &p in, then this
    // means it's the *SAME* pointer (since it's an ref
    // to the address of the ptr) and we can change it.
    *ptr = 0;
}

static void killptr(int *ptr)
{
    // ptr is a *different* pointer than passed in, this is
    // similar to pass-by-value in Ruby land.
    *ptr = 6;    // changes real value
    ptr = NULL;  // ruin my local ptr copy
}

static void killref(int &ref)
{
    // p is a *different* pointer than passed in, this is
    // similar to pass-by-value in Ruby land.
    ref = 0;
}

int pointerTest()
{
    int* p;
    *p = 4;
    int x = 5;
    printf("4(a) = %d\n", *p);
    killptr(p);
    printf("4(b) = %d\n", *p);
    voidptr(&p); // pass addr to ptr
    killref(x);
    p = (int *)malloc(sizeof(int));
    *p = 2;
    printf("4(c) = %d\n", *p);
    return 0;
}

void use_int(void *);
void use_float(void *);
void greeting(void (*)(void *), void *);

int voidTest() {
    char ans;
    int i_age = 22;
    float f_age = 22.0;
    void *p;
    printf("Use int (i) or float (f)? ");
//    scanf("%c", &ans);
    ans = 'f';
    if (ans == 'i') {
        p = &i_age;
        greeting(use_int, p);
    }
    else {
        p = &f_age;
        greeting(use_float, p);
    }
    return 0;
}
void greeting(void (*fp)(void *), void *q) {
    fp(q);
}
void use_int(void *r) {
    int a;
    a = * (int *) r;
    printf("As an integer, you are %d years old.\n", a);
}
void use_float(void *s) {
    float *b;
    b = (float *) s;
    printf("As a float, you are %f years old.\n", *b);
}

