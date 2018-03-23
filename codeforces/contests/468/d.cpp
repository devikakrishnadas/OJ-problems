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
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;

vector< vi >g(100023);

vi dis(100023,0);
void dfs(int a)
{
    for(int x:g[a])
    {
        dis[x] = dis[a]+1;
        dfs(x);
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vi p(n+1,0);
    FOR(i,1,n)
    {
        int p;
        cin>>p;
        g[p].pb(i+1);
    }
    dfs(1);
    map<int,int>a;
    for(int i=1;i<=n;i++)
    {
        a[dis[i]]++;
    }
    int ans=0;
    for(auto x:a)
    {
        ans+=((x.ss)%2);
    }
    cout<<ans<<endl;
	return 0;
}

