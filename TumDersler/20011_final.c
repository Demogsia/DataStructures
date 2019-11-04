//Herbir düðümünde tamsayý deðerler bulunan bir ikili arama aðacýnda
//tek çocuklu düðümlerin sayýsýný bulan ve aðacýýn kökünü silen C programý yazýnýz.

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct agac {
     int bilgi;
     struct agac *sol;
     struct agac *sag;
  }AGAC;
 
int main()
 {
      AGAC* kokptr = NULL;
      int x, k, no, yanit;
      
      
      AGAC* ekleme( int, AGAC* );
      AGAC* kok_sil(AGAC*);
      void tara( AGAC* );
      

     do
      {
         printf("\n DEGER GIRINIZ   ");
 
         scanf( "%d", &no );
         kokptr = ekleme( no, kokptr );
     
         printf("\n\n DEVAM == 1, SON == 0   ");
         scanf( "%d", &yanit );
    
      } while( yanit );
    
         
   
     tara( kokptr);  
    
     kokptr = kok_sil( kokptr );
     printf("\n koku silinmiþ agac : " );
     tara( kokptr);  
      
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
     
     { kokptr -> sol = ekleme( x, kokptr->sol ); return(kokptr);}

   else if( x > kokptr -> bilgi )
     { kokptr -> sag = ekleme( x, kokptr -> sag ); return(kokptr);}
    else
   return( kokptr );
}
/**********************/
/**********************/
void tara( AGAC*ptr1)
{
    

    if( ptr1 != NULL )
     {
        
        tara( ptr1 -> sol );
        printf("%d ", ptr1 -> bilgi );
        tara( ptr1 -> sag );
     }
}
/****************************/
AGAC* kok_sil( AGAC *kok )
{
      AGAC*ptr = kok, *ptr1;
      if(ptr == NULL)
       {
             printf("\n kok yok ");
             return( NULL );
       }
       
      if( ptr->sol == NULL && ptr -> sag == NULL)
       {
          free( ptr );
          return (NULL);
        }
        
       if( ptr -> sol == NULL )
         {
            kok = ptr -> sag;
            free( ptr );
            return (kok );  
          }     
          
         if( ptr -> sag == NULL)
         {
            kok = ptr -> sol;
            free( ptr );
            return (kok );  
          }         
        
		 ptr = ptr -> sag;
           if( ptr -> sol == NULL )
          {
            kok -> sag = ptr -> sag;
            kok ->bilgi = ptr->bilgi;
            free( ptr );
            return( kok);
          }      
          while( ptr -> sol !=NULL)
            {
                 ptr1 = ptr;
                 ptr = ptr->sol;
           }                
         
           kok -> bilgi = ptr -> bilgi;
           ptr1 -> sol = ptr -> sag;
           free( ptr );
           return(kok);
           }  
              
