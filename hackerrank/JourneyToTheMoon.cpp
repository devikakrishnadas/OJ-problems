#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;

vi G[100001];
int n,m;
int v[100023]={0};

void dfs(int x,int l)
{
	if(v[x]) return;
	v[x]=l;
	for(int i=0;i<G[x].size();i++)
	{
		dfs(G[x][i],l);
	}
}
int main()
{
	cin>>n>>m;
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		G[x].pb(y);
		G[y].pb(x);	
	}
	int l=1;
	for(int i=0;i<n;i++)
	{
		if(!v[i]) 
		{
			
			dfs(i,l);
			l++;
		}
	}
	int A[100023]={0};
	for(int i=0;i<n;i++)
	{
		A[v[i]]++;
	}
	ll sum=0;
	for(int i=0;i<l;i++)
	{
		sum+=A[i];
		
	}
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		sum=sum-A[i];
		ans=ans+sum*A[i];
	}
	cout<<ans<<endl;
	return 0;
}

