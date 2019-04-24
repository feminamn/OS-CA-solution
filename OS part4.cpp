#include<stdio.h> 
#include<conio.h>

void time(int num,int remt[10],int curt,int art[10], int bst[10]);




void time(int num,int remt[10],int curt,int art[10], int bst[10])
{
	
	float avgwait,avgtat;
    int i,j,n=num,temp,btime[20],prno[20],wtime[20],tatt[20],total=0,loc;
    
    printf("Third round with least burst time.\n");
    
    for(i=0;i<n;i++)
    {
        btime[i]=remt[i];
        wtime[i]=curt-art[i]-btime[i];
		prno[i]=i+1;
    }
	
 for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(btime[j]<btime[loc]){
            	loc=j;
            }
        }
        temp=btime[i];
        btime[i]=btime[loc];
        btime[loc]=temp;
        temp=prno[i];
        prno[i]=prno[loc];
        prno[loc]=temp;
    }
	
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++){
        	wtime[i]+=btime[j];
        }
        total+=wtime[i];
    }


 
    avgwait=(float)total/n;
    total=0;
    printf("\nProcess\t\tBurst time\t\tWaiting time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tatt[i]=btime[i]+wtime[i];
        total=total + tatt[i];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",prno[i],btime[i],wtime[i],tatt[i]);
    }

    avgtat=(float)total/n;
    printf("\n\nAverage waiting time = %f",avgwait);
    printf("\n Average turnaround time = %f\n",avgtat);
	
}


main() 
{
	
    int prno,j,num,curt,rempr,ind,timespan,wait,tat,art[10],bst[10],remt[10],x=1;
	ind = 0;
	wait = 0;
	tat = 0;
	printf("Enter number of processes "); 
	scanf("%d",&num);
	rempr = num;
	
	printf("\nEnter the arrival time and burst time of the processes\n");
	for(prno = 0;prno < num;prno++) 
	{
		printf("\nProcess P%d\n",prno+1);
		printf("Arrival time = "); 
		scanf("%d",&art[prno]);
		printf("Burst time = "); 
		scanf("%d",&bst[prno]); 
		remt[prno]=bst[prno]; 
	} 
	printf("The timespan are as follows:\n");
	printf("The timespan interruption at first is 3\n"); 
	timespan=3;
    curt=0;

	for(prno=0;rempr!=0;) 
	{

		if(remt[prno]<=timespan && remt[prno]>0)
		{ 
			curt+=remt[prno]; 
			remt[prno]=0; 
			ind=1; 
		} 
		else if(remt[prno]>0)
		{ 
			remt[prno]-=timespan; 
			curt+=timespan; 
		} 
		if(remt[prno]==0 && ind==1)			
		{ printf("%d",prno);
			rempr--;				
			printf("P %d",prno+1); 
			printf("\t\t\t%d",curt-art[prno]);
			printf("\t\t\t%d\n",curt-bst[prno]-art[prno]);
			wait+=curt-art[prno]-bst[prno]; 
			tat+=curt-art[prno]; 
			ind=0; 
                       
		} 
		if(prno==num-1){
			x++;
			if(x==2){
				prno=0;
				timespan=6;
				
				printf("The time span interruption in second is 6\n");
			}
			else{
				break;
			}
		}
		else if(curt >= art[prno+1]){
			prno++;
		}
		else{
			prno=0;
		}
	}
	
	time(num,remt,curt,art,bst);
	
	return 0;
}

