/* Bagli liste Gösterilimi */
#include <stdio.h>
#include <stdlib.h>
     
typedef struct yigit {
    int deger;
    struct yigit *sonraki;
            }YIGIT;

YIGIT* ust = NULL;

int main ()
 {
    int deger, secim, yanit = 1;     
    YIGIT* deger_al ( void );    
  
    void push ( YIGIT* );//yýgýta deger ekler
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
YIGIT* deger_al ( )
     {       
          YIGIT *ptr;       
          ptr = ( YIGIT * ) malloc ( sizeof ( YIGIT ) );
          
          printf ( "\n deger giriniz ");
          scanf ( "%d", &ptr -> deger );
          ptr -> sonraki = NULL;     
          return(ptr);
      }     
/****************************************/
void push ( YIGIT *ptr)
   {    
          
          if ( ust == NULL )
             ust = ptr;
         
          else
             {   
               ptr -> sonraki = ust;
               ust  =  ptr;
                  
             }   
   }
/****************************************/
void pop ( )
   {     
        YIGIT *temp; 
       
    
        if ( ust == NULL) 
           { printf ("\n\n YIGIT BOS..");
             return;
             }         
       
        temp = ust -> sonraki;
        free ( ust );
        ust = temp;
         
     }
/*****************************************/
void yaz ( )
    {
         YIGIT *ptr = ust;
         
         while ( ptr != NULL)
           {
                printf (" %d ", ptr -> deger );
                ptr = ptr ->sonraki;
            }             
         printf ("\n\n");
     
     }                                      
          
      
