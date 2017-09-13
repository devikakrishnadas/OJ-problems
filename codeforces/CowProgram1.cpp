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

ll n;
vll a(200023,0);
ll G[200023][3]={0},visited[200023][3]={0};
ll dfs(ll x,ll vis[200023][3],ll l)
{
	//cout<<x<<endl;
	if(x>n || x<1)
	{
		return 0;
	}
	else if(x==1)
	{
		return -1;
	}
	if(l%2)
	{
		if(visited[x][1])
		{
			return visited[x][1];
		}
		else if(vis[x][1])
		{
			visited[x][1]=-1;
			return -1;
		}
		else
		{
			vis[x][1]=1;
			ll t=dfs(G[x][1],vis,l+1);
			if(t==-1)
				visited[x][1]=-1;
			else visited[x][1]=a[x]+t;
			return visited[x][1];
		}
	}
	else
	{
		if(visited[x][2])
		{
			return visited[x][2];
		}
		else if(vis[x][2])
		{
			visited[x][2]=-1;
			return -1;
		}
		else
		{
			vis[x][2]=1;
			ll t=dfs(G[x][2],vis,l+1);
			if(t==-1)
				visited[x][2]=-1;
			else
				visited[x][2]=a[x]+t;
			return visited[x][2];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	cin>>n;
	n=200000;
	for(int i=2;i<=n;i++)
	{
		//cin>>a[i];
		a[i]=rand()%i +1;
		G[i][1]=i-a[i];
		G[i][2]=i+a[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(!visited[i][1])
		{
			ll vis[200023][3]={0};
			dfs(i,vis,1);
		}
		else
			cout<<i<<" "<<visited[i][1]<<endl;
	}
	for(int i=1;i<n;i++)
	{
		if(visited[i+1][1]==-1)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<i+visited[i+1][1]<<endl;
		}
	}
	return 0;
}

