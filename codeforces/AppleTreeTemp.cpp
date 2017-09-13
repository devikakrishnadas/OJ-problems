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
ll n;
vll mi(100023,0);
vll sum(100023,0);
ll fans=0;
void dfs(ll a, vector< vll >G,ll par, vll arr)
{
	if(G[a].size()==1 && a!=0)
	{
		if(arr[a]!=0)
		sum[a]=arr[a];
		
		mi[a]=1;
		
		return ;
	}
	ll si=G[a].size();
	if(a!=0) si--;
	ll mini=INT_MAX;
	ll lcm=1;
	
	for(ll i=0;i<G[a].size();i++)
	{
		if(G[a][i]!=par)
		{
			dfs(G[a][i],G,a,arr);
			sum[a]=sum[a]+sum[G[a][i]];
			if(mi[G[a][i]])
			{
				ll t=__gcd(lcm,mi[G[a][i]]);
				lcm=(lcm*mi[G[a][i]])/t;
			}
			mini=min(mini,sum[G[a][i]]);
		}
	}
	mi[a]=lcm*si;
	ll t=mi[a]/si;
	ll ans=(mini/t)*t;
	fans=fans+sum[a]-(si*ans);
	sum[a]=si*ans;

}

int main()
{
	mi[0]=1;
	vll arr;
	ll x,y;
	//cin>>n;
	sf("%I64d",&n);
	vector< vll >A(n);
	for(ll i=0;i<n;i++)
	{
		//cin>>x;
		sf("%I64d",&x);
		arr.pb(x);
	}
	for(ll i=0;i<n-1;i++)
	{
		//cin>>x>>y;
		sf("%I64d%I64d",&x,&y);
		x--; y--;
		A[x].pb(y);
		A[y].pb(x);
	}
	dfs(0,A,-1,arr);
	//cout<< fans <<endl;
	pf("%I64d",fans);
	return 0;
}
