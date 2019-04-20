#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int Twt,Ttt,A[20],Wt[20],n,Bu[20];
float Att,Awt;
char pname[20][20];
void Getdata();
void Sjf();
void Getdata()
{
    int i;
    printf("\n Enter the number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n\n Enter the process name:");
        scanf("%s",&pname[i]);
        printf("\n Enter The BurstTime for Process %s = ",pname[i]);
        scanf("%d",&Bu[i]);
        printf("\n Enter the Arrival Time for Process %s = ",pname[i]);
        scanf("%d",&A[i]);
    }
}
void Sjf()
{
    int w,t,i,B[10],Tt=0,temp,j;
    char S[10],c[20][20];
    int temp1,min,start;
    system("CLS");
    printf("\n      \t||SHORTEST JOB FIRST SCHEDULING|| \n");
    Twt=Ttt=0;
    w=0;
    for(i=0;i<n;i++)
    {
        B[i]=Bu[i];
        S[i]='T';
        Tt=Tt+B[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(B[j]>B[j+1])
            {
                temp=B[j];
                temp1=A[j];
                B[j]=B[j+1];
                A[j]=A[j+1];
                B[j+1]=temp;
                A[j+1]=temp1;
                strcpy(c[j],pname[j]);
                strcpy(pname[j],pname[j+1]);
                strcpy(pname[j+1],c[j]);
            }
        }
    }
    min=A[0];
    for(i=1;i<=n;i++)
    {
    	if(A[i]<min)
    	  {
    	  	min=A[i];
    	  	start=i;
		  }
	}
    Wt[start]=0;
    w=w+B[start];
    t=w;
    S[start]='F';
    while(w<Tt)
    {
        i=0;
        while(i<=n)
        {
            if(S[i]=='T'&&A[i]<=t)
            {
                Wt[i]=w;
                S[i]='F';
                w=w+B[i];
                t=w;
                i=0;
            }
            else
                i++;
        }
    }
        printf("\n  Process  ArrivalTime  BurstTime  TurnAroundTime  WaitingTime\n");
        for(i=0;i<n;i++)
        {   
         printf("     %s \t\t%d  \t  %d  \t\t%d  \t\t%d\n",pname[i],A[i],Bu[i],((Wt[i]-A[i])+B[i]),(Wt[i]-A[i]));
         Twt=Twt+(Wt[i]-A[i]);
         Ttt=Ttt+((Wt[i]-A[i])+B[i]);
        }
         Att=(float)Ttt/n;
         Awt=(float)Twt/n;
         printf("\n\n  Average Turn Around Time=%3.2f ms ",Att);
         printf("\n\n  Average Waiting Time=%3.2f ms",Awt);
}
int main()
{
    Getdata();
    Sjf();
}

