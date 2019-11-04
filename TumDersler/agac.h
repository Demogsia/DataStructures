typedef struct agac{
        int deger;
        struct agac *sol;
        struct agac *sag;
        }AGAC;

AGAC* ekle( AGAC *KOK, int x)
{
   AGAC* ptr1, *ptr;
   
   if( KOK == NULL)
    {
      KOK = (AGAC*)malloc(sizeof(AGAC));
      KOK->deger = x;
      KOK->sol=KOK->sag=NULL;
      return(KOK);
    }           
    
    ptr = KOK;
    
    while( ptr!=NULL)
    {
      if(ptr->deger==x)
       {
          printf("\n %d AGACTA VAR.", x);
          return(KOK);
       }
       if( x < ptr->deger)
       
       {
         ptr1 = ptr;
         ptr = ptr->sol;
        }
       else
        {
          ptr1=ptr;
          ptr = ptr->sag;
         }
         
      }           
     if( x < ptr1->deger)
     {
      ptr = ptr1->sol = (AGAC*)malloc(sizeof(AGAC));
      ptr->deger = x;
      ptr->sol = ptr->sag = NULL;
      return(KOK);
      }
      
      ptr = ptr1->sag = (AGAC*)malloc(sizeof(AGAC));
      ptr->deger = x;
      ptr -> sol = ptr -> sag = NULL;
      return(KOK);
}                  
/////////////////////////////
void inorder( AGAC*ptr)
{
   if( ptr!=NULL)
   {
     inorder( ptr->sol);
     printf(" %d", ptr->deger);
     inorder( ptr->sag);
   }  
}                              
/////////////////////////
void preorder( AGAC*ptr)
{
   if( ptr!=NULL)
   {
     
     printf(" %d", ptr->deger);
     preorder(ptr->sol);
     preorder( ptr->sag);
   }  
}                              
////////////////////////
void postorder( AGAC*ptr)
{
   if( ptr!=NULL)
   {
     postorder( ptr->sol);
     postorder( ptr->sag);
     printf(" %d", ptr->deger);
   }  
}
                          
