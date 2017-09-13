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
ll child[100023]={0};
ll moves[100023]={0};
void dfs(ll a,ll prev)
{
	for(int i=0;i<A[a].size();i++)
	{
		if(A[a][i]!=prev)
		{
			dfs(A[a][i],a);
			child[a]=child[a]+child[A[a][i]];
			moves[a]=moves[a]+abs(moves[A[a][i]]);
		}
	}
	//cout<<a<<" "<<child[a]<<" "<<v[a]<<endl;
	v[a]=v[a]+child[a];
	child[a]=(child[a]-1*v[a]);
	moves[a]+=abs(v[a]);
	v[a]=0;
	//cout<<moves[a]<<endl;
}
int main()
{
	/*ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/
	ll n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		A[a].pb(b);
		A[b].pb(a);
	}
	//child[0]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	//	child[i]=-1;
	}
	dfs((ll)1,(ll)-1);
	cout<<moves[1]<<endl;
	return 0;
}

