//this program deletes a node from given list
#include<stdio.h>
typedef struct list{
        int info;
        struct list *next;
        }LST;

int main()
{
    LST* start;
    LST*create_list();
    LST*delete( LST*, int);
    int x;// x to be deleted 
    void print_list(LST*);

    start = create_list();
    printf("\n Before deletion: "); 
    print_list(start); 
    
    printf("\n\n Enter x..");
    scanf("%d", &x);
    
    start = delete( start, x);
    printf("\n");
    
    printf("\n After deletion: ");
    print_list(start);
    
    getch();


}
//////////////////
LST* create_list(void)
{
   LST*start, *ptr;
   int n,i;//n number of nodes
   
   printf("\n enter number of nodes...");
   scanf("%d",&n);
   
   start = ptr = ( LST* )malloc( sizeof(LST) );
   
   for( i = 1; i <= n; i++ )
    {
      printf("\n enter a integer...");
      scanf("%d",&(ptr->info));
      
      if( i<n)
      ptr = ptr -> next = (LST*)malloc(sizeof(LST));
      
      else
      ptr->next=NULL;
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
/////////////////////////
LST*delete( LST*start, int x)
{
    LST*ptr = start, *ptr1;
    
    if( ptr == NULL)
    {
     printf("\n LIST DOES NOT EXIST");
     return(NULL);
     }
     
    while( ptr != NULL && x != ptr -> info )
    {
       ptr1 = ptr;
       ptr = ptr -> next;
     }
     if(ptr==NULL)
      {
        printf("\n x does not exit in list");
        return(start);
      } 
      
      if(ptr==start)
      {
        start = ptr->next;
        free(ptr);
        return(start);
       
        }
       
       ptr1->next = ptr->next;
       free(ptr);
       return(start);
       }                                
                                                   
