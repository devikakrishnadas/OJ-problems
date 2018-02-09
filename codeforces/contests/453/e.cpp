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
int n,m;
vector<vi>a(300000+23);
vi vis(300000+23,0);
vi smallest_cycle(300000+23,INT_MAX);

stack<int>S;
map<int,int>m;
void dfs(int u,int p)
{
    S.push(u);
    vis[u]=1;

    for(int x:A[u])
    {
        if(vis[x]==0)
        {
            dfs(x,u);
        }
        else
        {
            int mi = INT_MAX;
            int ma = 0;
            while(!S.empty())
            {
                int t = S.top();
                S.pop();
                mi = min(mi,t);
                ma = max(ma,t);
                if(t == v)
                    break;
            }
            smallest_cycle[mi] = ma;
            
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    for(int i=1;i<=n;i++)
        sort(all(a[i]));
    for(int i=1;i<=n;i++)
    {   
        if(!vis[i])
        {
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        
    }
	return 0;
}

