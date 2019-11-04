#include<stdio.h>
//Komsuluk matrisi verilen grafýn derinlemesine (DFS) taramasýný yapar.
#define DS 8
#define MXEL 8
typedef struct dugum{
    int statu;
  }DGM;
DGM DUG[DS];

int KOM[DS][DS]={0,1,0,0,1,0,0,0,
                 0,0,1,0,0,1,0,0,
                 0,0,0,1,0,1,1,0,
                 0,0,0,0,0,0,1,1,
                 0,0,0,0,0,1,0,0,
                 1,0,0,0,0,0,1,0,
                 0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,1,0};

int YIG[DS];
int ust = -1;
int main()
 {
    void push( int );
    int pop( void );
    int i, j, k;

    for( j = 0; j < DS; j++ )
      DUG[j].statu = -1;
    printf("\n Hangi dugumden baslanacak i=?  ");
    scanf("%d",&i);i=i-1;
    DUG[i].statu = 1;

   while( i != -1 )
     {
        printf("%d ",i+1);
     for( k = 0; k < DS; k++ )
         {
     if(KOM[i][k] != 0 && DUG[k].statu !=0 &&DUG[k].statu != 1 )
      {
         push(k);
         DUG[k].statu=0;
      }
     }
     i=pop();
     DUG[i].statu=1;
 }
    
    return 0;
}
/*********************/
void push(int k)
{
     YIG[++ust]=k;
}
/************/
int pop()
{
    int j;
    if( ust <0 )
     return(-1);
  
    j = YIG[ust--];
    return(j);
}






