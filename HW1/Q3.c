/*HASAN EFE OZKAVCI - 090130328*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
int main(){
    void soru3(){
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
            printf("%d Adet Bulunmaktadir.", count);
            getch();
    }
    soru3();
    return 0;
}
