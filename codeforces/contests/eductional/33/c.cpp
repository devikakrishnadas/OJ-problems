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
vi A(100023);
void dfs(vector<vi>&G,int a,int p,int &mi)
{
    if(vis[a]) return;
    vis[a]=1;
    mi=min(mi,A[a]);
    for(int i=0;i<G[a].size();i++)
    {
        if(G[a][i]==p) continue;
        dfs(G,G[a][i],a,mi);
        
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vi>G(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        int mi=INT_MAX;
        dfs(G,i,-1,mi);
        ans+=mi;
    }
    cout<<ans<<endl;
	return 0;
}

