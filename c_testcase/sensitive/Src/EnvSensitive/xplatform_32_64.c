#include <stdio.h>
#include <stdlib.h>

typedef struct ptr_array {
	int* ptr_a;
	int* ptr_b;
} ptr_array_t;

int xplatform_test()
{
	ptr_array_t *a = (ptr_array_t *)malloc(2*sizeof(int));
        printf("sizeof int is %d\n",sizeof(int));

        printf("sizeof int is %d\n",sizeof(a));

        printf("a->ptr_a:%d\n",a->ptr_a);

        printf("a->ptr_b:%d\n",a->ptr_b);

	if(a == NULL) {
		free(a);	
		return -1;
	}

	a->ptr_a = 0;
	a->ptr_b = 0;

	free(a);

	return 0;
}
 
int  main()
{
       return xplatform_test();
}
