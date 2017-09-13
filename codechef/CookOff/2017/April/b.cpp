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
		ll n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		ll a[100023]={0};
		ll b[100023]={0};
		for(int i=0;i<n;i++)
		{
			if(s[i]=='a')
			{
				if(i) a[i]=a[i-1]+1;
				else a[i]=1;
			}
			else if(i) a[i]=a[i-1];
		}
		ll tota=a[n-1];
		for(int i=n-1;i>=0;i--)
		{
			if(s[i]=='b')
			{
				if(i<n) b[i]=b[i+1]+1;
				else b[i]=1;
			}
			else if(i<n) b[i]=b[i+1];
		}
		ll totb=b[0];
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='a')
			{
				if(b[i])
					ans=ans+(k*b[i] + totb*((k*(k-1))/2));
				else
					ans=ans+totb*(((k-1)*k)/2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

