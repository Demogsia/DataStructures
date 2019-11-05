#include <stdio.h>
#include <stdlib.h>


struct n{
	int x;
	struct n* next;	
};
typedef struct n node;
int main(){
	node* root;
	root = (node*) malloc(sizeof(node));
	node* iter = root;
	root -> x = 5;
	root -> next = (node*) malloc(sizeof(node));
	root -> next -> x = 10;
	root -> next -> next = (node*) malloc(sizeof(node));
	root -> next -> next -> x = 20;
	int i = 0;
	while (iter -> next != NULL){
		printf("%d\n", iter -> x);
		iter = iter -> next;
	}
	printf("%d", iter -> x);
}

