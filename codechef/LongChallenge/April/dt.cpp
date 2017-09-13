#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

void dfs(ll a,vector<vector<pair<ll,ll> > >&A,vll &dist,ll pa)
{
	for(int i=0;i<A[a].size();i++)
	{
		if(dist[a]+A[a][i].ss < dist[A[a][i].ff] && A[a][i].ff!=a && A[a][i].ff!=pa)
		{
//			cout<<a<<" "<<A[a][i].ff<<" "<<A[a][i].ss<<endl;
			dist[A[a][i].ff]=dist[a]+A[a][i].ss;
			dfs(A[a][i].ff,A,dist,a);
		}
	}
}

void print(vll &d)
{
	for(int i=1;i<d.size();i++)
	{
		cout<<d[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k,x,m,s,a,b,c;

		cin>>n>>k>>x>>m>>s;
		vector<vector<pair<ll,ll> > >A(100001),G(100001);
		ll M[100023]={0};
		for(int i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			G[a].pb(mp(b,c));
			G[b].pb(mp(a,c));
			if(b<=k) swap(a,b);
			if(a<=k && a!=s)
			{
				if(M[b])
				{
					M[b]=min(M[b],c);
				}
				else
				{
					M[b]=c;
				}
			}	
			else
			{
				A[a].pb(mp(b,c));
				A[b].pb(mp(a,c));
//				cout<<a<<" "<<b<<" "<<c<<endl;
			}
		}
//		cout<<"r1"<<endl;
		for(int i=1;i<=n;i++)
		{
			if(M[i])
			{
				A[0].pb(mp(i,M[i]));
				A[i].pb(mp(0,M[i]));
//				cout<<i<<" "<<M[i]<<endl;
			}
		}	
		A[s].pb(mp(0,x));
		A[0].pb(mp(s,x));
		vll dist(n+1,LLONG_MAX);
		dist[s]=0;
//		cout<<endl<<endl;
//		cout<<"r2"<<endl;
		if(s<=k)
		{	
			for(int i=1;i<=k;i++) dist[i]=x;
			dist[s]=0;
//			cout<<"r2.1"<<endl;
//			dfs(s,G,dist,-1);
//			cout<<"r2.2"<<endl;
			dfs(s,A,dist,-1);
//			cout<<"r2.3"<<endl;
			for(int i=1;i<=k;i++)
			{
				dist[i]=min(dist[i],x);
			}
		}
		else
		{
			ll mink=LLONG_MAX;
			dfs(s,G,dist,-1);
			for(int i=1;i<=k;i++)
			{
				mink=min(mink,dist[i]);
			}
			for(int i=1;i<=k;i++)
			{
				dist[i]=min(dist[i],x+mink);
			}
		}
//		cout<<"r3"<<endl;
		print(dist);
	}
	return 0;
}
					
