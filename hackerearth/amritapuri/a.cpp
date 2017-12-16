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

ll ModE(ll a,ll b)
{
	ll rem = 1;
	a %= M;

	while(b > 0)
    {
		if(b & 1)
        {
			rem *= a;
		}
		a = a * a;
		a %= M;
		rem %= M;
		b = b >> 1;
	}
	return rem;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin>>q;
	while(q--)
    {
		ll n,l;
		cin>>n>>l;
		ll ans=ModE(n-1,min(n,l));
        cerr<<ans<<endl;
		ans*=ModE(n,max(l-n,(ll)0));
        cerr<<ans<<endl;
		ans%=M;
		cout<<ans<<endl;
	}
	
}
