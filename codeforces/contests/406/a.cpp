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

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	
	for(ll i=0;i<=1000000000;i++)
	{
		ll val=b+i*a;
		ll t=(val-d)/c;
		if(d+t*c==val)
		{
			cout<<val<<endl;
			return 0;
		}
		
	}
	cout<<-1<<endl;
	return 0;
}

