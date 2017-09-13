#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 10000000000
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
	ll ans=0;
	for(int i=1;i<=1000;i++)
	{
		ll val=1;
		for(int j=1;j<=i;j++)
		{
			val=(val*i)%M;
		}
		ans=(ans+val)%M;
	}
	cout<<ans<<endl;
	return 0;
}

