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
int ans=INT_MAX;
int v[200]={0};
int n;
void dfs(int G[200][200],int a,int l,int vis[100])
{
	if(vis[a])
	{
		if(l>1)
		ans=min(ans,l);
		
		return;
	}
	l++;
	
	v[a]++;
	vis[a]++;
	for(int i=0;i<n;i++)
	{
		if(G[a][i] && i!=a)
		dfs(G,i,l,vis);	
	}
}
int main()
{
	
	cin>>n;
	int A[1000];
	int G[200][200]={0};
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		A[i]--;
		
		G[i][A[i]]=1;
	}
	
	for(int i=0;i<n;i++)
	{
		if(!v[i])
		{
			int vis[200]={0};
			dfs(G,i,0,vis);
			
		}
	}
	if(ans==INT_MAX) cout<<-1<<endl;
	else cout<<(ans*(ans-1))/2<<endl;
	return 0;
}

