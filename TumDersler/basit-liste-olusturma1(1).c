      #include<stdio.h>
typedef struct list{
        int val;
        struct list *next;
        }LST;
int main()
{
    LST s1, s2, s3;
    LST *first;
    
    s1.next = &s2;
    s2.next = &s3;
    s3.next = NULL;
    first = &s1;
    
    s1.val = 123;
    s2.val = 765;
    s3.val = 654;
    
    while( first!=NULL)
     {
      printf(" %d ", first->val);
      first = first->next;
      }
      
       getch();
      }
