#include<stdio.h>
#include<iostream>
using namespace std;
int array[1005];
int n,m;
void init(int n)
{
	for(int i=1;i<=n;i++) array[i]=i;
}
void find(int n,int m)
{
	int c,c1,j;
	for(int i=1;i<=m-1;i++)
	{
		for(j=n-1;j>0;j--)
		{
			if(array[j]<array[j+1])
			{
				c=j;
				break;
			}
		}
		for(j=c+1;j<=n;j++)
		{
			if(array[j]>array[c])
			{
				
				c1=j;
			}
			else
			{
				break;
			}
		}
		int temp=array[c];
		array[c]=array[c1];
		array[c1]=temp;
		
		for(j=c+1;j<=(c+1+n)/2;j++)
		{
			int p=n-(j-(c+1));
			temp=array[p];
			array[p]=array[j];
			array[j]=temp;
		}
	}
	for(j=1;j<=n;j++)
	{
		if(j!=n) cout<<array[j]<<" ";
		else cout<<array[j];
	}
	cout<<endl;
}
int main()
{
	while(cin>>n>>m)
	{
		init(n);
		find(n,m);
	}
	return 0;
}