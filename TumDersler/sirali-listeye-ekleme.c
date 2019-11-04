//This program inserts a new node in sorted linked list
#include<stdio.h>
typedef struct list{
        int info;
        struct list *next;
        }LST;

int main()
{
    LST* start;
    LST*create_list();
    void print_list( LST* );
    LST* insert_sorted_list( LST*, int);
    int x = 122;// x to be inserted
    
    start = create_list();
    
    printf("\n Before insertion: "); 
    print_list( start );
    
    printf("\n\n Enter x..");
    scanf( "%d", &x );
    
    start= insert_sorted_list( start, x );  
    printf("\n");
    printf("\n After insertion: ");
    print_list( start );
    getch();


}
//////////////////
LST* create_list(void)
{
   LST*start, *ptr;
   int n, i;//n number of nodes
   
   printf("\n enter number of nodes...");
   scanf( "%d", &n );
   
   start = ptr = ( LST* )malloc( sizeof(LST) );
   
   for( i = 1; i <= n; i++ )
    {
      printf("\n enter a integer...");
      scanf("%d",&( ptr -> info ));
      
      if( i < n)
        ptr = ptr -> next = ( LST* )malloc( sizeof( LST ) );
      
      else
      ptr -> next = NULL;
    }
     return(start);
}    
//////////////////////
void print_list ( LST*start)
{
     LST*ptr = start;
     
     while(ptr!=NULL)
     {
       printf(" %d ", ptr->info);
       ptr = ptr -> next;
       }
}                                    
/////////////////////////////
LST* insert_sorted_list( LST* start, int x)
{
   LST*ptr = start, *ptr1, *temp;
   if( ptr == NULL)
    {
      printf("\n NO LIST");
      return(NULL);
     }
     
    while( ptr!=NULL&& x > ptr->info)
    {
       ptr1 = ptr;
       ptr = ptr->next;
    }          
    if( ptr == NULL)//insertion at end of list
    {
      ptr = ptr1->next = (LST*)malloc(sizeof(LST));
      ptr->info =x;
      ptr->next = NULL;
      return(start);
     }
      if( x == ptr->info)
      {
        printf("\n x exists in list");
        return(start);
       }       
      if( ptr == start)
       {
          ptr = (LST*)malloc(sizeof(LST));              
          ptr->info =x;
          ptr->next=start;
          return(ptr);
        }
        temp=ptr1->next;
        ptr = ptr1->next = (LST*)malloc(sizeof(LST));
        
                ptr->info=x; 
                ptr->next =temp;
                return(start);
 }              
