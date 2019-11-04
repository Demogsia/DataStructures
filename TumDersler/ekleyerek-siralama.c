
/* Verilen dizi siraniyor */
#include<stdio.h>
#include<conio.h>
#include<math.h>
main(){
        
        void yaz( int[], int );
        void sirala ( int [], int);
       
        int n, i;
       
        printf("\n dizinin eleman sayisi..? ");
        scanf( "%d", &n );
        
        int a[n];
        for( i = 0; i < n; i++ )
        {
        
            printf("\n a[%d]=?",i+1);
            scanf("%d", &a[i]);
        }       
       i=sizeof(a)/sizeof(int);
        printf("\n %d %d",*a,i);       
           
		   sirala( a, n);
           yaz( a, n );
           
}
 /**********************************/      
     void sirala( int a[], int n )
     {
          int gec, k, i;
                    
          for( i = 1; i < n; i++ )
          {
        
             k = i;
   
            while( a[k] < a[k - 1]&& k!=0 )
            {  
                 gec = a[k - 1];
                 a[k - 1] = a[k]; 
                 a[k] = gec; 
                 k--;
            } 
          }   
       

       }
/****************************************/
   void yaz(int a[],int n)
   { int i;  
         printf( "\n siralanmis dizi : " );
         for( i = 0; i < n; i++ )
           printf ( "%d ", a[i] );
          
   }
     
