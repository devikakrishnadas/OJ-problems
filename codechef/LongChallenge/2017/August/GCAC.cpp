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


/* FORD FULKERSON AND BFS CODE TAKEN FROM GEEKSFORGEEKS */

int graph[1010][1010];
bool bfs(int rGraph[1010][1010], int s, int t, int parent[1010],int n)
{
    bool visited[1001]={0};
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop(); 
        for (int v=1; v<=n; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {       
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    cout<<endl;
    return (visited[t] == true);
}


int fordFulkerson( int s, int t,int n,int m)
{
    int u, v;
    int rGraph[1010][1010]={0}; 
    for (u = 0; u <= n; u++)
    {
        for (v = 0; v <= m; v++)
        {
            rGraph[u][v] = graph[u][v];
            cout<<graph[u][v]<<"*"<<rGraph[u][v]<<" ";
        }
        cout<<endl;
    }
    cout<<"r1"<<endl; 
    int parent[1010];  
 
    int max_flow = 0;  
    cout<<"r2"<<endl;
    while (bfs(rGraph, s, t, parent,n))
    {
        cout<<t<<endl;
        int path_flow = 1000000007;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        max_flow += path_flow;
    }
    return max_flow;
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
        vi minSalary(n+1);
        for(int i=1;i<=n;i++)
            cin>>minSalary[i];
        vector<pair<int,int> >job(m+1);// < offered salary,maxJobOffers >
        for(int i=1;i<=m;i++)
        {
            int offeredSalary,maxJobOffer;
            cin>>offeredSalary>>maxJobOffer;
            job[i]=mp(offeredSalary,maxJobOffer);
        }
        int qual[1001][1001]={0};
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>qual[i][j];
            }
        }
        int s=0;
        int dest=n+1;
        for(int i=1;i<=n;i++)
        {
            graph[s][i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(job[j].ff>=minSalary[i] && qual[i][j])
                    graph[i][j]=1;
            }
        }
        for(int i=1;i<=m;i++)
        {
            graph[i][n+1]=job[i].ss;
        }
        cout<<"r0"<<endl;
        cout<<fordFulkerson(s,dest,n+1,m)<<endl;
    }
	return 0;
}

