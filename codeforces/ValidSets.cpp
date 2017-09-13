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
ll ans=0;
vector<vector<int> >A(n+1);

void dfs(int a,int prev,int d,vi val)
{
    for(int i=0;i<A[a].size();i++)
    {
        if(A[a][i]!=prev)
        {
            
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int d,n;
    cin>>d>>n;
    vi a(n);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        A[u].pb(v);
        A[v].pb(u);
    }
    queue<int>q;
    vi o;
    q.pb(1);
    int cur,par=-1;
    while(!q.empty())
    {
        cur=q.front();
        dfs(cur,par,d);
        q.pop();
        for(int i=0;i<A[cur].size();i++)
        {
            if(A[cur][i]!=par)
                q.insert(A[cur][i]);
        }
        par=cur;
    }
	return 0;
}

