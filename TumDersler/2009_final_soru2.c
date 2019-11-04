//SORU: kok iþaretcisi bilinen bir ikili arama aðacýnda tek
// cocuklu duðumlerin sayisini bulan ve en büyük, en küçük
// deðerlere sahip düðümleri silen C fonksiyonu yaziniz.
 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct agac {
     int bilgi;
     struct agac *sol;
     struct agac *sag;
  }AGAC;
 int dug_say = 0;
int main()
 {
      AGAC* kokptr = NULL;
      int x, k, no, yanit;
      
      AGAC* ekleme( int, AGAC* );
      void tek_cocuklU_say_bul( AGAC *);
      void buyuk_kucuk_sil(AGAC *); 
      void inorder( AGAC * );

     do
      {
         printf("\n DEGER GIRINIZ   ");
 
         scanf( "%d", &no );
         kokptr = ekleme( no, kokptr );
     
         printf("\n\n DEVAM == 1, SON == 0   ");
         scanf( "%d", &yanit );
    
      } while( yanit );
    
       
        printf("\n\n INORDER TARAMA   :  " ) ;
        inorder( kokptr );
  
        tek_cocuklu_say_bul( kokptr );
        printf("\n tek cocuklu dugum sayisi = %d", dug_say);
        buyuk_kucuk_sil (kokptr);   
     
        getch();
      return 0;
 }
/*************************************/
AGAC* ekleme( int x, AGAC *kokptr )
{

   if( kokptr == NULL)
   {
      kokptr = ( AGAC* )malloc( sizeof( AGAC ) );
      kokptr -> bilgi = x;
      kokptr -> sag = kokptr -> sol = NULL;
   }
 
   else if( x < kokptr -> bilgi )
     
      kokptr -> sol = ekleme( x, kokptr->sol );

   else if( x > kokptr -> bilgi )
      kokptr -> sag = ekleme( x, kokptr -> sag );
    
   return( kokptr );
}
/**************************************/
void inorder( AGAC *ptr )
{
    if( ptr != NULL )
     {
        inorder( ptr -> sol );
        printf("%d ", ptr -> bilgi );
     
        inorder( ptr -> sag );
     }
}
/****************************************/
void tek_cocuklu_say_bul( AGAC* ptr )
{
     if ( ptr != NULL )
      {
         tek_cocuklu_say_bul( ptr -> sol);
  
         if((ptr->sol==NULL&&ptr->sag!=NULL)||
            (ptr->sol!=NULL&&ptr->sag==NULL)) dug_say++;
  
         tek_cocuklu_bul(ptr -> sag);
       }
}
/********************************/
void buyuk_kucuk_sil( AGAC* ptr)
{
  AGAC *ptr1;
    
  if( ptr -> sol == NULL && ptr -> sag == NULL)
  
    {
       printf("\n Agac bir dugumden (kok) ");
       free(ptr);
       kokptr=NULL;
       return;
    }   
      
  else if(ptr -> sol == NULL&& ptr ->sag != NULL)
    { 
      temp = kokptr;
      kokptr = ptr = ptr -> sag;
      free( temp );  
      while( ptr -> sag -> sag != NULL)
       ptr = ptr -> sag;
       ptr1 = ptr;
       ptr1 ->sag = ptr->sag->sol;
       ptr1 ->sol=NULL;
       free(ptr);
       
     }     
      
  else if( ptr -> sol != NULL && ptr -> sag == NULL)
                      
    {
        
      while( ptr -> sol -> sol != NULL )
       ptr = ptr -> sol;
       
     printf("\n en buyuk degerli dugumun (kok) babasi yoktur.");
     printf("\n en kucuk degerli dugumun babasýnýn degeri = %d", ptr->bilgi);
    }           
  else
    {  
       ptr1 = ptr;
       while( ptr1 -> sag -> sag != NULL )
        ptr1 = ptr1 -> sag;
     
      printf("\n en buyuk degerli dugumun babasi = %d", ptr1->bilgi);
         
       ptr1 = ptr; 
       while( ptr1 -> sol -> sol != NULL )
         ptr1 = ptr1 -> sol;
          
      printf("\n en kucuk degerli dugumun Babasi = %d", ptr1->bilgi);
    }
 }          
              
