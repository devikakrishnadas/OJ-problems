 
#include <bits/stdc++.h>
using namespace std;
 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
 
int n,m,vis[3*10000];
vector<int> graph[3*10000];
vector<int>odd;
 
void dfs(int cur)
{
    for(int i=0;i<graph[cur].size();i++)
    {
        int neigh = graph[cur][i];
        if(vis[neigh] && (vis[neigh]-vis[cur])%2==0 )
            odd.pb(vis[neigh]-vis[cur]+1);
        else if(vis[neigh]==0)
        {
            vis[neigh] = vis[cur]+1;
            dfs(neigh);
        }
    }
}
 
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].pb(v2);
        graph[v2].pb(v1);   
    }
    vis[1] = 1;
    dfs(1);
 
    if(odd.size()==0)
        cout<<m;
    else if(odd.size()==1)
        cout<<odd[0];
    else
        cout<<0;
 
    return 0;
} 
