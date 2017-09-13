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
int query_tree(int ql,int qr,int l,int r,int k,int tp,vector<pair<pair<int,int>,int > >&segmentTree)
{
    if(segmentTree[tp].ff.ff>k)
    {
        return 0;
    }
    if(segmentTree[tp].ff.ss<=k)
    {
        return segmentTree[tp].ss;
    }
    int mid=(ql+qr)/2;
    int a=query_tree(ql,mid,l,r,k,2*tp+1,segmentTree);
    int b=query_tree(mid+1,qr,l,r,k,2*tp+2,segmentTree);
    return a^b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    int a;
    vi A;
    vector<pair<pair<int,int>,int > > segmentTree;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        A.pb(a);
    }
    segmentTree=create_tree(A);
    cout<<query_tree(0,2,0,2,3,0,segmentTree)<<endl<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<segmentTree[i].ss<<" ";
    }
    cout<<endl;
	return 0;
}

