#include <stdio.h>
#include <stdlib.h>

typedef struct ptr_array {
	int* ptr_a;
	int* ptr_b;
} ptr_array_t;

int xplatform_test()
{
	ptr_array_t *a = (ptr_array_t *)malloc(2*sizeof(int));
	if(a == NULL) {
		free(a);	
		return -1;
	}

	a->ptr_a = 0;
	a->ptr_b = 0;

	free(a);

	return 0;
}
