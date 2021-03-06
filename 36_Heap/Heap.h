#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int HPDataType;

typedef struct Heap{
	HPDataType *_arr;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap *hp, HPDataType *arr ,int n);
void HeapDestroy(Heap *hp,int n);
void HeapPush(Heap *hp, HPDataType x);
void HeapPop(Heap *hp);
HPDataType HeapTop(Heap *hp);
int HeapSize(Heap *hp);
int HeapEmpty(Heap *hp);
void HeapTest();

#endif //!__HEAP_H__
