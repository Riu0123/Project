#include<stdio.h>
#include<conio.h>
int main()
{
 int BurstTime[10],ProcessNo[10],WaitTime[10],TurnAroundTime[10];
 int ArrivalTime[10],Prior[10],i,j,NumberofProcess,total=0,flag,temp,AvgWaitTime,AvgTurnAroundTime;
  printf("Enter the Number of Process you want to calculate:");
  scanf("%d",&NumberofProcess);
  printf("\n Enter Burst Time and Prior\n");
  for(i=0;i<NumberofProcess;i++)
    {
        printf("\n P[%d]\n",(i+1));
        printf("Enter Burst Time:");
        scanf("%d",&BurstTime[i]);
        printf("Enter Arrival Time:");
        scanf("%d",&ArrivalTime[i]);
        printf("Enter Prior:");
        scanf("%d",&Prior[i]);
        ProcessNo[i]=i+1;
    }
  for(i=0;i<NumberofProcess;i++)
    {
        flag=i;
        for(j=i+1;j<NumberofProcess;j++)
        {
            if(Prior[j]<Prior[flag])
            flag=j;
        }
        temp=Prior[i];
        Prior[i]=Prior[flag];
        Prior[flag]=temp;
        temp=BurstTime[i];
        BurstTime[i]=BurstTime[flag];
        BurstTime[flag]=temp;
        temp=ProcessNo[i];
        ProcessNo[i]=ProcessNo[flag];
        ProcessNo[flag]=temp;
    }
 WaitTime[0]=0;
 for(i=1;i<NumberofProcess;i++)
 {
  WaitTime[i]=0;
  for(j=0;j<i;j++)
  WaitTime[i]+=BurstTime[j];
  total+=WaitTime[i];
 }
 
  
 
