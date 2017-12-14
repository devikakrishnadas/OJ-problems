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

void dfs(vector<vi>&G, vll &val,ll cur,ll p,ll gp,ll k,ll a,ll b,ll l,ll valp,ll valgp)
{
    if(l>k)
        return;
    if(p == -1 && gp == -1)
    {
        val[cur]+=a;
        valgp=valp;
        valp=a;
    }
    else if(gp == -1)
    {
        val[cur]+=b;
        valgp=valp;
        valp=b;
    }
    else
    {
        val[cur]+=(valp+valgp);
        ll par = valp + valgp;
        ll granpar = valp;
        valp=par;
        valgp=granpar;
    }
    val[cur]%=M;
    for(int i=0;i<G[cur].size();i++)
    {
        if(G[cur][i]!=p)
        {
            dfs(G,val,G[cur][i],cur,p,k,a,b,l+1,valp,valgp);
        }
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
        ll n,q;
        cin>>n>>q;
        vector<vi>G(n+1);
        vll val(n+1,0);
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            G[x].pb(y);
            G[y].pb(x);
        }
        while(q--)
        {
            int type;
            cin>>type;
            if(type==1)
            {
                ll v,k,a,b;
                cin>>v>>k>>a>>b;
                dfs(G,val,v,-1,-1,k,a,b,0,0,0);
            }
            else
            {
                int v;
                cin>>v;
                cout<<val[v]<<endl;
            }
        }
    }
	return 0;
}

