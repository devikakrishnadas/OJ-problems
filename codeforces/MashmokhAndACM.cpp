#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define M 1000000007
#define all(V) V.begin(),V.end()

using namespace std;

ll A[2001][2001]={0};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,k;
	
	cin>>n>>k;
	vi a[2001];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				a[i].pb(j);
				if((i/j)!=j)
				{
					a[i].pb(i/j);
				}
			}
		}
	}
	//ll A[3000][3000]={0};
	for(int j=1;j<=n;j++)
	{
		A[1][j]=1;
	}
	for(int i=1;i<=k;i++)
	{
		A[i][1]=1;
	}
	for(int i=2;i<=k;i++)
	{
		for(int j=2;j<=n;j++)
		{
			for(int l=0;l<a[j].size();l++)
			{
				A[i][j]+=A[i-1][a[j][l]];
				A[i][j]=A[i][j]%M;
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+A[k][i])%M;
	}
	cout<<ans<<endl;
	return 0;
}

