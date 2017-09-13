#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

ll lessthan(ll a, ll n,ll m)
{
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=ans+min(a/i,m);
	}
	return ans;
}
ll bs(ll n,ll m,ll k)
{
	ll s=1;
	ll e=n*m;
	ll ans=0;
	while(s<=e)
	{
		
		ll mid=(s+e)/2;
		ll val=lessthan(mid,n,m);
		//cout<<mid<<" "<<val<<endl;
		if(val>=k)
		{
			ans=mid;
			e=mid-1;
		}
		else
		{
			s=mid+1;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m,k;
	cin>>n>>m>>k;
	cout<<bs(n,m,k)<<endl;
	return 0;
}

