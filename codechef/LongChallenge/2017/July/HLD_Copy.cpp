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
#define MAX_N 1000001
#define INF 987654321
using namespace std;
typedef long long lld;
typedef unsigned long long llu;

struct Node
{
     vector<int> adj;
};
Node graf[MAX_N];

struct TreeNode
{
     int parent;
     int depth;
     int chainTop;
     int subTreeSize;
};
TreeNode T[MAX_N];

int DFS(int root, int parent, int depth)
{
     T[root].parent = parent;
     T[root].depth = depth;
     T[root].subTreeSize = 1;
     for (int i=0;i<graf[root].adj.size();i++)
     {
          int xt = graf[root].adj[i];
          if (xt == parent) continue;
          T[root].subTreeSize += DFS(xt, root, depth+1);
     }
     return T[root].subTreeSize;
}

void HLD(int root, int parent, int chainTop)
{
     T[root].chainTop = chainTop;
     
     for (int i=0;i<graf[root].adj.size();i++)
     {
          int xt = graf[root].adj[i];
          if (xt == parent) continue;
          if (T[xt].subTreeSize*1.0 > T[root].subTreeSize*0.5) HLD(xt, root, chainTop);
          else HLD(xt, root, xt);
     }
}

inline int LCA(int u, int v)
{
     while (T[u].chainTop != T[v].chainTop)
     {
          if (T[T[u].chainTop].depth < T[T[v].chainTop].depth) v = T[T[v].chainTop].parent;
          else u = T[T[u].chainTop].parent;
     }
     
     if (T[u].depth < T[v].depth) return u;
     else return v;
}

int n;

int main()
{
     //n = 7;

     cin>>n;
     for(int i=1;i<=n;i++)
     {
        int u,v,c;
        cin>>u>>v>>c;
        graf[u].adj.pb(v);
        graf[v].adj.pb(u)
     }
     graf[1].adj.push_back(2);
     graf[2].adj.push_back(1);
     
     graf[1].adj.push_back(3);
     graf[3].adj.push_back(1);
     
     graf[1].adj.push_back(4);
     graf[4].adj.push_back(1);
     
     graf[3].adj.push_back(5);
     graf[5].adj.push_back(3);
     
     graf[3].adj.push_back(6);
     graf[6].adj.push_back(3);
     
     graf[3].adj.push_back(7);
     graf[7].adj.push_back(3);
     
     DFS(1, 1, 0);
     HLD(1, 1, 1);
     
     printf("%d\n", LCA(5, 7));
     printf("%d\n", LCA(2, 7));
     
     return 0;
}
