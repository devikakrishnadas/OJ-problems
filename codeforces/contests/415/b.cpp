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
	ll n,f;
	cin>>n>>f;
	vll a(n),b(n);// k,l
	vector<pair<ll,ll> >c; //max product sold in no=k, no=2*k;
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		int sold=min(a[i],b[i]);
		int sold2=min(2*a[i],b[i]);
		if(sold==sold2)
			ans+=sold;
		else
			c.pb(mp(sold2-sold,sold));
	}
	sort(all(c));
	reverse(all(c));
	for(int i=0;i<c.size();i++)
	{
		if(i<f && c[i].ff!=-1) 
		{
			ans+=(c[i].ff+c[i].ss);
			//cout<<c[i].ff<<endl;
		}
		else 
		{
			ans+=c[i].ss;
			//cout<<c[i].ss<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}

