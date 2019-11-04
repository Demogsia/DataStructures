#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#define MAX 30
// This program evaluate a postfix expression
// by using stack in array representation
//Example:  The result of  "5,3,+,2,/,3,2,^,*,4,-" is 32 
char postfix[MAX];
    int *STACK[ MAX ];
    int top = -1;

    void push( int );
    int pop ( );
main()
 {
    int ato ( char );
    int power( int, int );
    int j, i = 0,t1, t2, bas = 0;
    char is; float a,b,c;
    
    printf("\n Enter postfix expression..  ");
    scanf("%s", &postfix );
   
    printf("\n\n ");
    while ( postfix [i]!= '\0' )
      {
          printf(" %c", postfix[i]);
          i++;
       }
  
      for( j = 0; j < i; j++ )
      {
          is = postfix[j];
       switch( is )
         {
	      case '+':
                push( pop() + pop() );
            
            break;
	     
         case '-': 
                t1 = pop();
                t2 = pop();
                push( t2 - t1 );
         
           break;
	     
         case '*': 
                push( pop() * pop() );
         
           break;
          
           case '/':  
                t1 = pop();
                t2 = pop();
                push( t2 / t1 );
                     
           break;
         
           case '^': 
                t1 = pop();
                t2 = pop();
                push( power ( t2, t1 ));                    
           break;
         
           case',': bas = 0;
                 continue;
           break;
         
           default:
                 
                 if( bas == 0)
                  {
                      push(ato(is)); 
                      bas++;
                  }
                 else
                  push ( pop()*10 + ato(is));
                   
          break;  
       }                                    
  
    }
   printf("\n\n  result = %d", *STACK[0]);
   
   
   getch();
}
/////////////////////////////
 

void push ( int p )
   {   
          
          int *ptr;       
              
        
          ptr = ( int * ) malloc ( sizeof ( int ) );
          
          *ptr = p;       
          STACK[ ++top ] = ptr;
             
    }
/****************************************/
int pop ( )
   {    int x;
        x = *STACK[top]; 
              
        free ( STACK [ top -- ] );
        return(x); 
     }
///////////////////////////// 
int ato(char ch)
{ 
    if( ch == '0' ) return 0;
    if( ch == '1' ) return 1;
    if( ch == '2' ) return 2;
    if( ch == '3' ) return 3;
    if( ch == '4' ) return 4;
    if( ch == '5' ) return 5;
    if( ch == '6' ) return 6;
    if( ch == '7' ) return 7;
    if( ch == '8' ) return 8;
    if( ch == '9' ) return 9;
}   
/////////////////////////
int power( int a, int b)
{
    int carp = 1;
    while( b--)
     carp = carp*a;
    return( carp);
}     
