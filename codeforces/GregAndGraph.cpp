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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	ll A[501][501]={0};
	ll B[501][501]={0};
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			cin>>A[i][j];
			B[i][j]=A[i][j];
		}
	}
	ll rem[501];
	for(ll i=n-1;i>=0;i--)
	{
		cin>>rem[i];
	}
	vll fans;
	
	for(ll i=0;i<n;i++)
	{
		ll ans=0;
		for(ll j=0;j<n;j++)
		{
			for(ll k=0;k<n;k++)
			{
				if(A[rem[j]][rem[i]]+A[rem[i]][rem[k]]<A[rem[j]][rem[k]])
				{
					A[rem[j]][rem[k]]=A[rem[j]][rem[i]]+A[rem[i]][rem[k]];
				}
				if(j<=i && k<=i)
				{
					ans=ans+A[rem[j]][rem[k]];
				}
				//ans=ans+A[rem[j]][rem[k]];
				//cout<<A[rem[j]][rem[k]]<<" ";
			}
			//cout<<endl;
		}
//		cout<<"THE ANS :"<<ans<<endl;
		fans.pb(ans);
	}
	reverse(all(fans));
	for(int i=0;i<fans.size();i++)
	{
		cout<<fans[i]<<" ";
	}
	cout<<endl;
	return 0;
}

