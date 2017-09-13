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
#define mod 1000000007
using namespace std;


ll sum(ll n)
{
	ll a=(n*(n+1));
	a=a%mod;
	a=(a*500000004)%mod;
	return a;
}

ll sum2(ll n)
{
	ll a=(n*(n+1));
	a=a%mod;
	a=a*(2*n+1);
	a=a%mod;
	a=(a*166666668)%mod;
	return a;
}
ll sum3(ll n)
{
	ll a=(n*(n+1));
	a=a%mod;
	a=a*a;
	a=a%mod;
	a=(a*250000002)%mod;
	return a;
}
int main()
{
	ifstream fin;
	fin.open("A-large-practice.txt");
	ofstream fout;
	fout.open("OP.txt");
	int t;
	if(!fin) cout<<"NOOOO"<<endl;
	fin>>t;
	//cin>>t;
	int i=1;
	while(t--)
	{
		
		ll r,c;
		fin>>r>>c;
		//cin>>r>>c;
		ll n=min(r,c)-1;
		ll ans=(((((r*c)%mod)*sum(n))%mod)-(((r+c)*sum2(n))%mod)+sum3(n))%mod;
		ans=ans%mod;
		if(ans<0)
			ans=ans+mod;
		fout<<"Case #"<<i<<": "<<ans<<endl;
		//cout<<"Case #"<<i<<": "<<ans<<endl;
		i++;
	}
	return 0;
}

