#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
//n! BULUNMAKTADIR
  typedef struct SAYI{
       int say;
       struct SAYI *sonraki;
        }SAYI;
void ekle(int, SAYI*);
int ato ( char );
int main()
{     
      SAYI *ptr, *ilk;
      SAYI* ters(SAYI*);
      SAYI *carp( int, SAYI* );
      int i,a;
      
      printf("\n sayi giriniz:  ");
      scanf("%d", &a);
      
      ilk = (SAYI*)malloc(sizeof(SAYI));
      ilk -> say = -1;
     
      ptr = (SAYI*)malloc(sizeof(SAYI));
      ptr -> say = 1;
     
      ptr -> sonraki = ilk;
      ilk->sonraki = ptr; 
      
      for(i = 2;i <= a; i++ )
         {  
           ilk = ters(ilk);
           ilk = carp(i,ilk);
           
          }
      
      
      ptr = ilk->sonraki;
      printf("\n %d! = ", a);

      while( ptr -> say != -1)
       {
         printf( "%d", ptr -> say );
         ptr = ptr -> sonraki;
        }
   
 }

/**********CARP**************/
SAYI*carp(int i,SAYI*ilk)
{
    SAYI *ptr = ilk -> sonraki,*crp;
    
   
    int cp, elde = 0;
    crp = ( SAYI* )malloc( sizeof( SAYI ) );
    crp -> say = -1;
    crp -> sonraki = crp;
        
    while( ptr -> say != -1 )
     {
       cp = ptr -> say * i + elde;
       elde = cp / 10;
       cp = cp % 10;
       ekle( cp, crp);
       ptr = ptr -> sonraki;
     }  
     while( elde != 0)
     {
       ekle( elde % 10, crp );
       elde = elde/10;
     }          
    return( crp);
} 

/**********EKLE********/
void ekle(int i , SAYI*ilk)
{
   SAYI*ptr, *ptr1;
   
   ptr1 = ilk -> sonraki;
   ptr = ( SAYI* )malloc( sizeof( SAYI ) );
   ptr -> say = i;
   ilk -> sonraki = ptr;
   ptr -> sonraki = ptr1;
    
 
 }
/*************TERS*************/
SAYI* ters(SAYI*ilk)
{
   SAYI* ilk1, *ptr, *ptr1,*ptr2;
   ilk1= (SAYI*)malloc(sizeof(SAYI));
   ilk1 -> say = -1; 
   ilk1 -> sonraki = ilk1; 
   ptr = ilk->sonraki;
   
   
  
   while( ptr -> say != -1 )
   {
     ptr2 = ptr -> sonraki;
     
     ptr1 = ilk1 -> sonraki;
     ilk1 -> sonraki = ptr;
     ptr -> sonraki = ptr1;
     ptr = ptr2;
   } 
   ilk = ilk1;
    return(ilk);
}        
    

