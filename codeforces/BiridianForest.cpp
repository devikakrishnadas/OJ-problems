#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int C[1002][1002]={0};
int ans=INT_MAX;
int n,m;
int vis[1002][1002]={0};
int vis1[1002][1002]={0};
int vis2[1002][1002]={0};
void dfs(int A[1001][1001],int i,int j,int B[1001][1001],int dist,int opt)
{
	if(A[i][j]==-3)
	{
		return;
	}
	else if(i>=n || i<0 || j>=m || j<0)
	{
		return;
	}
	else
	{
		//cout<<i<<" "<<j<<" "<<opt<<endl;
		if(opt==1)
		{
			//cout<<i<<" "<<j<<" "<<dist<<endl;
			if(A[i][j]==0 && vis1[i][j])
				return;
			vis1[i][j]=1;
			//B[i][j]=min(B[i][j],dist);
			dist++;
			if(dist>=0)
			B[i][j]=min(B[i][j],dist);
		}
		else if(opt==2)
		{
			if(vis[i][j])
				return;
			vis[i][j]=1;
			if(dist<=B[i][j] && A[i][j]>=0)
			{
				C[i][j]+=A[i][j];
			}
			dist++;
		}
		else if(opt==3)
		{
			dist+=C[i][j];
			if(dist>ans)
				return;
			if(A[i][j]==0 && vis2[i][j])
				return;
			vis2[i][j]=1;
			if(A[i][j]==-1)
			{
				cout<<dist<<" "<<ans<<endl;
				if(dist) ans=min(ans,dist);
				return;
			}
		}
	}
		dfs(A,i+1,j,B,dist,opt);
		dfs(A,i-1,j,B,dist,opt);
		dfs(A,i,j+1,B,dist,opt);
		dfs(A,i,j-1,B,dist,opt);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	pair<int,int>exit,source;
	int A[1001][1001]={0},B[1001][1001]={0};
	char c;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>c;
			if(c=='E')
			{
				A[i][j]=-1;
				exit=mp(i,j);
			}
			else if(c=='S')
			{
				A[i][j]=-2;
				source=mp(i,j);
			}
			else if(c=='T')
			{
				A[i][j]=-3;
			}
			else
			{
				A[i][j]=c-'0';	
			}
			B[i][j]=INT_MAX;
		}
	}
	
	
	dfs(A,source.ff,source.ss,B,0,1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(A[i][j]>0)
			{
				dfs(A,i,j,B,0,2);
			}
		}
	}
	dfs(A,source.ff,source.ss,B,0,3);
	cout<<ans<<endl;
	return 0;
}

