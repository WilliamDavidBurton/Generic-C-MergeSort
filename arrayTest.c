// This is the main code that I'm testing.
// It is NOT fully tested yet!  It seems to work, but full testing is NOT complete!

#include "arrayTest.h"




// This one runs the compare and swap functionality.
void compareAndSwap( void* elemOne, void* elemTwo, size_t typeSize, int compareFun( const void*, const void*) ){
	
	// First off, we run the comparison!
	
	if( compareFun(elemOne, elemTwo) > 0 ){
		// Only if this is true, do we continue on.
		for( int i = (typeSize-1); i >= 0; i-- ){
			((char*)elemOne)[i] = ((char*)elemOne)[i] ^ ((char*)elemTwo)[i];
			((char*)elemTwo)[i] = ((char*)elemOne)[i] ^ ((char*)elemTwo)[i];
			((char*)elemOne)[i] = ((char*)elemOne)[i] ^ ((char*)elemTwo)[i];
		}
	}
	
};




// For the compare function:  If the FIRST one is SMALLER, expect negative value.  If the SECOND one is SMALLER,
// 	expect positive value.
void genArrTest( void* array, size_t typeSize, size_t typeCount, int compareFun(const void*, const void*) ){
	if( array == NULL ){
		printf( "ERROR:  NULL ARRAY\n" );
		return;
	};
	
	if( typeSize < 1 ){
		printf( "ERROR:  TYPESIZE 0 OR LESS\n" );
	};
	
	// If the typeCount is equal to 1 or 0, then simply return.
	if( typeCount == 1 || typeCount == 0 ){
		return;
	};
	
	// Otherwise, we split it in half, and iterate!  If we have 3, then we want 1-2
	/*
		Array w/ 3 elem, (a,b,c)
		Split into (a) and (b,c)
		halfCount:  3/2 = 1; pass in halfCount and array start.
		pivotHalf:  total-half = 3-1 = 2; pass in pivotHalf and arrayStart + halfcount*typeSize
	*/
	int halfCount = typeCount/2;
	int pivotHalf = typeCount - halfCount;
	
	void* halfArray = (void*) (char*) array + (typeSize*halfCount);
	
	genArrTest(array, typeSize, halfCount, compareFun);
	genArrTest(halfArray, typeSize, pivotHalf, compareFun);
	
	/*
		Now time for the merge.  A few ways this could be done, but for now I'm just going to stick
		with a fairly basic one that doesn't use up any extra space, but will end up using an extra
		log(n) time.
	*/
	
	// This just gets the current type count -- used below to ensure the loop goes only as long as it
	// needs to.
	size_t curItr = typeCount;
	
	// This loop goes on until curItr reaches 0
	while( curItr > 1 ){
	
		curItr = (curItr%2) + curItr/2;
		
		for( int i = (typeCount-curItr-1); i >= 0; i -- ){
			
			void* t1 = (void*) (char*) array + (i * typeSize);
			void* t2 = (void*) (char*) array + ((i+curItr) * typeSize);
			compareAndSwap(t1, t2, typeSize, compareFun);
		};
		
	}
	
};
