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
    int n,k,d;
    cin>>n>>k>>d;
    vi p;
    queue<pair<int,int> >q;
    for(int i=0;i<k;i++)
    {
        int t;
        cin>>t;
        p.pb(t);
        q.push(mp(t,0));
    }
    vector<pair<int,int> >G[3*100002];
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].pb(mp(y,i+1));
        G[y].pb(mp(x,i+1));
    }
    vi vis(n+2,0);
    vi vis2(n+2,0);
    while(!q.empty())
    {
        pair<int,int> t = q.front();
        q.pop();
        if(vis[t.ff])
            continue;
        vis[t.ff]=1;
        for(int i=0;i<G[t.ff].size();i++)
        {
            if(G[t.ff][i].ff != t.ss)
            {
                if(vis[G[t.ff][i].ff])
                    vis2[G[t.ff][i].ss] = 1;
                else
                    q.push(mp(G[t.ff][i].ff,t.ff));
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n-1;i++)
    {
        if(vis2[i])
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=n-1;i++)
        if(vis2[i])
            cout<<i<<" ";
    cout<<endl;
	return 0;
}

