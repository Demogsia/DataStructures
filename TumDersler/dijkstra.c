/*DIJKSTRA ALGORITMASI ILE
AGIRLIK MATRISI VERILEN GRAFIN IKI
DUGUMU ARASINDAKI ENKISA YOLUN BULUNMASI*/
#include <stdio.h>

#define DS 11
#define sonsuz 1000
typedef struct dugum{
int on_dug;
int statu;
int uzaklik;
}DGM;
DGM DUG[DS];
int YOL[DS][DS], yol[DS];
void yolmat();
int minbul();
int AGR[DS][DS]={0,3,0,0,0,0,0,4,5,0,0,
                 0,0,2,0,0,0,0,0,5,7,0,
                 0,0,0,0,0,0,0,0,0,0,6,
                 0,0,3,0,0,0,0,0,0,0,7,
                 0,0,0,2,0,0,0,0,0,0,0,
                 0,0,0,0,5,0,0,0,0,0,4,
                 0,0,0,0,0,6,0,0,0,0,0,
                 0,0,0,0,0,0,2,0,0,5,0,
                 0,0,0,0,0,0,0,7,0,4,0,
                 0,0,4,0,0,3,4,0,0,0,0,
                 0,0,0,0,6,0,0,0,0,4,0};
main()
{
 DGM pp;
  int i, mm, say = 1, yolsay= 0, sd, bd;
  printf("\n Hangi dugumden...?  ");
  scanf("%d",&bd); bd = bd - 1;
  
  printf("\n Hangi dugume...?  ");
  scanf("%d",&sd);
  sd = sd - 1;

  yolmat();
  
  if( YOL[bd][sd] == 0 )
  {
     printf("\n Dugumler arasinda yol yok");
     
     return 0;
  }

 DUG[bd].uzaklik = 0;
 DUG[bd].on_dug = -1;
 mm = bd;

 for( i = 0; i < DS; i++ )
  if( i != bd )
    {
       DUG[i].statu = 0;
       DUG[i].uzaklik = sonsuz;
       DUG[i].on_dug = 0;
  }
do{
       say++;
       DUG[mm].statu = 1;

      for( i = 0; i < DS; i++ )

        if( AGR[mm][i] != 0 && DUG[i].statu != 1)
        if( DUG[mm].uzaklik + AGR[mm][i] < DUG[i].uzaklik )
         {
          DUG[i].uzaklik = DUG[mm].uzaklik + AGR[mm][i];
          DUG[i].on_dug = mm;
         }
       mm = minbul();
  }while( say < DS );

   pp.on_dug = sd;
   yol[ yolsay ] = sd;

   while( pp.on_dug != bd )
   {
        pp = DUG[pp.on_dug];
        yol[++yolsay] = pp.on_dug;
   }
   printf("\n\n ARANAN YOL: ");

   for( i = yolsay; i > 0; i-- )
     printf(" %d ->",yol[i] + 1);
     printf(" %d",yol[0] + 1);
	 printf("\n\n TOPLAM UZUNLUK= %d",DUG[sd].uzaklik);

 }
////////////////////
int minbul()
{
   int k, i, enk = sonsuz;
  for( i = 0; i < DS; i++ )
  {
    if(DUG[i].statu != 1 && enk > DUG[i].uzaklik)
    {
       enk = DUG[i].uzaklik; 
       k = i;
    }
}
return(k);
}
//////////////////////////
void yolmat()
{
     int GYOL[DS][DS];
     int i, j, k;
     for( i = 0; i < DS; i++ )
      for( j = 0; j < DS; j++ )
           GYOL[i][j] = AGR[i][j];
  
    for( k = 0; k < DS; k++)
     {
  	   for( i = 0; i < DS; i++)
	     for(j = 0; j < DS; j++)
            YOL[i][j] = GYOL[i][j]||( GYOL[i][k] && GYOL[k][j] );
    
       for( i = 0; i < DS; i++ )
        for( j = 0; j < DS; j++ )
         GYOL[i][j] = YOL[i][j];
    }
 }
