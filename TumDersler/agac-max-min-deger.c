#include<stdio.h>
#include<stdlib.h>
#include "agac.h"
//Ýkili arama aðacinda en büyük ve en küçük deðerleri bulur ve
// Bu degerlere sahip düðümler silinir.
main()
{
     AGAC *kok = NULL;
     AGAC* max_min_bul_ve_sil( AGAC *);
 
     int secim = 1, x;
  
     while( secim )
     {
       printf("\n Bir Deger Girin..");
       scanf("%d",&x);
     
       kok = ekle( kok, x);
   
       printf("\n ilk agac : ");
       inorder(kok);
     
       printf("\n 1--> devam,  0---> son  ");
       scanf("%d",&secim);
     }

    kok = max_min_bul_ve_sil( kok ); 
    printf("\n silinmis agac: ");
    inorder(kok);
}
//////////////////////            
AGAC* max_min_bul_ve_sil( AGAC*kok)
{
   AGAC* ptr, *ptr1;
   ptr = kok;
// minimum degere sahip dugum araniyor.   
   while( ptr->sol!=NULL)
    { 
	  ptr1 = ptr; 
	  ptr = ptr->sol;
    }
   printf("\n min deger = %d", ptr->deger);
// silnecek dugum kok olabilir.
   if(ptr == kok ) 
      { 
	   kok = ptr -> sag;
	   free(ptr);
      }
   else
      {
	     ptr1 -> sol = ptr -> sag;
         free(ptr);
      }
// maksimum degere sahip dugum araniyor.  
      ptr = kok;
   
   while( ptr->sag!=NULL)
    {  
	  ptr1 = ptr; 
	  ptr = ptr->sag;
    }
   printf("\n max deger = %d", ptr->deger);
 // silnecek dugum kok olabilir.
   if(ptr == kok ) 
     {
	   kok = ptr -> sol;
	   free(ptr);
     }
   else
    {
	   ptr1 -> sag = ptr -> sol;
       free(ptr);
	}
    return(kok); 
}       
