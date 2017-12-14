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

void dfs(int a,vector<vi>&G,vector<vi>&T,vi &vis,int p)
{
    if(vis[a])
        return;
    if(p!=-1)
    {
        T[p].pb(a);
    }
    vis[a]=1;
    for(int i=0;i<G[a].size();i++)
    {
        dfs(G[a][i],G,T,vis,a);
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vi>G(n+1),G_(n+1);
        vector<pair<int,int> >e;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            G[x].pb(y);
            G_[y].pb(x);
            e.pb(mp(x,y));
        }

        vector<vi>T(n+1),T_(n+1);
        vi vis1(n+1,0),vis2(n+1,0);

        dfs(1,G,T,vis1,-1);
        dfs(1,G_,T_,vis2,-1);

        map<pair<int,int>,int>val;
        int cnt=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<T[i].size();j++)
            {
                val[mp(i,T[i][j])]=1;
                cnt++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<T_[i].size();j++)
            {
                if(val.find(mp(T_[i][j],i))==val.end())
                {
                    val[mp(T_[i][j],i)]=1;
                    cnt++;
                }
            }
        }
        bool done=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<G[i].size();j++)
            {
                if(val.find(mp(i,G[i][j]))==val.end())
                {
                    val[mp(i,G[i][j])]=1;
                    cnt++;
                }
                if(cnt==2*n)
                {
                    done=1;
                    break;
                }
            }
            if(done) break;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<G[i].size();j++)
            {
                if(val.find(mp(i,G[i][j]))==val.end())
                {
                    cout<<i<<" "<<G[i][j]<<endl;
                }
            }
        }
    }
	return 0;
}

