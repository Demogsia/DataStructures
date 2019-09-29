/*HASAN EFE ÖZKAVCI - 090130328*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
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
                l = i;printf("l = %d oldu\n", l);
                for ( j = 0; j < m; j++) {
                    if ( aranacakDizi[j] != anaDizi[i] ){
                         sameSwitch = 0;
                         printf("If'e girildi.\n");
                         }
                    l++;printf("l = %d'ye artirildi\n", l);
                    i++;
                }
                i = i-m;
                if(sameSwitch == 1){
                              basariliSonuclar[count] = i;
                              count++;printf("count %d'ye artirildi.\n", count);
                             
                }
                i++;printf("i = %d'ye artirildi\n", i);
    }
    printf("\n\n\nSONUCLAR:\n\n");
    printf("%s Dizisinin icerisinde %s dizisi\n", anaDizi, aranacakDizi);
    for ( i = 0; i<count; i++ ){
        printf("%d - %d Arasinda \n", basariliSonuclar[i], basariliSonuclar[i]+m-1);
        }
    printf("%d Adet Bulunmaktadir.", count);
    getchar();
    return 0;
}
