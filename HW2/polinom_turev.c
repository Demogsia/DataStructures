#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct polinom
     {   int ust;
         int katsayi;
         struct polinom *sonraki;
     }PLNM;


int main()
    { 
       

	  /*ilk1 1.polinomun, ilk2 2.polinomun ilk toplam polinomun saklandigi
Listelerin ilk işaretçileridir. */       
  
          PLNM *ilk1, *ilk2, *ilk3, *poli, *toplam;

	  /*Kullanılacak fonksiyonlar tanımlandı*/
	  PLNM *pol_gir( void );
	  PLNM *pol_turev(PLNM*);
          void pol_yaz( PLNM* );
          PLNM *pol_top( PLNM*, PLNM* );
      
          printf ("Polinomu Giriniz\n " );
          ilk1 = pol_gir();      
          printf ("\n Polinom  : " );
          pol_yaz ( ilk1 );
      
	  printf("\n");

	    ilk2 = pol_turev( ilk1 );
	   
      printf("\n Polininomun 1.Turevi: ");
	  pol_yaz( ilk2 );
      
      
	  printf("\n");

	  ilk3 = pol_turev( ilk2 );
	  printf("\n Polininomun 2.Turevi: ");
	  
      pol_yaz( ilk3 );

	  printf("\n");

	  toplam = pol_top( ilk3, ilk1 );
	  printf("\n istenen islem y'' + y = ");
	  pol_yaz(toplam);
    
	  return 0;
}

/***********************************************************/
 PLNM* pol_gir()
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
 /////////// Ekleme1 basi/////////////////     
      if( ptr->ust == 0)
       {
        printf(" %d", ptr->katsayi);
        return;
       }
////////////Ekleme1 sonu///////////////////////      
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

/****************************************************************/

/* türevi alınacak polinomun derecesi 1 ise hesaplama yapmıyo ??? */


PLNM *pol_turev(PLNM *ptr)
 {

	int n, i, m;
	PLNM *ptr2, *ptr1;

	ptr2 = ptr1 = (PLNM*)malloc(sizeof(PLNM));
//////////// Ekleme2 basi//////////////////////
    if( ptr -> ust == 0 )
	 {
        ptr2 -> ust = ptr2 -> katsayi = 0;
        ptr2 -> sonraki = NULL;
        return( ptr2 );
     }     
//////////////Ekleme2 sonu///////////////////
    n = ptr -> ust;
    
	for( i = n; i > 0; i--)
     {
	
		m = ptr -> katsayi;

		if( i == 1 )
         {

			ptr1 -> ust = 0;
		    ptr1 -> katsayi = m;
			ptr1 -> sonraki = NULL;
            return( ptr2 );
		 }			
		else if( i > 1 )
         {
	                				
		    ptr1 -> ust = i - 1;
		    ptr1 -> katsayi = i * m;
			ptr1 = ptr1 -> sonraki  = (PLNM*)malloc(sizeof(PLNM));

		 }
			
	    ptr = ptr -> sonraki;
	//	ptr1 = ptr1 -> sonraki;
	}

	   return (ptr2);
}

//**************************************************************/

PLNM *pol_top( PLNM *pol1, PLNM *pol2 )
    
 {           PLNM *pol,*ply,*poly;
             poly = pol = ( PLNM * )malloc ( sizeof( PLNM ) ); 
   
     while( pol1 != NULL && pol2 != NULL )
       {    
          if( pol1 -> ust == pol2 -> ust )
           { 
             pol -> ust = pol1 -> ust;
             pol -> katsayi = pol1 -> katsayi + pol2 -> katsayi;
            
             pol1 = pol1 -> sonraki;
             pol2 = pol2 -> sonraki;
             ply = pol;
               
           }          
          
          else if( pol1 -> ust > pol2 -> ust)
          
          {
             pol -> ust = pol1 -> ust;
             pol -> katsayi = pol1 -> katsayi;          
        
             pol1 = pol1 -> sonraki;
             ply = pol;
                             
          }  
          else
          {
             pol -> ust = pol2 -> ust;
             pol -> katsayi = pol2 -> katsayi;          
           
             pol2 = pol2 -> sonraki;
             ply = pol;
          } 
    
             pol = pol -> sonraki = ( PLNM * )malloc ( sizeof( PLNM ) );
      
       }/* while sonu */ 

          if( pol1 == NULL )
             ply -> sonraki = pol2;
          else
             ply -> sonraki = pol1;   
        
          return( poly ) ;
 }

