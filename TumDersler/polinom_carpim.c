#include<stdio.h>
#include<conio.h>
#include <string.h>
#include <stdlib.h>
//VERILEN IKI POLINOMUN CARPIMI BULUNUYOR
typedef struct polinom
     {   int ust;
         int katsayi;
         struct polinom *sonraki;
     }PLNM;
/*P(n) ve Q(m) Polinomlarinin carpimi bulunmaktadir */ 
 void  pol_yaz( PLNM* );
 int main()
    { 
          int n, m, i = 1;
/*ilk1 1.polinomun, ilk2 2.polinomun ilk carpim polinomun saklandigi
Listelerin ilk iþaretçileridir. */       
  
          PLNM *ilk1, *ilk2, *ilk, *ptr1, *ptr2;
          PLNM* pol_gir( void );
          
          PLNM*pol_carp( PLNM*, PLNM* );
      
          printf (" 1.Polinomu Giriniz\n " );
          ilk1 = pol_gir();      
          printf ("\n 1.Polinom  : " );
          pol_yaz ( ilk1 );
      
          printf ("\n\n 2.Polinomu Giriniz\n" );
          ilk2 = pol_gir();
          printf ("\n 2.Polinom  : " );
          pol_yaz( ilk2 );
      
          ilk = pol_carp( ilk1, ilk2 );
          printf ("\n\n CARPIM  Polinom  :  " );
          pol_yaz( ilk );  
          
          printf ( "\n\n" );
          getch();  
}  
/**********************************/
 PLNM*pol_gir()
    {     
          int n, i;
          
          PLNM* ptr1,*ptr;
     
          printf ("\n Polinomun Derecesi..?  " );
          scanf( "%d", &n );
          
          ptr1 = ptr = (PLNM *)malloc (sizeof(PLNM));      
      
      for( i = n; i > 0; i -- )
        { 
          printf ("\n  X^%d nin katsayisi..?  ", i );
          scanf ("%d", &ptr -> katsayi ); 
          ptr -> ust = i;
          ptr = ptr -> sonraki = (PLNM *)malloc (sizeof(PLNM));          
        } 
          printf ("\n  Sabit Terim......?  " );
          scanf ( "%d", &ptr -> katsayi );
          
          ptr -> ust = 0;
          ptr -> sonraki = NULL;
          return( ptr1 );
    }
 /***********************************/
 void pol_yaz( PLNM *ptr )
    {
          PLNM*ptr1;
       
      for( ptr1 = ptr; ptr1 -> ust > 1; ptr1 = ptr1 -> sonraki )
        {  
          if( ptr1 -> katsayi == 0 )
               continue;
           
          if( ptr1 -> katsayi > 0 && ptr1 -> katsayi != 1 )
               printf (" + %d X^%d", ptr1->katsayi, ptr1->ust );
           
          else if( ptr1 -> katsayi < 0 && ptr1 -> katsayi != -1 ) 
            
               printf (" - %d X^%d",abs( ptr1 -> katsayi ), ptr1 -> ust ); 
          
          else if( ptr1 -> katsayi == 1 )        
               printf (" + X^%d", ptr1 -> ust );
           
          else if( ptr1 -> katsayi == -1 )
               printf (" - X^%d", ptr1 -> ust );
               
        }   
          if(ptr1 -> ust == 1 && ptr1 -> katsayi > 1 )    
             {
               printf (" + %d X", ptr1->katsayi );
               ptr1 = ptr1 -> sonraki;
             }
          else if( ptr1 -> ust == 1 && ptr1 -> katsayi < -1 )
             {
               printf ( " - %d X", abs( ptr1 -> katsayi ) );
               ptr1 = ptr1 -> sonraki;
             }
          else if( ptr1 -> ust == 1 && ptr1 -> katsayi == 1 )
             {
               printf (" + X" );
               ptr1=ptr1->sonraki;
             }         
          else if ( ptr1 -> ust == 1 && ptr1 -> katsayi == -1 )
             {
               printf (" - X " );
               ptr1 = ptr1 -> sonraki;
             }
          else  
             ptr1 = ptr1 -> sonraki;
           
          if( ptr1 -> katsayi > 0 )
             printf ( " + %d", ptr1 -> katsayi );
          
          if( ptr1 -> katsayi < 0 )
             printf (" - %d", abs( ptr1 -> katsayi ) );
    }        
/**********************************************/
PLNM *pol_carp( PLNM *pol1, PLNM*pol2 ) 
    
  {  
      PLNM *pol,*ply,*poly, *ilk;
      
      poly = pol = ( PLNM * )malloc ( sizeof( PLNM ) ); 
      
      int m, top;
      
      while( pol1 != NULL  )
       {    
           ply = pol2;
         
         
          while( ply != NULL )
          {
             pol -> ust = pol1 -> ust + ply -> ust;
             pol -> katsayi = (pol1 -> katsayi) * (ply -> katsayi);
     
             if(ply -> sonraki == NULL && pol1 -> sonraki == NULL )
               {
                    pol -> sonraki = NULL;
                    break;
                }
             pol = pol -> sonraki = ( PLNM * )malloc ( sizeof( PLNM ) );
             ply = ply -> sonraki;
           }  
           pol1 = pol1 -> sonraki;
        
        }    
      
        m = poly -> ust;
        ilk = pol = ( PLNM * )malloc ( sizeof( PLNM ) );
      
        while( m >= 0 )
         { 
           ply = poly;   
           top = 0;
          
            while( ply != NULL )
             {
               if( ply -> ust == m)
                top = top + ply -> katsayi;       
              
               ply=ply->sonraki;
             }
            
            pol -> ust = m; 
            pol -> katsayi = top;
          
            if ( m == 0 )
              { 
                   pol -> sonraki = NULL;
                   break;
              }
            
            pol = pol->sonraki= ( PLNM * )malloc ( sizeof( PLNM ) );        
          
            m--;
        
         }        
          
          free(poly);
          
          return( ilk ) ;
 }



