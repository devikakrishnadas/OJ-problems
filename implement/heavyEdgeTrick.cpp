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

//vi G[100100];
vi ans(100023,0);
vector<set<int> >A(100023);
int sub[100100];

void merge(set<int>&a,set<int>&b)
{
    for(set<int>::iterator it=b.begin();it!=b.end();it++)
    {
        a.insert(*it);
    }
}
void func(vector<vi>&G,int a,int p,vi &val)
{
    int ma=0;
//    cout<<"dfs of "<<a<<endl;
    for(int i=0;i<G[a].size();i++)
    {
        if(G[a][i]==p)
            continue;
        func(G,G[a][i],a,val);
        if(A[ma].size()<A[i].size())
        {
            ma=i;
        }
        //cout<<ma<<" "<<A[ma].size()<<endl;
    }
    for(int i=0;i<G[a].size();i++)
    {
        if(i==ma || G[a][i]==p) continue;
        merge(A[ma],A[i]);
    }
    A[ma].insert(val[a]);
    ans[a]=A[ma].size();
}

/*
void dfs(int u, int p, vi & vals) {
    sub[u] = 1;
    int maxSize = -1, maxNode = -1;
    for (int c : G[u]) if (c != p) {
        dfs(c, u, vals);
        sub[u] += sub[c];
        if (sub[c] > maxSize) {
            maxSize = sub[c];
            maxNode = c;
        }
    }
    if (maxNode != -1) {
        swap(dis[u], dis[maxNode]);
        for (int c : G[u]) if (c != p) {
            for (int e : dis[c]) dis[u].insert(e);
        }
    }
    dis[u].insert(vals[u]);
    ans[u] = dis[u].size();
}
*/

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vi val(n+1);
    vector<vi>G(n+1);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    func(G,1,-1,val);

    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
	return 0;
}

