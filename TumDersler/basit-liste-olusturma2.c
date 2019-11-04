
/* basit bir baglý liste olusturuluyor */
#include<stdio.h>
#include<conio.h>

typedef struct matogr
     {   int no;
         char soyad[15];
         int anot;
         struct matogr *sonraki;
     }MTOG;
     
 main()
 { 
       void yaz( MTOG* );
       MTOG og1, og2, og3, *ilk;
  
       strcpy( og1.soyad, "caner" );
       strcpy( og2.soyad, "masal" );
       strcpy( og3.soyad, "dalaman" );
   
       og1.no = 123;
       og2.no = 456;
       og3.no = 987;
   
      og1.sonraki = &og2;
      og2.sonraki = &og3;
      og3.sonraki = NULL;
    
      ilk = &og1;
      yaz( ilk );
   
      getch();
}
/***************************/
  void yaz( MTOG*ptr )
  {
       while( ptr != NULL )
       {
          printf("\n %s  %d ",ptr -> soyad, ptr -> no );
          ptr = ptr -> sonraki;
       }
}     
   


