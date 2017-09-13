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


ll phi(ll n)
{   
	if(n==1) return 1; 
	if(n==2) return 1;
	if(n==3) return 2;
    ll result = n;  
    for (ll p=2; p*p<=n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

ll findpow(ll x, ll y, ll p)
{
	ll res=1;
	x=x%p;
	while(y>0)
	{
		if(y&1)
		{
			res=(res*x)%p;
		}
		y=y>>1;
		x=(x*x)%p;
	}
	return res;
}
ll func(ll x, ll k, ll m)
{
	if(x%m==0)
		return 0;
	if(k==1) return x%m;
	if(k==2)
	{
		return findpow(x%m,x%phi(m),m)%m;	
	}
	
	return findpow(x%m,func(x,k-1,phi(m)),m)%m;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		ll x,k,m;
		cin>>x>>k>>m;
		cout<<func(x,k,m)<<endl;
		
	}
	return 0;
}

