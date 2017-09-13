#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;

ll n,m,k;

ll b_s()
{
	ll a=min(k,n-k);
	ll b=a*a;
	if(m==b) return a;
	else if(m<b)
	{
		
	}
}
int main()
{
	cin>>n>>m>>k;
	ll ans=1;
	ll p;
	if(k!=1 && k!=n)
		p=sqrt(n);
	else
	{
		p=(-1+sqrt(1+8*m))/2;
	}
	
	while(m<p*p &&k!=1&&k!=n)
	{
		p--;
	}
	while((k==1||k==n)&& m<(p*(p-1)/2))
		p--;
	m=m-(p*p);
	ans=p+m/n;
	cout<<ans<<endl;
	return 0;
}

