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


void dfs(vector<vi>A,int a,int prev,int c,int cp,int cgp,int dp[1000][2][2][2])
{
    for(int i=0;i<A[a].size();i++)
    {
        c1=dfs(A,A[a][i],a,-1,1,cp);
        c2=dfs(A,A[a][i],a,-1,0,cp);
        dp[a][c][cp][cgp]=min(c1,c2);
    }
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
        int n;
        //Q.clear();
        cin>>n;
        vector< vi >A(n+1);
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            A[u].pb(v);
            A[v].pb(u);
        }
        vi coins(n+1,0);
        //cout<<"values"<<endl;
        dfs(1,-1,coins,A);
        
    }
	return 0;
}

