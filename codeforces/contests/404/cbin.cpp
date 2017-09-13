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

ll bin(ll n,ll m)
{
	ll r=0;
	ll mid,ans;
	ll l=100;
	while(r<l)
	{
		
		mid=(r+l)/2;
		cout<<l<<" "<<r<<" "<<mid<<endl;
		ans=n-(mid*(mid+1))/2 +mid*(m-1);
		cout<<"="<<ans<<endl;
		if(ans<0)
		{
			l=mid;
		}
		else
			r=mid+1;
		if(ans==0)
			return mid;
	}
	return mid+1;
}
int main()
{
	ll n,m;
	cin>>n>>m;
	cout<<bin(n,m)<<endl;
	return 0;
}

