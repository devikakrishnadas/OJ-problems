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

int dfs(vi &ChildCount, vi &SpecialChild, int a, int prev,vi &array_imp,vi &depth,int d,vector<vector<pair<int,int> > >&A)
{
    int c=0;
    int ma=-1;
    
    if(array_imp[a]==-1)
        array_imp[a]=a;

    depth[a]=d;
    for(int i=0;i<A[a].size();i++)
    {
        if(A[a][i].ff!=prev)
        {
            if(ma==-1)
                ma=i;
            int val=0;
            val=dfs(ChildCount,SpecialChild,A[a][i].ff,a,array_imp,depth,d+1,A);
            c+=val;
            if(ChildCount[A[a][ma].ff]<ChildCount[A[a][i].ff])
            {
                ma=i;
            }
            array_imp[A[a][i].ff]=a;
        }
    }
    if(ma!=-1)
        SpecialChild[a]=A[a][ma].ff;
    else SpecialChild[a]=-1;
    ChildCount[a]=c;
    return ChildCount[a]+1;
}

void HLD(vector<vector<pair<int,int> > >&A,vi &SpecialChild,int a,int prev,int &ChainNo,vector<vi>&Chain,vi &Head,vi &BelongsToChain,vi &NodePos)
{
    if(Head[ChainNo]==-1)
    {
        Head[ChainNo]=a;
    }
    BelongsToChain[a]=ChainNo;

    int s=Chain[ChainNo].size();

    Chain[ChainNo].pb(a);

    NodePos[a]=s;
    if(SpecialChild[a]!=-1)
    HLD(A,SpecialChild,SpecialChild[a],a,ChainNo,Chain,Head,BelongsToChain,NodePos);
    for(int i=0;i<A[a].size();i++)
    {
        if(A[a][i].ff==prev) continue;
        else if(A[a][i].ff==SpecialChild[a])
        {
            //Chain[ChainNo].pb(A[a][i].ss);
            continue;
            //HLD(SpecialChild,A[a][i].ff,a,ChainNo,Chain,Head,BelongsToChain,NodePos);
        }
        else
        {
            ChainNo++;
            //Chain[ChainNo].pb(A[a][i].ss);
            HLD(A,SpecialChild,A[a][i].ff,a,ChainNo,Chain,Head,BelongsToChain,NodePos);
        }
    }
}

int LCA_Util(int v,int u,vi &array_imp,vi &depth)
{
    while(1)
    {
        if(u==v)
        {
            return u;
        }
        if(depth[u]>depth[v])
        {
            u=array_imp[u];
        }
        else
        {
            v=array_imp[v];
        }

    }
}

int LCA(int u,int v,vi &array_imp, vi &depth)
{
    return LCA_Util(u,v,array_imp,depth);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vi array_imp(n+1,-1);
    vector<vector<pair<int,int> > >A(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        A[u].pb(mp(v,c));
        A[v].pb(mp(u,c));
    }
    vi ChildCount(n+1,0); /* ChildCount[i] : represents the number of nodes that exist in the subtree rooted at i */
    vi SpecialChild(n+1,-1);
    vi depth(n+1,0);
    dfs(ChildCount,SpecialChild,1,-1,array_imp,depth,1,A);
    
    int ChainNo=0;
    vi Head(n+1,-1),BelongsToChain(n+1,-1),NodePos(n+1,-1);
    vector<vi>Chain(n+1);
    //cout<<SpecialChild[1]<<" "<<SpecialChild[2]<<" "<<SpecialChild[3]<<endl;
    HLD(A,SpecialChild,1,-1,ChainNo,Chain,Head,BelongsToChain,NodePos);
    cout<<"CHAINS"<<endl;    
    for(int i=0;i<=ChainNo;i++)
    {
        for(int j=0;j<Chain[i].size();j++)
        {
            cout<<Chain[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}



