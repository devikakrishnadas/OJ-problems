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

ll compute(vll a,vll b,ll n,ll noC,ll k)
{
	for(int i=0;i<n;i++)
	{
		//cout<<k<<endl;
		ll A=a[i]*noC;
		ll B=b[i];
		if(B<A)
		{
			k=k-(A-B);
		}
		if(k<0)
			return 0;
	}
	return 1;
}
ll bs(vll a,vll b, ll n,ll k)
{
	ll s=0;
	ll e=3000000000;
	ll ans=0;
	while(s<=e)
	{
		ll mid=(s+e)/2;
		//cout<<mid<<endl;
		ll A=compute(a,b,n,mid,k);
		if(A==1)
		{
			ans=mid;
			s=mid+1;
		}
		else
		{
			e=mid-1;
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,k;	
	cin>>n>>k;
	vll a(n),b(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	cout<<bs(a,b,n,k)<<endl;
	return 0;
}

