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
		ll ans=0;
		sort(a.begin(),a.begin()+n);
		for(int i=1;i<n;i++)
		{
			if(a[i]!=a[i-1]+1)
			{
				if(i==n-1) 
					ans=a[i];
				else ans=a[i-1];
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

