#include<stdio.h>
#include <stdlib.h>
//Bu program rekursif fonksiyon kullanarak agac olusturur.
typedef struct agac{
        int deger;
        struct agac *sol;
        struct agac *sag;
        }AGAC;

main()
{
  AGAC *KOK = NULL;
  AGAC*ekle ( AGAC*, int);
  void inorder( AGAC*);
  void preorder( AGAC*);
  void postorder( AGAC*);
  
  int secim = 1, x;
  
  while( secim )
  {
     printf("\n Bir deger giriniz.. ");
     scanf("%d",&x);
     
     KOK = insert( KOK, x);
   
     printf("\n LNR : ");
     inorder(KOK);
     
     printf("\n NLR : ");
     preorder(KOK);
     
     printf("\n LRN : ");
     postorder(KOK);
     
     printf("\n 1--> devam,  0--->cikis  ");
     scanf("%d",&secim);
     
  }

 
 
}
//////////////////////            
AGAC* ekle( AGAC *KOK, int x)
{
      
   if( KOK == NULL)
    {
      KOK = (AGAC*)malloc(sizeof(AGAC));
      KOK->deger = x;
      KOK->sol = KOK->sag = NULL;
      return(KOK);
    }           
     if( x < KOK->deger)
     {
         KOK->sol = ekle ( KOK->sol,x);
         return(KOK);
      }   
      else if( x > KOK->deger)
     {
         KOK->sag = ekle ( KOK->sag,x);
         return(KOK);
      } 
     else
      printf(" %d DEGERÝ AGACTA VAR", x);
      return(KOK);
      
}                  
/////////////////////////////
void inorder( AGAC*ptr)
{
   if( ptr!=NULL)
   {
     inorder( ptr->sol);
     printf(" %d", ptr->deger);
     inorder( ptr->sag);
   }  
}                              
/////////////////////////
void preorder( AGAC*ptr)
{
   if( ptr!=NULL)
   {
     
     printf(" %d", ptr->deger);
     preorder(ptr->sol);
     preorder( ptr->sag);
   }  
}                              
////////////////////////
void postorder( AGAC*ptr)
{
   if( ptr!=NULL)
   {
     postorder( ptr->sol);
     
     postorder( ptr->sag);
   printf(" %d", ptr->deger);
   }  

   }                              
