#include <stdio.h>
#include <math.h>
void siralaAzalan(int[], int);
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
	int i, j, k, n, m;
	printf("Dizi kac elemanli olsun?\n");scanf("%d", &n);
	int a[n];
	printf("Dizinin elemanlarini giriniz.\n");
	for (i = 0; i<n; i++){
		scanf("%d", &a[i]);
	}
	printf("Dizinin kacinci en buyuk elemanini bulmak istiyorsunuz?\n");
	scanf("%d", &k);
	int b[k];
	for (int i = 0; i < k; ++i)
	{
		b[i] = a[i];
	}
	siralaAzalan(b, k);
	for(i = k;i<n;i++){
		if (a[i] > b[k-1])
		{
			b[k-1] = a[i];
			siralaAzalan(b,k);
		}
	}
	printf("a dizisi:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\nb dizisi:\n");
	for (int i = 0; i < k; ++i)
	{
		printf("%d ", b[i]);
	}
	printf("\na dizisinin 3. En buyuk elemani:\n");
	printf("%d\n", b[k-1]);
	return 0;
}