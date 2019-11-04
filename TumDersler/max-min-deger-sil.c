//This program creats a linked list ,
//finds max and min values in the list and
//delets the nodes that contain the max and min values.
#include <stdio.h>
#include<conio.h>
typedef struct list{
        int value;
        struct list *next;
        }LST;

int main()
{ 
  LST*start, *ptr;
  LST* create_list();
  void print_list (LST*);
  LST*delet( LST*, int);
  int max, min;
  
  start = create_list();
  print_list( start ); 
  ptr = start;
  
  max = min = ptr -> value;
  ptr = ptr->next;
  while( ptr!=NULL)
  {
    if( ptr -> value > max)
      max = ptr->value;
             
    if( ptr -> value < min)
      min = ptr -> value;
  
    ptr = ptr->next;
  }
  printf("\n max = %d    min = %d", max, min);
  start = delet( start, max );
  start = delet( start, min );
  
  print_list(start);
  getch();
}
////////////////////////////////////
LST* create_list()
{
   LST* start, *ptr;
   int n, i = 1;
   start = ptr =(LST*)malloc(sizeof(LST));
  
   printf("\n Number of nodes...?" );
   scanf("%d",&n);
  
   while( i < n)        
    {
     printf("\n Enter an integer...");
     scanf("%d", &(ptr->value));
     
     ptr = ptr-> next =(LST*)malloc(sizeof(LST));
     i++;
    }  
     printf("\n Enter an integer...");
     scanf("%d", &(ptr->value));
     ptr -> next = NULL;       
     return(start);
    
} 
////////////////////////////
void print_list(LST *ptr)
 {  
      printf("\n");
      while( ptr != NULL )
      {
        printf(" %d ",ptr -> value);
        ptr = ptr -> next;
      }
     
}       
////////////////////       
 LST* delet( LST*start,int x)
{
   LST*ptr = start, *ptr1,*temp;
   while( ptr!=NULL && ptr->value != x)
   {  
      ptr1 = ptr;
      ptr = ptr->next;
   }   
   
    if( ptr==start)
     {
       temp = start;
       start = start -> next;
       free( temp);
       return(start);
     }                          
     ptr1 -> next = ptr -> next;
     free( ptr );
     return(start);
}    
         
    
