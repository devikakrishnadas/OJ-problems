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

ll n;
vll a(200023,0);
vector<pair< ll , ll> > visited(200023,mp(0,0));
//0 should be x-a[x]
ll dfs(vector< pair<ll,ll> >&G,ll x,ll l,vector<pair<bool,bool> > &vis)
{
	cout<<"dfs beg" <<" "<<x<<endl;
	if(x>n || x<1)
	{
		return 0;
	}
	if(x==1)
	{
		if(l%2)
		{
			visited[x].ff=-1;
		}
		else visited[x].ss=-1;
		return -1;
	}
	if(l%2)
	{
		if(visited[x].ff)
		{
			return visited[x].ff;
		}
		else if(vis[x].ff)
		{
			vis[x].ff=-1;
			visited[x].ff=-1;
			return -1;
		}
		else
		{
			vis[x].ff=1;
			visited[x].ff=dfs(G,G[x].ff,l+1,vis);
			if(visited[x].ff!=-1)
				visited[x].ff+=a[x];
			return visited[x].ff;
		}
	}
	else
	{
		if(visited[x].ss)
                        return visited[x].ss;
		else if(vis[x].ss)
                {
                        vis[x].ss=-1;
                        visited[x].ss=-1;
                        return -1;
                }
		 else
                {
                        vis[x].ss=1;
                        visited[x].ss=dfs(G,G[x].ss,l+1,vis);
                        if(visited[x].ss!=-1)
                                visited[x].ss+=a[x];
			return visited[x].ss;
                }
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	n=200000;
	vector<pair<ll,ll> >G(200023,mp(0,0));
	for(int i=2;i<=n;i++)
	{
		a[i]=rand()%i;
		G[i]=mp(i-a[i],a[i]+i);
	}
	cout<<"r1"<<endl;
	for(int i=2;i<=n;i++)
	{
		vector<pair<bool,bool> >vis(n+1,mp(0,0));
		
		if(!visited[i].ff)
		{	
			dfs(G,i,1,vis);
		}
		else
			cout<<visited[i].ff<<" "<<i<<endl;
		cout<<endl<<endl;
	}
	for(int i=1;i<n;i++)
	{
		if(visited[i+1].ff==-1)
			cout<<-1<<endl;
		else
			cout<<i+visited[i+1].ff<<endl;
	}
	return 0;
}

