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
	int n,m;
	cin>>n>>m;
	ll ans=(n-n%2)*(m-m%2);
	ans=ans/4;
	ans=ans+(m%2)*(n/2) + (n%2)*(m/2) + (n%2)*(m%2);
	cout<<ans<<endl;
	return 0;
}

