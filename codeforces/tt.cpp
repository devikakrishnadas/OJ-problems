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
vi mi(100023,0);
vll sum(100023,0);
//vll leaf;
//ll lcm=1;
ll m=INT_MAX;
ll fans=0;
void dfs(ll a, vi G[100023],ll par, vll arr)
{
	if(G[a].size()==1)
	{
		if(arr[a]!=0)
		sum[a]=arr[a];
		mi[a]=1;
	//	lcm=(lcm*mi[a])/(__gcd(lcm,mi[a]));
		return ;
	}
	ll si=G[a].size();
	if(a!=0) si--;
	ll mini=INT_MAX;
	int lcm=1;
	
	for(int i=0;i<G[a].size();i++)
	{
		if(G[a][i]!=par)
		{
			dfs(G[a][i],G,a,arr);
			sum[a]=sum[a]+sum[G[a][i]];
			if(mi[G[a][i]])
				lcm=(lcm*mi[G[a][i]])/(__gcd(lcm,mi[G[a][i]]));
			mini=min(mini,sum[G[a][i]]);
		}
	}
	mi[a]=lcm*si;
	//cout<<mi[a]<<"*"<<si<<endl;
	ll t=mi[a]/si;
	ll ans=(mini/t)*t;
	fans=fans+sum[a]-(si*ans);
	sum[a]=si*ans;
}

int main()
{
	mi[0]=1;
	vll arr;
//	int n;
	ll x,y;
	vi A[100023];
	cin>>n;
	//int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		arr.pb(x);
	//	sum+=x;
	}
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		x--; y--;
		A[x].pb(y);
		A[y].pb(x);
	}
	dfs(0,A,-1,arr);
	
//	for(int i=0;i<n;i++)
//	{
//		cout<<mi[i]<<" ";
//	}
//	cout<<endl;
	//sort(mi.begin(),mi.begin()+n);
	//reverse(mi.begin(),mi.begin()+n);
	
