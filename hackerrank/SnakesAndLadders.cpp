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
int ans=INT_MAX;

void dfs(int a,vi G[1000],int l)
{
	if(a>100) return;
//	if(v[a]) return;
	//v[a]=1;
	cout<<a<<endl;
	l++;
	if(a==100)
	for(int i=0;i<G[a].size();i++)
	{
		dfs(G[a][i],G,l);
	}
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ans=INT_MAX;
		int n;
		vi G[1000];
		cin>>n;
		int x,y;
		for(int i=0;i<n;i++)
		{
			
			cin>>x>>y;
			for(int j=max(x-6,1);j<=x;j++)
			{
				G[j].pb(y);
			}
		}
		int m;
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			for(int j=max(x-6,0);j<=x;j++)
			{
				G[j].pb(y);
			}
		}
		for(int i=1;i<=100;i++)
		{
			for(int j=i+1;j<=min(i+6,100);j++)
			{
				G[i].pb(j);
			}
		}
		int v[1000]={0};
		dfs(1,G,0);
		cout<<ans<<endl;
	}
	return 0;
}

