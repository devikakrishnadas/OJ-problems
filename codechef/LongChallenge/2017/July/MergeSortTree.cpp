#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define N 50
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

void merge(vector<pair<int,int> > &t1, vector<pair<int,int> > &t2,vector<pair<int,int> > &t)
{
    int i=0,j=0;
    int x=0;
    while(1)
    {
        int a=0,b=0;
        if(i<t1.size())
            a=t1[i].ff;
        else a=INT_MAX;

        if(j<t2.size())
            b=t2[j].ff;
        else b=INT_MAX;

        if(a==INT_MAX && b==INT_MAX) break;

        if(a<b)
        {
            x=x^a;
            i++;
            t.pb(mp(a,x));
        }
        else
        {
            j++;
            x=x^b;
            t.pb(mp(b,x));
        }
    }
}

void buildTree(vector<vector<pair<int,int> > > &tree,int l,int r,vi &A,int tp)
{
    //cout<<l<<" "<<r<<endl;
    if(l==r)
    {
        tree[tp].pb(mp(A[l],A[l]));
        return;
    }
    int mid=(l+r)/2;
    buildTree(tree,l,mid,A,2*tp+1);
    buildTree(tree,mid+1,r,A,2*tp+2);
    merge(tree[2*tp+1],tree[2*tp+2],tree[tp]);
}

int binary_search(int k, vector<pair<int,int> > &tree)
{
    int s=0;
    int e=tree.size()-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(tree[mid].ff<=k)
        {
            ans=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    if(ans==-1)
        return 0;
    return tree[ans].ss;
}
int query_tree(int tp,int l,int r,int ql,int qr,int k,vector<vector<pair<int,int> > > &tree)
{
    
    if(r<ql)
    {
        return 0;
    }
    if(l>qr)
    {
        return 0;
    }
//    cout<<"range "<<l<<" "<<r<<endl;
    if(l>=ql && r<=qr)
    {
        
        int a= binary_search(k,tree[tp]);
//        cout<<"ans :"<<a<<endl;
        return a;
    }
    int mid=(l+r)/2;
    return query_tree(2*tp+1,l,mid,ql,qr,k,tree) ^ query_tree(2*tp+2,mid+1,r,ql,qr,k,tree);
}

int dfs(vi &ChildCount, vi &SpecialChild, int a, int prev,vi &array_imp,vi &depth,int d,vector<vector<pair<int,int> > >&A,vi &array_val)
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
            val=dfs(ChildCount,SpecialChild,A[a][i].ff,a,array_imp,depth,d+1,A,array_val);
            array_val[A[a][i].ff]=A[a][i].ss;
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

void HLD(vector<vector<pair<int,int> > >&A,vi &SpecialChild,int a,int prev,int &ChainNo,vector<vi>&Chain,vi &Head,vi &BelongsToChain,vi &NodePos,vi &array_val)
{

    if(Head[ChainNo]==-1)
    {
        Head[ChainNo]=a;
    }
    BelongsToChain[a]=ChainNo;

    int s=Chain[ChainNo].size();

    Chain[ChainNo].pb(array_val[a]);

    NodePos[a]=s;
    if(SpecialChild[a]!=-1)
    HLD(A,SpecialChild,SpecialChild[a],a,ChainNo,Chain,Head,BelongsToChain,NodePos,array_val);
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
            HLD(A,SpecialChild,A[a][i].ff,a,ChainNo,Chain,Head,BelongsToChain,NodePos,array_val);
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

int query_up(int u,int v,int k,vector<vector<pair<int,int> > >tree[N],vi &BelongsToChain,vector<vi>&Chain,vi &array_imp,vi &NodePos)
{
    int uchain=BelongsToChain[u],vchain=BelongsToChain[v];
    int ans=0;
    while(1)
    {
        //cout<<"uchain "<<uchain<<" vchain "<<vchain<<endl;
        if(uchain==vchain)
        {
            //cout<<NodePos[v]<<" "<<NodePos[u]<<endl;
            ans=ans^query_tree(0,0,Chain[uchain].size()-1,NodePos[v]+1,NodePos[u],k,tree[uchain]);
            
            /*
                NodePos[v]+1 can be wrong
            */
            break;
        }
        else
        {
            ans=ans^query_tree(0,0,Chain[uchain].size()-1,0,NodePos[u],k,tree[uchain]);
            u=array_imp[u];
            uchain=BelongsToChain[u];
            if(u==v)
                break;
        }
    }
    return ans;
}

int query(int u,int v,int k,vi &depth,vector<vector<pair<int,int> > >tree[N],vi &BelongsToChain,vector<vi>&Chain,vi &array_imp,vi &NodePos)
{
    int lca=LCA(u,v,array_imp,depth);
    //cout<<"r1"<<endl;
//    cout<<"LCA "<<lca<<endl;
    int a=query_up(u,lca,k,tree,BelongsToChain,Chain,array_imp,NodePos);
    int b=query_up(v,lca,k,tree,BelongsToChain,Chain,array_imp,NodePos);
//    cout<<a<<" "<<b<<endl;
    return a^b;
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
        cin>>n;
        vector< vector<pair<int,int> > >A(n+1);
        for(int i=1;i<n;i++)
        {
            int u,v,r;
            cin>>u>>v>>r;
            A[u].pb(mp(v,r));
            A[v].pb(mp(u,r));
        }
        vector<vector<pair<int,int> > > tree[N];
        vector<vector<pair<int,int> > > temp(5*n);
        vi ChildCount(n+1,0); /* ChildCount[i] : represents the number of nodes that exist in the subtree rooted at i */
        vi SpecialChild(n+1,-1);
        vi depth(n+1,0);
        vi array_val(n+1,0);
        vi array_imp(n+1,0);
        dfs(ChildCount,SpecialChild,1,-1,array_imp,depth,1,A,array_val);
        int ChainNo=0;
        vector< vi >Chain(n+1);
        vi Head(n+1,-1),BelongsToChain(n+1,-1),NodePos(n+1,-1);
        HLD(A,SpecialChild,1,-1,ChainNo,Chain,Head,BelongsToChain,NodePos,array_val);
        for(int i=0;i<=ChainNo;i++)
        {
            tree[i]=temp;
            buildTree(tree[i],0,Chain[i].size()-1,Chain[i],0);
        }
        // Chain[i][j] was correct;
        int m;
        cin>>m; 
        
        while(m--)
        {
            int l,r,k;
            cin>>l>>r>>k;
            cout<<query(l,r,k,depth,tree,BelongsToChain,Chain,array_imp,NodePos)<<endl;
            
        }
    }
	return 0;
}

