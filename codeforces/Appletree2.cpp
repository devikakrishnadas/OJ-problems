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
vll mi(100023,0);
vll sum(100023,0);
//vll leaf;
//ll lcm=1;
//int m=INT_MAX;
ll fans=0;
void dfs(int a, vector< vi >G,int par, vll arr)
{
	if(G[a].size()==1)
	{
		if(arr[a]!=0)
			sum[a]=arr[a];
		mi[a]=1;
	//	lcm=(lcm*mi[a])/(__gcd(lcm,mi[a]));
		return ;
	}
	int si=G[a].size();
	if(a!=0) si--;
	ll mini=LLONG_MAX;
	ll lcm=1;
	
	for(int i=0;i<G[a].size();i++)
	{
		if(G[a][i]!=par)
		{
			dfs(G[a][i],G,a,arr);
			sum[a]=sum[a]+sum[G[a][i]];
			if(mi[G[a][i]])
				lcm=(lcm*mi[G[a][i]])/(__gcd(lcm,mi[G[a][i]]));
			else
			{
				cout<<G[a][i]+1<<endl;
			}
			mini=min(mini,sum[G[a][i]]);
		}
	}
	mi[a]=lcm*si;
	//cout<<mi[a]<<"*"<<si<<endl;
	ll t=mi[a]/si;
	ll ans=(mini/t)*t;
	fans=fans+sum[a]-(si*ans);
	sum[a]=si*ans;
}

int main()
{
	mi[0]=1;
	srand(153);
	vll arr;
//	int n;
	int x,y;
	//vi A[100023];
	n=100000;
	vector< vi >A(n);
	//int sum=0;
	for(int i=0;i<n;i++)
	{
		x=rand()%100000000+1;
		arr.pb(x);
	//	sum+=x;
	}
	for(int i=0;i<n-1;i++)
	{
		//cin>>x>>y;
		//x--; y--;
		x=i;y=i+1;
		A[x].pb(y);
		A[y].pb(x);
	}
	dfs(0,A,-1,arr);
	
	cout<< fans <<endl;
	return 0;
}
