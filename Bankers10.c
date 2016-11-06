#include<stdio.h>
void main()
{
	int cl[10][10],al[10][10],av[10],i,j,k,m,n,ne[10][10],flag=0;
	
	printf("\nEnter the claim matrix:");	//max requirenment of resources
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cl[i][j]);
		}
	}
	//******allocation matrix********//
	printf("\nEnter allocated matrix:");	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&al[i][j]);
		}
	}
	//********Need matrix*********//
	printf("\nThe need matrix:\n");		//remaining possible need of each process
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			ne[i][j]=cl[i][j]-al[i][j];
			printf("\t%d",ne[i][j]);
		}
		printf("\n");
	}
	//*********Available matrix*******//
	printf("\nEnter avaliable matrix");		//available resources
	for(i=0;i<n;i++)
		scanf("%d",&av[i]);

	//********Printing part starts******//
	printf("Claim matrix:\n");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++)
		{
			printf("\t%d",cl[i][j]);
		}
		printf("\n");
	}
	printf("\n Allocated matrix:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\t%d",al[i][j]);
		}
		printf("\n");
	}
	printf("Available matrix:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",av[i]);
	}

	//******Check for flags*******//
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(av[j]>=ne[i][j])	//pay attention av -> j
				flag=1;
			else
				flag=0;
		}
	}
	if(flag==0)
		printf("Unsafe State");
	else
		printf("Safe State");
}
