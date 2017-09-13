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

vector< vll >A(100023);
vll v(100023);
ll moves=0;
ll l[100002]={0},r[100003]={0};
ll dfs(ll a, ll prev)
{
	ll lt=0,rt=0;
	for(int i=0;i<A[a].size();i++)
	{
		if(A[a][i]!=prev)
		{
			dfs(A[a][i],a);
			lt=max(lt,l[A[a][i]]);
			rt=max(rt,r[A[a][i]]);
		}
	}
	v[a]=v[a]+rt-lt;
	if(v[a]>0)
		lt += v[a];
	else
		rt -= v[a];
	l[a]=lt;
	r[a]=rt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	ll a,b;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		A[a].pb(b);
		A[b].pb(a);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	dfs(1,-1);
	cout<<l[1]+r[1]<<endl;
	return 0;
}

