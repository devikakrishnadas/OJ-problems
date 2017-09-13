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

ll delta(ll m)
{
	ll t=sqrt(12*m*m-4*m+1);
	return t;
}

ll tri(ll n)
{
	return (n*(n+1))/2;
}

ll pent(ll m)
{
	return (m*(3*m-1))/2;
}
ll hex(ll p)
{
	return p*(2*p-1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(ll m=166;;m++)
	{
		ll n=(-1+delta(m))/2;
		ll p=(1+delta(m))/4;
		cout<<n<<" "<<m<<" "<<p<<endl;
		ll T=tri(n);
		ll P=pent(m);
		ll H=hex(p);
		if(T==P && T==H)
		{
			cout<<T<<endl;
			break;
		}
	}
	return 0;
}

