#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ss second
#define ff first
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

vll aa(20000,0);
void dfs(ll a, ll b, vector< vll >&A,ll d)
{
	if(d==3)
	{
		aa[a]++;
		return;
	}
	//cout<<a<<endl;
	for(int i=0;i<A[a].size();i++)
	{
		if(A[a][i]!=b)
		{
			dfs(A[a][i],a,A,d+1);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	vector< vll >A(n+1);
	bool enter=0;
	ll s;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		if(!enter)
		{
			s=a;
			enter=1;
		}
		A[a].pb(b);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		dfs(i,-1,A,1);
		for(int j=1;j<=n;j++)
		{
			ans=ans+(aa[j]*(aa[j]-1))/2;
			aa[j]=0;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}

