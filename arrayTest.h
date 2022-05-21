#ifndef ARRAYTEST_H
#define ARRAYTEST_H


// Included for size_t and the null pointer
#include <stddef.h>
#include <stdio.h>
/* 
	This entire .h document might be basically superflurous, but it's good practice anyway.
*/

void compareAndSwap( void* elemOne, void* elemTwo, size_t typeSize, int compareFun( const void*, const void*) );

void genArrTest( void* array, size_t typeSize, size_t typeCount, int compareFun(const void*, const void*) );



#endif
