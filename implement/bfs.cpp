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


vi BFS(vector<vector< pair<int,int> > >&Graph,int source)
{
	queue<int>Q;
	vi visited(100023,INT_MAX);
	visited[source]=0;
	Q.push(source);
	while(!Q.empty())
	{
		source=Q.front();
		for(int i=0;i<Graph[source].size();i++)
		{
			if(visited[Graph[source][i].ff]>(visited[source]+Graph[source][i].ss))
			{
				Q.push(Graph[source][i].ff);
				visited[Graph[source][i].ff]=(visited[source]+Graph[source][i].ss);
			}
		}
		Q.pop();
	}
	return visited;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,x,y,z,source;
	cin>>n>>m;
	vector<vector<pair<int,int> > >Graph(n+1);
	vi visited;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>z;
		Graph[x].pb(mp(y,z));
	}
	cin>>source;
	visited=BFS(Graph,source);
	for(int i=1;i<=n;i++)
	{
		cout<<visited[i]<<" ";
	}
	cout<<endl;
	return 0;
}

