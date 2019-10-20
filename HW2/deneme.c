#include <stdio.h>
int main(){
	int a = 5;
	int i;
	int *ptr;
	int A[15];
	ptr = &A[0];
	for (i = 0; i<15; i++){
		ptr = &A[i];
		printf("%p\n", ptr);
	}
	//printf("%p\n", ptr);
	return 0;	

}
