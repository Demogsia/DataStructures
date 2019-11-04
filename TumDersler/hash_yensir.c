
#include<conio.h>
#include<stdio.h>
#define nulkey -1
#define TABLOBOY 10
#define silkey -2
//yeniden sýralanmýþ hash tablosu oluþturur.
typedef struct fened{
	char ad[10];
	char soyad[12];
	char bolum[30];
	int no;
	}FENED;

int arama( int );

FENED tablo[ TABLOBOY ];
int say = 0;

int main()
 {
      int i, secim, no, k, j, yanit;
      void ekle( void );
      void sil( void );
      
 
 
      for( i = 0; i < TABLOBOY; i++ )
        tablo[i].no = nulkey;
   
      do{
         
          printf( "\n SECÝMÝNÝZ:  " );
          printf("\n\n 1-----EKLEME  2-----SILME   3-----ARAMA  ");
          scanf( "%d", &secim );

          switch( secim )
           {
             case 1:
               ekle();break;
             
             case 2: 
               sil();break;

             case 3:
               printf("\n ARANAN DEGER...?");
               scanf( "%d", &no );
               k = arama( no );

           if( k == -1 )
             printf("\n ARANAN DEGER YOK \n");
           else
            
             printf("\n ARANAN DEGER %d TABLONUN %d. ELEMANI ", tablo[k].no, k );
             break;
      }

           for( j = 0; j< TABLOBOY; j++ )
             printf(" \nt[%d] %d", j, tablo[j].no );

           printf("\n\n 1-------DEVAM 0-------SON   "); 
           scanf( "%d", &yanit );
    }while(yanit);

     getch();
}
/*******************/
void ekle(void)
{
     int j, i, no, k;
     FENED  tt, temp;

     if( say == TABLOBOY )
     {
      printf("\n TABLO DOLU EKLEME YAPILAMAZ.\n");
      return;
     }

    printf("\n NO....? ");
    scanf( "%d", &tt.no );
    printf("\n");
    
    k = tt.no % TABLOBOY; 
    
   while( tablo[k].no != nulkey && tablo[k].no != silkey )
    {
      if( tablo[k].no == tt.no )
      {
        printf("\n EKLENEN DEGER MEVCUT \n");
        return;
      }

     else if( tablo[k].no < tt.no )
      {

         temp = tablo[k];
         tablo[k] = tt;
         tt = temp;
         k = ( k + 1 ) % TABLOBOY;
              
      }
     else
    
      k = (k + 1) % TABLOBOY;
  }

    tablo[k] = tt;
    say++;
}
/**************************/
void sil(void)
{
   int no, k; 
   printf( "\n SÝLÝNECEK DEGER..? " );
   scanf( "%d", &no );
   
   k = arama( no );
  
   if( k == -1 )
    {
      printf( "\n SÝLÝNECEK DEGER YOK \n" );
      return;
    }
  else
    tablo[k].no = -2;

  printf("\n SÝLME TAMAMLANDI \n");
  say--;
}
/*******************************/
int arama( int no )
 {
    int k, i = 1;
    k = no % TABLOBOY;

     while(( tablo[k].no > no || tablo[k].no == silkey ) && i <= TABLOBOY )
      {
         k = ( k + 1 ) % TABLOBOY;
         i++;
      }

    if( tablo[k].no == no )
      return( k );
    else
     return(-1);
 }
