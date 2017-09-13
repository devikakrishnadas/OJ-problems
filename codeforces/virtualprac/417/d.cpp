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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m,k,q;
	cin>>n>>m>>k>>q;
	vector< queue<ll> >G(m+1),_G(n+1);
	vll toys(100023,-1);
	for(int i=0;i<k;i++)
	{
		int a,b;
		cin>>a>>b;
		G[b].push(a);
		_G[a].push(b);
		if(toys[b]==-1)
			toys[b]=-1;
	}
	for(int i=0;i<q;i++)
	{
		int a,b;
		cin>>a>>b;
		_G[a].push(b);
	}
	return 0;
}

