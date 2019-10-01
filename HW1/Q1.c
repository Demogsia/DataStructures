#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void switchNumbers(int, int);
void siralaArtan(int[], int);
void siralaAzalan(int[], int);

void siralaArtan(int x[], int m){
	int i, j, k, temp;
	for ( i = (m-1); i>=0; i--){
		for ( j = 0;j<i; j++ ){
			if(x[j] > x[j+1]){
				temp = x[j];
				x[j] = x[j+1];
				x[j+1] = temp;
			}
		}
	}
}
void siralaAzalan(int x[], int m){
	int i, j, k, temp;
	for ( i = (m-1); i>=0; i--){
		for ( j = 0;j<i; j++ ){
			if(x[j] > x[j+1]){
				temp = x[j];
				x[j] = x[j+1];
				x[j+1] = temp;
			}
		}
	}
}
int main(){
	int m, n, i, j, k;
	
	printf("Ilk dizi kac elemanli?\n");scanf("%d", &m);
	printf("Ikinci dizi kac elemanli?\n");scanf("%d", &n);
	int a[m];
	int b[n];
	int c[m+n];
	printf("Ilk dizinin elemanlarini giriniz.");
	for(i = 0; i<m; i++){
		scanf("%d", &a[i]);
	}
	printf("Ikinci dizinin elemanlarini giriniz.");
	for(i = 0; i<n; i++){
		scanf("%d", &b[i]);
	}
	siralaArtan(a, m);
	
	for (i = 0; i<m; i++){
		printf("%d ", a[i]);
	}
	
	getchar();
	return 0;
}
