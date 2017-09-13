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
vector< vll >G(200023);
vll A(200023);
ll n;
ll cnt=0;
vll v(200023,0);
vll Ma(200023,0);
vll _v(200023,0);
void dfs(ll a,ll prev)
{
	v[a]=A[a];
	for(int i=0;i<G[a].size();i++)
	{
		if(G[a][i]!=prev)
		{
			dfs(G[a][i],a);
			v[a]=v[G[a][i]]+v[a];
		}
	}
	Ma[a]=v[a];
	for(int i=0;i<G[a].size();i++)
	{
		if(G[a][i]!=prev)
		{
			Ma[a]=max(Ma[a],Ma[G[a][i]]);
		}
	}
	cnt++;
}
ll ans=INT_MIN;

void bfs(ll a)
{
	queue<ll>q;
	q.push(a);
	ll prev=-1;
	while(!q.empty())
	{
		a=q.front();
		cout<<a<<" ";
		q.pop();
		ll ma=INT_MIN,ma2=INT_MIN;
		for(int i=0;i<G[a].size();i++)
		{
			if(G[a][i]!=prev)
			{
				q.push(G[a][i]);
				if(v[G[a][i]]>ma)
				{
					ma2=ma;
					ma=v[G[a][i]];
				}
			}	
		}
		for(int i=0;i<G[a].size();i++)
		{
			if(G[a][i]==prev) continue;
			if(v[G[a][i]]==ma)
			{
				_v[G[a][i]]=ma2;
			}
			else
			{
				v[G[a][i]]=ma;
			}
		}
		ans=max(ans,Ma[a]+v[a]);
		prev=a;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
	}
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);	
	}
	cout<<"r1"<<endl;
	dfs(1,-1);
	cout<<"r2"<<endl;
	if(cnt==1)
	{
		cout<<"Impossible"<<endl;
	}
	else
	{
		bfs(1);
		cout<<"r3"<<endl;
		cout<<ans<<endl;
	}
	
	return 0;
}

