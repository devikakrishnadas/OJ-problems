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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    priority_queue<int>g;
    int n,q;
    cin>>n;
    vi vis(2*n+1);
    for(int i=1;i<=n;i++)
    {
        g.push(2*i-1);
        vis[2*i-1]=i;
    }
    int v=1;
    while(1)
    {
        int a = g.top();
        g.pop();

        int t = a-v;
        if(vis[t] or t<=0)
            break;
        v++;
        g.push(t);
        vis[t]=vis[a];
        vis[a]=0;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<vis[i]<<" ";
    }
    cout<<endl;
	return 0;

}

