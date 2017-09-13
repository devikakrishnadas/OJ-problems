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
int n,m;
int A[1002][1002]={0};

int dist[1002][1002]={0};

void dfs(int i,int j,int d)
{
	if(i>=n || i<0 || j>=m || j<0)
		return ;
	if(d>dist[i][j])
		return;
	if(A[i][j]==-3)
		return;
	
	dist[i][j]=min(dist[i][j],d);
	dfs(i+1,j,d+1);
	dfs(i-1,j,d+1);
	dfs(i,j+1,d+1);
	dfs(i,j-1,d+1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	pair<int,int> s,e;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char x;
			cin>>x;
			if(x=='S')
			{
				A[i][j]=-1;
				s=mp(i,j);
			}
			else if(x=='E')
			{
				A[i][j]=-2;
				e=mp(i,j);
			}
			else if(x=='T')
				A[i][j]=-3;
			else 
				A[i][j]=x-'0';
			dist[i][j]=INT_MAX;
		}
	}
	/*
	ALGORITHM
	1. find the shortest path from S to every cell [j][k], call it dist[j][k]
	2. find the shortest path from every breeder cluster i to every other cell [j][k], call it A[i][j][k]
	3. if A[i][j][k] is less than dist[j][k], increment cnt[j][k] by the number of breeders in cluster i
	4. find the shortest path from source to sink in cnt[j][k], with the value cnt[j][k] as the weight.


	IMPROVISED ALGO
	1. find distance of every node from the exit
	2. if the distance of a breeder cluster is <= the distance of source from exit, then there will be a fight with them.
	3. viola !
	*/
	dfs(e.ff,e.ss,0);
	int dsource=dist[s.ff][s.ss];
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(A[i][j]>0)
			{
				if(dist[i][j]<=dist[s.ff][s.ss])
				{
					ans+=A[i][j];
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

