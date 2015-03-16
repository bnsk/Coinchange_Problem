/*Exhaustive Back-tracking coin_change problem without pruning*/

#include<stdio.h>

#define INT_MAX 1000

int fewestCoins(int change, int coinTypes[], int numberOfCoinTypes)
{
  int coin, minNumberOfCoins, numberOfCoins;
 
  minNumberOfCoins = INT_MAX;
  for (coin = 0; coin < numberOfCoinTypes; coin++)
  {
   if (change == coinTypes[coin]) 
   {
    return 1;
   } 
   else if (change > coinTypes[coin])  
   {
    numberOfCoins = fewestCoins(change-coinTypes[coin], coinTypes,numberOfCoinTypes);
    if (numberOfCoins < minNumberOfCoins) 
    {
     minNumberOfCoins = numberOfCoins;
    } // end if (numberOfCoins...
   } // end if (change...
  } // end for (coin...
return minNumberOfCoins + 1;
} // end FewestCoins


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
             
          int result=fewestCoins(amount,denominations,4);
          
        printf("The minimum number of coins required to get the given amount is %d",result);
         }
     }
     else
       printf("\nSorry u have entered wrong input...\n");
 
       printf("\nPlease enter a integer amount between 0-10000 or -1 to exit: \n");
       scanf(" %d",&amount); 
       

    } 


}




