#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define M 1000000007
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll ans1=0;
	ll n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		ll t=n/i;
		ans1=ans1+(i*(t*(t+1))/2)%M;
		ans1=ans1%M;
	}
	
	cout<<ans1<<endl;
	return 0;
}

