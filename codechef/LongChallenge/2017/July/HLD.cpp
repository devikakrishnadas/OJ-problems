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

/*
    SpecialChild[i] : Keeps track of Special Child of the ith node 
    a : current node
    prev : previous node
    ChainNo : current Chain Number 
    Chain : Stores all Chains ; Chain[ChainNo] stores the ChainNo'th Chain
    Head[i] : stores the node which is the head of the ith chain
    BelongsToChain[i] : stores the number of the Chain the ith node belongs to
    NodePos[i] : Gives the position of the ith node in the BelongstoChain[i]'th chain
    
*/
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

/**********
    Create Segment tree where each node contains -  min,max and XOR
    
**********/
/*
    SegmentTree[i]=< <min,max>, XOR >
*/
pair<pair<int,int>,int> create_util(int l,int r,int tp,int ap,vector<pair<pair<int,int>,int > >&segmentTree,vi &A)
{
    if(l==r)
    {
        segmentTree[tp].ff.ff=segmentTree[tp].ff.ss=segmentTree[tp].ss=A[l];
        return segmentTree[tp];
    }
    pair<pair<int,int>,int>t1,t2;
    int mid=(l+r)/2;
    t1=create_util(l,mid,2*tp+1,ap,segmentTree,A);
    t2=create_util(mid+1,r,2*tp+2,ap,segmentTree,A);
    segmentTree[tp].ff.ff=min(t1.ff.ff,t2.ff.ff);
    segmentTree[tp].ff.ss=max(t1.ff.ss,t2.ff.ss);
    segmentTree[tp].ss=t1.ss^t2.ss;
    return segmentTree[tp];
}

vector<pair<pair<int,int>,int> > create_tree(vi A)
{
    vector<pair<pair<int,int>,int> >segmentTree(5*A.size()+1);
    create_util(0,A.size()-1,0,0,segmentTree,A);
    return segmentTree;
}
/*
    v is the ancestor of u
*/
/*
    SpecialChild[i] : Keeps track of Special Child of the ith node 
    a : current node
    prev : previous node
    ChainNo : current Chain Number 
    Chain : Stores all Chains ; Chain[ChainNo] stores the ChainNo'th Chain
    Head[i] : stores the node which is the head of the ith chain
    BelongsToChain[i] : stores the number of the Chain the ith node belongs to
    NodePos[i] : Gives the position of the ith node in the BelongstoChain[i]'th chain
*/

int query_tree(int ql,int qr,int l,int r,int k,int tp,vector<pair<pair<int,int>,int > >&segmentTree)
{
//    cout<<"Range"<<ql<<" "<<qr<<" "<<l<<" "<<r<<endl;
    if(qr<l)
        return 0;
    if(ql>r)
        return 0;
//    cout<<"Range"<<ql<<" "<<qr<<endl;
    //cout<<"tp "<<tp<<endl; 
    //cout<<"segment Tree XOR "<<segmentTree[tp].ss<<endl;
    if(segmentTree[tp].ff.ff>k)
    {
        //cout<<segmentTree[tp].ff.ff<<endl;
        //cout<<ql<<" "<<qr<<" "<<"ql and qr"<<endl;
//        cout<<"Enter1"<<endl;
        return 0;
    }
    //cout<<"Not Enter1"<<endl;
    if(ql==qr && segmentTree[tp].ss<=k && ql>=l && qr<=r)
    {
//        cout<<"Enter2"<<endl;
        //cout<<"range "<<ql<<" "<<qr<<endl;
        //cout<<"element :";
        //cout<<segmentTree[tp].ss<<endl;
        //cout<<"tp :"<<tp<<endl;
        
        return segmentTree[tp].ss;
    }
    else if(ql==qr)
    {
//        cout<<"Not Enter2"<<endl;
        return 0;
    }
    if(segmentTree[tp].ff.ss<=k && ql>=l && qr<=r )
    {
//        cout<<"Enter3"<<endl;
        //cout<<"range "<<ql<<" "<<qr<<" "<<segmentTree[tp].ff.ss<<endl;
        return segmentTree[tp].ss;
    }
//    cout<<"Enter4"<<endl; 
    int mid=(ql+qr)/2;
    int a=query_tree(ql,mid,l,r,k,2*tp+1,segmentTree);
    int b=query_tree(mid+1,qr,l,r,k,2*tp+2,segmentTree);
    //cout<<"ans :"<<(a^b)<<endl;
    return a^b;
}
int query_up(int u,int v,int k,vector<vector<pair<pair<int,int>,int> > >&segmentTree,vi &BelongsToChain,vector<vi>&Chain,vi &array_imp,vi &NodePos)
{
    int uchain=BelongsToChain[u],vchain=BelongsToChain[v];
    int ans=0;
    while(1)
    {
        
        //cout<<"uchain "<<uchain<<" vchain "<<vchain<<endl;
        if(uchain==vchain)
        {
            //cout<<NodePos[v]<<" "<<NodePos[u]<<endl;
            ans=ans^query_tree(0,Chain[uchain].size()-1,NodePos[v]+1,NodePos[u],k,0,segmentTree[uchain]);
            /*
                NodePos[v]+1 can be wrong
            */
            break;
        }
        else
        {
            ans=ans^query_tree(0,Chain[uchain].size()-1,0,NodePos[u],k,0,segmentTree[uchain]);
            u=array_imp[u];
            uchain=BelongsToChain[u];
            if(u==v)
                break;
        }
    }
    return ans;
}
int query(int u,int v,int k,vi &depth,vector<vector<pair<pair<int,int>,int> > > &segmentTree,vi &BelongsToChain,vector<vi>&Chain,vi &array_imp,vi &NodePos)
{
    int lca=LCA(u,v,array_imp,depth);
    //cout<<"r1"<<endl;
//    cout<<"LCA "<<lca<<endl;
    int a=query_up(u,lca,k,segmentTree,BelongsToChain,Chain,array_imp,NodePos);
    int b=query_up(v,lca,k,segmentTree,BelongsToChain,Chain,array_imp,NodePos);
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
        vi array_imp(n+1,-1);
        vector<vector<pair<int,int> > >A(n+1);
        vector<vector<pair<pair<int,int>,int> > >SegmentTrees(n+1);
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
        vi array_val(n+1,0);
        dfs(ChildCount,SpecialChild,1,-1,array_imp,depth,1,A,array_val);
    
        int ChainNo=0;
        vector< vi >Chain(n+1);
        vi Head(n+1,-1),BelongsToChain(n+1,-1),NodePos(n+1,-1);
        HLD(A,SpecialChild,1,-1,ChainNo,Chain,Head,BelongsToChain,NodePos,array_val);
    
        for(int i=0;i<=ChainNo;i++)
        {
            SegmentTrees[i]=create_tree(Chain[i]);
        }
        int m;
        cin>>m;
        while(m--)
        {
            int u,v,k;
            cin>>u>>v>>k;
            cout<<query(u,v,k,depth,SegmentTrees,BelongsToChain,Chain,array_imp,NodePos)<<endl;
        }
    }
    return 0;
}

