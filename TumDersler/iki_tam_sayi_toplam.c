/* BUYUK BASAMAKLI TAMSAYILARIN TOPLAMI YAPILIYOR */

#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

  typedef struct SAYI{
       int say;
       struct SAYI *sonraki;
       }SAYI;

SAYI *ilk1, *ilk2;

int ekle(int,SAYI*);
int ato ( char );


int main()
{     
      SAYI *ptr;
      SAYI *say_gir( void );
      SAYI *toplam( void );
      
      
      printf("\n birinci sayiyi giriniz:  ");
      ilk1 = say_gir();

      printf("\n ikinci sayiyi giriniz :  ");
      ilk2 = say_gir();

      ptr = toplam() -> sonraki;
      printf("\n\t       TOPLAM =   ");

     while( ptr -> say != -1)
       {
         printf( "%d", ptr -> say );
         ptr = ptr -> sonraki;
        }
   
     getch();
 }
/*********SAY_GIR*******/
 SAYI *say_gir()
 {
    SAYI *ilk;
    char ch;
    
    ilk = (SAYI*)malloc(sizeof(SAYI));
    ilk -> say = -1;
    ilk -> sonraki = ilk;

    while( (ch = getchar())!='\n')
 
       ekle( ato( ch ), ilk);
   
     return (ilk);
 }
/**********TOPLAM********/

SAYI* toplam()
  {
    SAYI *ptr1 = ilk1 -> sonraki;
    SAYI *ptr2 = ilk2 -> sonraki,*top;
   
    int tp, elde=0;

    top = ( SAYI* )malloc( sizeof( SAYI ) );
    top -> say = -1;
    top -> sonraki = top;

   while(ptr1->say!=-1&&ptr2->say!=-1)
   {
      tp = ptr1 -> say + ptr2 -> say + elde;
      elde = tp / 10;
      tp = tp%10;
      ekle( tp, top );
      ptr1 = ptr1 -> sonraki; ptr2 = ptr2 -> sonraki;
      
   }

    if( ptr1 -> say == -1 && ptr2 -> say == -1 )
    {
      if( elde == 0 )
        return( top );
  
      else ekle( 1, top );
      return( top );
    }

    else if( ptr1 -> say == -1 )
      {
        while( ptr2 -> say != -1 )
          {
             ekle( (ptr2 -> say + elde)%10, top );
            // elde=0;
             elde = (ptr2 -> say + elde ) / 10;
             ptr2 = ptr2 -> sonraki;
          }
          if(elde!=0)
             ekle( elde, top ); 
       
       return( top );
      }

    else
    {
       while( ptr1 ->say != -1 )
         {
            ekle( (ptr1 -> say + elde)%10, top );
          //  elde = 0;
            elde = (ptr1 -> say+elde)/10;
            ptr1 = ptr1 -> sonraki;
         }
        if(elde!=0)
           ekle( elde, top ); 
        return(top);
    }
 }
/**********EKLE********/
int ekle(int a, SAYI *pp )
{
   SAYI*ptr, *ptr1;
   
   ptr1 = pp -> sonraki;
   ptr = ( SAYI* )malloc( sizeof( SAYI ) );
   ptr -> say = a;
   pp -> sonraki = ptr;
   ptr -> sonraki = ptr1;
 }
/**********ATO*************/
int ato(char ch)
{ 
    if( ch == '0' ) return 0;
    if( ch == '1' ) return 1;
    if( ch == '2' ) return 2;
    if( ch == '3' ) return 3;
    if( ch == '4' ) return 4;
    if( ch == '5' ) return 5;
    if( ch == '6' ) return 6;
    if( ch == '7' ) return 7;
    if( ch == '8' ) return 8;
    if( ch == '9' ) return 9;
}   


