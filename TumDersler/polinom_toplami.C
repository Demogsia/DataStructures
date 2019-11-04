#include<stdio.h>
#include<string.h>
#include <math.h>
#include<stdlib.h>
#include<conio.h>

typedef struct pol{
   int kat;
   int ust;
   struct pol *sonraki;
}POL;

int main(void)
 {
  POL *gir( void );
  POL *top( POL*, POL* );
  void pol_yaz( POL* );
  
  POL *pol1, *pol2, *top_pol;
  char is;
  
  pol1 = gir();
  pol2 = gir();
  
  printf("\n\n BIRINCI POLINOM : ");
  pol_yaz( pol1);
  
  printf("\n\n IKINCI POLINOM  : "); 
  pol_yaz(pol2);

  top_pol = top( pol1, pol2 );
  printf("\n\n TOPLAM          : ");  
  pol_yaz(top_pol);
  

}
//////////////////////////
void pol_yaz( POL *ptr)
{
  
  char is;

 
  while( ptr -> sonraki != NULL )
   {
     if( ptr -> kat == 0) goto s;
     
     else if( ptr -> kat < 0 ) is='-';
     
     else is = '+';

     if( ptr -> ust == 1 && abs( ptr -> kat) == 1 )
       printf(" %c X",is);
    
     else if( ptr -> ust == 1 )
       printf(" %c %d X",is,abs(ptr->kat));
     
     else if(ptr->ust == 0)
       printf(" %c %d",is, abs( ptr -> kat ) );
     
     else if( abs( ptr -> kat ) == 1 )
       printf(" %c X^%d", is, ptr -> ust );
     else
       printf(" %c %d X^%d",is, abs( ptr -> kat ), ptr -> ust );
   
   s: ptr = ptr -> sonraki;
   } 

  }
//////////////////////////
POL *gir()
 {
     POL *ptr, *pp; 
     int deg, i;

     pp = ptr = (POL *)malloc( sizeof( POL ) );
     
     printf("\n polinomun derecesi?  ");
     scanf("%d", &deg);

     while( deg >= 0 )
     {
        ptr -> ust = deg;

       printf("\n X^%d nin katsayisi:", deg );
       scanf("%d", &ptr -> kat );

       if(deg!=0)
        {

         ptr -> sonraki = (POL *)malloc(sizeof(POL));
         ptr=ptr->sonraki;
        }
      else
       ptr -> sonraki = NULL;
     
      deg--;
     }
      return (pp);
 }
////////////////////////////////////
POL *top( POL *ptr1, POL *ptr2 )
{
   POL *ptr, *pp;
   pp = ptr = (POL *)malloc(sizeof(POL));

   while( ptr1 != NULL || ptr2 != NULL )
    {
      if( ptr1 -> ust == ptr2 -> ust)
       {
         ptr -> kat = ptr1 -> kat + ptr2 -> kat;
         ptr -> ust = ptr1 -> ust;
         ptr1 = ptr1 -> sonraki;
         ptr2 = ptr2 -> sonraki;
       }

      else if( ptr1 -> ust > ptr2 -> ust )
       {
         *ptr = *ptr1;
         ptr1 = ptr1 -> sonraki;
       }
     else
       {
         *ptr = *ptr2;
          ptr2 = ptr2 -> sonraki;
       }
       ptr -> sonraki = ( POL* )malloc( sizeof(POL) );
       ptr = ptr -> sonraki;
       ptr -> sonraki = NULL;
     }
return(pp);
}
