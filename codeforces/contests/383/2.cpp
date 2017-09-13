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
	ll n,x,a;
	cin>>n>>x;
	map<ll,ll>A;
	ll X[100023];
	ll B[100023];
	for(int i=0;i<n;i++)
	{
		cin>>a;
		B[i]=a;
		A[a]++;
		X[i]=a^x;
	}
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ans=ans+ A[B[i]]*A[X[i]];
		A[B[i]]=0;
		A[X[i]]=0;
	}
	cout<<ans<<endl;
	return 0;
}

