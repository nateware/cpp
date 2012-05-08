//
//  array.cpp
//  classes
//
//  Created by nwiger on 5/4/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "array.h"

// http://forums.devarticles.com/c-c-help-52/c-pointer-to-multidimensional-array-11075.html
static int allocateMatrix(int ***matrixPtr, long int order) {
    
    int i, j; // temporary counter 
    
    *matrixPtr = (int **) calloc (order, sizeof(int));
    if (*matrixPtr == (int **) NULL) {
        printf("Error allocating memory for row pointer \n");
        return(1);
    }
    
    **matrixPtr = (int *) calloc (order * order, sizeof(int));
    if (**matrixPtr == (int *) NULL) {
        printf("Error allocating memory for array \n");
        return(1);
    }
    
    // initialize our row pointers to allow array indexing into our array 
    for (i = 0, j = 0; i < order; i++, j += order) {
        *(*matrixPtr + i) = (**matrixPtr + j);
    }
    return (0);
}

// Here's a snuiplet from main that shows the definition of our arrary pointer and the call to allocateMatrix. 

void arrayStuff() 
{
    long int order; // order of array (rows and columns 
    int **matrixPtr; // pointer to our magic square 
    
    
    // Allocate memory for our magic square 
//    if (allocateMatrix(&matrixPtr, order) != 0) {
//        printf("Error allocating memory for magic square\n");
//        exit(1);
//    }
//    
//    // At this point you can use matrixPtr as if it were a two dimensional array:
//    matrixPtr[2][3] = 42;
//    printf("int = %d\n", matrixPtr[2][3]);


    // Setting up an array of pointers is one way to accomplish something
    // similar to the original question, but it is not the best way. An
    // array of pointers requires an additional memory reference for each
    // dimension, and creating and destroying the array requires a loop. 
    //
    // C++ directly supports an answer to the original question, however.
    // The syntax is a bit tricky, and I always end up using a typedef to simplify it.
    //
    // The trick is to parenthisize the pointer declaration. This informs C++
    // that you want a pointer to an array, rather than array of pointers.

    // So writing
    int (*a)[10];
    // declares that a is a pointer to an array of 10 ints. By constrast,
    int *b[10];
    //declares that a is an array of 10 pointers to ints.
    
    // To get back to the original question, instead of writing
    // object (*ptr)[10] = new object[5][10];
    // or
    // object (*ptr)[10][15] = new object[5][10][15];
    
    // you must write
    //typedef object (*ObjectArray)[5][10][15];
    //ObjectArray ptr = (ObjectArray) new object[5][10][15];
    // You would also have to dereference the array whenever you refer to an element. For example,
    //(*ptr)[4][3][2] = 0;
    
    double (*pmd)[5] = new double[4][5];
    pmd[1][2] = 1.0;
    delete [] pmd;
    



}

