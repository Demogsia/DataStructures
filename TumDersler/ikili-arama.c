#include<stdio.h>
#include<conio.h>
#include<math.h>
//sýralý bir dizide verilen x degerini
// ikili arama ile bulan C programýi
int main(){
    
     int a[10] = {12, 34, 56, 78, 90, 123, 234, 333, 555, 789 };
    
     int ilk = 0, son = 9, orta, x;
     printf ("\n aranacak deger..?  ");
     scanf ( "%d", &x );
     
      while ( ilk <= son )
        
       {  
          orta = (ilk + son) / 2;
           
          if ( a[orta]==x )
           {
  printf ( "\n aranan %d degeri dizinin %d.elemanidir", x, orta+1 );
                getch();
                return 0;   
           }
        
            else if ( x < a[orta] )
                 son = orta - 1;  
            else
                 ilk = orta + 1;
       }        
                 printf("\n aranan %d degeri dizide yok", x);      
                 getch();
     
  }
     
