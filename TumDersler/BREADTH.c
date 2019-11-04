//Komþuluk matrisi verilen grafýn geniþlemsine (BFS) taramasýný yapar.
#include<stdio.h>
#include<conio.h>
#define DS 8
#define MXEL 8
typedef struct dugum{
int statu;
}DGM;
DGM DUG[DS];
int KOM[DS][DS]={0,0,1,1,0,0,0,0,
                 0,0,0,0,1,0,0,1,
                 0,0,0,0,1,0,1,0,
                 0,1,0,0,0,0,0,0,
                 0,0,0,1,0,0,0,0,
                 0,1,0,0,0,0,1,0,
                 0,0,0,1,0,1,0,0,
                 0,0,0,0,0,1,1,0};
int KUY[DS];
int arka=0;
int on = 0;
int sayac = 0;
int main()
 {
    void ekle( int );
    int sil( void );
    int i, j, k;

    for( j = 0; j < DS; j++ )
     DUG[j].statu = -1;
 printf("\n Hangi dugumden baslanacak i = ?  ");
 scanf("%d",&i);
 i=i-1;

 DUG[i].statu = 1;
 
 while(i!=-1)
  {
    printf(" %d ",i+1);
    for( k = 0;k < DS; k++ )
      {
        if(KOM[i][k]!=0&&DUG[k].statu!=0
           &&DUG[k].statu!=1)
         {
          ekle(k);
          DUG[k].statu=0;
         }
      }
        i = sil();
       DUG[i].statu = 1;
   }

}
/*********************/
void ekle( int k )
 {
     KUY[ arka ] = k;
     arka = ++arka % MXEL;
     ++sayac;
 }
/*******************/
int sil()
{
    int j;
    if( sayac == 0 )
       return( -1 );
      
    j = KUY[ on ];

   on = ++on % MXEL;
    --sayac;
   return(j);
}






