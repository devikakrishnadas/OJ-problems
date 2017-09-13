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
int A[123][123]={0};

int dist[123][123]={0};
int dist2[123][123]={0};
int cnt=0;
int sd=INT_MAX;
queue<pair<int,int> >q;

bool isValid(int i,int j)
{
	if(i>=n || j>=m || i<0 || j<0)
		return 0;
	if(A[i][j]==-3)
		return 0;
	return 1;
}
void bfs(int i,int j,int d)
{
	dist[i][j]=d;
	q.push(mp(i,j));
	while(!q.empty())
	{
		i=q.front().ff;
		j=q.front().ss;
		cout<<i<<" "<<j<<endl;
		if(isValid(i+1,j))
		{
			if(dist[i+1][j]>dist[i][j]+1)
			{
				dist[i+1][j]=dist[i][j]+1;
				q.push(mp(i+1,j));
			}
		}
		if(isValid(i-1,j))
		{
			if(dist[i-1][j]>dist[i][j]+1)
			{
				dist[i-1][j]=dist[i][j]+1;
				q.push(mp(i-1,j));
			}
		}
		if(isValid(i,j+1))
		{
			if(dist[i][j+1]>dist[i][j]+1)
			{
				dist[i][j+1]=dist[i][j]+1;
				q.push(mp(i,j+1));
			}
		}
		if(isValid(i,j-1))
		{
			if(dist[i][j-1]>dist[i][j]+1)
			{
				dist[i][j-1]=dist[i][j]+1;
				q.push(mp(i,j-1));
			}
		}
		q.pop();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cin>>n>>m;
	n=1000;
	m=1000;
	pair<int,int> s,e;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char x;
			//cin>>x;
			if(i==0 && j==0)
			    x='S';
			 else if(i==999 && j==999)
			    x='E';
			 else
			    x='9';
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
	*/
	//dist[e.ff][e.ss]=0;
	bfs(e.ff,e.ss,0);
	//cout<<"abc"<<endl;
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
				    //cout<<i<<" "<<j<<" "<<dist[i][j]<<endl;
					ans+=A[i][j];
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
