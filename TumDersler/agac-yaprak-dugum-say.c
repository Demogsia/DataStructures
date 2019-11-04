#include<stdio.h>
#include <stdlib.h>
#include "agac.h"
//Yaprak ve dugum sayisi bulunuyor
int yaprak_say = 0;
int dugum_say = 0;
main()
{
  AGAC *kok = NULL;
  void yaprak_sayisi (AGAC*);
  void dugum_sayisi (AGAC*);
  
  
  int secim = 1, x;
  
  while( secim )
  {
     printf("\n Deger Giriniz..");
     scanf("%d",&x);
     
     kok = ekle( kok, x);
   
     printf("\n LNR : ");
     inorder(kok);
     
     
     printf("\n 1--> devam,  0---> son  ");
     scanf("%d",&secim);
     
  }

  yaprak_sayisi (kok);
  dugum_sayisi (kok);
 
 printf("\n Yaprak Sayisi = %d", yaprak_say);
 printf("\n Dugum Sayisis = %d", dugum_say);
 return 0;
}
////////////////////////////
void yaprak_sayisi( AGAC*ptr)
{
   if( ptr!=NULL)
   {
     yaprak_sayisi( ptr->sol);
    
     if( ptr->sol == NULL&&ptr->sag == NULL)
      yaprak_say++;
    
	 yaprak_sayisi( ptr->sag);
   }  
}
////////////////////////////////
void dugum_sayisi( AGAC*ptr)
{
   if( ptr!=NULL)
   {
     dugum_sayisi( ptr->sol);
     dugum_say++;
     dugum_sayisi( ptr->sag);
   }  
}
