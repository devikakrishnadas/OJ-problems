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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vll a(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		ll gcd=a[0];
		ll lcm=a[0];
		for(int i=1;i<n;i++)
		{
			gcd=__gcd(lcm,a[i]);
			lcm=lcm*a[i];
			lcm=lcm/gcd;
		}
		cout<<lcm<<endl;
		
	}
	return 0;
}

