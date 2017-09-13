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
//ll n,m,k;

ll dp[5005][5005]={0};
vll A(5005,0);
int main()
{

	int n,m,k;
	cin>>n>>m>>k;
//	cout<<"abc"<<endl;
	//vi A(n+1,0);
	
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
		A[i]=A[i-1]+A[i];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=i*m;j<=n;j++)
		{
			dp[i][j]=max(dp[i][j-1],dp[i-1][j-m]+A[j]-A[j-m]);
		}
	}
	cout<<dp[k][n]<<endl;
	return 0;
}
