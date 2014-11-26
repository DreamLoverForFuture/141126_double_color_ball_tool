/*
 ============================================================================
 Name        : hello.c
 Author      : Adam
 Version     :
 Copyright   : Feel free to copy
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void heap_sort(int a[], int n);

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	int a[] = {9,8,7,6,12,14,16,1,2,3,2,4,667,8989,1,5555,666666666666,444,66666,222,555,888,222};
	heap_sort(a, sizeof(a)/sizeof(int) );

	return EXIT_SUCCESS;
}
