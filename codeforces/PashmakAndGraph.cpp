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
	vector< vector<pair<int,int> > >G(300023);
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		G[z].pb(x,y);
	}
	return 0;
}

