
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

void createSegmentTree(int STree[5*100002][3],vi &a,int tp,int s,int e)
{
    if(s==e)
    {
        STree[tp][1]=s;
        STree[tp][2]=a[s];
        return;
    }
    int m=(s+e)/2;
    createSegmentTree(STree,a,2*tp+1,s,m);
    createSegmentTree(STree,a,2*tp+2,m+1,e);
    STree[tp][2]=max(STree[2*tp+1][2],STree[2*tp+2][2]);
    if(STree[2*tp+1][2]>STree[2*tp+2][2])
    {
        STree[tp][1]=STree[2*tp+1][1];
    }
    else if(STree[2*tp+1][2]==STree[2*tp+2][2])
    {
        STree[tp][1]=min(STree[2*tp+1][1],STree[2*tp+2][1]);
    }
    else
    {
        STree[tp][1]=STree[2*tp+2][1];
    }
}
void createSegmentTreeUtil(int STree[5*100002][3],vi &a,int n)
{
    createSegmentTree(STree,a,0,0,n-1);
}

void updateTree(int STree[5*100002][3],int ql,int qr,int s,int e,int x,int tp)
{
    if(e<ql || s>qr) return;
    if(s==e)
    {
        
        STree[tp][2]+=x;
        STree[tp][2]+=STree[tp][0];
        STree[tp][0]=0;
        return;
    }
    if(s>=ql && e<=qr)
    {
        STree[tp][2]+=x;
        STree[tp][0]+=x;
        STree[2*tp+1][0]+=STree[tp][0];
        STree[2*tp+2][0]+=STree[tp][0];
        STree[tp][0]=0;
        return;
    }
    STree[2*tp+1][0]+=STree[tp][0];
    STree[2*tp+2][0]+=STree[tp][0];
    STree[tp][2]+=STree[tp][0];
    STree[tp][0]=0;
    
    int m=(s+e)/2;
    updateTree(STree,ql,qr,s,m,x,2*tp+1);
    updateTree(STree,ql,qr,m+1,e,x,2*tp+2);
    STree[tp][2]=max(STree[2*tp+1][2],STree[2*tp+2][2]);
    if(STree[2*tp+1][2]>STree[2*tp+2][2])
    {
        STree[tp][1]=STree[2*tp+1][1];
    }
    else if(STree[2*tp+1][2]==STree[2*tp+2][2])
    {
        STree[tp][1]=min(STree[2*tp+1][1],STree[2*tp+2][1]);
    }
    else
    {
        STree[tp][1]=STree[2*tp+2][1];
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,q;
    cin>>n;//>>q;
    vi a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int STree[5*100002][3]={0}; 
    /*  STree[i][0] lazy
        Stree[i][1] stores the segment tree for max element ( but stores j if a[j] is the max element in given range )
        Stree[i][2] stores the max val;
    */
    for(int i=0;i<=10;i++) 
    {
        STree[i][1]=-1;
    }
    createSegmentTreeUtil(STree,a,n);
    for(int i=0;i<=10;i++)
    {
        cout<<STree[i][2]<<" ";
    }
    cout<<endl;
    updateTree(STree,0,1,0,2,3,0);
    updateTree(STree,0,0,0,2,3,0);
    updateTree(STree,1,1,0,2,3,0);
    updateTree(STree,2,2,0,2,3,0);
    for(int i=0;i<=10;i++)
    {
        cout<<STree[i][2]<<" ";
    }
    cout<<endl;
	return 0;
}

