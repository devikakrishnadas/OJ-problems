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

int ans=0;

int dfs(vector<vi>&G,int a,vi &vis)
{
    int val=1;
    vis[a]=1;
    for(int i=0;i<G[a].size();i++)
    {
        if(!vis[G[a][i]]) 
            val+=dfs(G,G[a][i],vis);
    }
    return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vector<vi>G(n+1);
    vi vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        G[i].pb(x);
    }
    
	return 0;
}

