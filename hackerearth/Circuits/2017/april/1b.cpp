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
	double n;
	cin>>n;
	int x;
	double ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		ans=ans+log(x);
	}
	ll s=0;
	ll e=LLONG_MAX;
	ll fans=0;
	while(s<=e)
	{
		ll m=(s+e)/2;
		//cout<<m<<endl;
		double y=ans/log(m);
		if(n-y>(-0.000000000001))
		{
			fans=m;
			e=m-1;
		}
		else
		{
			s=m+1;
		}
	}
	cout<<fans<<endl;
	return 0;
}

