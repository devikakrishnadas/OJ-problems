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
ll n,m,k,x,y;
ll pos(ll x,ll y)
{
	if(n==1)
	{
		ll ans= k/m;
		if(k%m>=y) ans++;
		return ans;
	}
	ll T=n*m+(n-2)*m;
	ll rem=k%T;
	ll fullP=k/T;
	ll indVal=(x-1)*m+y;
	if(x==1||x==n)
	{
		ll ans=fullP;
		if(indVal<=rem) ans++;
		return ans;
	}
	ll ans=2*fullP ;
	if(indVal<=rem) ans++;
	if((n*m)+(n-x-1)*m+y<=rem)
		ans++;
	return ans;
}


int main()
{
	cin>>n>>m>>k>>x>>y;
	cout<<max(pos(1,1),max(pos(2,1),pos(n-1,1)))<<" "<<pos(n,m)<<" "<<pos(x,y)<<endl;
	return 0;
}

