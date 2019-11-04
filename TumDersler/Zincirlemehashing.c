/**ZÝNCÝRLEME YÖNTEMÝ***/
#include<stdlib.h>
#include<stdio.h>

typedef struct fened{

    char ad_soy[12];
    int no;
    struct fened *sonraki;
    } FENED;

FENED *tablo[10];

int main()
 {
      int i, no, yanit;
      
      void yaz ( FENED*[]);
      void ekle(void);
 
      for( i = 0; i < 10; i++ )
           tablo[i] = NULL;
     
      do{
          ekle();
          yaz( tablo);
		  printf("\n 1-------DEVAM 0-------SON ");
          scanf("%d", &yanit);
       
        }while( yanit );

          
}
/*******************/
void ekle(void)
  { 
      int i, ono;
      FENED *ptr;
     
      printf("\n ogrenci no....?");
      scanf("%d", &ono );
    
      i = ono%10;

      if( tablo[i] == NULL )
       {
         tablo[i] = ( FENED* )malloc( sizeof( FENED ) );
         tablo[i] -> no = ono;
       
         printf("\n ogrenci ad soyad..?");
         scanf("%s", &tablo[i]->ad_soy);
        
         tablo[i] -> sonraki = NULL;
      
         return;
      }
      
        ptr = tablo[i];
      
      while( ptr ->sonraki != NULL )
          ptr = ptr -> sonraki;
    
       ptr = ptr -> sonraki = ( FENED* )malloc( sizeof( FENED ) );
       ptr -> no = ono;
      
       printf("\n ogrenci ad soyad..?");
       scanf("%s", &ptr -> ad_soy );
       ptr -> sonraki = NULL;
     
      return;
 }
 //////////////////////
 void yaz( FENED* tablo[])
 {
 	FENED *ptr;
 	int i;
 	for( i = 0; i < 10; i++ )
       {
          printf ( "%d -> ", i);
          ptr = tablo[i];
         
         while( ptr != NULL )
         {
           printf(" %d  %s -->", ptr->no, ptr->ad_soy );
           ptr=ptr->sonraki;
         }
          printf("\n");
      }
}
