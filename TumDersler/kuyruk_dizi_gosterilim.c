/**KUYRUK DIZI GOSTERILIMI****/
#include <stdio.h>
#include <conio.h>

 typedef struct aday{
	int no;
	
 }KUY;

#define MAX_EL 10

 KUY *KUYRUK[ MAX_EL ];

 int arka=0,on=0,sayac=0;
 
 int main()
  {
     void ekle( KUY );
     void sil(), yaz();
   
     int i, j, m;
     KUY aday;
  
     printf ("\n Aday sayisi..?" );
     scanf ("%d", &m );
  
    for( j = 1; j <= m; j++ )
       {
        
         printf ("\n %d.ci adayýn nosu...? ",j ); 
         scanf("%d", &aday.no );
      
         ekle( aday );
      
         yaz();
      }   
         getch();
    
      printf("\n" );
         sil();
     
         yaz();
     
         getch();
         return 0;       
  }
/*******************************************/
  void ekle ( KUY ad )
  {
    KUY *ptr;
 
    if(sayac>=MAX_EL)
     {
       printf("\n kuyruk Dolu "); 
       return;
     }     
      
      ptr = (KUY *)malloc( sizeof( KUY ) );
      *ptr = ad;
 
      KUYRUK[ arka ] = ptr;
      arka = ++arka % MAX_EL;
      ++sayac;
      return;
    }
      
/********************************/  
  void  sil()
  {
  
    if(sayac==0)
    {
          printf ("\n kuyruk bos " );
          return;
    }
      free( KUYRUK[on] );
      on = ++on % MAX_EL;
      --sayac;
}      
/********************************/
 void yaz()
 { 
      int i = on;
        while( i < arka )
         {
          printf("\n %d" ,KUYRUK[i]->no );
          ++i;
         }    
} 
