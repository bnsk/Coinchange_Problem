/*Greedy coin-change problem*/ 

#include<stdio.h>


int main(int argc,char *argv[])
{
 int amount,i,j;
 int denominations[]={10,5,2,1};
 int count[4];

 

 printf("\nPlease enter a integer amount between 0-10000 or -1 to exit: \n");
 scanf(" %d",&amount);
while(amount!=-1)
{
 for(j=0;j<4;j++) //Initializing the number of coins required for the given amount in each denomination to 0.
  count[j]=0;

 if(amount>=0 && amount<=10000)
 {
   for(i=0;i<4;i++)  //number of denominations available.
   {
    while(amount>=denominations[i])
    { 
     amount=amount-denominations[i];
     count[i]+=1;
    }
     printf("%d number of %d denomination coins used\n",count[i],denominations[i]);
 
   }
 }
 else
  printf("\nSorry u have entered wrong input...\n");
 
 printf("\nPlease enter a integer amount between 0-10000 or -1 to exit: \n");
 scanf(" %d",&amount);
 
}
 return;
} 
