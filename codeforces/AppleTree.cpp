#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;
int n;
vector<bool>vis(100023,0);
vll mi(100023,0);
vll sum(100023,0);
//vll leaf;
//ll lcm=1;
//int m=INT_MAX;
ll fans=0;
ll abc=0;
void dfs(int a, vector< vll >G,int par, vll arr)
{
//	cout<<a<<endl;
	if(vis[a]==1)
		return;
	if(abc==1)
		return;
	vis[a]=1;
	if(G[a].size()==1 && a!=0)
	{
		if(arr[a]!=0)
			sum[a]=arr[a];
		else
		{	
//			cout<<"r1"<<endl;
			abc=1;
			return ;	
		}
		mi[a]=1;
	//	lcm=(lcm*mi[a])/(__gcd(lcm,mi[a]));
		return ;
	}
	ll si=G[a].size();
	if(a!=0) si--;
	ll mini=LLONG_MAX;
	ll lcm=1;
	
	for(int i=0;i<G[a].size();i++)
	{
		
		if(G[a][i]!=par)
		{
			dfs(G[a][i],G,a,arr);
			if(abc==1)
				return;
			sum[a]=sum[a]+sum[G[a][i]];
//			if(mi[G[a][i]])
			lcm=(lcm*mi[G[a][i]])/(__gcd(lcm,mi[G[a][i]]));
//			else
			{
//				cout<<G[a][i]+1<<"zero "<<endl;
			}
			//mini=min(mini,sum[G[a][i]]);
			if(mini>sum[G[a][i]])
			{
				mini=sum[G[a][i]];
			}
		}
	}
	mi[a]=lcm*si;
	//cout<<mi[a]<<"*"<<si<<endl;
	//ll t=lcm;
	ll ans=(mini/lcm)*lcm;
	fans=fans+sum[a]-(si*ans);
	if(ans==0)
	{
//		cout<<"r2"<<endl;
		abc=1;
		return ;
	}
	sum[a]=si*ans;
}

int main()
{
	mi[0]=1;
	vll arr;
//	int n;
	ll x,y;
	//vi A[100023];
	cin>>n;
	vector< vll >A(n);
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		arr.pb(x);
		sum+=x;
	}
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		x--; y--;
		A[x].pb(y);
		A[y].pb(x);
	}
	dfs(0,A,-1,arr);
	if(abc)
	{
		cout<<sum<<endl;
	}
	else
		cout<< fans <<endl;
	return 0;
}
