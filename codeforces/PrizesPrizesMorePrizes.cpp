#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
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
	ll n;
	cin>>n;
	vll a(n);
	vector< pair<ll,ll> >A;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<=5;i++)
	{
		ll x;
		cin>>x;
		A.pb(mp(x,i));
	}
	A.pb(mp(LLONG_MAX,6));
	sort(all(A));
	ll pts=0;
	vll cnt(10,0);
	for(ll i=0;i<n;i++)
	{
		pts=pts+a[i];
		pk:ll val=0;
		ll valp=-1;
		bool enter=0;
		for(ll j=0;j<5;j++)
		{
			if(A[j].ff<=pts) 
			{
				enter=1;
				val=A[j].ff;
				valp=A[j].ss;
			}
			else break;
		}
		if(enter)
		{
			
			ll aaa=pts%val;
			cnt[valp]+=((pts-aaa)/val);
			pts=aaa;
			goto pk;
		}
	}
	for(int i=1;i<=5;i++)
	{
		cout<<cnt[i]<<" ";
	}
	cout<<endl;
	cout<<pts<<endl;
	return 0;
}

