#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int maxD(int a,vi &d)
{
	int ans=0;
	for(int i=2;i*i<=a;i++)
	{
		if(a%i==0)
		{
			ans=max(ans,d[i]);
			ans=max(ans,d[a/i]);
		}
	}
	
	return ans;
}

void factD(int a,vi &d,int val)
{
	for(int i=2;i*i<=a;i++)
	{
		if(a%i==0)
		{
			d[i]=max(d[i],val);
			d[a/i]=max(d[a/i],val);
		}
	}
	d[a]=max(d[a],val);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vi a(n);
	int ma=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	vi dp(100001,0),d(100001,0);
	for(int i=0;i<n;i++)
	{
		dp[a[i]]=maxD(a[i],d)+1;
		factD(a[i],d,dp[a[i]]);
	}
	
	cout<<*max_element(dp.begin(),dp.begin()+ma+1)<<endl;
	return 0;
}

