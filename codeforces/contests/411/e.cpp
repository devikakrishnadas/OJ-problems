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
	int n,m;
	cin>>n>>m;
	int ans=0;
	vector<vi>A(n+1);
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		ans=max(ans,k);
		for(int j=0;j<k;j++)
		{
			int x;
			cin>>x;
			A[i].pb(x);
		}
	}
	set<int>COL[n];
	
	return 0;
}

