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


//use long instead of ll. ll is taking time
int main()
{	
	ios_base::sync_with_stdio(0);
	ll n,m;
	cin>>n>>m;
	ll dp[2][200023];
	ll totb=0;
	ll lr=1;
	dp[0][0]=1;
	ll ans=0;
	for(int h=1;h<=900;h++)
	{
		totb+=h;
		ll tans=0;
		for(int r=0;r<=n;r++)
		{
			dp[h%2][r]=0;
			if(totb-r<=m)
			{
				dp[h%2][r]=dp[1-h%2][r];
				lr=h%2;
			}
			if(r>=h)
			{
				dp[h%2][r]+=dp[1-h%2][r-h];
				dp[h%2][r]=dp[h%2][r]%M;
				lr=h%2;
			}
			tans+=dp[h%2][r];
			if(tans>M)
				tans-=M;
		}
		
		if(tans>0)
			ans=tans;
		else break;
	}	
	cout<<ans<<endl;
	cin.get();
	return 0;
}

