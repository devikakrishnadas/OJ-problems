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
	vector<pair<int,int> >A,item;
	int n;
	int val,wt;
	//cin>>n;
	int totwt;
	cin>>totwt;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>wt>>val;
		A.pb(mp(wt,val));
	}
	int dp[2000][2000]={0};
	sort(all(A));
	for(int i=0;i<=totwt;i++)
	{
		if(i<A[0].first)
		{
			dp[0][i]=0;
		}
		else
		{
			dp[0][i]=A[0].second;
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=totwt;j++)
		{
			if(j<A[i].first)
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=max(A[i].second+dp[i-1][j-A[i].first],dp[i-1][j]);
			}
		}
	}
	cout<<dp[n-1][totwt]<<endl;
	int x=n-1,y=totwt;
	while(y)
	{
		if(dp[x][y]==dp[x-1][y])
		{
			x=x-1;
		}
		else
		{
			y=y-A[x].first;
			item.pb(A[x]);
			x=x-1;
		}
	}
	for(int i=0;i<item.size();i++)
	{
		cout<<item[i].first<<" ";
	}
	cout<<endl;
	return 0;
}
