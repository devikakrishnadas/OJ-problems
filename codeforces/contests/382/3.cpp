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

int is_prime( ll a)
{
	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
			return 0;
	}
	return 1;
}


int main()
{
	ll n;
	cin>>n;
	//ll x=n-2;
	ll ans=0;
	if(is_prime(n))
	{
		cout<<1<<endl;
		return 0;
	}
	if(n<=3)
	{
		cout<<1<<endl;
		return 0;
	}
	if(n==4)
	{
		cout<<2<<endl;
		return 0;
	}
	if(n==6)
	{
		cout<<2<<endl;
		return 0;
	}
	
	if(n%2==0) cout<<2<<endl;
	else 
	{
		if(is_prime(n-2))
			cout<<2<<endl;
		else cout<<3<<endl;
	}
	return 0;
}

