/*Dynamic coin-change problem*/

#include<stdio.h>
#include<string.h>

#define NUMDENOS 4




int count(int denominations[],int amount)
{
   int i, j,temp;
   int table[amount+1];  //holds the minimum number of coins required to hold the amounts
   
 
   // Initialize all table values,given the first denomination 1
    for(i=0;i<=amount;i++)
    {
      table[i]=i;
      
    } 
    
    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for(i=1; i<NUMDENOS; i++)
    {
     for(j=1; j<=amount; j++)
     {
      
       if(j>=denominations[i])
       {
         temp=table[j];
          if(temp<1+table[j-denominations[i]])
             table[j]=temp;
          else
             table[j]=1+table[j-denominations[i]];
       }
 
     }
    } 
    return table[amount];
}

int main(int argc,char *argv[])
{
  
  int denominations[]={1,2,5,10};
  int amount; 
  
   printf("\nPlease enter a integer amount between 0-10000 or -1 to exit: \n");
   scanf(" %d",&amount);
    
   while(amount!=-1)
   {
     if(amount>=0 && amount<=10000)
     {  
       if(amount==0)
        printf("\nThe minimum number of coins needed is 0...\n");
       else{
             
          int result=count(denominations,amount);
          
        printf("The minimum number of coins required to get the given amount is %d",result);
         }
     }
     else
       printf("\nSorry u have entered wrong input...\n");
 
       printf("\nPlease enter a integer amount between 0-10000 or -1 to exit: \n");
       scanf(" %d",&amount); 
       

    } 


}




