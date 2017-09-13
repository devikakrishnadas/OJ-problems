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

int main()
{
	int n,m;
	cin>>n>>m;
	vector< vi >G(n);
	for(int i=0;<n;i++)
	{
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	vi vis(n+1,0);
	dfs(g,1,vis);
	for(int i=0;i<n;i++)
	{
	}	
	return 0;
}
