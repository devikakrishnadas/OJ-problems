#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define ss second
#define ff first
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;
    void DFS(int v, bool visited[]);
public:
    Graph(int V);   // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // Returns true if graph is connected
    bool isConnected();
 
    bool isBridge(int u, int v);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add w to v’s list.
    adj[v].push_back(u); // Add w to v’s list.
}
 
void Graph::DFS(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
 
    // Recur for all the vertices adjacent to
    // this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited);
}
 
// Returns true if given graph is connected, else false
bool Graph::isConnected()
{
    bool visited[V];
    memset(visited, false, sizeof(visited));
 
    // Find all reachable vertices from first vertex
    DFS(0, visited);
 
    // If set of reachable vertices includes all,
    // return true.
    for (int i=1; i<V; i++)
       if (visited[i] == false)
           return false;
 
    return true;
}
 
// This function assumes that edge (u, v)
// exists in graph or not,
bool Graph::isBridge(int u, int v)
{
    // Remove edge from undirected graph
    adj[u].remove(v);
    adj[v].remove(u);
 
    bool res = isConnected();
 
    // Adding the edge back
    addEdge(u, v);
 
    // Return true if graph becomes disconnected
    // after removing the edge.
    return (res == false);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	Graph g(n+1);
	vi ans(m+1,1);
	vector<pair<int,pair<int,pair<int,int> > > >A;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		A.pb(mp(w,mp(i+1,mp(u,v))));
		g.addEdge(u,v);
	}
	sort(all(A));
	int val=0;
	for(int i=0;i<m;i++)
	{
		if(k==0) break;
		if(g.isBridge(A[i].ss.ss.ff, A[i].ss.ss.ss))
		{
			k--;
			val++;
			ans[A[i].ss.ff]=0;
		}
	}
	cout<<n-val<<endl;
	for(int i=1;i<=m;i++)
	{
		if(ans[i])
			cout<<i<<" ";
	}
	cout<<endl;
	
	return 0;
}

