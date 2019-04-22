#include<stdio.h> 
#include<conio.h>

void time(int num,int remt[10],int curt,int art[10], int bst[10]);

main() 
{
	
    int prno,,num,curt,rempr,ind,timespan,art[10],bst[10],remt[10];
	ind = 0;
	printf("Enter number of processes "); 
	scanf("%d",&num);
	rempr = num;
	
	printf("\nEnter the arrival time and burst time of the processes\n");
	for(prno = 0;prno < no;prno++) 
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
	return 0;
}
