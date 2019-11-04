#include<stdio.h>
#include<conio.h>

typedef struct liste
     {   int deger;
         struct liste *sonraki;
     }LST;
//m dügümden oluþan bagli liste olusturuluyor.  
int main()
    { 
      int n, m, i = 1;//n dugumlerdeki degerler, m listedeki dugum saysý
     
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
            
         getch();  
}  
      
  
  
