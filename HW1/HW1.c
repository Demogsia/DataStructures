#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>
void Soru1();
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
    void Soru1(){
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
    	printf("Ilk dizi(Siralanmamis):\n");
    	for (i = 0; i<m; i++){printf("%d ", a[i]);}printf("\n");
    	printf("Ikinci dizi(Siralanmamis):\n");
    	for (i = 0; i<m; i++){printf("%d ", b[i]);}printf("\n");
    	
    	siralaArtan(a, m);
    	siralaAzalan(b,n);
    	
    	printf("Ilk dizi(Siralanmis):\n");
    	for (i = 0; i<m; i++){printf("%d ", a[i]);}printf("\n");
    	printf("Ikinci dizi(Siralanmis):\n");
    	for (i = 0; i<m; i++){printf("%d ", b[i]);}printf("\n");
    	
    	for (i = 0; i<(m+n); i++){
    		if (i < m){
    			c[i] = a[i];
    		}
    		else{
    			c[i] = b[i%m];
    		}
    	}
    	printf("Ucuncu dizi(Siralanmamis):\n");
    	for (i = 0; i<m+n; i++){printf("%d ", c[i]);}printf("\n");
    	siralaArtan(c, (m+n));
    	printf("Ucuncu dizi(Siralanmis):\n");
    	for (i = 0; i<m+n; i++){printf("%d ", c[i]);}printf("\n");
    	printf("Tekrar secim yapmak icin bir tusa tiklayiniz.\n\n");
    	getch();
    	return main();
    }
    
    int Soru2(){
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
    	for (i = 0; i < k; ++i)
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
    	for (i = 0; i < n; ++i)
    	{
    		printf("%d ", a[i]);
    	}
    	printf("\nb dizisi:\n");
    	for (i = 0; i < k; ++i)
    	{
    		printf("%d ", b[i]);
    	}
    	printf("\na dizisinin 3. En buyuk elemani:\n");
    	printf("%d\n", b[k-1]);
    	printf("Tekrar secim yapmak icin bir tusa tiklayiniz.\n\n");
    	getch();
    	return main();
    }
    int Soru3(){
         int i,j,k,n,m, l;
            printf("Ilk dizinin eleman sayisini giriniz.\n");scanf("%d", &n);
            printf("Ikinci dizinin eleman sayisini giriniz.\n");scanf("%d", &m);
            char anaDizi[n];
            char aranacakDizi[m];
            int basariliSonuclar[n];
            printf("Ana diziyi giriniz.");scanf("%s", &anaDizi);
            printf("Arayacaginiz diziyi giriniz.\n");scanf("%s", &aranacakDizi);
            i = 0;
            l = 0;
           
            int count = 0;
            bool sameSwitch = 1;
            while ( i <= (n-m) ) {
                        sameSwitch = 1;
                        l = i;
                        for ( j = 0; j < m; j++) {
                            if ( aranacakDizi[j] != anaDizi[i] ){
                                 sameSwitch = 0;
                                 
                                 }
                            l++;
                            i++;
                        }
                        i = i-m;
                        if(sameSwitch == 1){
                                      basariliSonuclar[count] = i;
                                      count++;
                                     
                        }
                        i++;
            }
            printf("\n\n\nSONUCLAR:\n\n");
            printf("%s Dizisinin icerisinde %s dizisi\n", anaDizi, aranacakDizi);
            for ( i = 0; i<count; i++ ){
                printf("%d - %d Arasinda \n", basariliSonuclar[i], basariliSonuclar[i]+m-1);
                }
            printf("%d Adet Bulunmaktadir.\n", count);
            printf("Tekrar secim yapmak icin bir tusa tiklayiniz.\n\n");
            getch();
            return main();    
    }
    
    
    int x;
    printf("Hangi soruyu cozmek istersiniz? Numarasini giriniz.\n");
    printf("1. SORU    ");printf("2. SORU    ");printf("3. SORU\n");scanf("%d", &x);
    if( x == 1)
        Soru1();
    else if( x == 2)
        Soru2();
    else if( x == 3)
        Soru3();
    else{
        printf("Lutfen 1, 2 ya da 3 seciniz.\n\n");
        return main();
    }
    
    
    
    
    
    return 0;
}
