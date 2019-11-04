/* YIGIT DIZI GOSTERILIM */
#include<stdio.h>
#define MAX 10

    int *YIGIT[ MAX ];
    int ust = -1;

    int * deger_al( void );

int main()
  {
     int deger, secim, yanit = 1;
     
     void push ( int* );//yigita deger ekler
     void pop ( void );// yýgýttan deger siler
     void yaz ( void );// yýgýttaki degerleri yazar 
     
     while ( yanit )
       {
           printf ( "\n 1 ----> push\t 2 ----> pop .... secim: ? ");
           scanf ("%d", &secim );
           
           if( secim == 1)
              push ( deger_al( ) );
              
           else
              pop ();
           
           printf ("\n\n"); 
           yaz ( );             
           
           printf ("\n 1 ----> DEVAM\t 0 ----> CIKIS....YANIT: ? "); 
           scanf ("%d", &yanit );   
        }
       
  
}    
/***************************************/
int* deger_al ( )
  {       int *ptr;       
          ptr = ( int * ) malloc ( sizeof ( int ) );
          
          printf ( "\n deger giriniz ");
          scanf ( "%d", ptr );
    
          return(ptr);
   }     
/****************************************/
void push ( int *ptr)
   {   
          if ( ust >= MAX - 1)
             printf( "\n YIGIT DOLU ");
             
          else
             YIGIT[ ++ust ] = ptr;
             
    }
/****************************************/
void pop ( )
   {
          if (ust < 0)
             printf ( "\n YIGIT BOS " );
            
          else
             free (YIGIT [ ust -- ] );
         
     }
/*****************************************/
void yaz ( )
    {
         int ys = ust;
         
         printf ( "\n YIGIT :");
         
         while ( ys > -1)
            printf (" %d ", *YIGIT[ ys -- ] );
         
         printf ("\n\n");
       
     }                                      
          
      
 
