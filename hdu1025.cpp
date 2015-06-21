#include<stdio.h>
#include<iostream>
using namespace std;
const int max=500005;
int road[max];
int stack[max];
int main()
{
//    cout<<"hhh"<<endl;
	
	int n;
	int i=0,low=1,up=1,mid,pos;
	int len=1;
	int cas=0;
	while(scanf("%d",&n)!=-1)
	{
		cas++;
		int temp1;
		int temp2;
		for(i=0;i<n;i++)
		{
			cin>>temp1;
			cin>>temp2;
			road[temp1]=temp2;
		}
		len=1;
		for(i=1;i<=n;i++)
		{
			stack[1]=road[1];
			low=1,up=len;
			while(low<=up)
			{
				mid=(low+up)/2;
				
				if(stack[mid]<road[i])low=mid+1;
				else up=mid-1;
			}

			stack[low]=road[i];
			//cout<<"stack["<<low<<"]="<<stack[mid]<<","<<"road["<<i<<"]="<<road[i]<<endl;
			if(low>len)len++;
			//cout<<"len="<<len<<endl;
		}
		printf("Case %d:\n",cas);  
        if(len==1)  printf("My king, at most 1 road can be built.");  
        else    printf("My king, at most %d roads can be built.",len);  
        printf("\n");  
        printf("\n");  

	}
	
	return 0;
}