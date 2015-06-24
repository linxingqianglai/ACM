#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int dp[110][110],prt[110][110];
char gr[110][110];
int queue[110*110*20][2];
int n,m;
void bfs()
{
	//int count=0;
	//int flag=0;
	int tab[4][2]={0,1,0,-1,1,0,-1,0};
	int front=0,rear=1,parent;
	int time=0;
	dp[0][0]=0;
	queue[0][0]=0,queue[0][1]=0;
	while(front!=rear)
	{
		parent=front;
		int x=queue[front][0];
		int y=queue[front][1];
		front++;
		for(int i=0;i<4;i++)
		{
			int xx=x+tab[i][0];
			int yy=y+tab[i][1];
			if(xx<0||xx>=n) continue;
			if(yy<0||yy>=m) continue;
			if(gr[xx][yy]=='X') continue;
			time=dp[x][y]+1;
			if(gr[xx][yy]!='.') time+=(int)(gr[xx][yy]-'0');
			if(dp[xx][yy]!=-1&&dp[xx][yy]<=time)continue;
			//printf("time=%d\n",time);
			//printf("dp[%d][%d]=%d,dp[%d][%d]=%d",x,y,dp[x][y],xx,yy,dp[xx][yy]);
			//cout<<endl;
			
			//printf("(%d,%d)->(%d,%d)\n",x,y,xx,yy);
			dp[xx][yy]=time;
			prt[xx][yy]=parent;
			queue[rear][0]=xx;
			queue[rear][1]=yy;
			rear++;
		//	count++;
			//if(count>n*m)
		//	{
			//	flag=1;
			//	break;
		//	}
		}
	//	if(flag==1) break;
		
	}
}
int print(int x,int y)
{
	if(prt[x][y]==-1) return 0;
	int parent=prt[x][y];
	int xx=queue[parent][0];
	int yy=queue[parent][1];
	int t=print(xx,yy);
	
	printf("%ds:(%d,%d)->(%d,%d)\n",++t,xx,yy,x,y);
	if(gr[x][y]!='.')
	{
		int num=(int)(gr[x][y]-'0');
		for(int i=0;i<num;i++)
		{
			printf("%ds:FIGHT AT (%d,%d)\n",++t,x,y);
		}
	}
	return t;
	
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		//cout<<"n="<<n<<endl;
		//cout<<"m="<<m<<endl;
		for(int i=0;i<n;i++)
		{
			scanf("%s%*c",gr[i]);
		}
		memset(dp,-1,sizeof(dp));
		memset(prt,-1,sizeof(dp));
		memset(queue,-1,sizeof(queue));
		bfs();
		if (dp[n-1][m-1] == -1)
            puts ("God please help our poor hero.") ;
        else
        {
            printf ("It takes %d seconds to ""reach the target "
            "position, let me show you the way.\n", dp[n-1][m-1]) ;
            print(n-1, m-1) ;
        }
        puts ("FINISH") ;
	}

	return 0;
}