//SORU: Her bir dugumunde tamsayi degerler bulunan bir baglý
//listenin dugum sayýsi n yi bulan ve n/2.dugumu silen C fonksiyonu yaz.


#include<stdio.h>
#include<conio.h>

typedef struct liste
     {   int deger;
         struct liste *sonraki;
     }LST;
//m dügümden oluþan bagli liste olusturuluyor.  
int main()
    { 
      LST* dug_say_bul_sil(LST*); 
      int m, i = 1;//n dugumlerdeki degerler, m listedeki dugum saysý
     
      LST *ilk, *ptr;
     
      ilk = ptr = ( LST* )malloc( sizeof( LST ) ); 
      
      printf("\n DUGUM SAYISI...?  ");
      scanf( "%d", &m );  
  
      for( i = 1; i <= m; i++ )
      {  
         printf ( "\n  DEGER GIRINIZ.." );
         scanf("%d", &ptr->deger );
     
             if( i < m ) 
             ptr = ptr -> sonraki = ( LST* )malloc( sizeof( LST ) );
            
             else   
    
             ptr -> sonraki = NULL; 
       }  
       
         printf ( "\n\n LISTE :" );         
         ptr = ilk; 
  
        while( ptr != NULL )
         {  
            printf( " %d ", ptr -> deger );
            ptr = ptr -> sonraki;
        }       
            
       ilk = dug_say_bul_sil( ilk );  
      
       printf ( "\n\n LISTE :" );         
         ptr = ilk; 
  
        while( ptr != NULL )
         {  
            printf( " %d ", ptr -> deger );
            ptr = ptr -> sonraki;
        }    
      
      
         getch();  
}  
      
////
LST* dug_say_bul_sil( LST*ilk)
 {
     LST* ptr = ilk, *ptr1;
     int n = 0, i;       
  
     while( ptr != NULL)
      {
         n = n + 1;
         ptr = ptr -> sonraki;
      }
     printf("\n dugum sayisi = %d", n );
     
     ptr = ilk;
     if( n == 1 )
      {
        printf( "\n n/2 = 0 oldugu icin silme yapilamaz" );
        return( ilk );
      }
    
     if( n == 2 )
      {
// ilk dugum siliniyor.
        ptr1 = ilk;
        ilk = ptr -> sonraki;
        free( ptr1 );
        return( ilk );
       }
     
     for ( i = 1; i < n/2; i++ )
      {
         ptr1 = ptr;
         ptr = ptr -> sonraki;
      }
      
      ptr1 -> sonraki = ptr -> sonraki;
      return ( ilk );
  }       
      
      
      
                           
