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
	int n,m;
	vi A[2000];
	cin>>n>>m;
	int x,y;
	int v[3000];
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		A[x].pb(y);
		A[y].pb(x);
	}
	int ans=INT_MAX;
	int val;
	int ansi=0,fans=0;
	for(int k=0;k<n;k++)
	{	
		ans=INT_MAX;
		for(int i=1;i<=n;i++)
		{
			val=0;
			for(int j=0;j<A[i].size();j++)
			{
				val=val+v[A[i][j]];
			}
			if(val<ans && A[i].size())
			{
				ans=val;
				ansi=i;
			}
		}
		fans=fans+ans;
		A[ansi].clear();
		v[ansi]=0;
		cout<<ansi<<"*"<<endl;
	}
	cout<<fans<<endl;
	return 0;
}

