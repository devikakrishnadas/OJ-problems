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

vi vis(100023,0);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vi>G(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].pb(y);
    }
    int s;
    cin>>s;
    dfs(G,s);
	return 0;
}

