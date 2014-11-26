/*
 * sort.c
 *
 *  Created on: 2014Äê11ÔÂ18ÈÕ
 *      Author: Administrator
 */



#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int size;
	int pos;
	int *buffer;
}STACK;

int stack_init(STACK *pst, int size){
	pst->size = size;
	pst->pos = 0;
	pst->buffer = (int*)malloc(sizeof(int)*size);
	if (0 == pst->buffer)
		return -1;
	return 0;
}

int stack_push(STACK *pst, int mem){
	if (pst->pos >= pst->size)
		return -1;
	(pst->buffer)[pst->pos++] = mem;
	return 0;
}

int stack_pop(STACK *pst){
	if (0 == pst->pos)
		return 0xFFFFFFFF;
	return (pst->buffer)[--pst->pos];
}

int stack_isempty(STACK *pst)
{
	if(0 == pst->pos)
		return 1;
	return 0;
}

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void heap_adjust(int a[], int i, int n)//i is the node position, n is size of a
{
	STACK st = {0};
	STACK *pst = &st;
	stack_init(pst, n);

	if(i >= n)
		return;
	stack_push(pst,i);//pos into stack
	stack_push(pst,n);//size into stack

	while(!stack_isempty(pst)){

		int size = stack_pop(pst);
		int pos = stack_pop(pst);
		int min = pos;
		int lchild = pos*2 + 1;
		int rchild = lchild +1;

		printf("--start %d %d %d\n", pos, lchild, rchild);

		if(lchild < size && a[lchild] < a[min])
			min = lchild;
		if(rchild < size && a[rchild] < a[min])
			min = rchild;
		if (pos != min){

			//printf("  swap %d %d %d-%d\n",pos, min, a[pos],a[min]);
			swap(a+pos, a+min);
			stack_push(pst,min);//child into stack
			stack_push(pst,size - 1);//table size into stack
		}
	}
}

void build_heap(int a[], int n){
	int i;
	for(i=n/2; i>=0;i--){
		heap_adjust(a,i,n);
	}
}

void heap_sort(int a[], int n){
	int i;
	build_heap(a,n);

	//printf("-----------------init heap ok\n");
	for(i=n;i>=1; --i){

		swap(a, a+i-1);
		printf("%d\n",a[i-1]);
		heap_adjust(a,0, i-1);
	}
}

