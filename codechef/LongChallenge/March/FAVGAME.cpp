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
		int n,h;
		cin>>n>>h;
		vi t(n);
		for(int i=0;i<n;i++)
			cin>>t[i];
		int x,m;
		vector< vi >A(n+1);
		for(int i=1;i<=n;i++)
		{
			cin>>m;
			for(int j=0;j<m;j++)
			{
				A[i].pb(x);
			}
		}
	}
	return 0;
}

