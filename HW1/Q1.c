#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void switchNumbers(int, int);
void siralaArtan(int[], int);
void siralaAzalan(int[], int);
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
	void switchNumbers(int x, int y) {
		int temp;
		temp = x;
		x = y;
		y = temp;
	}
	void siralaArtan(int x[], int m){
		int i, j, k;
		for ( i = (m-1); i>=0; i--){
			for ( j = 0;j<i; j++ ){
				if(x[j] < x[j+1]){
					switchNumbers(x[j], x[j+1]);
				}
			}
		}
	}
	
	siralaArtan(a, m);
	puts(a);
	/*for (i = 0; i<m; i++){
		printf("%c ", a[i]);
	}*/
	
	getchar();
	return 0;
}
