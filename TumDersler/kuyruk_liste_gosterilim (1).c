/* Kuyrugun Liste Gösterilimi */
#include<stdio.h>
#include <stdlib.h>

typedef struct yapi{
	int bilgi;
	struct yapi *sonraki;
 }KUY;
	
    KUY *on = NULL, *arka;

	int ust = 3;
    char Y[4] = { '+', '*', '-', '+' };

 int main()
  {
    void ekle(int);
    int sil();
  
    int i, m;
    char is;
 
  printf( "\n numaranizin son rakami...? " ); 
  scanf ( "%d", &m );
 
  for( i = 0; i < 5; i++ )
    {
	  m = ( 9 + 2 * i ) % (5 + m );
	  
      printf ("\n m = %d", m);
	  
      ekle( m );
    }

  while( ust != -1 )
    {
	  is = Y[ust--];
	  
      switch( is )
       {
	     case '+': ekle( sil() + sil() );
           
           break;
	     
         case '-': ekle( sil() - sil() );
         
           break;
	     
         case '*': ekle( sil() * sil() );
         
           break;
        }
     }
      
      printf ("\n sonuc= %d ", on->bilgi );
      
      getch ();
  }
/*******************************************/
  void ekle ( int x )
    {
       if( on == NULL )
        {
          on = (KUY *)malloc( sizeof( KUY ) );
          on -> bilgi = x;
          on -> sonraki = NULL;
     
          arka=on;
          
          return;
        }
     
        arka = arka -> sonraki = ( KUY* )malloc( sizeof( KUY ) );
      
        arka -> bilgi = x;
        arka -> sonraki = NULL;
   }
/********************************/  
  int sil()
  {
     int m;
     
     m = on -> bilgi;
     on = on -> sonraki;
     return( m );
  }
