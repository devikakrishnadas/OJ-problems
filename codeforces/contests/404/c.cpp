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

int main()
{
	ll n,m;
	cin>>n>>m;
	ll k=-1+sqrt(1+8*n);
	k=k/2;
	while((k*(k+1))/2 <n)
	{
		k++;
	}
	if(m>n)
	{
		cout<<k<<endl;
	}
	else
	{
		ll ans=m;
		n=n-m;
		k=-1+sqrt(1+8*n);
		k=k/2;
		while(((k*(k+1))/2)<n)
		{
			k++;
		}
		ans+=k;
		cout<<ans<<endl;
	}
	return 0;
}

