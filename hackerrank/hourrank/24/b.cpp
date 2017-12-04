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

ll val=0;

void findp(vector<vi>&G,int a,int p,int l)
{
    
    for(int i=0;i<G[a].size();i++)
    {
        if(G[a][i]==p) continue;
        val=val+l;
        findp(G,G[a][i],a,l+1);
    }
    
}

double ans=0.0;
void dfs(vector<vi>&G,int a,int p,double v,double prob,int l)
{
    if(G[a].size()==0)
        ans+=(1.0-v);
    for(int i=0;i<G[a].size();i++)
    {
        if(G[a][i]==p) continue;
        ans=ans+1.0-v;
        dfs(G,G[a][i],a,v+l*prob,prob,l+1);
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;  
    cin>>n;
    vector<vi>G(n+1);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    findp(G,1,-1,1);
    double p=1/((double)val);
//    cout<<p<<endl;
    dfs(G,1,-1,0.0,p,1);
    cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;
}

