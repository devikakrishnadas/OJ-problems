
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

vi leaf;
vi dfs(vector<vi> &G,int root,int par)
{
    int si=1;
    vector<vi>t;
    if(G[root].size()==1 && par!=-1)
    {
        return {0, 1};
    }
    for(int i=0;i<G[root].size();i++)
    {
        if(G[root][i]==par) continue;
        t.push_back(dfs(G,G[root][i],root));
        si += (int)t.back().size() - 1;
    }
    vi A = t[0];
    for (int i = 1; i < t.size(); ++i) {
        vi right = t[i];
        vi tmp((int)right.size() + (int)A.size() - 1, 4000);
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < right.size(); ++j) {
                tmp[i+j] = min(tmp[i+j],  A[i] + right[j]);
            }
        A.clear();
        A = tmp;
    }
    A.back() = 1;
    return A;
}

int func(int root,vector<vi>&G)
{
    vi A=dfs(G,root,-1);
    return A[leaf.size()/2];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    vector<vi>G(n+1);
    srand(time(NULL));
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
       
    for(int i=1;i<=n;i++)
    {
        if(G[i].size()==1)
            leaf.pb(i);
    }
    int mival=INT_MAX;
    for(int i=0;i<min(20,n);i++)
    {
        int root;
        root=rand()%leaf.size();
        root=leaf[root];
        
        int mi=func(root,G);
        mival=min(mival,mi);
    }
    cout<<mival<<endl;
	return 0;
}

