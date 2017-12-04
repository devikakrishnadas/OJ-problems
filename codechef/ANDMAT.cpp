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


struct Edge
{
    int v ;  // Vertex v (or "to" vertex)
    int flow ; // flow of data in edge
    int C;    // capacity
    int rev ; // To store index of reverse
};
 
class Graph
{
    int V; // number of vertex
    int *level ; // stores level of a node
    vector< Edge > *adj;
public :
    Graph(int V)
    {
        adj = new vector<Edge>[V];
        this->V = V;
        level = new int[V];
    }
 
    void addEdge(int u, int v, int C)
    {
        Edge a{v, 0, C, adj[v].size()};
        Edge b{u, 0, 0, adj[u].size()};
        adj[u].push_back(a);
        adj[v].push_back(b); // reverse edge
    }
    bool BFS(int s, int t);
    int sendFlow(int s, int flow, int t, int ptr[]);
    int DinicMaxflow(int s, int t);
};
bool Graph::BFS(int s, int t)
{
    for (int i = 0 ; i < V ; i++)
        level[i] = -1;
    level[s] = 0;  // Level of source vertex
    list< int > q;
    q.push_back(s);
    vector<Edge>::iterator i ;
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            Edge &e = *i;
            if (level[e.v] < 0  && e.flow < e.C)
            {
                level[e.v] = level[u] + 1;
                q.push_back(e.v);
            }
        }
    }
    return level[t] < 0 ? false : true ;
}
int Graph::sendFlow(int u, int flow, int t, int start[])
{
    if (u == t)
        return flow;
    for (  ; start[u] < adj[u].size(); start[u]++)
    {
        Edge &e = adj[u][start[u]]; 
        if (level[e.v] == level[u]+1 && e.flow < e.C)
        {
            int curr_flow = min(flow, e.C - e.flow);
            int temp_flow = sendFlow(e.v, curr_flow, t, start);
            if (temp_flow > 0)
            {
                e.flow += temp_flow;
                adj[e.v][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
    }
    return 0;
}
int Graph::DinicMaxflow(int s, int t)
{
    if (s == t)
        return -1;
    int total = 0;  // Initialize result
    while (BFS(s, t) == true)
    {
        int *start = new int[V+1];
        while (int flow = sendFlow(s, INT_MAX, t, start))
            total += flow;
    }
    return total;
}
ll func(vector<pair<ll,pair<ll,ll> > >&b,int n,ll ma)
{
    ll cnt=1;
    ll c=0;
    ll cans=0;
    ll val=0;
    while(ma)
    {
        if(ma%2==1)
        {
            val=cnt;
            cans=c;
        }
        cnt*=2;
        c++;
        ma/=2;
    }
//    cout<<val<<endl;
    vector<pair<ll,pair<ll,ll> > >tb;
    tb=b;
    ll SOURCE = 0;
    ll SINK = 2*n+1;
    ll ans=0;
    ll lsb=val;
    ll  tt=cans + 1;
    while(val)
    {
        Graph g(2*n+2);
        bool enter=0;
      //  cout<<"when lsb is "<<lsb<<endl;
      for(int i=1;i<=n;i++)
      {
        g.addEdge(SOURCE,i,1);
      }
      for(int i=n+1;i<=2*n;i++)
      {
        g.addEdge(i,SINK,1);
      }
        for(int i=0;i<tb.size();i++)
        {
    //        cout<<" orval b/w "<<tb[i].ff<<" and "<<lsb<<" is "<<(tb[i].ff | lsb)<<endl;
            if((tb[i].ff | lsb) == tb[i].ff)
            {
                enter=1;
                //g.addEdge(SOURCE,tb[i].ss.ff,1);
                g.addEdge(tb[i].ss.ff,tb[i].ss.ss,1);
                //g.addEdge(tb[i].ss.ss,SINK,1);
  //              cout<<"edge b/w : "<<tb[i].ss.ff<<" and "<<tb[i].ss.ss<<" with weight "<<tb[i].ff<<endl;
            }
            else
            {
                if(lsb > tb[i].ff) break;
//                cout<<"did not enter"<<endl;
            }
        }
        ll maxflow=0;
        if(enter)
            maxflow = g.DinicMaxflow(SOURCE,SINK);
//        cout<<maxflow<<" "<<n<<endl;
        if(maxflow >= n)
        {
            
            ans= lsb;
//            cout<<ans<<" ***** "<<maxflow<<endl;
            val=val/2;
            lsb = ans | val;
        }
        else
        {
            val = val / 2;
            lsb = ans | val;
        }
    }
    return ans;
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
        int n;
        cin>>n;
        vector<pair<ll,pair<ll,ll> > >b;
        ll ma=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ll x;
                cin>>x;
                ma=max(ma,x);
                b.pb(mp(x,mp(i,j+n)));
            }
        }
        sort(all(b));
        reverse(all(b));
        ll ans=func(b,n,ma);
        cout<<ans<<endl;
    }

	return 0;
}

