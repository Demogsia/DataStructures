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
			if(x[j] < x[j+1]){
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
	printf("İlk dizi(Sıralanmamış):\n");
	for (i = 0; i<m; i++){printf("%d ", a[i]);}printf("\n");
	printf("İkinci dizi(Sıralanmamış):\n");
	for (i = 0; i<m; i++){printf("%d ", b[i]);}printf("\n");
	
	siralaArtan(a, m);
	siralaAzalan(b,n);
	
	printf("İlk dizi(Sıralanmış):\n");
	for (i = 0; i<m; i++){printf("%d ", a[i]);}printf("\n");
	printf("İkinci dizi(Sıralanmış):\n");
	for (i = 0; i<m; i++){printf("%d ", b[i]);}printf("\n");
	
	for (i = 0; i<(m+n); i++){
		if (i < m){
			c[i] = a[i];
		}
		else{
			c[i] = b[i%m];
		}
	}
	printf("Üçüncü dizi(Sıralanmamış):\n");
	for (i = 0; i<m+n; i++){printf("%d ", c[i]);}printf("\n");
	siralaArtan(c, (m+n));
	printf("Üçüncü dizi(Sıralanmış):\n");
	for (i = 0; i<m+n; i++){printf("%d ", c[i]);}printf("\n");
	
	getchar();
	return 0;
}
