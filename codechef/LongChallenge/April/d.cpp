#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define ff first
#define ss second
#define all(V) V.begin(),V.end()

using namespace std;

void dfs(ll a, vll &dist,ll val,vector<vector<pair<ll,ll> > > &G,int k1,int k2)
{
	if(val>dist[a]) return;
	dist[a]=val;
	for(int i=0;i<G[a].size();i++)
	{
		if(dist[G[a][i].first]>=val + G[a][i].second )
		{
			dist[G[a][i].first]=val + G[a][i].second;
			
			dfs(G[a][i].first , dist , dist[G[a][i].first] ,G,k1,k2);
		}
	}
}

void print(vll &dist,ll n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<dist[i]<<" ";
	}
	cout<<endl;
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
		ll n,k,x,m,s;
		cin>>n>>k>>x>>m>>s;
		ll a,b,c;
		vll d(n+1);
		vector<vector<pair<ll,ll> > >G(n+1),A(n+1); /* 2D graph that contains ordered pair ( destination city, cost )*/
		ll M[100023]={0};
		ll K=k;
		if(s==k) k--;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			G[a].pb(mp(b,c));
			G[b].pb(mp(a,c));
			if(b<=K) swap(a,b);
			if(a<=K && a!=s)
			{
				if(!M[b])
				{
					M[b]=c;
				}
				else M[b]=min(M[b],c);
			}
			
		}
		for(int i=0;i<=100000;i++)
		{
			if(M[i])
			{
				A[k].pb(mp(i,M[i]));
				A[i].pb(mp(k,M[i]));
			}
			
		}
//		cout<<M[5]<<endl;
		for(int i=min(s,k);i<=n;i++)
		{
			if(i!=s && i<k && i!=K) continue;
//			if(i==5)cout<<"r5 "<<G[i].size()<<endl;
			for(int j=0;j<G[i].size();j++)
			{
				if(G[i][j].ff>K || G[i][j].ff==s || G[i][j].ff==k)
				{
					A[i].pb(G[i][j]);
				}
			}
		}
		A[s].pb(mp(k,x));
		A[k].pb(mp(s,x));
//		cout<<A[5].size()<<endl;
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=0;j<A[i].size();j++)
//			{
//				cout<<i<<" "<<A[i][j].ff<<" "<<A[i][j].ss<<endl;
//			}
//		}
		if(s<=K)
		{
			vll dist(n+1,LLONG_MAX);
			ll val;
			dist[s]=0;
			for(int i=1;i<=K;i++)
			{
				if(i!=s)
					dist[i]=x;
			}
			//A[s].pb(mp(k,x));
			//A[k].pb(mp(s,x));
			dfs(s,dist,0,A,0,0);
			//dfs(k,dist,x,A,k,0);
			/*for(ll i=1;i<=k;i++)
			{
				if(i==s) val=0;
				else val=x;
				dfs(i,dist,val,G,k,0);
			}*/
			print(dist,n);
		}
		else
		{
			vll dist(n+1,LLONG_MAX);
			dist[s]=0;
			dfs(s,dist,0,G,0,0);
			ll mink=LLONG_MAX;
			for(int i=1;i<=K;i++)
			{
				mink=min(mink,dist[i]);
			}
			for(int i=1;i<=K;i++)
			{
				dist[i]=min(dist[i],mink+x);
			}
			print(dist,n);
		}
		
	}
	return 0;
}

