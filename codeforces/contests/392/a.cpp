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
	int n;
	cin>>n;
	vi A;
	int ma=0;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		A.pb(x);
		ma=max(ma,x);
	}
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ans=ans+(ma-A[i]);
	}
	cout<<ans<<endl;
	return 0;
}

